#include "point.hpp"
#include "shapes/square.hpp"
using namespace std;
#include <cmath>


Square::Square(Point P, Point R) : A(P), C(R) {};

double Square::side()
{
    double hypothenuse = sqrt(pow(C.x - A.x,2) + pow(C.y - A.y,2));
    double hypothenuse_square = pow(hypothenuse, 2);
    double side = sqrt(hypothenuse_square / 2);
    return side;
}

