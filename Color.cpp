/**
 * Color.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Dylan Robles ,Savannah Brown
 * dtrobles, savvyy
 *
 * The Color.cpp file for the Cool Pictures project.
 */

#include "Color.h"

Color::Color() {
    red = 0;
    green = 0;
    blue = 0;
}

// Constructor that sets RGB values.
Color::Color(int redVal, int greenVal, int blueVal) {
    red = checkRange(redVal);
    green = checkRange(greenVal);
    blue = checkRange(blueVal);
}

// Sets red value.
void Color::setRed(int redVal) {
    red = checkRange(redVal);
}

// Returns red value.
int Color::getRed() {
    return red;
}

// Sets green value.
void Color::setGreen(int greenVal) {
    green = checkRange(greenVal);
}

// Returns green value.
int Color::getGreen() {
    return green;
}

// Sets blue value.
void Color::setBlue(int blueVal) {
    blue = checkRange(blueVal);
}

// Returns blue value.
int Color::getBlue() {
    return blue;
}

// Reads color in form red green blue.
void Color::read(istream& ins) {
    int tempR;
    int tempG;
    int tempB;

    ins >> tempR >> tempG >> tempB;

    red = checkRange(tempR);
    green = checkRange(tempG);
    blue = checkRange(tempB);
}

// Writes color in form red green blue
void Color::write(ostream& outs) {
    outs << red << " " << green << " " << blue;
}

// Returns val if it is in range [0,255], otherwise returns the closest of 0 and 255.
int Color::checkRange(int val) {
    if (val < 0) {
        return 0;
    }
    else if (val > 255) {
        return 255;
    }
    else {
        return val;
    }
}

// Your code goes above this line.
// Don't change the implementations below!

istream& operator >> (istream& ins, Color& color)
{
   color.read(ins);
   return ins;
}

ostream& operator << (ostream& outs, Color color)
{
   color.write(outs);
   return outs;
}
