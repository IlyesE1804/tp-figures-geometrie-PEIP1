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


void test_side() {
    Square s({0, 0}, {10, 10});
    assert(s.side() == 10);
    cout << "test_side passed\n";
}

void test_perimeter() {
    Square s({0, 0}, {5, 5});
    assert(s.perimeter() == 20);
    cout << "test_perimeter passed\n";
}

void test_area() {
    Square s({0, 0}, {4, 4});
    assert(s.area() == 16);
    cout << "test_area passed\n";
}

void test_center() {
    Square s({2, 2}, {6, 6});
    Point center = s.center();
    assert(center.x == 4);
    assert(center.y == 4);
    cout << "test_center passed\n";
}

void test_draw() {
    Square s({0, 0}, {100, 100});
    cout << "Test visuel : un carré devrait s'afficher\n";
    s.draw();
}

void test_translate() {
    Square s({0, 0}, {10, 10});

    s.translate({5, -3});

    // Vérification des nouveaux coins
    assert(s.A.x == 5 && s.A.y == -3);  // Nouveau A
    assert(s.C.x == 15 && s.C.y == 7);  // Nouveau C

    cout << "test_translate passed\n";
}


void test_resize() {
    Square s({0, 0}, {10, 10});

    s.resize(2.0);

    // Vérification des nouveaux coins
    assert(s.A.x == -5 && s.A.y == -5);  // Nouveau A
    assert(s.C.x == 15 && s.C.y == 15);  // Nouveau C

    cout << "test_resize passed\n";
}

void test_rotate() {
    Square s({0, 0}, {10, 10});

    s.rotate(90);

    // Vérification des nouveaux coins (après une rotation de 90°)
    assert(s.A.x == 10 && s.A.y == 0);  // Nouveau A
    assert(s.C.x == 0 && s.C.y == 10);  // Nouveau C

    cout << "test_rotate passed\n";
}


void test_inscribedCircle() {
    Square s({0, 0}, {10, 10});
    Circle c = s.inscribedCircle();

    assert(c.center.x == 5);
    assert(c.center.y == 5);
    
    assert(c.radius == 5);

    cout << "test_inscribedCircle passed\n";
}

void test_circumscribedCircle() {
    Square s({0, 0}, {10, 10});
    Circle c = s.circumscribedCircle();

    assert(c.center.x == 5);
    assert(c.center.y == 5);

    double expected_radius = sqrt(100 * 2) / 2;  // sqrt(200)/2
    assert(c.radius == expected_radius);

    cout << "test_circumscribedCircle passed\n";
}



int main() {
    test_side();
    test_perimeter();
    test_area();
    test_center();
    test_draw();
    test_translate();
    test_resize();
    test_rotate();
    //test_equals a faire en fonction de ce qu'aura dit le prof...
    test_inscribedCircle();
    test_circumscribedCircle();

    std::cout << "\n Tous les tests du carré sont passés.\n";
    return 0;
}


