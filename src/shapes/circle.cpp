#include "../../include\point.hpp"
#include "../../include/shapes/circle.hpp"
#include "../../include/CTurtle.hpp"
#include "../../include/draw.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;
#include <vector>
#include <stdexcept>  // pour std::invalid_argument




Circle::Circle(double r, Point c) : radius(r), center(c) {
    if (r < 0){
        throw std::invalid_argument("Le rayon ne peut pas être négatif.");
    }
};

double Circle::circumference()
{
    double circumf = 2*M_PI * radius ;
    return circumf;

}

double Circle::area()
{
    double aire = M_PI * pow(radius,2);
    return aire;
}
void Circle::draw() {
    const int num_points = 10000;
    vector<Point> points;

    for (int i = 0; i < num_points; ++i) {
        double angle = 2 * M_PI * i / num_points;
        int x = static_cast<int>(center.x + radius * cos(angle));
        int y = static_cast<int>(center.y + radius * sin(angle));
        points.push_back(Point(x, y));
    }

    draw_picture(points);
}

void Circle::translate(Point T) 
{
    center.x += T.x;
    center.y += T.y;
}

void Circle::resize(double ratio) 
{
    if (ratio <= 0)
        {cout << "Valeur du ratio invalide ! (val <= 0)" << endl;}
    else{
        radius *= ratio;
    }
}

bool Circle::equals(Circle circle) 
{
    return (radius == circle.radius && center.x == circle.center.x   && center.y == circle.center.y );
}

