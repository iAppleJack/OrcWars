#include "Unit.h"
#include "Tween.h"

Unit::Unit(Vector2 position, string img,  int hp,  Vector2 startVelocity, int team, int attack, Color unitcolor,string _icon, int attackSpeed):
    position(position),
    velocity(startVelocity),
    isBlock(false),
    currenthp(hp),
    maxhp(hp),
    attack_point(attack),
    team(team),
    attackSpeed(attackSpeed)
{
    view = new UnitView(position,img, hp, img, attackSpeed);
    if (team == 1)
        view->setColor(Color::Red);
    else
        view->setColor( Color::Blue);
    view->setColor(view->getColor() + unitcolor);
    view->addClickListener([this](Event *e)
    {
        UnitClickEvent ucl(UnitClickEvent::SHOWUNIT, this);
        dispatchEvent(&ucl);
    }
    );
}

Vector2 Unit::getSize()
{
    return view->getSize();
}

int Unit::getTeam()
{
    return team;
}

int Unit::getCurrentHp()
{
    return currenthp;
}

int Unit::getAttackPoint()
{
    return attack_point;
}

spSprite Unit::getIcon()
{
    return view->getIcon();
}

void Unit::die()
{
    view->setAnchorY(0.5);
    view->addTween(Actor::TweenRotation(MATH_PI*8), 2000)->setDetachActor(true);
}

Unit::~Unit()
{

}

void Unit::move()
{

    unitstate = UnitState::MOVE;
    unitstate = view->startAnim(unitstate);
    position += velocity;
    view->setPosition(getPosition());
}

void Unit::hold()
{
    unitstate = UnitState::HOLD;
    unitstate = view->startAnim(unitstate);
}

void Unit::hit(int power)
{
    currenthp -= power;
    updateHp();
}

void Unit::attack()
{
    unitstate = UnitState::ATTACK;
    unitstate = view->startAnim(unitstate);
}

void Unit::attachTo(spActor actor)
{
    actor->addChild(view);
}

void Unit::attachTo(Actor *actor)
{
    actor->addChild(view);
}

void Unit::updateHp()
{
    view->showCurrentHp(currenthp,maxhp);
}

void Unit::turnAround()
{
    velocity.x = -velocity.x;
}

Vector2 Unit::getPosition()
{
    return position;
}
