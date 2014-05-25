//
//  MockBuffer.h
//  list template
//
//  Created by Stepan Khapugin on 5/20/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#ifndef list_template_MockBuffer_h
#define list_template_MockBuffer_h

#include <cassert>

class mock_buff : public std::streambuf {
    
public:
    
    mock_buff(std::streambuf* buf,
              std::string &exp_string) : buf(buf),
                                        last_char(traits_type::eof()),
                                        exp_string(exp_string) { setp(0, 0); }
    
    char get_last_char() const { return last_char; }
    
    virtual int_type overflow(int_type c) {
        buf->sputc(c); // suppress actual printing
        if (c!='\n'){ // ignore newlines
            buffered_string += c;
        }
        return c;
    }
    
    std::string exp_string;
    void checkExpectation () {
        assert(exp_string.compare(buffered_string) == 0);
    }
    
    void clearBuffer () {
        buffered_string.clear();
    }
private:
    std::streambuf* buf;
    std::string buffered_string;
    char last_char;
};



#endif
