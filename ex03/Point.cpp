#include "Point.hpp"
#include "Fixed.hpp"

/*
** Methods
*/
Fixed Point::getX()
{
	return _x.toFloat();
}

Fixed Point::getY()
{
	return _y.toFloat();
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

Point::Point(const Point &point)
{
	*this = point;
}

Point& Point::operator = (const Point &point)
{
	if (this != point)
	{
		//do stuff
	}
	return *this;
}