#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__
#include "UnitFactory.h"
#include "BuildMenuConstructor.h"


using namespace std;
class GameState : public Actor
{
public:
    void makeBack(int Width);
    GameState();
    ~GameState();
    void update();
private:
    vector<spUnit> units;
    void step();
    void attack();
    void die();
    UnitState findOpponent(spUnit u);
    void block_move();
    std::vector<spSprite> ground;
    spBuildMenuConstructor gamemenu;
};

#endif
