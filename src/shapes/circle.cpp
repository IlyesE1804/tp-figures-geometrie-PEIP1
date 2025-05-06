#include "../../include\point.hpp"
#include "../../include/shapes/circle.hpp"
#include "../../include/CTurtle.hpp"
#include "../../include/draw.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
using namespace std;
#include <vector>



Circle::Circle(double r, Point c) : radius(r), center(c) {};

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
    std::vector<Point> points;

    for (int x = -radius; x <= radius; ++x) {
        for (int y = -radius; y <= radius; ++y) {
            int dx = x;
            int dy = y;
            int d2 = dx*dx + dy*dy;
            int r2 = radius * radius;
            
            if (d2 >= 0.95 * r2 && d2 <= 1.05 * r2) {
                points.push_back(Point(center.x + dx, center.y + dy));
            }
        }
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
    radius *= ratio;
}

bool Circle::equals(Circle circle) 
{
    return (radius == circle.radius && center.x == circle.center.x   && center.y == circle.center.y );
}

