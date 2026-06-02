#include <input/touch/touchinteractionresolver.h>
#include <input/touch/touchcontextresolver.h>
#include <worldsim/character/charactermanager.h>
#include <worldsim/character/character.h>
#include <ai/actionbuttonhandler.h>

TouchInteractionResolver& TouchInteractionResolver::GetInstance()
{
    static TouchInteractionResolver sInstance;
    return sInstance;
}

TouchInteractionResolver::TouchInteractionResolver()
{
}

TouchInteractionResolver::~TouchInteractionResolver()
{
}

void TouchInteractionResolver::Reset()
{
}

TouchInteractionType TouchInteractionResolver::ResolveCharacterInteraction() const
{
    if ( !TouchContextResolver::GetInstance().IsCharacter() )
    {
        return TOUCH_INTERACTION_NONE;
    }

    Character* character = GetCharacterManager()->GetCharacter( 0 );

    if ( character == 0 )
    {
        return TOUCH_INTERACTION_NONE;
    }

    if ( character->IsInCarOrGettingInOut() )
    {
        return TOUCH_INTERACTION_NONE;
    }

    ActionButton::ButtonHandler* handler =
        character->GetActionButtonHandler();

    if ( handler == 0 )
    {
        return TOUCH_INTERACTION_NONE;
    }

    if ( !handler->IsInstanceEnabled() )
    {
        return TOUCH_INTERACTION_NONE;
    }

    /*
     * Fase 1:
     * Cualquier acción contextual activa se muestra como exclamación.
     * Luego refinamos por tipo de handler.
     */
    return TOUCH_INTERACTION_MISSION_MAIN;
}

TouchInteractionIcon TouchInteractionResolver::ResolveCharacterInteractionIcon() const
{
    return TouchInteractionTypeToIcon(
        ResolveCharacterInteraction()
    );
}