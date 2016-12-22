#include "Berserk.h"

Berserk::Berserk(Vector2 position, Vector2 velocity, int team)
    : Unit(position,"Berserk_move", 40, velocity, team, 5, Color::Black, "Berserk_Icon")
{
    isBlock = true;
    if (velocity.x < 0)
        view->setScaleX(1);
    view->setAttack("Berserk_attack");
}

