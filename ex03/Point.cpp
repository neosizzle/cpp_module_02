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
	//*this = point;
}

Point& Point::operator = (const Point &point)
{
	// if (this != &point)
	// {
	// 	this->_x = point.getX();
	// }
	std::cout << point.getX() << "\n";
	(void)point;
	// Point* newPt= new Point(point);
	return Point(point);
}