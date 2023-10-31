/**
 * test.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * Dylan Robles, Savannah Brown
 * dtrobles, savvyy
 *
 * Test different class and their functions
 */

#include "Graphics.h"
#include "Circle.h"
#include "Color.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Triangle.h"

#include <iostream>
#include <fstream>

using namespace std;


void test_Circle();
void test_Color();
void test_Line();
void test_Point();
void test_Rectangle();
void test_Triangle();

void startTests() {
    test_Point();
    test_Color();
    test_Line();
    test_Triangle();
    test_Circle();
    test_Rectangle();
    return;
}

void test_Point() {
    cout << "Now testing Point class" << endl;

    Point pt1;
    cout << "Expected: (0,0), actual: " << pt1 << endl;

    Point pt2(13, 25);
    cout << "Expected: (13,25), actual: " << pt2 << endl;


    pt1.setX(15);
    pt1.setY(25);
    cout << "Expected: (15,25), actual: " << pt1 << endl;

    cout << "Expected x: 15, actual x: " << pt1.getX() << endl;
    cout << "Expected y: 25, actual y: " << pt1.getY() << endl;

    pt1.setX(15);
    pt1.setY(0);
    cout << "Expected: (15,0), actual: " << pt1 << endl;

    cout << endl;
    return;
}

void test_Color() {
    cout << "Now testing Color class" << endl;
    Color color;
    cout << "Expected: 0 0 0, Actual: " << color << endl;

    Color color2(2, 7, 9);
    cout << "Expected: 2 7 9, Actual: " << color2 << endl;

    color.setBlue(4);
    color.setRed(3);
    color.setGreen(2);
    cout << "Expected: 3 2 4, Actual: " << color << endl;

    color.setRed(280);
    color.setGreen(400);
    color.setBlue(256);
    cout << "Expected: 255 255 255, Actual: " << color << endl;

    //Color color3;
    //ifstream ins;
    //ins.open("circle.txt");
    //color3.read(ins);
    //cout << "Expected: , Actual: " << color3 << endl;

   

    cout << endl;

    return;
}

void test_Line() {
    cout << "Now testing Line class" << endl;
    Line line1;
    cout << "Expected (0,0) (0,0) 0 0 0, Actual: " << line1 << endl;
    Point ptStart(5, 7);
    Point ptEnd(4, 7);
    Color color(212, 131, 23);

    Line line2(ptStart, ptEnd, color);
    cout << "Expected (5,7) (4,7) 212 131 23, Actual: " << line2 << endl;

    
    Line line3;
    ifstream ins;
    ins.open("lines.txt");
    char junk;
    ins >> junk;
    line3.read(ins);
    cout << "Expected (5,5) (95,5) 255 0 0, Actual: " << line3 << endl;
    ins.close();

    

    cout << endl;
}

void test_Triangle() {
    cout << "Now testing Triangle class" << endl;
    Triangle triangle1;
    cout << "Expected: (0,0) (0,0) "
        "(0,0) 0 0 0, Actual: " << triangle1 << endl;

    Point p1(2, 3);
    Point p2(4, 2);
    Point p3(5, 7);
    Color color1(23, 4, 2);
    Triangle triangle2(p1, p2, p3, color1);
    cout << "Expected: (2,3) (4,2), (5,7) 23 4 2, Actual: "
        << triangle2 << endl;

    Color color2(3, 3, 3);
    Color color3(34, 23, 42);
    Triangle triangle3(p1, color1, p2, color2, p3, color3);
    cout << "Expected: (2,3) 23 4 2 (4,2) 3 3 3 (5,7)" <<
        " 34 23 42, Actual: " << triangle3 << endl;


    Triangle triangle4;
    ifstream ins;
    ins.open("triangles.txt");
    string junk;
    char alsoJunk;
    getline(ins, junk);
    
    ins >> alsoJunk;
    triangle4.read(ins);
    cout << "Expected: (10,10) (50,20) (20,40) 200 0 5, Actual: "
        << triangle4 << endl;
    ins >> alsoJunk;
    triangle4.read(ins);
    ins.close();
    cout << "Expected: (80,5) 0 200 5 (50,20) 200 0 5 (85,90) 50 0 5," 
        << " Actual: " << triangle4 << endl;

    cout << endl;
}

void test_Circle() {
    cout << "Now testing Circle class" << endl;

    Circle circle1;
    cout << "Expected: (0,0) 0 0 0 0, Actual: " << circle1 << endl;

    Point pt1(7, 3);
    Color color1(3, 4, 20);
    Circle circle2(pt1, 23, color1);
    cout << "Expected: (7,3) 23 3 4 20, Actual: " << circle2 << endl;

    Point pt2(50, 4);
    Color color2(7, 7, 7);
    circle1.setCenter(pt2);
    circle1.setColor(color2);
    circle1.setRadius(-30);
    cout << "Expected: (50, 4) 30 7 7 7, Actual: " << circle1 << endl;

    Circle circle3;
    string junk;
    char alsoJunk;
    ifstream ins;
    ins.open("circles.txt");
    getline(ins, junk);
    ins >> alsoJunk;
    circle3.read(ins);
    cout << "Checking junk char: " << alsoJunk << endl;

    cout << "Expected: (20,20) 30 255 0 0, Actual: " << circle3 << endl;
    ins.close();
    cout << endl;

}

void test_Rectangle() {
    cout << "Now testing Rectangle class" << endl;

    Rectangle rectangle1;
    cout << "Expected: (0,0) (0,0) 0 0 0, Actual: " << rectangle1 << endl;

    Point p1(5, 6);
    Point p2(4, 2);
    Color c1(3, 2, 3);
    Color c2(3, 3, 3);
    Color c3(43, 44, 23);
    Color c4(32, 4, 2);

    Rectangle rectangle2(p1, p2, c1);
    cout << "Expected: (5,6) (4,2) 3 2 3, Actual: " << rectangle2 << endl;

    Rectangle rectangle3(p1, p2, c1, c2, c3, c4);
    cout << "Expected: (5,6) (4,2) 3 2 3 3 3 3 43 44 23 32 4 2, Actual: " << rectangle3 << endl;

    rectangle1.setStart(p1);
    rectangle1.setEnd(p2);
    rectangle1.setColor(c1);
    cout << "Expected: (5,6) (4,2) 3 2 3, Actual: " << rectangle1 << endl;

    rectangle1.setColorTopLeft(c1);
    rectangle1.setColorTopRight(c2);
    rectangle1.setColorBottomRight(c3);
    rectangle1.setColorBottomLeft(c4);
    cout << "Expected: (5,6) (4,2) 3 2 3 3 3 3 43 44 23 32 4 2, Actual: " << rectangle1 << endl;

    Rectangle rectangle4;
    ifstream ins;
    ins.open("rectangles.txt");
    char junk;
    string alsoJunk;
    ins >> junk;
    rectangle4.read(ins);
    cout << "Expected: (0,0) (99,99) 255 255 255, Actual: " << rectangle4 << endl;

    getline(ins, alsoJunk);
    Rectangle rectangle5;
    ins >> junk;
    rectangle5.read(ins);
    cout << "Expected: (10,50) (40,90) 200 0 5  200 0 5  200 0 5"  
        "  200 0 5, Actual: " <<
        rectangle5 << endl;

    cout << endl;

}
