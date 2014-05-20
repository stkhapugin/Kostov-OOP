//
//  Tests.cpp
//  list template
//
//  Created by Khapugin Stepan on 15/05/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#include "Tests.h"
#include <iostream>
#include "PrintableTestCase.h"
#include "XListTestCase.h"
#include "ShapeTestCase.h"
#include "ShapesTestCase.h"

void runTests () {
    
    std::cout << "Running tests..." << std::endl;

    testPrintable();
    testXList();
    testShape();
    testShapes();
    
    std::cout << "Tests ran successfully!" << std::endl;
}