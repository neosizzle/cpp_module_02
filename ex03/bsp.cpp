#include "Point.hpp"
#include "Fixed.hpp"
#include "main.hpp"

/*
** Helper function to get gradient between two points
*/
Fixed get_gradient(Point const a, Point const b)
{
	//gradient wont work, need cross vector
	//https://stackoverflow.com/questions/17592800/how-to-find-the-orientation-of-three-points-in-a-two-dimensional-space-given-coo
	std::cout << "a " << a << " b " << b << "\n";
	std::cout << b.getY() - a.getY() << "\n";
	std::cout << b.getX() - a.getX() << "\n";
	std::cout << "grad : " <<  (b.getY() - a.getY()) / (b.getX() - a.getX()) << "\n";
	return ((b.getY() - a.getY()) / (b.getX() - a.getX()));
}

void	test(Point const a)
{
	std::cout << a.getX() << "\n";
	std::cout << a.getY() << "\n";
}

/*
** Helper function to determine orientation between 3 points (a->b->c)
** 0 is collienar, 1 is clockwise and 2 is counter-clockwise
*/
int	orientation(Point const a, Point const b, Point const c)
{
	Fixed mAB;
	Fixed mBC;

	mAB = get_gradient(a, b);
	mBC = get_gradient(b, c);
	std::cout << "mab : " << mAB << "\n";
	std::cout << "mbc : " << mBC << "\n";
	if (mAB > mBC)
		return 1;
	else if (mAB < mBC)
		return 2;
	return 0;

// 	Fixed res;
// 	res = (b.getY() - a.getY()) * (c.getX() - b.getX()) - (b.getX() - a.getX()) * (c.getY() - b.getY());
// 	if (res > 0) 
// 		return 1;
// 	else if (res < 0)
// 		return 2;
// 	return 0;
}

/*
** Determines if line p1p2 and q1q2 intersect
*/
bool is_intersect(Point const p1, Point const p2, Point const q1, Point const q2)
{
	int	ori1;
	int	ori2;
	int ori3;
	int	ori4;

	ori1 = orientation(p1, p2, q1);
	ori2 = orientation(p1, p2, q2);
	ori3 = orientation(q1, q2, p1);
	ori4 = orientation(q1, q2, p2);

	std::cout << "oris : "<< ori1 << ori2 << ori3 << ori4 << "\n";
	if (ori1 != ori2 && ori3 != ori4)
		return true;
	return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	int	indexes;
	int	i;
	int	next;
	int	intersectCount;
	Point const points[3] = {a, b, c};

	indexes = 3;
	i = 0;
	intersectCount = 0;
	Point ray(float(100), point.getY().toFloat());
	do
	{
		next = (i + 1) % indexes;
		//std::cout << "is inter: "<< is_intersect(points[i], points[next], point, ray) << "\n";
		if (is_intersect(points[i], points[next], point, ray))
			++intersectCount;
		i = next;
	} while (i != 0);
	std::cout << "Inter count : "<< intersectCount << "\n";
	return (intersectCount % 2 == 1);
}