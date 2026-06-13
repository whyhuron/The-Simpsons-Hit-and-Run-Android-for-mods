//=============================================================================
// Copyright (C) 2002 Radical Entertainment Ltd.  All rights reserved.
//
// File:        inputmanager.cpp
//
// Description: Implementation for the InputManager class.
//
// History:     + Created -- TBJ
//
//=============================================================================

//========================================
// System Includes
//========================================
#include <string.h> // ::strcmp()
//FTech 
#include <raddebugwatch.hpp>
#include <raddebug.hpp>
#include <radcontroller.hpp>

//========================================
// Project Includes
//========================================
#include <input/inputmanager.h>
#ifdef RAD_PC
#include <input/usercontrollerWin32.h>
#else
#include <input/usercontroller.h>
#endif
#include <input/button.h>

#include <main/game.h>
#include <main/platform.h>

#include <data/gamedatamanager.h>

#ifndef WORLD_BUILDER
#include <memory/srrmemory.h>
#else
#define MEMTRACK_PUSH_GROUP(x)
#define MEMTRACK_POP_GROUP(x)
#define GMA_PERSISTENT 0
#define GMA_DEFAULT 0
#endif

#ifdef RAD_PS2
#include <main/ps2platform.h>
#include <libmtap.h>
#endif


#ifdef RAD_ANDROID
#include <input/touch/touchcameracontroller.h>
#include <input/touch/touchinputadapter.h>
#include <input/touch/touchinputmodemanager.h>
#include <data/config/androidconfigurationmanager.h>
extern "C" void radControllerSDLSetAndroidRumblePolicyCallback( bool (*callback)() );
extern "C" void radControllerSDLSetAndroidGamepadInputCallback( void (*callback)(float) );
#endif

#if defined(RAD_ANDROID)
  #include <android/log.h>
  #define LOG_TAG "SimpsonsHitAndRun"
  #define LOGI(...) __android_log_print(ANDROID_LOG_INFO,  LOG_TAG, __VA_ARGS__)
  #define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#endif

#if defined RAD_XBOX

    InputManager::eButtonMap RESET_BUTTONS[] =
    {
        InputManager::Start,
        InputManager::Select
    };

    const int NUM_RESET_BUTTONS = 2;

#else //GC handled in gcmanager and we don't do this on the PC

InputManager::eButtonMap RESET_BUTTONS[] =
{
    InputManager::Start
};

const int NUM_RESET_BUTTONS = 0;

#endif

const unsigned int RESET_TIMEOUT = 2000;

#if defined(RAD_ANDROID)
static void AndroidInputManagerGamepadInputCallback( float magnitude )
{
    TouchInputModeManager& inputMode =
        TouchInputModeManager::GetInstance();

    /*
     * Option B:
     * InputManager ignores repeated physical gamepad input if the gamepad
     * is already confirmed.
     */
    if ( inputMode.IsGamepadConfirmed() )
    {
        return;
    }

    inputMode.NotifyGamepadInput( magnitude );

    if ( inputMode.IsGamepadConfirmed() )
    {
        TouchInputAdapter::GetInstance().ClearQueuedInputs();
        TouchInputAdapter::GetInstance().ClearActiveInputs();

        InputManager* inputManager = InputManager::GetInstance();

        for ( unsigned int i = 0; i < Input::MaxControllers; ++i )
        {
            inputManager->SetRumbleForDevice(
                static_cast<int>( i ),
                inputManager->IsRumbleEnabled()
            );
        }
    }
}

static bool AndroidInputManagerRumblePolicy()
{
    if ( !GetAndroidConfigurationManager()->IsGamepadVibrationEnabled() )
    {
        return false;
    }

    if ( !InputManager::GetInstance()->IsAndroidPhysicalGamepadConnected() )
    {
        return false;
    }

    return true;
}

static bool IsAndroidRumbleAllowed( bool rumbleEnabled )
{
    if ( !rumbleEnabled )
    {
        return false;
    }

    if ( !GetAndroidConfigurationManager()->IsGamepadVibrationEnabled() )
    {
        return false;
    }

    if ( !InputManager::GetInstance()->IsAndroidPhysicalGamepadConnected() )
    {
        return false;
    }

    return true;
}

