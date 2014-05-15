//
//  List.h
//  list template
//
//  Created by Stepan Khapugin on 3/17/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#ifndef __list_template__List__
#define __list_template__List__

#include <iostream>
#include "assert.h"

// a non-retaining list
template < class T > class XList{

private:
    struct ListNode {
        T *value;
        ListNode *next;
        ListNode *prev;
        ListNode(T *value, ListNode * next, ListNode * prev);
    };
    
    ListNode * head;
    void deleteNode(ListNode * node);
    
public:
    class Iterator {
        friend class XList;
    public:
        T * currentItem();
        void next();
        void prev();
        bool operator==(XList<T>::Iterator rhs);
        
    private:
        ListNode * currentNode;
        XList<T> * currentList;
    };
    
    XList();
    ~XList();
    
    int numberOfElements();
    bool isEmpty();
    void clearList();

    void pushBack(T * element);
    void pushForward(T * element);
    
    void deleteLastObject();
    void deleteFirstObject();
    
    T * firstObject();
    T * lastObject();
    
    Iterator begin();
    Iterator end();
};

#include "XList.tpp"

#endif /* defined(__list_template__List__) */
