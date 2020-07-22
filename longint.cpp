//
// Created by Tony Tran on 12/8/19.
//

//#include "longint.h"
//#include "deque.cpp"

LongInt::LongInt() {                            // default constructor
    negative = false;
}

LongInt::LongInt(const string str) {            // single parameter constructor, taking strings
    negative = str[0] == '-';                   // checks front of string to see if negative, assign negativity boolenan
    for (int i = 0; i < str.size(); i++) {      // iterates through the string and add into LngInt
        if (isdigit(str[i]))                    // only accepts number chars
            digits.addBack(str[i]);
    }
    remove0s();                                 // remove leading zeros if there are any
}

LongInt::LongInt( const LongInt &rhs ){         // Copy Constructor, accepts LongInt class as parameter
    this->digits = Deque<char>(rhs.digits);     // assign digits
    this->negative = rhs.negative;              // assign negativity
    remove0s();                                 // removing leading zeros if there are any
}

LongInt::~LongInt(){                            // Destructor
    digits.clear();                             // clears all digits from linked list
    negative = false;                           // resets negativity to default
}

void LongInt::remove0s( ){                      // remove leading zeros
    while( digits.getFront() == '0') {          // while front == 0 remove the zeros. This will only do it once in the beginning of number
        if (digits.size() != 1)                 // if all numbers are == 0, leave one
            digits.removeFront();
        else
            break;
    }
}

LongInt LongInt::operator+( const LongInt& rhs ) const { // overloaded add operator for LongInt
    LongInt current1, current2;
    if ( this->compareList(rhs) >= 0 ) {                // places larger integer in current 1 position
        current1 = *this;                               // assign to current to not not change constant
        current2 = rhs;
    }
    else{
        current2 = *this;
        current1 = rhs;
    }
    LongInt result;                                     // resultant list
    result.negative = current1.negative;                // assign negativity
    int carry = 0, sum=0, add1, add2;
    while (current1.digits.getFront() !=  NULL|| current2.digits.getFront() != NULL) //while both lists exist
    {
        add1 = 0;                                                           // temp variables for what is being added together
        add2 = 0;
        if ( current1.digits.getFront()!= NULL){                             // checks if list exist because while
            add1 = current1.getBackInt();                                   // statement only require one to continue
        }
        if ( current2.digits.getFront()!= NULL){
            add2 = current2.getBackInt();                                   // assign back to temp variable
        }
        sum = carry + add1 + add2;                                          // assign sum with total from carry, add1, and add2
        carry = (sum >= 0)? ((sum >= 10)? 1 : 0) : ((sum <= -10)? -1 : 0);  // if sum is positive && >= 10 carry = 1, vice versa for negative
        if ( current1.negative != current2.negative){                       // if negativity is not the the same, it is not a regular add. adding negative# to positive# and vice versa
            if (current1.negative == 0){                                    // if current1 neg=false. the larger number is a positive number
                if ( sum < 0){
                    sum = 10 + sum;                                         // if sum is negative number
                    carry = -1;                                             // carry over -1
                }
            }
            else{                                                           // else larger number is negative
                if ( sum > 0){                                              // if sum is positive, add to negative number
                    sum = -10 + sum;                                        // the cary over will be positive 1
                    carry = 1;
                }
            }
        }
        char sum1 = '0' + ( ( (sum < 0 ) ? -sum : sum) % 10);               // convert single digit integer back to char
        result.digits.addFront(sum1);                                       // add to temporary result list
        current1.digits.removeBack();                                       // remove the back of the list/number just added to new list
        current2.digits.removeBack();                                       // if nothing was added, list was null, and method with just return null
    }
    if( sum >= 10 )                                                         // add the last cary over
        result.digits.addFront('1');
    if( sum <= -10 )
        result.digits.addFront('1');
    result.remove0s();                                                      // remove any leading zeros resulting from adding
    return result;                                                          // return temporary long int result
}

LongInt LongInt::operator-( const LongInt& rhs )const{
    LongInt current1, current2;
    if ( this->compareList(rhs) >= 0 ) {                                    // places larger integer in current 1 position
        current1 = *this;
        current2 = rhs;
    }
    else{
        current2 = *this;
        current1 = rhs;
    }
    LongInt result;                                                         // resultant list
    result.negative = current1.negative;                                    // set negativity of results
    if (current1 == rhs && current1.negative == true) // if rhs > this && negative. set result to not negative, because - - == +
        result.negative = false;
    int carry = 0, sum=0, add1, add2;
    while (current1.digits.getFront() != NULL || current2.digits.getFront() != NULL) //while both lists exist
    {
        add1 = 0;
        add2 = 0;
        if ( current1.digits.getFront()!= NULL){
            add1 = current1.getBackInt();
        }
        if ( current2.digits.getFront()!= NULL){
            add2 = current2.getBackInt();
        }
        sum = carry + add1 - add2;
        carry = (sum >= 0)? ((sum >= 10)? 1 : 0) : ((sum <= -10)? -1 : 0);
        if ( current1.negative == current2.negative){
            if (current1.negative == 0){
                if ( sum < 0){
                    sum = 10 + sum;
                    carry = -1;
                }
            }
            else{
                if ( sum > 0){
                    sum = -10 + sum;
                    carry = 1;
                }
            }
        }
        char sum1 = '0' + ( ( (sum < 0 ) ? -sum : sum) % 10); // convert integer back to char
        result.digits.addFront(sum1);                         // add char
        current1.digits.removeBack();
        current2.digits.removeBack();
    }
    if( sum >= 10 )
        result.digits.addFront('1');
    if( sum <= -10 )
        result.digits.addFront('1');
    result.remove0s();
    return result;
}