bool InputManager::IsAndroidPhysicalGamepadCandidateConnected() const
{
    if ( mxIControllerSystem2 == NULL )
    {
        return false;
    }

    /*
     * This only means SDL has enumerated at least one physical controller
     * object.
     *
     * On Android this must be treated as a candidate, not as a confirmed
     * external gamepad, because some devices can expose false positives.
     */
    return mxIControllerSystem2->GetNumberOfControllers() > 0;
}

bool InputManager::IsAndroidPhysicalGamepadConnected() const
{
    /*
     * From now on, Android "physical gamepad connected" means:
     * confirmed by real physical gamepad input.
     *
     * This is the value used for rumble and for blocking touch.
     */
    return TouchInputModeManager::GetInstance().IsGamepadConfirmed();
}

void InputManager::SyncAndroidInputModeWithPhysicalGamepad()
{
    if ( this->IsAndroidPhysicalGamepadCandidateConnected() )
    {
        /*
         * SDL detected something that could be a gamepad.
         *
         * Do NOT hide the touch HUD yet.
         * Do NOT enable rumble yet.
         * Wait until real physical input confirms the gamepad.
         */
        TouchInputModeManager::GetInstance().NotifyGamepadCandidateConnected();
    }
    else
    {
        TouchInputModeManager::GetInstance().NotifyGamepadDisconnected();
    }
}


#endif // RAD ANDROID

//******************************************************************************
// Global Data, Local Data, Local Classes
//******************************************************************************

//
// Static pointer to instance of singleton.
//
InputManager* InputManager::spInstance = NULL;


//******************************************************************************
// Public Member Functions
//******************************************************************************

// Creates the InputManager.
// This is a singleton so only one instance is allowed.
InputManager* InputManager::CreateInstance()
{
MEMTRACK_PUSH_GROUP( "InputManager" );

    rAssert( spInstance == NULL );

    spInstance = new InputManager;
MEMTRACK_POP_GROUP("InputManager");

    return spInstance;
}

// Access point for the InputManager singleton.  
InputManager* InputManager::GetInstance()
{
    rAssert( spInstance != NULL );

    return spInstance;
}

// Destroy the InputManager.singleton
void InputManager::DestroyInstance()
{
    rAssert( spInstance != NULL );

    delete spInstance;
    spInstance = NULL;
}


void InputManager::Init()
{

MEMTRACK_PUSH_GROUP( "InputManager" );
    ::radControllerInitialize( this, GMA_DEFAULT );

    mxIControllerSystem2 = radControllerSystemGet();

    #if defined(RAD_ANDROID)
        radControllerSDLSetAndroidRumblePolicyCallback( &AndroidInputManagerRumblePolicy );
        radControllerSDLSetAndroidGamepadInputCallback( &AndroidInputManagerGamepadInputCallback );
    #endif

#ifdef RAD_PS2
    // On PS2, check for initial button pushes.
    m_isProScanButtonsPressed = PS2Platform::GetInstance()->CheckForStartupButtons( );
    rDebugPrintf( "Do Progressive scan: %s\n", m_isProScanButtonsPressed ? "yup" : "nope" );
#endif

    unsigned int i = 0;

    for ( i = 0; i < Input::MaxControllers; i++ )
    {
        // preallocate run time controller structure.
        mControllerArray[ i ].Create(i);
    }
    #if defined(__ANDROID__)
            /*
        * Android touch input is injected into controller 0 as virtual input.
        *
        * This keeps controller 0 updateable even when no physical gamepad is
        * connected, allowing the touch HUD/frontend/gameplay controls to work.
        *
        * Important:
        * This does NOT mean that a physical gamepad is connected.
        * Physical gamepad detection must use IsAndroidPhysicalGamepadConnected(),
        * not IsInputAvailable().
        */
    mControllerArray[ 0 ].SetVirtualInputAvailable( true );
    #endif
#ifndef RAD_PC
    mxIControllerSystem2->RegisterConnectionChangeCallback( this );
#endif
    rDebugString( "Just created User controller system\n" );

    EnumerateControllers( );
    #if defined(RAD_ANDROID)
        SyncAndroidInputModeWithPhysicalGamepad();
    #endif
MEMTRACK_POP_GROUP("InputManager");

}


