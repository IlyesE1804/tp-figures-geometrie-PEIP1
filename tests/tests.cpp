#include "../include/shapes/circle.hpp"
#include "../include/shapes/square.hpp"
#include "../include/shapes/triangle.hpp"
#include <iostream>
#include <cassert>

int main() {
    // Test Cercle
    Circle c(5.0, Point(0, 0));
    assert(c.area() == M_PI * 25);
    c.translate(Point(2, 3));
    assert(c.center.x == 2 && c.center.y == 3);

    std::cout << "Tous les tests ont réussi avec succès. " << std::endl;
    return 0;
}
