#include "Point.hpp"
#include "Fixed.hpp"

/*
** Methods
*/
Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}

/*
** Constructors
*/
Point::Point() : _x(), _y()
{
	
}

Point::Point(float x, float y): _x(x), _y(y)
{
}

Point::~Point()
{

}

Point::Point(const Point &point): _x(point.getX()), _y(point.getY())
{

}

Point& Point::operator = (const Point &point)
{
	if (this != &point)
	{
		(void) point;
		std::cout << "No values to assign, const values are immutable\n";
	}
	return *this;
}

std::ostream& operator << (std::ostream& os, const Point &point)
{
	os << "(" << point.getX() << ", " << point.getY() << ")";
	return os;
}