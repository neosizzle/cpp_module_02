#ifndef __POINT__H__
#define __POINT__H__
#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(float x, float y);
	~Point();
	Point(const Point &point);
	Point & operator = (const Point &point);

	Fixed getX();
	Fixed getY();
};

#endif  //!__POINT__H__