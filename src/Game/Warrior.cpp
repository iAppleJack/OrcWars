#include "Warrior.h"

Warrior::Warrior(Vector2 position, Vector2 velocity, int team)
    : Unit(position,"Huscarl_move", 25, velocity, team, 8, Color::Black, "Huscarl_Icon")
{
    isBlock = true;
    if (velocity.x < 0)
        view->setScaleX(1);
    view->setAttack("Huscarl_attack");
}

