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
    void printOut(); //< prints the object name
    using Named::Named;
};

#endif /* defined(__list_template__Printable__) */
