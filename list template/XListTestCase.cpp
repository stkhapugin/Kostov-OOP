//
//  XListTestCase.cpp
//  list template
//
//  Created by Khapugin Stepan on 15/05/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#include "XListTestCase.h"
#include <iostream>
#include <cassert>
#include <cstdbool>
#include "XList.hpp"

void testCreation () {
    
    XList<int> * aList = new XList<int>;
    assert(aList != NULL);
}

void testEmptiness () {
    
    XList<int> aList;
    assert(aList.isEmpty());
    assert(aList.numberOfElements() == 0);
}

void testPushBack () {
    
    XList<int> aList;
    int testArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i<100; i++){
        aList.pushBack(&testArray[i%10]);
    }
    
    assert(!aList.isEmpty());
    assert(aList.numberOfElements() == 100);
}

void testLastObject () {
    XList<int> aList;
    assert(aList.lastObject() == NULL);
    int three = 3;
    aList.pushBack(&three);
    assert(*aList.lastObject() == 3);
}

void testLastObjectDeletion () {
    XList<int> aList;
    int three = 3;
    int four = 4;
    aList.pushBack(&three);
    aList.pushBack(&four);
    aList.deleteLastObject();
    assert(*aList.lastObject() == 3);
}

void testFirstObjectDeletion () {
    XList<int> aList;
    int three = 3;
    int four = 4;
    aList.pushBack(&three);
    aList.pushBack(&four);
    aList.deleteFirstObject();
    assert(*aList.lastObject() == 4);
}

void testFirstObject(){
    XList<int> aList;
    int three = 3;
    int four = 4;
    aList.pushBack(&three);
    aList.pushBack(&four);
    assert(aList.firstObject() == &three);
}

void testBegin(){
    XList<int> aList;
    int three = 3;
    int four = 4;
    aList.pushBack(&three);
    aList.pushBack(&four);
    XList<int>::Iterator it = aList.begin();
    assert(it.currentItem() == &three);
}

void testEnd(){
    XList<int> aList;
    int three = 3;
    int four = 4;
    int five = 5;

    aList.pushBack(&three);
    aList.pushBack(&four);
    aList.pushBack(&five);
    
    XList<int>::Iterator it = aList.end();
    assert(it.currentItem() == &five);
}

void testClearList(){
    XList<int> aList;
    int testArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i<100; i++){
        aList.pushBack(&testArray[i%10]);
    }
    
    assert(!aList.isEmpty());
    assert(aList.numberOfElements() == 100);
    aList.clearList();
    assert(aList.isEmpty());
    assert(aList.numberOfElements() == 0);
}

void testIterator(){
    XList<int> aList;
    int testArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i<10; i++){
        aList.pushBack(&testArray[i%10]);
    }
    
    XList<int>::Iterator it = aList.begin();
    assert(*it.currentItem() == 0);
    it.next();
    assert(*it.currentItem() == 1);
    it.prev();
    assert(*it.currentItem() == 0);
}

void testDeleteFirstLastException(){
    
    XList<int> aList;
    int a = 5;
    aList.pushBack(&a);
    
    try {
        aList.deleteFirstObject();
    } catch(std::string e){
        assert(false);
    }
    
    bool exceptionCaught = false;
    try {
        aList.deleteFirstObject();
    } catch(std::string e){
        exceptionCaught = true;
    }
    
    assert(exceptionCaught);
    
    exceptionCaught = false;
    try {
        aList.deleteLastObject();
    } catch (std::string e){
        exceptionCaught = true;
    }
    
    assert(exceptionCaught);
}

void testXList() {
    std::cout << "running XList tests" << std::endl;
    testCreation();
    testEmptiness();
    testPushBack();
    testLastObject();
    testLastObjectDeletion();
    testFirstObjectDeletion();
    testFirstObject();
    testBegin();
    testEnd();
    testClearList();
    testIterator();
    testDeleteFirstLastException();
    std::cout << "finished running XList tests" << std::endl;
}
