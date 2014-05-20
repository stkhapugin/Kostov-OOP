//
//  OperatorOverload.h
//  list template
//
//  Created by Stepan Khapugin on 5/20/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#ifndef list_template_OperatorOverload_h
#define list_template_OperatorOverload_h

#include "Shape.h"

template <typename T>
std::ostream& operator<< (std::ostream& stream, T* shape) {
    shape->printDescription(stream);
    return stream;
}

#endif
