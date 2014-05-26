//
//  PrintableTestCase.cpp
//  list template
//
//  Created by Khapugin Stepan on 15/05/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#include "Shapes.h"
#include <cassert>
#include "PrintableTestCase.h"
#include "MockBuffer.h"

void testPrintOut(){
    
    std::streambuf* cbuf = std::cout.rdbuf(); // back up cout's streambuf
    std::cout.flush();
    std::string expected_output = "TestPrintable";
    mock_buff mock_buff(cbuf, expected_output);
    
    std::cout.rdbuf(&mock_buff);          // assign your streambuf to cout
    
    Printable * aPrintable = new Printable(expected_output);
    aPrintable->printDescription(std::cout);
    mock_buff.checkExpectation();
    
    delete(aPrintable);
    
    std::cout.rdbuf(cbuf);
    
}

void testPrintable(){
    testPrintOut();
}