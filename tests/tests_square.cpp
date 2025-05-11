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


void test_side() {
    Square s({0, 0}, {10, 10});
    assert(s.side() == 10);
    std::cout << "test_side passed\n";
}

void test_perimeter() {
    Square s({0, 0}, {5, 5});
    assert(s.perimeter() == 20);
    std::cout << "test_perimeter passed\n";
}

void test_area() {
    Square s({0, 0}, {4, 4});
    assert(s.area() == 16);
    std::cout << "test_area passed\n";
}

void test_center() {
    Square s({2, 2}, {6, 6});
    Point center = s.center();
    assert(center.x == 4);
    assert(center.y == 4);
    std::cout << "test_center passed\n";
}

void test_draw() {
    Square s({0, 0}, {100, 100});
    std::cout << "Test visuel : un carré devrait s'afficher\n";
    s.draw();
}

void test_translate() {
    Square s({0, 0}, {10, 10});

    s.translate({5, -3});

    // Vérification des nouveaux coins
    assert(s.A.x == 5 && s.A.y == -3);  // Nouveau A
    assert(s.C.x == 15 && s.C.y == 7);  // Nouveau C

    std::cout << "test_translate passed\n";
}


void test_resize() {
    Square s({0, 0}, {10, 10});

    s.resize(2.0);

    // Vérification des nouveaux coins
    assert(s.A.x == -5 && s.A.y == -5);  // Nouveau A
    assert(s.C.x == 15 && s.C.y == 15);  // Nouveau C

    std::cout << "test_resize passed\n";
}


int main() {
    test_side();
    test_perimeter();
    test_area();
    test_center();
    test_draw();
    test_translate();
    test_resize();

    std::cout << "\n Tous les tests du carré sont passés.\n";
    return 0;
}

