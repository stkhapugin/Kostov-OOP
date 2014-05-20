//
//  Point.h
//  list template
//
//  Created by Stepan Khapugin on 5/20/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#ifndef __list_template__Shapes__
#define __list_template__Shapes__

#include <iostream>
#include <cmath>
#include "Shape.h"
#include "Printable.h"

class Point : public Shape {

// ivars:
public: double m_x, m_y;
    
public:
    Point(const std::string &name, const double x, const double y):Shape(name), m_x(x), m_y(y) {}
    
    // outputs "name Point(x, y)"
    virtual void printDescription(std::ostream &out) {
        out << m_name << " Point" <<  "(" << m_x << ", " << m_y << ")";
    };
};

class Circle : public Shape {
    
public:
    
    double m_radius;
    Point m_center;
    
    Circle(const std::string &name, const double radius, const Point& center): Shape(name), m_radius(radius), m_center(center){};
    
    double area() const {
        return m_radius * m_radius * M_PI;
    }
    
    // outputs: name Circle(center:(x,y), radius:radius)
    virtual void printDescription(std::ostream &out) const{
        out << m_name << " Circle(center:(" << m_center.m_x << ", " << m_center.m_y << "); radius:" << m_radius << "). Area: " << this->area();
    };
};

class Size {
    
    private :
    double m_width, m_height;
    
public:
    
    double width() const {
        return m_width;
    }
    
    double height() const {
        return m_height;
    }
    
    double area() const {
        return m_width * m_height;
    }
    
    Size(double width, double height): m_width(width), m_height(height){};
};

class Rect : public Shape {

protected :
    Size m_size;
    Point m_origin;

public:
    
    Rect(const std::string& name, double x, double y, double width, double height):
    Shape(name), m_origin("point", x, y), m_size(width, height) {};
    
    double area() const {
        return m_size.area();
    }
    
    // outputs name Rect(size:(w, h) origin:(x, y)) area: w*h
    virtual void printDescription(std::ostream &out) const{
        out << m_name << " Rect(size:(" << m_size.width() << ", " << m_size.height();
        out << ") origin:(" << m_origin.m_x << ", " << m_origin.m_y << ")) ";
        out << "area: " << this->area();
    }
};

class Square : public Rect {
    
public:
    double side() const {
        return m_size.width();
    }
    
    Square(const std::string& name, double x, double y, double side) :
    Rect(name, x, y, side, side) {};
    
    // outputs name Square(side:s origin:(x, y)) area: s^2
    virtual void printDescription(std::ostream &out) const{
        out << m_name << " Square(side:" << side() << " ";
        out << "origin:(" << m_origin.m_x << ", " << m_origin.m_y << ")) ";
        out << "area: " << this->area();
    }
};
#endif /* defined(__list_template__Shapes__) */