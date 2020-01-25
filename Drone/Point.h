#include "Arduino.h"

#ifndef CLASS_POINT
#define CLASS_POINT

class Point
{
private:
    int _x, _y;

public:
    Point(int x = 0, int y = 0);

    int getX();
    int getY();

    void setX(int x);
    void setY(int y);
};

#endif
