//
// Created by Tony Tran on 12/8/19.
//

#ifndef LONGINT_H
#define LONGINT_H
#include <iostream>
#include "deque.h"
using namespace std;

class LongInt {

    friend istream &operator>>(istream &in, LongInt &rhs );         // overloaded instream for LongInt
    friend ostream &operator<<( ostream &out, const LongInt &rhs ); // overloaded outstream for LongInt


    public:
         Deque<char> digits;
         LongInt();                                     // Defualt constructor
         LongInt( const string str );                   // Single parameter string constructor
         LongInt( const LongInt &rhs );                 // Copy constructor
         ~LongInt( );                                   // Destructor
         LongInt operator+( const LongInt &rhs ) const; // overloaded operators add for LongInt
         LongInt operator-( const LongInt &rhs ) const; // overloaded operators subtract for LongInt
         LongInt& operator=( const LongInt &rhs );      // overloaded operators assignment for LongInt
         bool operator< ( const LongInt & rhs ) const;  // overloaded operators less than for LongInt
         bool operator<=( const LongInt & rhs ) const;  // overloaded operators less than or equal to for LongInt
         bool operator> ( const LongInt & rhs ) const;  // overloaded operators greater than for LongInt
         bool operator>=( const LongInt & rhs ) const;  // overloaded operators greater than or equal to for LongInt
         bool operator==( const LongInt & rhs ) const;  // overloaded operators equal to for LongInt
         bool operator!=( const LongInt & rhs ) const;  // overloaded operators not equal to for LongInt
         int compareList (const LongInt & rhs ) const;  // helper methods : finds if this LongInt is smaller, larger, or equal independent of negativity
         int getBackInt () const;                       // returns the back of longInt as integer instead of char

private:
         bool negative;
         void remove0s( );                              // Removes zeros in the front of the integer
 };

#include "longint.cpp"
 #endif
