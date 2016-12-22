#include "BuildMenuConstructor.h"
#include "UnitFactory.h"
#include "../ViewHelper.h"
BuildMenuConstructor::BuildMenuConstructor(Vector2 position)
{
    setPosition(position);
    background = new Sprite();
    background->setResAnim(ViewHelper::res.getResAnim("Menu"));
    this->addChild(background);
    info = new Actor();
    background->addChild(info);
}

void BuildMenuConstructor::showUnit(spUnit u)
{
    currentUnit = u;
    info->detach();
    info = new Actor();
    background->addChild(info);




    makeInfo();
    makeFactory();

}

void BuildMenuConstructor::makeInfo()
{
    spSprite icon (currentUnit->getIcon());
    icon->setPosition(65,60);
    scale(Vector2(100,100), icon);
    info->addChild(icon);

    spTextField hp = new TextField();
    hp->setText("hp : " + to_string(currentUnit->getCurrentHp()));
    hp->setFontSize(14);
    hp->setPosition(200,85);
    info->addChild(hp);

    spTextField team = new TextField();
    team->setText("team : " + to_string(currentUnit->getTeam()));
    team->setFontSize(14);
    team->setPosition(200,105);
    info->addChild(team);


    if (currentUnit->getAttackPoint() > 0)
    {
        spTextField attack = new TextField();
        attack->setPosition(200,130);
        attack->setFontSize(14);
        attack->setText("attack : " + to_string(currentUnit->getAttackPoint()));
        info->addChild(attack);
    }
}

void BuildMenuConstructor::makeFactory()
{
    for (size_t i = 0; i < currentUnit->factory.size(); i++)
    {
        spUnit factoryUnit = UnitFactory::createUnit(currentUnit->factory[i], currentUnit->getPosition(), currentUnit->getTeam());
        scale(Vector2(45,45),factoryUnit->getIcon());
        factoryUnit->getIcon()->setPosition(Vector2(370 + i*50, 100));
        factoryUnit->getIcon()->setAnchor(0.5,0.5);
        UnitId idUnit = currentUnit->factory[i];
        factoryUnit->getIcon()->addClickListener([this, idUnit, factoryUnit](Event* e)
        {
            factoryUnit->getIcon()->addTween(TweenScale(1.3),500,1,true);
            spUnit newUnit = UnitFactory::createUnit(idUnit, this->currentUnit->getPosition(), this->currentUnit->getTeam());
            UnitClickEvent ucl(UnitClickEvent::CREATEUNIT, newUnit);
            dispatchEvent(&ucl);
        });

        info->addChild(factoryUnit->getIcon());
    }
}

void BuildMenuConstructor::scale(Vector2 size, spSprite sprite)
{
    sprite->setScale(size.x/sprite->getSize().x , size.y/sprite->getSize().y);
}

