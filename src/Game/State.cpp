#include "State.h"
#include "DebugActor.h"
#include "../ViewHelper.h"


void GameState::makeBack(int width)
{
    int currentWidth = 0;
    while (currentWidth < width)
    {
        spSprite part = new Sprite();
        part->setResAnim(ViewHelper::res.getResAnim("ground"));
        part->setPosition(currentWidth,0);
        ground.push_back(part);
        currentWidth+= 640;
        this->addChild(part);
    }

    gamemenu = new BuildMenuConstructor(Vector2(0,480));
    addChild(gamemenu);

}

GameState::GameState()
{
    addEventListener(UnitClickEvent::CREATEUNIT, [this](Event *e)
    {
        UnitClickEvent* ucEvent = dynamic_cast<UnitClickEvent*>(e);
        spUnit unit = ucEvent->unit;
        units.push_back(unit);
        unit->attachTo(this);
        unit->addEventListener(UnitClickEvent::SHOWUNIT, [this, unit](Event *e)
        {
            gamemenu->showUnit(unit);
        });

    });

    makeBack(1600);
    spFortress f1 = safeSpCast<Fortress> (UnitFactory::createUnit(UnitId::ID_Fortress, Vector2(  200,390), 1));
    spFortress f2 = safeSpCast<Fortress> (UnitFactory::createUnit(UnitId::ID_Fortress, Vector2(700,390), 2));

    units.push_back(f1);
    units.push_back(f2);



   std::for_each(units.begin(), units.end(), [this](spUnit unit){
        unit->attachTo(this);
        unit->addEventListener(UnitClickEvent::SHOWUNIT, [this, unit](Event *e)
        {
            gamemenu->showUnit(unit);
        });
    });
}

GameState::~GameState()
{
    printf("Destroy Game State");
}

void GameState::update()
{
    step();
    attack();
    die();

}

void GameState::step()
{
    for (size_t i = 0; i < units.size(); i ++)
    {
        UnitState state = UnitState::MOVE;
        spUnit unit = units[i];

        for (size_t j = 0; j < units.size(); j++)
        {
            spUnit enemy = units[j];
            if (i != j && unit->getTeam() != enemy->getTeam() && unit->isBlock && enemy->isBlock &&
                 (unit->getPosition().x  )>= enemy->getPosition().x - enemy->getSize().x/2 &&
                    unit->getPosition().x <= enemy->getPosition().x + enemy->getSize().x/2)
            {
                DebugActor::instance->addDebugString("i j k  %d %d", i, j);

                state = UnitState::ATTACK;
                break;
            }
        }

        switch (state) {
        case UnitState::MOVE:
            unit->move();
            break;
        case UnitState::ATTACK:
            unit->attack();
            break;
        case UnitState::HOLD:
            unit->hold();
            break;
        default:
            break;
        }
        unit->updateHp();
    }
}

void GameState::attack()
{
    for (size_t i = 0; i < units.size(); i ++)
    {
        spUnit unit = units[i];
        for (size_t j = 0; j < units.size(); j++)
        {
            spUnit enemy = units[j];
            if (unit->unitstate  == UnitState::ATTACK && i != j && unit->getTeam() != enemy->getTeam() && unit->isBlock &&
                 (unit->getPosition().x  )>= enemy->getPosition().x - enemy->getSize().x/2 &&
                    unit->getPosition().x <= enemy->getPosition().x + enemy->getSize().x/2 && unit->getTeam() != enemy->getTeam())
            {
                enemy->hit(unit->getAttackPoint());
                DebugActor::instance->addDebugString("i hp max  %d %d", enemy->currenthp, enemy->maxhp);
                break;
            }
        }
    }
}



void GameState::die()
{
    for (size_t i = 0; i < units.size(); i ++)
    {
        spUnit unit = units[i];
        if (unit->getCurrentHp() <= 0)
        {
            unit->removeAllEventListeners();
            unit->die();
            units.erase(units.begin() + i);
            break;
        }
    }
}



void GameState::block_move()
{

}

