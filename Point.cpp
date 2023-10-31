/**
 * Point.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Dylan Robles, Savannah Browm
 * dtrobles, savvyy
 *
 * The Point.cpp file for the Cool Pictures project.
 */

#include "Point.h"


#include "utility.h"



Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int xVal, int yVal) {
    x = checkRange(xVal);
    y = checkRange(yVal);
}

void Point::setX(int xVal) {
    x = checkRange(xVal);
}

int Point::getX() {
    return checkRange(x);
}

void Point::setY(int yVal) {
    y = checkRange(yVal);
}

int Point::getY() {
    return checkRange(y);
}

void Point::read(istream& ins) {
    int xNum = 0;
    int yNum = 0;
    char junk = '(';
    char comma = ',';
    char alsoJunk = ')';
    ins >> junk >> xNum >> comma >>
        yNum >> alsoJunk;
    xNum = checkRange(xNum);
    yNum = checkRange(yNum);
    setX(xNum);
    setY(yNum);

    return;
}

void Point::write(ostream& outs) {
    int x = checkRange(getX());
    int y = checkRange(getY());
    outs << '(' << x << ',' << y << ')';

    return;

}

int Point::checkRange(int val) {
    if (val >= 0 && val < DIMENSION) {
        return val;
    }
    else {
        if (val < 0) {
            return 0;
        }
        else {
            return (DIMENSION - 1);
        }
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins,  Point& pt)
{
    pt.read(ins);
    return ins;
}

ostream& operator<< (ostream& outs, Point pt)
{
    pt.write(outs);
    return outs;
}