void InputManager::Update( unsigned int timeinms )
{
    // update the button timestamp (so we can tell when buttons were pressed)
    Button::Tick(timeinms);

    ::radControllerSystemService();

    // if controllers have been disconnected, change the state
    if(mConnectStateChanged)
    {
        mConnectStateChanged = false;
        EnumerateControllers( );
        #if defined(RAD_ANDROID)
            SyncAndroidInputModeWithPhysicalGamepad();
        #endif
    }

    #ifdef RAD_ANDROID
    TouchCameraController::GetInstance().Update( timeinms );
    TouchInputAdapter::GetInstance().FlushQueuedInputs();
    #endif

    unsigned int i = 0;

    // update physical controllers
    bool resetting = false;
    for ( i = 0; i < Input::MaxControllers; i++ )
    {
        if(mControllerArray[i].IsInputAvailable())
        {
            mControllerArray[i].Update(timeinms);

            if ( mControllerArray[i].IsConnected() && 
                mResetEnabled &&
                NUM_RESET_BUTTONS > 0 &&
                !resetting &&
                mControllerArray[i].GetInputValueRT( RESET_BUTTONS[ 0 ] ) > 0.5f &&
                mControllerArray[i].GetInputValueRT( RESET_BUTTONS[ 1 ] ) > 0.5f )
            {
                resetting = true;
            }
        }
    }

#ifndef RAD_XBOX
    if ( mResetEnabled )
    {
        if ( !resetting )
        {
            mResetTimeout = 0;
            mIsResetting = false;
        }
        else if ( resetting && !mIsResetting )
        {
            mResetTimeout = RESET_TIMEOUT;
            mIsResetting = true;
        }
    }
#endif


    // broadcast new game state if it has changed
    if(mChangeGameState)
    {
        for ( i = 0; i < Input::MaxControllers; i++ )
        {
            // TC: Why does controller have to be connected for its game state to be updated?
            //     Having the 'if' conditional here causes a problem when the controller is
            //     disconnnected during a state when it's non-active.
            //
//            if(mControllerArray[i].IsConnected())
            {
                mControllerArray[i].SetGameState(mGameState);
            }
        }
        mChangeGameState = false;
    }

    if ( mResetEnabled && mIsResetting && mResetTimeout >= 0 )
    {
        if ( mResetTimeout <= timeinms )
        {
            GetGame()->GetPlatform()->LaunchDashboard();
            mResetTimeout = 0;
            mIsResetting = false;
        }
        else
        {
            mResetTimeout -= timeinms;
        }
    }
}


void InputManager::OnControllerConnectionStatusChange( IRadController * pIController2 )
{
    mConnectStateChanged = true;
}

bool InputManager::IsControllerInPort( int portnum ) const
{
    rAssert(portnum < static_cast< int >( Input::MaxControllers ) );
    #if defined(__ANDROID__)
    return mControllerArray[portnum].IsInputAvailable();
#else
    return mControllerArray[portnum].IsConnected();
#endif
}

void InputManager::ToggleRumble( bool on )
{
    unsigned int i;
    for ( i = 0; i < Input::MaxControllers; ++i )
    {
        if ( mControllerArray[ i ].IsConnected() )
        {
            mControllerArray[ i ].SetRumble( on );
        }
    }
}


//=============================================================================
// InputManager::SetRumbleEnabled
//=============================================================================
// Description: Comment
//
// Parameters:  ( bool isEnabled )
//
// Return:      nothing
//
//=============================================================================
void InputManager::SetRumbleEnabled( bool isEnabled )
{
    #if defined(RAD_ANDROID)
    mIsRumbleEnabled = GetAndroidConfigurationManager()->IsGamepadVibrationEnabled();
#else
    mIsRumbleEnabled = isEnabled;
#endif
}

void InputManager::SetRumbleForDevice( int controllerId, bool bRumbleOn )
{
    if ( (unsigned int)controllerId < Input::MaxControllers)
    {
        #if defined(RAD_ANDROID)
            bRumbleOn = bRumbleOn && IsAndroidRumbleAllowed( mIsRumbleEnabled );
        #endif
        mControllerArray[controllerId].SetRumble( bRumbleOn );
    }
}


