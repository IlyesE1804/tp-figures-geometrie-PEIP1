#include "../include/shapes/circle.hpp"
#include "../include/shapes/square.hpp"
#include "../include/shapes/triangle.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

//Commande pour créer un executable test.exe :
//g++ -std=c++23 -Iinclude -o tests_square ../src/draw.cpp ../src/point.cpp ../src/shapes/circle.cpp ../src/shapes/square.cpp ../src/shapes/triangle.cpp tests_square.cpp -lgdi32 -luser32


void test_perimeter() {
    Triangle t({0, 0}, {3, 0}, {0, 4}); 
    assert(t.perimeter() == 12);
    cout << "test_perimeter passed\n";
}

void test_area() {
    Triangle t({0, 0}, {3, 0}, {0, 4});
    assert(t.area() == 6);
    cout << "test_area passed\n";
}

void test_center() {
    Triangle t({0, 0}, {3, 0}, {0, 3});
    Point c = t.center();
    assert(c.x == 1);
    assert(c.y == 1);
    cout << "test_center passed\n";
}

void test_draw() {
    Triangle t({0, 0}, {100, 0}, {50, 100});
    cout << "Test visuel : un triangle devrait s'afficher\n";
    t.draw();
}

void test_translate() {
    Triangle t({0, 0}, {2, 0}, {0, 2});
    t.translate({1, 1});
    assert(t.A.x == 1 && t.A.y == 1);
    assert(t.B.x == 3 && t.B.y == 1);
    assert(t.C.x == 1 && t.C.y == 3);
    cout << "test_translate passed\n";
}

void test_resize() {
    Triangle t({0, 0}, {2, 0}, {0, 2});
    t.resize(2); 
    Point c = t.center(); 
    assert(t.A.x == -2.0/3 && t.A.y == -2.0/3);
    assert(t.B.x == 10.0/3 && t.B.y == -2.0/3);
    assert(t.C.x == -2.0/3 && t.C.y == 10.0/3);
    cout << "test_resize passed\n";
}

void test_rotate() {
    // Triangle initial
    Triangle t({0, 0}, {1, 0}, {0, 1});

    // Rotation de 90° dans le sens antihoraire
    t.rotate(90);

    assert(t.A.x == 1.0 / 3 && t.A.y == 4.0 / 3);
    assert(t.B.x == -2.0 / 3 && t.B.y == 1.0 / 3);
    assert(t.C.x == 1.0 / 3 && t.C.y == -2.0 / 3);

    cout << "test_rotate passed\n";
}

int main() {
    test_perimeter();
    test_area();
    test_center();
    test_draw();
    test_translate();
    test_resize();
    test_rotate();

    cout << "\nTous les tests du triangle sont passés.\n";
    return 0;
}


