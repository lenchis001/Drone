#include "Arduino.h"

#ifndef CLASS_POINT
#define CLASS_POINT

class Point
{
private:
    float _x, _y;

public:
    Point(float x = 0, float y = 0);

    float getX();
    float getY();

    void setX(float x);
    void setY(float y);
};

#endif
