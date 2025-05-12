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
    vector<Point> points = {A, B, C, A}; 
    draw_picture(points);
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
    // Convertir l'angle en radians
    double radian = angle * M_PI / 180.0;

    Point centre = center();

    //On soustrait d'abord les coordonnées du centre à celles du coin A 
    //pour obtenir les coordonnées du point relatives au centre.
    double xA = A.x - centre.x;
    double yA = A.y - centre.y;

    // Appliquer la rotation au coin A sachant que l'on connait la matrice de rotation vu en cours
    // de maths qui est ( cos(teta), -sin(teta) )
    //                  ( sin(teta),  cos(teta) )

    A.x = xA * cos(radian) - yA * sin(radian) + centre.x;
    A.y = xA * sin(radian) + yA * cos(radian) + centre.y;

    
    // Appliquer la rotation au coin B...
    double xB = B.x - centre.x;
    double yB = B.y - centre.y;

    B.x = xB * cos(radian) - yB * sin(radian) + centre.x;
    B.y = xB * sin(radian) + yB * cos(radian) + centre.y;
    
    
    // Appliquer la rotation au coin C...
    double xC = C.x - centre.x;
    double yC = C.y - centre.y;

    C.x = xC * cos(radian) - yC * sin(radian) + centre.x;
    C.y = xC * sin(radian) + yC * cos(radian) + centre.y;

};

