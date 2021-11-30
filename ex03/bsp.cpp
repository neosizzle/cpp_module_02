#include "Point.hpp"
#include "Fixed.hpp"
#include "main.hpp"

/*
** Helper function to get gradient between two points
*/
Fixed get_gradient(Point const a, Point const b)
{
	std::cout << b.getY() << "\n";
	std::cout << a.getY() << "\n";
	std::cout << b.getX() << "\n";
	std::cout << a.getX() << "\n";
	return ((b.getY() - a.getY()) / (b.getX() - a.getX()));
}

void	test(Point const a)
{
	std::cout << a._x << "\n";
	std::cout << a._y << "\n";
}

/*
** Helper function to determine orientation between 3 points (a->b->c)
0 is collienar, 1 is clockwise and 2 is counter-clockwise
*/
int	orientation(Point const a, Point const b, Point const c)
{
	Fixed mAB;
	Fixed mBC;

	mAB = get_gradient(a, b);
	mBC = get_gradient(b, c);
	if (mAB - mBC > 0)
		return 1;
	else if (mAB - mBC < 0)
		return 2;
	return 0;
}

// bool is_intersect(Point const p1, Point const p2, Point const q1, Point const q2)
// {
// 	return false;
// }

// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
// 	return false;
// }