bool InputManager::IsRumbleOnForDevice( int controllerId ) const
{
    if ( (unsigned int)controllerId < Input::MaxControllers)
    {
        return mControllerArray[controllerId].IsRumbleOn( );
    }
    return false;
}

void InputManager::TriggerRumblePulse( int controllerId )
{
    if ( (unsigned int)controllerId < Input::MaxControllers)
    {
        #if defined(RAD_ANDROID)
            if ( !IsAndroidRumbleAllowed( mIsRumbleEnabled ) )
            {
                return;
            }
        #endif
        mControllerArray[ controllerId ].PulseRumble();
    }
}

// Returns the value of the input point 'inputIndex' owned by the controller at
// controllerIndex.
float InputManager::GetValue( unsigned int controllerIndex, unsigned int inputIndex ) const
{
    rAssert( controllerIndex < Input::MaxControllers);
    if ( controllerIndex < Input::MaxControllers)
    {
        return mControllerArray[ controllerIndex ].GetInputValue( inputIndex );
    }
    else
    {
        return 0.0f;
    }
}

// Returns a const pointer to the controller at controller index.
UserController* InputManager::GetController( unsigned int controllerIndex )
{
    rAssert( controllerIndex < Input::MaxControllers );
    if ( controllerIndex < Input::MaxControllers )
    {
        return &mControllerArray[ controllerIndex ];
    }
    else
    {
        return 0;
    }
}


// Associate this device with a game object.
int InputManager::RegisterMappable( unsigned int index, Mappable *pMappable )
{
    int handle = Input::INVALID_CONTROLLERID;
    if ( index < Input::MaxControllers)
    {
        handle = mControllerArray[ index ].RegisterMappable( pMappable );
    }
    return handle;
}


// Remove associations between this device and a game object.
void InputManager::UnregisterMappable( unsigned int index, int handle )
{
    if ( handle > Input::INVALID_CONTROLLERID )
    {
        if ( index < Input::MaxControllers)
        {
            mControllerArray[ index ].UnregisterMappable( handle );
        }
    }
}

void InputManager::UnregisterMappable( unsigned int index, Mappable* mappable)
{
    mControllerArray[ index ].UnregisterMappable( mappable );
}

void InputManager::UnregisterMappable( Mappable *pMappable  )
{
    unsigned int i;
    for ( i = 0; i < Input::MaxControllers; ++i )
    {
        mControllerArray[ i ].UnregisterMappable( pMappable );
    }
}


void InputManager::LoadData( const GameDataByte* dataBuffer, unsigned int numBytes )
{
    #if defined(RAD_ANDROID)
    mIsRumbleEnabled = GetAndroidConfigurationManager()->IsGamepadVibrationEnabled();
#else
    mIsRumbleEnabled = ( dataBuffer[ 0 ] != 0 );
#endif
}

void InputManager::SaveData( GameDataByte* dataBuffer, unsigned int numBytes )
{
    dataBuffer[ 0 ] = mIsRumbleEnabled ? ~0 : 0;
}

void InputManager::ResetData()
{
    //Rumble does not RESET.  This is a TRC thing. 
    //mIsRumbleEnabled = true;
}

//******************************************************************************
// Private Member Functions
//******************************************************************************

InputManager::InputManager()
:
mGameState(Input::ACTIVE_ALL),
mChangeGameState(false),
mConnectStateChanged(false),
mIsRumbleEnabled(true),
mIsResetting(false),
mResetEnabled( false ),
m_isProScanButtonsPressed( false )
{
    for( int i = 0; i < MAX_PLAYERS; i++ )
    {
        m_registeredControllerID[ i ] = -1;
    }

    GetGameDataManager()->RegisterGameData( this, 1, "Input Manager" );
#ifdef RAD_PC
    m_pFEMouse = new FEMouse;
#endif
#ifdef RAD_PS2
    mLastMultitapStatus[0] = mLastMultitapStatus[1] = 0;
    mCurMultitapStatus[0] = mCurMultitapStatus[1] = 0;

#endif
}


InputManager::~InputManager()
{
    ReleaseAllControllers();

#ifndef RAD_PC
    mxIControllerSystem2->UnRegisterConnectionChangeCallback( this );
#endif
    #if defined(RAD_ANDROID)
        radControllerSDLSetAndroidRumblePolicyCallback( NULL );
        radControllerSDLSetAndroidGamepadInputCallback( NULL );
    #endif
    ::radControllerTerminate();
#ifdef RAD_PC
    delete m_pFEMouse;
    m_pFEMouse = NULL;
#endif
}

