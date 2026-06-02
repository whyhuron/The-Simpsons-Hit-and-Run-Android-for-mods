#include <input/touch/touchinputmodemanager.h>

TouchInputModeManager& TouchInputModeManager::GetInstance()
{
    static TouchInputModeManager sInstance;
    return sInstance;
}

TouchInputModeManager::TouchInputModeManager()
    :
    mCurrentMode( TOUCH_INPUT_MODE_TOUCH ),
    mGamepadConnected( false ),
    mTouchHudEnabled( true ),
    mGamepadInputThreshold( 0.20f ),
    mTimeMs( 0 ),
    mLastTouchInputTimeMs( 0 ),
    mLastGamepadInputTimeMs( 0 )
{
}

TouchInputModeManager::~TouchInputModeManager()
{
}

void TouchInputModeManager::Reset()
{
    mCurrentMode = TOUCH_INPUT_MODE_TOUCH;
    mGamepadConnected = false;
    mTouchHudEnabled = true;
    mGamepadInputThreshold = 0.20f;
    mTimeMs = 0;
    mLastTouchInputTimeMs = 0;
    mLastGamepadInputTimeMs = 0;
}

void TouchInputModeManager::Update( unsigned int elapsedMs )
{
    mTimeMs += elapsedMs;
}

void TouchInputModeManager::NotifyTouchInput()
{
    mLastTouchInputTimeMs = mTimeMs;

    /*
     * Physical gamepad has priority.
     * Touch input should not steal the active mode while a real gamepad
     * is connected.
     */
    if ( mGamepadConnected )
    {
        return;
    }

    mCurrentMode = TOUCH_INPUT_MODE_TOUCH;
}

void TouchInputModeManager::NotifyGamepadConnected()
{
    mGamepadConnected = true;
    mCurrentMode = TOUCH_INPUT_MODE_GAMEPAD;
}

void TouchInputModeManager::NotifyGamepadDisconnected()
{
    mGamepadConnected = false;

    // On Android, if the external gamepad is gone, touch should become the
    // default available input method again.
    mCurrentMode = TOUCH_INPUT_MODE_TOUCH;
}

void TouchInputModeManager::NotifyGamepadInput( float magnitude )
{
    if ( magnitude < 0.0f )
    {
        magnitude = -magnitude;
    }

    if ( magnitude < mGamepadInputThreshold )
    {
        return;
    }

    mCurrentMode = TOUCH_INPUT_MODE_GAMEPAD;
    mLastGamepadInputTimeMs = mTimeMs;
}

void TouchInputModeManager::ForceMode( TouchInputMode mode )
{
    mCurrentMode = mode;
}