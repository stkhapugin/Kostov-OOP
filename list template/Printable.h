//
//  Printable.h
//  list template
//
//  Created by Khapugin Stepan on 15/05/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#ifndef __list_template__Printable__
#define __list_template__Printable__

#include <iostream>
#include "Named.h"

class Printable: public Named {
    
public:
    
    Printable(const std::string& name):Named::Named(name){};
    
    virtual void printDescription(std::ostream &out) const{
        out << m_name;
    };
    
    friend std::ostream & operator << (std::ostream& s, const Printable& obj) {
        obj.printDescription(s);
        return s;
    }
};

#endif /* defined(__list_template__Printable__) */
