//
//  ShapeTestCase.cpp
//  list template
//
//  Created by Khapugin Stepan on 15/05/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#include "ShapeTestCase.h"
#include "Shape.h"
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

void testShape ()
{
    testShapeCount();
}