void InputManager::EnumerateControllers( void )
{
    // on the console the controller device and all the mappables are
    // preallocated.  So we don't have to create new associations.
    //
#ifndef RAD_PC
    ref< IRadController > xIC2;
#else
    ref< IRadController > radController[ NUM_CONTROLLERTYPES ];
#endif

    ReleaseAllControllers( );

    bool somethingPluggedIn0 = false;
    bool somethingPluggedIn1 = false;

    unsigned int slot = 0;
    unsigned int port = 0;
    for ( port = 0; port < Input::MaxPorts; ++port )
    {
        for ( slot = 0; slot < Input::MaxSlots; ++slot )
        { 
            unsigned int i = port * Input::MaxSlots + slot;

            char szLocation[ 256 ];

#if defined(RAD_CONSOLE) && !defined( RAD_GC )
            sprintf( szLocation, "Port%d\\Slot%d", port, slot );
#elif defined(RAD_PC)
            char szJoystickLoc[ 256 ];
            char szMouseLoc[ 256 ];
            char szWheelLoc[ 256 ];

            sprintf( szLocation, "Keyboard%d", 0);
            sprintf( szJoystickLoc, "Joystick%d", i);
            sprintf( szMouseLoc, "Mouse%d", i);
            sprintf( szWheelLoc, "SteeringWheel%d", i);
#else //This is GC
            sprintf( szLocation, "Channel%d", i );
#endif

#ifndef RAD_PC
            xIC2 = mxIControllerSystem2->GetControllerAtLocation( szLocation );
#else
            radController[KEYBOARD] = mxIControllerSystem2->GetControllerAtLocation( szLocation );
            radController[GAMEPAD] = mxIControllerSystem2->GetControllerAtLocation( szJoystickLoc );
            radController[MOUSE] = mxIControllerSystem2->GetControllerAtLocation( szMouseLoc );
            radController[STEERINGWHEEL] = mxIControllerSystem2->GetControllerAtLocation( szWheelLoc );

            //Check to see if the steering wheel is on controller 0.

#endif

            //
            // Grab the controller device associated with the foundation controller.
            //
            UserController* controller = &mControllerArray[ i ];


#ifdef RAD_PC
            // One keyboard has to be present. (might want to change later)
            if ( (radController[KEYBOARD] == NULL || !radController[KEYBOARD]->IsConnected( )) && (i == 0) )
            {
                controller->NotifyDisconnect( );
            }
            else
            {
                controller->Initialize( radController );
                controller->NotifyConnect( );
                controller->LoadControllerMappings( );

                for( int i = 0; i < NUM_CONTROLLERTYPES; i++ )
                {
                    radController[i] = NULL;
                }
            }
#else
            if ( xIC2 == NULL || !xIC2->IsConnected( ) )
            {
                controller->NotifyDisconnect( );
            }
            else
            {
#ifdef RAD_PS2
               if(strcmp( "PsxDualShock2", xIC2->GetType() ) == 0 )
                {
                    controller->Initialize( xIC2 );
                    controller->NotifyConnect( );
                    controller->LoadControllerMappings( );
                    controller->SetRumble( IsRumbleEnabled() );
                }
                xIC2 = NULL;

                if ( port == 0 )
                {
                    somethingPluggedIn0 = true;
                }
                else
                {
                    somethingPluggedIn1 = true;
                }
#else
                controller->Initialize( xIC2 );
                controller->NotifyConnect( );
                controller->LoadControllerMappings( );
                SetRumbleForDevice( i, IsRumbleEnabled() ); // Originalmente como esta arriba para ps2

                xIC2 = NULL;
#endif
            }
#endif
        }
    }

#ifdef RAD_PS2

    //TEST THE MULTITAP STATUS
    if ( somethingPluggedIn0 || somethingPluggedIn1 )
    {
        if ( somethingPluggedIn0 )
        {
            mLastMultitapStatus[0] = sceMtapGetConnection(0);
        }

        if ( somethingPluggedIn1 )
        {
            mLastMultitapStatus[1] = sceMtapGetConnection(1);
        }
    }
#endif


#ifdef RAD_PS2
    unsigned int i;
    for ( i = 0; i < Input::MaxUSB; ++i )
    {
        char szLocation[ 256 ];
        sprintf( szLocation, "USB%d", i );

        xIC2 = mxIControllerSystem2->GetControllerAtLocation( szLocation );
        //
        // Grab the controller device associated with the foundation controller.
        //
        UserController* controller = &mControllerArray[ Input::USB0 + i ];

        if ( xIC2 == NULL || !xIC2->IsConnected( ) )
        {
            controller->NotifyDisconnect( );
        }
        else
        {
            if ( xIC2->IsConnected( ) && strcmp( xIC2->GetClassification(), "Wheel" ) == 0 )
            {
                // Initialize the controller.  This will notify all observers of the
                // controller being added.

                controller->Initialize( xIC2 );
                controller->NotifyConnect( );
                controller->LoadControllerMappings( );
            }
            else
            {
                controller->NotifyDisconnect( );
            }
            xIC2 = NULL;
        }
    }
#endif

//#ifdef RAD_DEBUG
    char connectionMap[128] = "Controller status changed (connection : ";

    for( port = 0; port < Input::MaxPorts; port++)
    {
        for( slot = 0; slot < Input::MaxSlots; slot++)
        {
            int index = port * Input::MaxSlots + slot;
            if(mControllerArray[ index ].IsConnected())
            {
                strcat(connectionMap, "x");
            }
            else
            {
                strcat(connectionMap, "o");
            }
        }
        strcat(connectionMap," ");
    }
#ifdef RAD_PS2
    for(unsigned int i = (Input::MaxSlots * Input::MaxPorts); i < Input::MaxControllers; ++i )
    {
        if ( mControllerArray[i].IsConnected() )
        {
            strcat(connectionMap,"U");
        }
        else
        {
            strcat(connectionMap, "o");
        }
    }
#endif
    strcat(connectionMap,")\n");

    rReleaseString(connectionMap);
    
//#endif
}

