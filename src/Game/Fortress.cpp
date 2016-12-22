#include "Fortress.h"

Fortress::Fortress(Vector2 position, int team ) : Unit(position,"Fortress", 250, Vector2(0,0), team)
{
    isBlock = false;
    factory = {UnitId::ID_Berserk, UnitId::ID_Warrior, UnitId::ID_OrcScout};
   // bmc = new BuildMenuConstructor({UnitId::ID_Berserk, UnitId::ID_Warrior, UnitId::ID_Berserk}, team, view->getSize(), getPosition());
   // bmc->setPosition(0, - 200);
   // bmc->addEventListener(FortressEvent::CREATEUNIT, [this](Event *e){
   //     dispatchEvent(e);
   // });
   // view->addClickListener([this](Event *e) {
   //     this->bmc->addTween(Actor::TweenY( this->bmc->getY() == 0 ? -200 : 0 ), 2000);
   // });
   // view->addChild(bmc);
}

void Fortress::createUnit()
{
    spUnit u = UnitFactory::createUnit((rand()%2 ? UnitId::ID_Warrior : UnitId::ID_Berserk), getPosition(), getTeam());
    //FortressEvent ev(FortressEvent::CREATEUNIT, u);
    //dispatchEvent(&ev);
}

