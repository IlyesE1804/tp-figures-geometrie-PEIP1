#include "../include/shapes/circle.hpp"
#include "../include/shapes/square.hpp"
#include "../include/shapes/triangle.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>

//Commande pour créer un executable test.exe :
//g++ -std=c++23 -Iinclude -o test ../src/draw.cpp ../src/point.cpp ../src/shapes/circle.cpp ../src/shapes/square.cpp ../src/shapes/triangle.cpp tests.cpp -lgdi32 -luser32


int main() {
    // Test Cercle
    Circle c(5.0, Point(0, 0));
    assert(c.area() == M_PI * 25);
    c.translate(Point(2, 3));
    assert(c.center.x == 2 && c.center.y == 3);

    std::cout << "Tous les tests ont réussi avec succès. " << std::endl;
    return 0;
}
