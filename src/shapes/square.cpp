#include "../../include\point.hpp"
#include "../../include/shapes/square.hpp"
#include "../../include/CTurtle.hpp"
#include "../../include/draw.hpp"
using namespace std;
#include <cmath>
#include <vector>


Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side()
{
    double hypothenuse = sqrt(pow(C.x - A.x,2) + pow(C.y - A.y,2));
    double hypothenuse_square = pow(hypothenuse, 2);
    double side = sqrt(hypothenuse_square / 2);
    return side;
}

double Square::perimeter()
{
    double perimetre = side()*4;
    return perimetre;
}

double Square::area(){
	double area = side()*side();
	return area;
}

Point Square::center(){
    return Point{(A.x + C.y) / 2, (A.y + C.y) / 2};
}

void Square::draw(){
    // On va déduire les autres coins B et D
    
    Point B = {C.x, A.y}; // coin adjacent à A
    Point D = {A.x, C.y}; // autre coin adjacent à A

    // Construction du contour en ordre (A → B → C → D → A)
    vector<Point> points = {A, B, C, D, A};

    draw_picture(points);
}

void Square::translate(Point T)
{
    A.x += T.x;
    A.y += T.y;

    C.x += T.x;
    C.y += T.y;
}

void Square::resize(double ratio)
{
    Point centre = center();

    // On calcule le demi-vecteur de A à C
    double dx = (C.x - A.x) / 2.0;
    double dy = (C.y - A.y) / 2.0;

    // On applique le ratio aux demis-vecteurs
    dx *= ratio;
    dy *= ratio;

    // Nouveaux coins A et C
    A.x = centre.x - dx;
    A.y = centre.y - dy;

    C.x = centre.x + dx;
    C.y = centre.y + dy;
}

