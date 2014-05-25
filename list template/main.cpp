//
//  main.cpp
//  list template
//
//  Created by Stepan Khapugin on 3/17/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#include <iostream>
#include "Tests.h"
#include "Shape.h"
#include "Shapes.h"
#include "XList.h"

int Shape::shapeCount = 0;

// this function is what is required by task #3 here: https://sites.google.com/site/kostovoop/tasks
//    Составить и отладить программу:
//    - создать некий XList фигур, наполнить его случайным образом конкретными фигурами всех типов;
//    - вывести в std::cout общее кол-во фигур с помощью Shape::GetCount();
//    - напечатать в std::cout сведения обо всех фигурах, находящихся в списке;
//    - очистить память;
//    - вывести в std::cout общее кол-во фигур с помощью Shape::GetCount() – удостовериться, что там 0;
//    - завершить работу программы.
void task3()
{
    XList<Shape> shapesList;
    // pt, circle, rect, square, polyline
    Point * pt = new Point("a point", 10, 100); // 1
    Circle * circle = new Circle("a circle", 30, Point("circle center", 10, 20)); // 2
    Rect * rect = new Rect("a rect", 10, -30, 10, -100); // 2
    Square * square = new Square("a square", 40, 20, 10); // 2
    Polyline * line = new Polyline("line"); // 1
    
    Point * pt1 = new Point("", 10, 20);
    Point * pt2 = new Point("", 20, 20);
    Point * pt3 = new Point("", 20, 40);
    Point * pt4 = new Point("", 10, 40);

    line->AddPoint(*pt1);
    line->AddPoint(*pt2);
    line->AddPoint(*pt3);
    line->AddPoint(*pt4);

    shapesList.pushBack(pt);
    shapesList.pushBack(circle);
    shapesList.pushBack(rect);
    shapesList.pushBack(square);
    shapesList.pushBack(line);
    
    std::cout << "Total number of shapes is: " << Shape::getCount() << std::endl;
    assert(Shape::getCount() == 16); // 5 figures in list and their copies, 4 points in the polyline, rect's origin, square's origin, circle's center
    
    XList<Shape>::Iterator it = shapesList.begin();
    while(!(it == shapesList.end())){
        Shape shape = *it.currentItem();
        std::cout << shape << std::endl;
        it.next();
    }
    Shape * shape = it.currentItem();
    std::cout << shape << std::endl; // last item
    delete shape;
    
    shapesList.clearList();
    // freeing memory
    delete pt;
    delete circle;
    delete square;
    delete rect;
    delete line;
    delete pt1;
    delete pt2;
    delete pt3;
    delete pt4;
    
    std::cout << "Total number of shapes is now: " << Shape::getCount() << std::endl;
    assert(Shape::getCount() == 0);
}

int main(int argc, const char * argv[])
{
    runTests();
    task3();
    return 0;
}

