#ifndef __UNIT_H
#define __UNIT_H
#include "View/UnitView.h"
#include "oxygine-framework.h"


DECLARE_SMART(Unit, spUnit)

enum class UnitId
{
    ID_Fortress = 1,
    ID_Warrior = 2,
    ID_Berserk = 3,
    ID_OrcScout = 4
};

class UnitClickEvent : public Event
{
public:
    enum
    {
        SHOWUNIT = eventID('s', 'h', 'o', 'w'),
        CREATEUNIT = eventID('c', 'r', 'e', 'e')
    };

    spUnit unit;

    UnitClickEvent(eventType type,  spUnit unit) :
        Event(type, true),
        unit(unit)
    {}
};


class Unit : public oxygine::EventDispatcher
{
public:
    Unit(Vector2 position, string img, int hp, Vector2 startVelocity = Vector2(0,0), int team = 0, int attack_point = 0, Color unitcolor = Color::Black, string _icon = "Huscarl_Icon", int attack_speed = 1);
    ~Unit();
    bool isBlock;
    Vector2 getPosition();
    Vector2 setVelosity();
    void turnAround();
    virtual void move();
    virtual void attack();
    virtual void hold();
    void hit(int power);
    void updateHp();
    void attachTo(Actor *actor);
    void attachTo(spActor actor);
    Vector2 getSize();
    int getTeam();
    int getCurrentHp();
    int getAttackPoint();
    void die();
    int maxhp;
    int currenthp;
    UnitState unitstate;
    spSprite getIcon();
    vector<UnitId> factory;
protected:
    spUnitView  view;
private:
    Vector2 position;
    Vector2 velocity;
    Vector2 size;
    int attackSpeed;

    int attack_point;
    int team;
};
#endif