void InputManager::ReleaseAllControllers( void )
{
    unsigned int i = 0;
    for ( i = 0; i < Input::MaxControllers; i++ )
    {
        mControllerArray[ i ].ReleaseRadController( );
    }
}


void InputManager::SetGameState( Input::ActiveState state )
{
    //
    // The only way to get out of the animated cam input state is to set it
    // to the DEACTIVE_ANIM_CAM state, which actually sends you to active all.
    // Perhaps the input system should really be a stack?
    //
    if( mGameState == Input::ACTIVE_ANIM_CAM )
    {
        if( state == Input::DEACTIVE_ANIM_CAM )
        {
            state = Input::ACTIVE_ALL;
        }
        else
        {
            state = Input::ACTIVE_ANIM_CAM;
        }
    }
    else
    {
        if( state == Input::DEACTIVE_ANIM_CAM )
        {
            return;
        }
    }
    mChangeGameState = true;
    mGameState = state;
}

Input::ActiveState InputManager::GetGameState() const
{
    return static_cast<Input::ActiveState>(mGameState);
}


void
InputManager::RegisterControllerID( int playerID, int controllerID )
{
    rAssert( playerID >= 0 && playerID < MAX_PLAYERS );

    m_registeredControllerID[ playerID ] = controllerID;

    rTunePrintf( "*** Registered Controller ID [%d] for Player %d ***\n",
                 controllerID, playerID + 1 );
}

void
InputManager::UnregisterControllerID( int playerID )
{
    rAssert( playerID >= 0 && playerID < MAX_PLAYERS );

    m_registeredControllerID[ playerID ] = -1;
}

void
InputManager::UnregisterAllControllerID()
{
    for( int i = 0; i < MAX_PLAYERS; i++ )
    {
        UnregisterControllerID( i );
    }
}

#ifdef RAD_WIN32

void InputManager::StartRumbleEffects()
{
    for( int i = 0; i < MAX_PLAYERS; i++ )
    {
        SetRumbleForDevice(i, true);
    }
}

void InputManager::StopRumbleEffects()
{
    for( int i = 0; i < MAX_PLAYERS; i++ )
    {
        SetRumbleForDevice(i, false);
    }
}

#endif


