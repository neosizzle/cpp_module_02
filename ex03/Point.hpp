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

	Fixed getX() const;
	Fixed getY() const;
	void setX(float num) const;
	void setY(float num) const;
};

std::ostream& operator<< (std::ostream& os, const Point &point);

#endif  //!__POINT__H__