#include "Point.h"

Point::Point(float x, float y)
{
    _x = x;
    _y = y;
}

float Point::getX()
{
    return _x;
}

float Point::getY()
{
    return _y;
}

void Point::setX(float x)
{
    _x = x;
}

void Point::setY(float y)
{
    _y = y;
}
