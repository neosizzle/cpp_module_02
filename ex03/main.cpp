#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "main.hpp"

int main( void ) {
	Point point1(1, 1);
	Point point2(5, 5);
	Point point3(10, 2);

	point2 = point1;

	std::cout << point1.getY() << "\n";
	std::cout << point1.getX() << "\n";
	std::cout << point2.getY() << "\n";
	std::cout << point2.getX() << "\n";
	// test(point1);
	//std::cout << get_gradient(point1, point2) << "\n";
	return 0;
}
