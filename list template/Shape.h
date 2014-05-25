//
//  Shape.h
//  list template
//
//  Created by Khapugin Stepan on 15/05/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#ifndef __list_template__Shape__
#define __list_template__Shape__

#include <iostream>
#include "Printable.h"

static int shapeCount;

class Shape: public Printable {
    
public:
    
    static int getCount()//< returns total number of all shapes in heap and on stack
    {
        return shapeCount;
    }
    
    virtual ~Shape()
    {
        shapeCount --;
    }
    
    Shape(std::string name):Printable(name)
    {
        shapeCount ++;
    }
    
    Shape(const Shape& shape): Printable(shape)
    {
        shapeCount ++;
    }
    
    static int shapeCount;
};

#endif /* defined(__list_template__Shape__) */
