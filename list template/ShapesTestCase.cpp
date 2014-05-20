//
//  PointTestCase.cpp
//  list template
//
//  Created by Stepan Khapugin on 5/20/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#include "ShapesTestCase.h"
#include "Shapes.h"
#include "OperatorOverload.h"
#include "MockBuffer.h"
#include <cassert>

#pragma mark - point tests

void testPointCreation () {
    Point pt = Point("name", 10.0, 20.0);
    assert(pt.m_x == 10.0);
    assert(pt.m_y == 20.0);
}

void testPrint () {
    
    // setup
    std::streambuf* cbuf = std::cout.rdbuf();
    std::cout.flush();
    std::string expected_output = "somepoint Point(20, 30)";
    mock_buff mock_buff(cbuf, expected_output);
    std::cout.rdbuf(&mock_buff);
    
    Point pt = Point("somepoint", 20.0, 30.0);
    std::cout << &pt;
    mock_buff.checkExpectation();
    
    // teardown
    std::cout.rdbuf(cbuf);
}

void testPoint () {
    testPointCreation();
    testPrint();
}

#pragma mark - circle tests

void testCirclePrint() {
    // setup
    std::streambuf* cbuf = std::cout.rdbuf();
    std::cout.flush();
    std::string expected_output = "a circle Circle(center:(10, 20); radius:10). Area: 314.159";
    mock_buff mock_buff(cbuf, expected_output);
    std::cout.rdbuf(&mock_buff);
    
    Circle circle = Circle("a circle", 10, Point("pt", 10, 20));
    std::cout << &circle;
    mock_buff.checkExpectation();
    
    // teardown
    std::cout.rdbuf(cbuf);
}

void testCircle () {
    testCirclePrint();
}

#pragma mark - rect tests

void testRectPrint() {
    
    // setup
    std::streambuf* cbuf = std::cout.rdbuf();
    std::cout.flush();
    std::string expected_output = "aRect Rect(size:(30, 40) origin:(10, 20)) area: 1200";
    mock_buff mock_buff(cbuf, expected_output);
    std::cout.rdbuf(&mock_buff);

    
    Rect aRect = Rect("aRect", 10, 20, 30, 40);
    std::cout << &aRect;
    mock_buff.checkExpectation();
    
    // teardown
    std::cout.rdbuf(cbuf);
}

void testRect() {
    testRectPrint();
}

#pragma mark - square tests

void testSquarePrint() {
    // setup
    std::streambuf* cbuf = std::cout.rdbuf();
    std::cout.flush();
    std::string expected_output = "aSquare Square(side:30 origin:(10, 20)) area: 900";
    mock_buff mock_buff(cbuf, expected_output);
    std::cout.rdbuf(&mock_buff);
    
    
    Square aSquare = Square("aSquare", 10, 20, 30);
    std::cout << &aSquare;
    mock_buff.checkExpectation();
    
    // teardown
    std::cout.rdbuf(cbuf);
}

void testSquare() {
    testSquarePrint();
}

#pragma mark - square tests

void testPolylinePrint() {
    
    // setup
    std::streambuf* cbuf = std::cout.rdbuf();
    std::cout.flush();
    std::string expected_output = "line Polyline((10,20), (11,21), (12,22))";
    mock_buff mock_buff(cbuf, expected_output);
    std::cout.rdbuf(&mock_buff);
    
    
    Polyline line = Polyline("line");
    Point pt1 = Point("", 10, 20);
    Point pt2 = Point("", 11, 21);
    Point pt3 = Point("", 12, 22);

    line.AddPoint(pt1);
    line.AddPoint(pt2);
    line.AddPoint(pt3);
    
    std::cout<<&line;
    mock_buff.checkExpectation();
    
    // teardown
    std::cout.rdbuf(cbuf);
}

void testPolyline() {
    testPolylinePrint();
}


#pragma mark - shapes tests

void testShapes() {
    testPoint();
    testCircle();
    testRect();
    testSquare();
    testPolyline();
}