#ifndef FORTRESS_H
#define FORTRESS_H
#include "UnitFactory.h"
#include "Unit.h"

DECLARE_SMART(Fortress, spFortress)



class Fortress : public Unit
{
public:
    Fortress(Vector2 position, int team);
    void createUnit();
private:
    //spBuildMenuConstructor bmc;
};

#endif // FORTRESS_H
