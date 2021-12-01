#ifndef __MAIN__H__
#define __MAIN__H__
#define INF 2147483647
#include "Fixed.hpp"
#include "Point.hpp"

Fixed get_gradient(Point const a, Point const b);
int	orientation(Point const a, Point const b, Point const c);
bool bsp( Point const a, Point const b, Point const c, Point const point);
bool is_intersect(Point const p1, Point const p2, Point const q1, Point const q2);
void	test(Point const a);
#endif  //!__MAIN__H__