
#include <iostream>
#include "longint.h"
using namespace std;
int main( ) {
    LongInt a, b("-200"), c("-00"), e( "-0099999999999999999999999999999999x" );
    cout << "---Testing instream and reassigning default constructor: --- " << endl;
    cout << endl;
    cout << "enter for a: ";
    cin >> a;
    cout << "a = " << a << endl;
    cout<<endl;
    cout << "---Testing parameter constructor , remove0s, only taking integers in the long int: --- " << endl;
    cout << endl;
    cout << "input parameter = -200 : b = " << b << endl;
    cout << "input parameter = -00 : c = " << c << endl;
    cout << "input parameter = -0099999999999999999999999999999999x : e = " << e << endl;
    cout<<endl;
    cout << "---Testing assignment operator: --- " << endl;
    cout << endl;
    cout << "f = b 'expected' = -200" << endl;
    LongInt f = b;
    cout << "test: f = " << f << endl;
    cout<<endl;
    cout << "---Testing add adn subtract overload: --- " << endl;
    cout << endl;
    cout << a << " + " << b << " =  " << ( a + b ) << endl;
    cout << a << " - " << b << " =  " << ( a - b ) << endl;
    cout << b << " - " << a << " =  " << ( b - a ) << endl;
    cout << b << " + " << a << " =  " << ( b + a ) << endl;
    cout<<endl;
    cout << "---Testing boolean overload: --- " << endl;
    cout << endl;
    cout << a << " == " << c << " =  " << ( a == c ) << endl;
    cout << a << " != " << c << " =  " << ( a != c ) << endl;
    cout << a << " > " << c << " =  " << ( a > c ) << endl;
    cout << a << " >= " << c << " =  " << ( a >= c ) << endl;
    cout << a << " < " << c << " =  " << ( a < c ) << endl;
    cout << a << " <= " << c << " =  " << ( a <= c ) << endl;
    cout<<endl;
    cout << "---Testing if contains number longer than int: --- " << endl;
    cout << endl;
    cout << "f = f - 1 = " << ( f = f + *( new LongInt( "-1" ) ) ) << endl;
    cout << "e = " << e << endl;

}

