#include "bits/stdc++.h"
#include <iostream>
using namespace std;

class A {
public:
    int x,y,xde,d,c;
    virtual void test(){};
};

int main(){
    A *a = new A();
    char * p ;
    A aa;
    cout << sizeof(a) <<endl;
    cout << sizeof(A) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(a->c) <<endl;
    cout << sizeof(aa) <<endl;
    cout << sizeof(aa.c) <<endl;
    delete a;

    unique_ptr<A> x (new A);
    A* a = x.get();
    return 0;
}
