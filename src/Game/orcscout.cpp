#include "orcscout.h"

OrcScout::OrcScout(Vector2 position, Vector2 velocity, int team)
    : Unit(position,"OrcWarrior_Move", 30, velocity, team, 6, Color::Black, "OrcWarrior_Move",10)
{
    isBlock = true;
    if (velocity.x < 0)
        view->setScaleX(1);
    view->setAttack("OrcWarrior_Attack");
}

