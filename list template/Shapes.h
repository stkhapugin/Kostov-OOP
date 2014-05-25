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
#include "XList.h"

class Point : public Shape {

// ivars:
public: double m_x, m_y;
    
public:
    Point(const std::string &name, const double x, const double y):Shape(name), m_x(x), m_y(y) {}
    
    // outputs "name Point(x, y)"
    virtual void printDescription(std::ostream &out) {
        out << m_name << " Point" <<  "(" << m_x << ", " << m_y << ")";
    };
    
    static double distanceBetweenPoints(const Point& a, const Point& b){
        double distX = abs(a.m_x - b.m_x);
        double distY = abs(a.m_y - b.m_y);
        return sqrt(distX*distX + distY*distY);
    }
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
    virtual void printDescription(std::ostream &out) {
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
    virtual void printDescription(std::ostream &out){
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
    virtual void printDescription(std::ostream &out){
        out << m_name << " Square(side:" << side() << " ";
        out << "origin:(" << m_origin.m_x << ", " << m_origin.m_y << ")) ";
        out << "area: " << this->area();
    }
};

class Polyline : public Shape {
    
private:
    XList<Point> m_points;
    
public:
    
    ~Polyline(){
        
        // as we're using a non-retaining list, we're copying points when adding them to the polyline. Thus we have to clean-up those copies in the destructor.
        XList<Point>::Iterator it = m_points.begin();
        int l = m_points.numberOfElements();
        
        while(l > 0){
            delete(it.currentItem());
            it.next();
            l--;
        }

    };
    
    Polyline(const std::string& name): Shape(name) {};
    
    void AddPoint( Point const & point) {
        Point * newPoint = new Point(point);
        m_points.pushBack(newPoint);
    }
    
    virtual void printDescription(std::ostream &out){
        out << m_name << " Polyline(";
        XList<Point>::Iterator it = m_points.begin();
        int l = m_points.numberOfElements();
        
        while(l > 0){
            Point pt = *it.currentItem();
            out << "(" << pt.m_x << "," << pt.m_y << ")";
            it.next();
            
            l--;
            if (l > 0){
                std::cout << ", ";
            }
        }
        
        out << ")";
    }
    
    double length() {
        if (m_points.numberOfElements() < 2){
            return 0.0;
        }
        
        XList<Point>::Iterator it = m_points.begin();
        int l = m_points.numberOfElements();
        
        Point *a = it.currentItem();
        it.next();
        Point *b = it.currentItem();
        l--;
        
        double len = 0.0;
        while(l > 0){
            len += Point::distanceBetweenPoints(*a, *b);
            it.next();
            a = b;
            b = it.currentItem();
            l--;
        }
        
        return len;
    }
};
#endif /* defined(__list_template__Shapes__) */
