//
//  ShapeTestCase.cpp
//  list template
//
//  Created by Khapugin Stepan on 15/05/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#include "ShapeTestCase.h"
#include "Shape.h"
#include "OperatorOverload.h"
#include "MockBuffer.h"
#include <cassert>

void testShapeCount(){
    std::string uno = "UNO";
    std::string dos = "DOS";

    assert(Shape::getCount() == 0);
    Shape aShape = Shape(uno);
    assert(Shape::getCount() == 1);
    Shape * anotherShape = new Shape(dos);
    assert(Shape::getCount() == 2);
    delete anotherShape;
    assert(Shape::getCount() == 1);
}

void testOperatorOut () {
    
    // setup
    std::streambuf* cbuf = std::cout.rdbuf();
    std::cout.flush();
    std::string expected_output = "Shape test";
    mock_buff mock_buff(cbuf, expected_output);
    std::cout.rdbuf(&mock_buff);
    
    Shape aShape = Shape(expected_output);
    aShape.printDescription(std::cout);
    mock_buff.checkExpectation();
    
    // teardown
    std::cout.rdbuf(cbuf);
}

void testShape ()
{
    testShapeCount();
    testOperatorOut();
}