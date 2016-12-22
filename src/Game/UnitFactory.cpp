#include "UnitFactory.h"

spUnit UnitFactory::createUnit(UnitId id, Vector2 pos, int team)
{
    spUnit u;
    switch (id)
    {
        case UnitId::ID_Fortress:
            u = new Fortress(pos, team);
            break;
        case UnitId::ID_Warrior:
            u = new Warrior(pos, team == 1 ? Vector2(1,0) : Vector2(-1,0), team);
            break;
        case UnitId::ID_Berserk:
            u = new Berserk(pos, team == 1 ? Vector2(1,0) : Vector2(-1,0), team);
            break;
        case UnitId::ID_OrcScout:
            u = new OrcScout(pos, team == 1 ? Vector2(1,0) : Vector2(-1,0), team);
            break;
        default:
            assert( false);
    }
    return u;
}


