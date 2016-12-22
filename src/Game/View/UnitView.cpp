#include "UnitView.h"
#include "../../ViewHelper.h"
UnitView::UnitView(Vector2 _position, string image, int current_hp, string icon_image, int attack_speed) :
    position(_position),
    isnextAnim(true),
    attackspeed(attack_speed)
{
    _hold = ViewHelper::res.getResAnim(image, ep_show_warning);
    delayhold = 1000;
    _move = ViewHelper::res.getResAnim(image, ep_show_warning);
    delaymove = 1000;
    _attack = ViewHelper::res.getResAnim(image, ep_show_warning);
    delayattack = 1000 - (attackspeed - 1)*10;

    setPosition(position);
    setAnchor(0.5,1);
    setScaleX(-1);
    setSize(_hold->getSize());

    viewHp = new ColorRectSprite();
    viewHp->setColor(Color(0xFFAABB));
    viewHp->setSize(_hold->getWidth(), 5);
    viewHp->setAnchorX(0.5);
    viewHp->setX(_hold->getWidth()/2);
    addChild(viewHp);

    icon = new Sprite();
    icon->setResAnim(ViewHelper::res.getResAnim(icon_image, ep_show_warning));

}

spSprite UnitView::getIcon()
{
    return icon;
}

void UnitView::turnAround()
{
    setScaleX(- getScaleX());
}

void UnitView::setAttack(string img)
{
    _attack = ViewHelper::res.getResAnim(img, ep_show_warning);

}

void UnitView::setHold(string img)
{
    _hold = ViewHelper::res.getResAnim(img, ep_show_warning);

}

void UnitView::setMove(string img)
{
    _move = ViewHelper::res.getResAnim(img, ep_show_warning);
}


UnitView::~UnitView()
{

}

void UnitView::showCurrentHp(int currentHp, int maxHp)
{
    viewHp->setSize( _hold->getWidth()*( (double)currentHp/ (double)maxHp), 5);
}


UnitState UnitView::startAnim(UnitState unitstate)
{
    if (!isnextAnim)
        return UnitState::HOLD;
    ResAnim* action;
    int delay = 1000;
    switch (unitstate)
    {
    case UnitState::HOLD:
        action = _hold;
        delay = delayhold;
        break;
    case UnitState::ATTACK:
        action = _attack;
        delay = delayattack;
        break;
    case UnitState::MOVE:
        action = _move;
        delay = delaymove;
        break;
    default:
        action = _hold;
        break;
    }
    isnextAnim = false;
    addTween(TweenAnim(action), delay)->addDoneCallback(
                [this](Event *e) {isnextAnim = true;});
    return unitstate;
}
