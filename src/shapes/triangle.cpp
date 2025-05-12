#include "../../include/point.hpp"
#include "../../include/shapes/triangle.hpp"
#include "../../include/CTurtle.hpp"
#include "../../include/draw.hpp"
#include <cmath>
#include <vector>
using namespace std;

Triangle::Triangle(Point P, Point Q, Point R) : A(P), B(Q), C(R) {}

double Triangle::perimeter() {
    double AB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    double BC = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
    double CA = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));
    return AB + BC + CA;
}

double Triangle::area() {
    // Formule de Héron
    double AB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    double BC = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
    double CA = sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2));
    double s = (AB + BC + CA) / 2;
    return sqrt(s * (s - AB) * (s - BC) * (s - CA));
}

Point Triangle::center() {
    return Point{
        (A.x + B.x + C.x) / 3,
        (A.y + B.y + C.y) / 3
    };
}

void Triangle::draw() {
    
}

void Triangle::translate(Point T) {
    A.x += T.x; A.y += T.y;
    B.x += T.x; B.y += T.y;
    C.x += T.x; C.y += T.y;
}

void Triangle::resize(double ratio) {
    Point centre = center();

    A.x = centre.x + (A.x - centre.x) * ratio;
    A.y = centre.y + (A.y - centre.y) * ratio;

    B.x = centre.x + (B.x - centre.x) * ratio;
    B.y = centre.y + (B.y - centre.y) * ratio;

    C.x = centre.x + (C.x - centre.x) * ratio;
    C.y = centre.y + (C.y - centre.y) * ratio;
}

void Triangle::rotate(double angle) {
    
    };

