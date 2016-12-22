#include "oxygine-framework.h"

#ifndef __UNIT_VIEW_H__
#define __UNIT_VIEW_H__
using namespace oxygine;
DECLARE_SMART(UnitView, spUnitView)
using namespace std;

enum class UnitState
{
    HOLD = 1,
    ATTACK = 2,
    MOVE = 3
};

class UnitView : public Sprite
{
public:

    spColorRectSprite viewHp;
    UnitView(Vector2 _position, string image, int current_hp, string _icon_image, int attack_speed = 1);
    ~UnitView();
    void showCurrentHp(int currentHp, int maxHp);
    void turnAround();

    void setMove(string move);
    void setAttack(string attack);
    void setHold(string hold);
    UnitState startAnim(UnitState unitstate);
    bool isFinishAttackAnim;
    spSprite getIcon();
private:
    ResAnim* _move;
    int delaymove;
    ResAnim* _attack;
    int delayattack;
    ResAnim* _hold;
    int delayhold;
    Vector2 position;
    spSprite icon;
    bool isnextAnim;
    int attackspeed;

};
#endif
