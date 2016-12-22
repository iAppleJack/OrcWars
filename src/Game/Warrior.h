#ifndef WARRIOR_H
#define WARRIOR_H
#include "Unit.h"
DECLARE_SMART(Warrior, spWarrior)

class Warrior: public Unit
{
public:
    Warrior(Vector2 position, Vector2 velocity = Vector2(0,0), int team = 0);
};

#endif // WARRIOR_H
