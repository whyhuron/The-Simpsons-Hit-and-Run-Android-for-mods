#ifndef TOUCHINTERACTIONRESOLVER_H_
#define TOUCHINTERACTIONRESOLVER_H_

#include <input/touch/touchtypes.h>

class TouchInteractionResolver
{
public:
    static TouchInteractionResolver& GetInstance();

    void Reset();

    TouchInteractionType ResolveCharacterInteraction() const;
    TouchInteractionIcon ResolveCharacterInteractionIcon() const;

private:
    TouchInteractionResolver();
    ~TouchInteractionResolver();

    TouchInteractionResolver( const TouchInteractionResolver& );
    TouchInteractionResolver& operator=( const TouchInteractionResolver& );
};

#endif // TOUCHINTERACTIONRESOLVER_H_