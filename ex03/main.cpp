#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "main.hpp"

int main( void ) {
	Point point1(0, 0);
	Point point2(4, 4);
	Point point3(5, 2);
	Point point4(4 ,0);

	std::cout << get_gradient(point1, point2) << "\n\n";
	std::cout << get_gradient(point2, point3) << "\n";
	return 0;
}
