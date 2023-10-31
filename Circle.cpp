/**
 * Circle.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Dylan Robles, Savannah Brown
 * dtrobles, savvyy
 *
 * The Circle.cpp file for the Cool Pictures project.
 */

#include "Circle.h"
#include "Line.h"
#include "Graphics.h"
#include "utility.h"
#include <algorithm>
using namespace std;


// Default constructor
Circle::Circle() {
    Point pt1;
    Color color1;

    center = pt1;
    radius = 0;
    color = color1;

}

// Overloaded constructor. Sets center, radius, and single color.
Circle::Circle(Point pt, int r, Color c) {
    center = pt;
    radius = checkRadius(r);
    color = c;
}

void Circle::setCenter(Point pt) {
    center = pt;
}

Point Circle::getCenter() {
    return center;
}

void Circle::setRadius(int r) {
    radius = checkRadius(r);
}

int Circle::getRadius() {
    return radius;
}

void Circle::setColor(Color c) {
    color = c;
}

Color Circle::getColor() {
    return color;
}

void Circle::read(istream& ins) {
    Point tempCenter;
    int tempRadius;
    Color tempColor;
    tempCenter.read(ins);
    ins >> tempRadius;
    tempColor.read(ins);

    center = tempCenter;
    radius = checkRadius(tempRadius);
    color = tempColor;
}

void Circle::write(ostream& outs) {
    center.write(outs);
    outs << " " << radius << " ";
    color.write(outs);
}

istream& operator >> (istream& ins, Circle& circle)
{
    circle.read(ins);
    return ins;
}

ostream& operator << (ostream& outs, Circle circle)
{
    circle.write(outs);
    return outs;
}

void Circle::draw(Graphics & drawer)
{
    int radius = min(getRadius(), (int)DIMENSION);
    int error = -radius;
    int x = radius;
    int y = 0;
    Color c = getColor();

    while (x >= y)
    {
        plot8points(x, y, c, drawer);

        error += y;
        ++y;
        error += y;

        if (error >= 0)
        {
            error -= x;
            --x;
            error -= x;
        }
    }
}

int Circle::checkRadius(int radius)
{
    if (radius < 0)
    {
        return -1 * radius;
    }
    return radius;
}

void Circle::plot8points(int x, int y, Color c, Graphics& drawer)
{
    plot4points(x, y, c, drawer);
    if (x != y) plot4points(y, x, c, drawer);
}

void Circle::plot4points(int x, int y, Color c, Graphics& drawer)
{
    // cx and cy denote the offset of the circle center from the origin.
    int cx = getCenter().getX();
    int cy = getCenter().getY();

    Point pt1Start(cx - x, cy + y);
    Point pt1End(cx + x, cy + y);
    Line line1(pt1Start, pt1End, c);
    line1.draw(drawer);

    Point pt2Start(cx - x, cy - y);
    Point pt2End(cx + x, cy - y);
    Line line2(pt2Start, pt2End, c);
    line2.draw(drawer);
}
