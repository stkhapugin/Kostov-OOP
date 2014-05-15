//
//  Named.h
//  list template
//
//  Created by Khapugin Stepan on 15/05/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#ifndef __list_template__Named__
#define __list_template__Named__

#include <iostream>
#include "stdlib.h"

class Named {
protected:
    std::string name;
public:
    Named(std::string objName)
    {
        name = objName;
    }
};

#endif /* defined(__list_template__Named__) */
