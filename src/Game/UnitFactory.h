#ifndef UNITFACTORY_H
#define UNITFACTORY_H
#include "Unit.h"
#include "Fortress.h"
#include "Warrior.h"
#include "Berserk.h"
#include "orcscout.h"


class UnitFactory
{
public:
    static spUnit createUnit( UnitId id, Vector2 pos, int team);

};

#endif // UNITFACTORY_H
