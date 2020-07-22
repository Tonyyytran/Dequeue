//
// Created by Tony Tran on 12/5/19.
//

#ifndef DEQUE2_DEQUE_H
#define DEQUE2_DEQUE_H
#include <iostream>
using namespace std;

template <class Object>
struct DequeNode {                  // a list node
     Object item;
     DequeNode *next;
     DequeNode *prev;
     };

     template <class Object>
     class Deque {
     public:

         Deque( );                         // the constructor
         Deque(const Deque &rhs );        // the copy constructor
         ~Deque( );                        // the destructor
         bool isEmpty( ) const;            // checks if a list is empty.
         int size( ) const;                // retrieves # list nodes;
         const Object &getFront( ) const;            // retrieve the front node
         const Object &getBack( ) const;             // retrieve the tail node
         void clear( );                    // clean up all list entries.
         void addFront(const Object &obj  );         // add a new node to the front
         void addBack( const Object &obj );          // add a new node to the tail
         Object removeFront( );                      // remove the front node
         Object removeBack( );                       // remove the tail node
         const Deque &operator=(const Deque &rhs );       // assignment
         void print() const;
     private:
         DequeNode<Object> *front;
         DequeNode<Object> *back;
     };
     #include "deque.cpp"
#endif //DEQUE2_DEQUE_H
