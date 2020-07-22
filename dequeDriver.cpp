//
// Created by Tony Tran on 12/9/19.
//
//
#include <iostream>
using namespace std;

#include <iostream>
#include "deque.h"
//#include "deque.cpp"

int main() {
    Deque<string> list1;
    cout << "---Testing add and remove methods and get size: --- " << endl;
    cout << endl;
    list1.addBack( "first" );
    list1.addFront( "second addfront" );
    list1.addBack( "third addback" );
    list1.addBack( "fourth addback" );
    cout << "added: 4 expected in list = 4 : test = " << list1.size( ) << endl;
    cout << " list 1 : ----"<< endl;
    list1.print();
    list1.removeBack();
    cout << "removed 1, expected in list = 3: test = " << list1.size( ) << endl;
    cout << " list 1 : ---- " <<endl;
    list1.print();
    list1.removeFront();
    cout << "removed 1 expected in list = 2 : test = " << list1.size( ) << endl;
    cout << " list 1 : ----"<<endl;
    list1.print();
    cout << endl;

    Deque<string> list2;
    cout << "--Testing default constructor and is empty-- " << endl;
    cout << endl;
    cout << " list 2 : ----"<< endl;
    cout << "isempty expect true = 1 test = "<< list2.isEmpty() << endl;
    cout<<endl;

    cout << "--Testing equals operator-- " << endl;
    cout << endl;
    cout << "list 2 = list 1 : expected in list = first,third addback :: test ="<< endl;
    list2 = list1;
    list2.print();
    cout<<endl;

    cout << "--Testing clear method-- " << endl;
    cout << endl;
    cout << "list2.clear(); list2 expected isEmpty = 1" << endl;
    list2.clear();
    cout << "list2.isEmpty = " << list2.isEmpty() << endl;
    return 0;
}