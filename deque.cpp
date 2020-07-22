//
// Created by Tony Tran on 12/5/19.
//
#include "deque.h"

template<class Object>
Deque<Object>::Deque( ) {
    front = back = NULL;
}

template <class Object>
Deque<Object>::Deque(const Deque &rhs){         // the copy constructor
    front = back = NULL;
    *this = rhs;
}


template<class Object>
Deque<Object>::~Deque( ) {
     clear( );                                       // delete items starting 1st
}

template<class Object>
bool Deque<Object>::isEmpty( ) const {
     return front == NULL;
}

template<class Object>
int Deque<Object>::size( ) const {
    int i = 0;
    for ( DequeNode<Object> *ptr = front; ptr != NULL; ptr = ptr->next )//traverse que
        ++i;
    return i;
}

template<class Object>
void Deque<Object>::clear( ) {
    while ( !isEmpty( ) )                 // dequeue till the queue gets empty.
        removeFront( );
}


//add a new node to front
template<class Object>
void Deque<Object>::addFront(const Object &obj  ) {
    //implement the function body.
    DequeNode<Object> *newPtr = new DequeNode<Object>;
    newPtr->item = obj;
    newPtr->next = front;
    newPtr->prev = NULL;

    if (front != NULL)
        front->prev = newPtr;
    front = newPtr;

    if (back == NULL)
        back = newPtr;

}

// add a new node to tail

template <class Object>
void Deque<Object>::addBack( const Object &obj ) {
    DequeNode<Object> *newPtr = new DequeNode<Object>;
    newPtr->item = obj;
    if (front == NULL)
        front = newPtr; //this was your main problem!

    if (back != NULL)
        back->next = newPtr;

    newPtr->next = NULL;
    newPtr->prev = back;
    back = newPtr;

}

template <class Object>
Object Deque<Object>::removeFront( ) {  // remove the front node
    DequeNode<Object> *deleteNode = front;
    Object tempItem = front->item;
    if ( front == NULL) // no nodes in the list
        return 0;
    if ( front == back) { // only one item in the list
        front = NULL;
        back = NULL;
    }
    else{
        front = front->next;
        front -> prev = NULL;
        delete deleteNode;
    }
    return tempItem;
}

template <class Object>
Object Deque<Object>::removeBack( ) {   // remove the tail node
    if ( front == NULL)
        return 0;
    DequeNode<Object> *deleteNode = back;
    Object tempItem = back->item;
    if ( front == back) { // only one item in the list
        front = NULL;
        back = NULL;
    }
    else{
        back = back->prev;
        back -> next = NULL;
        delete deleteNode;
    }
    return tempItem;
}

template <class Object>
const Object &Deque<Object>::getFront( ) const {   // retrieve the front node
    if ( isEmpty( ) )
        return NULL;
    return front->item;
}

template <class Object>
const Object &Deque<Object>::getBack( ) const {    // retrieve the tail node
    if ( isEmpty( ) )
        return NULL;
    return back->item;
}

template<class Object>
const Deque<Object> &Deque<Object>::operator=(const Deque &rhs ) {
    if ( this != &rhs ) { // avoid self assignment
        clear( );
        for ( DequeNode<Object> *rptr = rhs.front; rptr != NULL; rptr = rptr->next )
            addBack( rptr->item );
    }
    return *this;
}

template <class Object>
void Deque<Object>::print() const {
    DequeNode<Object> *p = front;
    if ( isEmpty() )
        return;
    cout << p->item << endl;
    while (p->next != NULL){
        p = p->next;
        cout << p->item << endl;
    }
}

