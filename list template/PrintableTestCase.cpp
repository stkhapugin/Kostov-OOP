//
//  PrintableTestCase.cpp
//  list template
//
//  Created by Khapugin Stepan on 15/05/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#include "PrintableTestCase.h"
#include "assert.h"
#include "Printable.h"

class mock_buff : public std::streambuf {
public:
    mock_buff(std::streambuf* buf, char exp_char) : buf(buf), last_char(traits_type::eof()) { setp(0, 0); expected_char = exp_char; }
    char get_last_char() const { return last_char; }
    
    virtual int_type overflow(int_type c) {
        buf->sputc(c);
        if (c!='\n'){ // ignore newlines
            last_char = c;
        }
        return c;
    }
    
    char expected_char;
    void checkLastChar () { assert(last_char == expected_char); }
private:
    std::streambuf* buf;
    char last_char;
};


void testPrintOut(){
    
    std::streambuf* cbuf = std::cout.rdbuf(); // back up cout's streambuf
    std::cout.flush();
    mock_buff mock_buff(cbuf, 'e');
    std::cout.rdbuf(&mock_buff);          // assign your streambuf to cout
    
    std::string nameString = "TestPrintable";
    Printable * aPrintable = new Printable(nameString);
    aPrintable->printOut();
    mock_buff.checkLastChar();
    delete(aPrintable);
    
    std::cout.rdbuf(cbuf);
    
    }

void testPrintable(){
    testPrintOut();
}