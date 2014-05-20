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
#include <cstdlib>

class Named {
protected:
    std::string m_name;
public:
    Named(const std::string& objName) : m_name (objName){}
};

#endif /* defined(__list_template__Named__) */
