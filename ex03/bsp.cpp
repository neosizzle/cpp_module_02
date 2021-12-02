#include "Point.hpp"
#include "Fixed.hpp"
#include "main.hpp"

//https://stackoverflow.com/questions/17592800/how-to-find-the-orientation-of-three-points-in-a-two-dimensional-space-given-coo
/*
** The coordinates can be represented by 2 vectors.
** The cross product of two vectors will compute the area of the parallelogram formed 
** By the two vectors.
** 
** However, the result of the computation if another vector, which is the vector
** perpendicular to the plane formed in the z-axis. If this vectors magnitutde is > 0,
** the angle of rotation is clockwise, vice versa for counter clockwise
**
** EXAMPLE EQUATION
** a(0,0) b (2, 1) c(0, 3)
** 
** a ->b = 2i + j; b->c = -2i + 2j
** 
** =>
** | i j k |
** | 2 1 0 |
** | -2 2 0|
** 
** => [(1 * 0) - (0 * 2)]i + [(2 * 0) - (-2 * 0)]j - [(2 * 2) - (-2 * 1)]k
** =>-6k
** => magnitude of vector is <0, ordered coords are counter - clockwise.
*/
Fixed get_cross_product(Point const a, Point const b, Point const c)
{
	Fixed ab_i;
	Fixed ab_j;
	Fixed bc_i;
	Fixed bc_j;
	Fixed vector;

	ab_i = b.getX() - a.getX();
	ab_j = b.getY() - a.getY();
	bc_i = c.getX() - b.getX();
	bc_j = c.getY() - b.getY();
	vector = Fixed(-1) * Fixed(((ab_i * bc_j) - (bc_i * ab_j)));
	return vector;
}

/*
** Helper function to determine orientation between 3 points (a->b->c)
** 0 is collienar, 1 is clockwise and 2 is counter-clockwise
*/
int	orientation(Point const a, Point const b, Point const c)
{
	Fixed res;
	res = get_cross_product(a, b, c);
	// std :: cout << res << "\n";
	// std :: cout << (b.getY() - a.getY()) * (c.getX() - b.getX()) - (b.getX() - a.getX()) * (c.getY() - b.getY()) << "\n";
	if (res > 0)
		return 1;
	else if (res < 0)
		return 2;
	return 0;
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

	// std::cout << "oris : "<< ori1 << ori2 << ori3 << ori4 << "\n";
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
	Point ray(float(INF), point.getY().toFloat());
	do
	{
		next = (i + 1) % indexes;
		//std::cout << "is inter: "<< is_intersect(points[i], points[next], point, ray) << "\n";
		if (is_intersect(points[i], points[next], point, ray))
			++intersectCount;
		i = next;
	} while (i != 0);
	// std::cout << "Inter count : "<< intersectCount << "\n";
	return (intersectCount % 2 == 1);
}