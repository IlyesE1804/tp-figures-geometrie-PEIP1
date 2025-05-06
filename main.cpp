#include "draw.hpp"
#include "point.hpp"
#include "shapes.hpp"
#include <vector>
#include <iostream>
#include <cassert>
#define _USE_MATH_DEFINES
#include <cmath>



int main() {
	
	// Define points in a vector
	std::vector<Point> points = {
		Point(0, 0),
		Point(100, 0),
		Point(100, 100),
		Point(0, 100),
		Point(0, 0)
		
	};
	
	// Draw the picture by connecting the points
	draw_picture(points);

	Circle c(5.0, Point(0, 0));
    assert(c.area() == M_PI * 25);
    c.translate(Point(2, 3));
    assert(c.center.x == 2 && c.center.y == 3);

    std::cout << "Tous les tests ont réussi avec succès. " << std::endl;
     
	
	return 0;
}
