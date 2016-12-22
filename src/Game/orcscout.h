#ifndef ORCSCOUT_H
#define ORCSCOUT_H

#include "Unit.h"
DECLARE_SMART(OrcScout, spOrcScout)

class OrcScout: public Unit
{
public:
    OrcScout(Vector2 position, Vector2 velocity = Vector2(0,0), int team = 0);
};

#endif // ORCSCOUT_H
