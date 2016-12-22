#ifndef BERSERK_H
#define BERSERK_H
#include "Unit.h"
DECLARE_SMART(Berserk, spBerserk)

class Berserk: public Unit
{
public:
    Berserk(Vector2 position, Vector2 velocity = Vector2(0,0), int team = 0);
};

#endif // BERSERK_H
