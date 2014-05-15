//
//  main.cpp
//  list template
//
//  Created by Stepan Khapugin on 3/17/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#include <iostream>
#include "List.h"

int main(int argc, const char * argv[])
{

    XList<int> * aList = new XList<int>;
    
    std::cout << "Array is empty: " << ((aList->isEmpty())?"YES":"NO") << "\n";
    
    int myArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    for (int i = 0; i<100; i++){
        
        aList->pushBack(&myArray[i%10]);
    }
    
    std::cout << "Array is empty: " << ((aList->isEmpty())?"YES":"NO") << "\n";
    std::cout << "Number of elements: " << aList->numberOfElements() << "\n";
    
        std::cout << "Before deletion first object is: " << *aList->firstObject() << "; last: " << *aList->lastObject() << "\n";
    
    aList->deleteLastObject();
    aList->deleteFirstObject();
    
    std::cout << "After deletion first object is: " << *aList->firstObject() << "; last: " << *aList->lastObject() << "\n";
    
    
    std::cout << "Number of elements in cleared list: " << aList->numberOfElements() << "\n";

    // *** iterators ***
    
    XList<int>::Iterator it = aList->begin();
    std::cout << "Begin iterator: " << *it.currentItem() << "\n";
    it.next();
    std::cout << "Next item: " << *it.currentItem() << "\n";
    it.prev();
    std::cout << "Prev item: " << *it.currentItem() << "\n";
    it.prev();
    std::cout << "Prev item: " << *it.currentItem() << "\n";
    
    int i = 0;
    for (XList<int>::Iterator newIt = aList->begin(); !(newIt == aList->end()); newIt.next()){
        std::cout << "Current item: " << *newIt.currentItem() << "\n";
        i++;
    }
    
    assert(i+1 == aList->numberOfElements());

    aList->clearList();
    it = aList->begin();
    assert(it.currentItem() == NULL);
    
    delete aList;

    return 0;
}

