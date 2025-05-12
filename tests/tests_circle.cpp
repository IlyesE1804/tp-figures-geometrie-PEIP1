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
//g++ -std=c++23 -Iinclude -o tests_circle ../src/draw.cpp ../src/point.cpp ../src/shapes/circle.cpp ../src/shapes/square.cpp ../src/shapes/triangle.cpp tests_circle.cpp -lgdi32 -luser32


int main() {
    // Test Cercle

       // Cas simples
    Circle c(5.0, Point(0, 0));

    assert(c.circumference() == 2 * M_PI * c.radius);
    assert(c.area() == M_PI * pow(c.radius,2));

    c.draw();

    c.translate(Point(2, 3));
    assert(c.center.x == 2 && c.center.y == 3);

    c.resize(2);
    assert(c.center.x == 2 && c.center.y == 3);

    Circle c2(5.0, Point(0,0));
    Circle c3(10.0, Point(2,3));

    assert(c.equals(c2)==false);
    assert(c.equals(c3)==true);

    cout << "Tous les tests simples du cercle ont réussi avec succès. " << std::endl;


        //Cas limites !!!!!!

    Circle c0(0.0, Point(0,0));
    assert(c0.circumference()==0);
    assert(c0.area()==0);

    Circle cnegative_center(5.0, Point(-100,-100));
    assert(cnegative_center.center.x == -100);
    assert(cnegative_center.center.y == -100);

    Circle c4(5.0, Point(1,1));
    Circle c5(10.0, Point(1,1));
    c4.translate(Point(0, 0));
    assert(c4.center.x == 1 && c4.center.y == 1);
    assert(c4.equals(c5)==false);

    Circle c6(10.0, Point(1,1));
    //c5.resize(0); //ne doit pas resize car val <= 0
    //c5.resize(-10); //ne doit pas resize car val <= 0
    assert(c5.equals(c6)==true);

    //Circle crayon_negatif(-5, Point(1,1));

    cout << "Tous les tests limites du cercle ont réussi avec succès. " << std::endl;


    
    return 0;
}
