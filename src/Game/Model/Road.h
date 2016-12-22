#ifndef ROAD_H
#define ROAD_H
#include "oxygine-framework.h"

using namespace oxygine;
using namespace std;
struct Cell
{
    Vector2 position;
    spClipRectActor img;
};

class Road
{
public:
    vector<Cell> cells;
    Road();
};

#endif // ROAD_H
