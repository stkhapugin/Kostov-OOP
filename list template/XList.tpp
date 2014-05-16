//
//  XList.tpp.h
//  list template
//
//  Created by Khapugin Stepan on 15/05/14.
//  Copyright (c) 2014 Stepan Khapugin. All rights reserved.
//

#ifndef list_template_XList_tpp_h
#define list_template_XList_tpp_h

#pragma mark - ListNode implementation

template < class T >
XList<T>::ListNode::ListNode(T *value, ListNode * next, ListNode * prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

#pragma mark - Xlist implementation

template < class T >
XList<T>::~XList() {
    this->clearList();
}

template < class T >
XList<T>::XList() {
    ListNode * naught = new ListNode(NULL, NULL, NULL);
    this->head = naught;
    naught->next = naught->prev = naught;
}

#pragma mark - unsorted

template <class T>
bool XList<T>::isEmpty() const{
    return (this->head->next == this->head);
}

template <class T>
int XList<T>::numberOfElements() const{
    
    ListNode * naught = this->head;
    ListNode * node = naught;
    int count = 0;
    while (naught != (node = node->next)){
        ++count;
    }
    
    return count;
}

template < class T >
void XList<T>::clearList() {
    
    ListNode * naught = this->head;
    ListNode * node = naught->next;
    while (node->next != naught){
        ListNode * nodeToDelete = node;
        node = node->next;
        delete(nodeToDelete);
    }
    
    naught->prev = naught->next = naught;
}

#pragma mark - adding elements

template <class T>
void XList<T>::pushForward(T * element){
    
    ListNode * naught = this->head;
    ListNode * newNode = new ListNode(element, naught->next, naught);
    naught->next = naught->next->prev = newNode;
}

template <class T>
void XList<T>::pushBack(T * element){
    
    ListNode * naught = this->head;
    ListNode * newNode = new ListNode(element, naught, naught->prev);
    naught->prev = naught->prev->next = newNode;
}

#pragma mark - deleting elements

template <class T>
void XList<T>::deleteFirstObject() {
    ListNode * naught = this->head;
    ListNode * deletedNode = naught->next;
    if (deletedNode != naught){
        this->deleteNode(deletedNode);
    } else {
        throw "XList: cannot delete first object in an empty list";
    }
}

template <class T>
void XList<T>::deleteLastObject() {
    ListNode * naught = this->head;
    ListNode * deletedNode = naught->prev;
    if (deletedNode != naught){
        this->deleteNode(deletedNode);
    } else {
        throw "XList: cannot delete first object in an empty list";
    }
}

template <class T>
void XList<T>::deleteNode(ListNode * node){
    
    assert(this->head != node);
    
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete(node);
}

#pragma mark - getting elements

template <class T>
T * XList<T>::firstObject() const{
    return this->head->next->value;
}

template <class T>
T * XList<T>::lastObject() const{
    return this->head->prev->value;
}

#pragma mark - iterator
template <class T>
typename XList<T>::Iterator XList<T>::begin(){
    XList<T>::Iterator iterator;
    iterator.currentList = this;
    iterator.currentNode = this->head->next;
    
    return iterator;
}

template <class T>
typename XList<T>::Iterator XList<T>::end(){
    XList<T>::Iterator iterator;
    iterator.currentList = this;
    iterator.currentNode = this->head->prev;
    
    return iterator;
}

template <class T>
T * XList<T>::Iterator::currentItem(){
    return this->currentNode->value;
}

template <class T>
void XList<T>::Iterator::next(){
    
    ListNode * naught = this->currentList->head;
    ListNode * nextNode = this->currentNode->next;
    
    if (nextNode == naught){
        // try to move over the naught element
        nextNode = nextNode->next;
    }
    
    this->currentNode = nextNode;
}

template <class T>
void XList<T>::Iterator::prev(){
    
    ListNode * naught = this->currentList->head;
    ListNode * prevNode = this->currentNode->prev;
    
    if (prevNode == naught){
        // try to move over the naught element
        prevNode = prevNode->prev;
    }
    
    this->currentNode = prevNode;
}

template <class T>
bool XList<T>::Iterator::operator==(const XList<T>::Iterator& rhs){
    return ((this->currentList == rhs.currentList)&&(this->currentNode == rhs.currentNode));
}


#endif
