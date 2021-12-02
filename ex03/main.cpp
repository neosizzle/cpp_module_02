#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "main.hpp"

void print_points(Point const point1, Point const point2,Point const point3,Point const point4)
{
	std::cout << "bsp for " << point1 << " " << point2 << " " << point3 << " " << point4 << " : ";
}

int main( void ) {
	Point point1(0, 0);
	Point point2(7, 3);
	Point point3(2, -4);
	Point point4(2, 3);

	print_points(point1, point2, point3, point4);
	std::cout << bsp(point1, point2,point3,point4) << "\n";

	Point point5(0, 0);
	Point point6(7, 3);
	Point point7(2, -4);
	Point point8(2, -3);

	print_points(point5, point6, point7, point8);
	std::cout << bsp(point5, point6, point7, point8) << "\n";

	Point point_a(0, 0);
	Point point_b(0, 3);
	Point point_c(2, -4);
	Point point_d(0, 2);

	print_points(point_a, point_b, point_c, point_d);
	std::cout << bsp(point_a, point_b, point_c, point_d) << "\n";

	Point point_a1(0, 0);
	Point point_b2(6.9f, 3);
	Point point_c3(2.6f, -4.15f);
	Point point_d4(3.2f, 0);

	print_points(point_a1, point_b2, point_c3, point_d4);
	std::cout << bsp(point_a1, point_b2, point_c3, point_d4) << "\n";
	return 0;
}
