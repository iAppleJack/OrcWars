#ifndef ___BUILDMENUCONSTRUCTOR_H
#define ___BUILDMENUCONSTRUCTOR_H
#include "Unit.h"

DECLARE_SMART(BuildMenuConstructor, spBuildMenuConstructor)

using namespace std;
using namespace oxygine;



class BuildMenuConstructor : public Actor
{
public:
    BuildMenuConstructor( Vector2 position);
    void showUnit(spUnit u);
private:
    spSprite background;
    spActor info;
    spUnit currentUnit;

    void makeInfo();
    void makeFactory();

    void scale(Vector2 size, spSprite sprite);
};

#endif // BUILDMENUCONSTRUCTOR_H