LongInt& LongInt::operator=( const LongInt &rhs ){
    LongInt temp = LongInt(rhs);
    this->digits = temp.digits;
    this->negative = temp.negative;
    return *this;
}

bool LongInt::operator < ( const LongInt & rhs ) const{
    if (this->negative != rhs.negative)                 // if they are not both the same sign, smaller number is negative
        return (this->negative)? true : false;
    if (this->compareList(rhs) != 0){
        if ( this->compareList(rhs) < 0 ){              // if smaller integer size, smaller negative = false, smaller positive equals true.
            return (this -> negative) ?  false : true;
        }
        if ( this->compareList(rhs) < 0 ){              // if larger integer size, larger negative = true, smaller positive equals false
            return (this -> negative) ?  true : false;
        }
    }
    return false;                                       // list is equals
}

bool LongInt::operator<= ( const LongInt & rhs ) const{
    if (this->negative != rhs.negative)                 // if they are not both the same sign, smaller number is negative
        return (this->negative)? true : false;
    if (this->compareList(rhs) != 0){
        if ( this->compareList(rhs) < 0 ){              // if smaller integer size, smaller negative = false, smaller positive equals true.
            return (this -> negative) ?  false : true;
        }
        if ( this->compareList(rhs) < 0 ){              // if larger integer size, larger negative = true, smaller positive equals false
            return (this -> negative) ?  true : false;
        }
    }
    return true;                                        // list is equals
}

bool LongInt::operator> ( const LongInt & rhs ) const{
    if (this->negative != rhs.negative)                 // if they are not both the same sign, larger number is positive
        return (this->negative)? false : true;
    if (this->compareList(rhs) != 0){
        if ( this->compareList(rhs) < 0 ){              // if smaller integer size, smaller negative = true, smaller positive equals false.
            return (this -> negative) ?  true : false;
        }
        if ( this->compareList(rhs) < 0 ){              // if larger integer size, larger negative = false, smaller positive equals true
            return (this -> negative) ?  false : true;
        }
    }
    return false;                                       // list is equals
}

bool LongInt::operator>= ( const LongInt & rhs ) const{
    if (this->negative != rhs.negative)                 // if they are not both the same sign, larger number is positive
        return (this->negative)? false : true;
    if (this->compareList(rhs) != 0){
        if ( this->compareList(rhs) < 0 ){              // if smaller integer size, smaller negative = true, smaller positive equals false.
            return (this -> negative) ?  true : false;
        }
        if ( this->compareList(rhs) < 0 ){              // if larger integer size, larger negative = false, smaller positive equals true
            return (this -> negative) ?  false : true;
        }
    }
    return true; // list is equals
}

bool LongInt::operator== ( const LongInt & rhs ) const{
    if (this->negative != rhs.negative)                 // if they are not both the same sign, they are not equal
        return false;
    if (this->compareList(rhs) != 0)                    // if they are different sizes, they are not equal
        return false;
    return true;                                        // list is equals
}

bool LongInt::operator!= ( const LongInt & rhs ) const{
    if (this->negative != rhs.negative)                  // if they are not both the same sign, they are not equal
        return true;
    if (this->compareList(rhs) != 0)                     // if they are different sizes, they are not equal
        return true;
    return false;                                        // list is equals
}

ostream& operator<<( ostream &out, const LongInt& rhs ) {
    Deque<char> temp = Deque<char>(rhs.digits);
    if (rhs.negative && rhs.digits.getFront() != '0')
        out << '-';
    while (!temp.isEmpty())
        out << temp.removeFront();
    return out;
}

istream& operator>>( istream& in, LongInt &rhs ) {
    string input;
    in >> input;
    LongInt temp = LongInt(input);
    rhs.digits = temp.digits;
    rhs.negative = temp.negative;
    return in;
}

int LongInt::compareList(const LongInt & rhs) const {       // compares the size of two long ints independent of negativity.
    LongInt current1 = *this;                               // if equals return 0. less than return -1, more than return 1
    LongInt current2 = rhs;
    if (current1.digits.size() != current2.digits.size())   // if size is not the same compare with this to see which is larger
        return (current1.digits.size() > current2.digits.size()) ? 1 : -1 ;
    while(!current1.digits.isEmpty()){                                  // else size is equal
        if (current1.digits.getFront() > current2.digits.getFront())    // compare chars starting from the front.
            return 1;                                                   // if chars not equal compare this to see which is larger
        if (current1.digits.getFront() < current2.digits.getFront())
            return -1;
        current2.digits.removeFront();                                  // remove front continue down the long int
        current1.digits.removeFront();
    }
    return 0;                                                           // list is equal if it makes it through the while loop
}

int LongInt::getBackInt() const{                                        // help method to return back of list as a integer not a char
    char a = this->digits.getBack();
    int i = a - '0';
    if (this->negative)
        return  -i;
    else
        return i;
}
