#include <iostream>
using namespace std;

class A{
public:
    A(int a_, int b_) : a(a_), b(b_){};

    int get_a() const{
        return this->a;     
    }

    static int get_c(){
        return c;
    }

    static void  add_c(int x){
        c += x; 
    }

private:
    int a;
    const int b;
    static int c;
};

int A::c = 2;

int A::get_c(4);

const int get(int x){
    return x + 1;
}

int main(){
    A a(1, 2);
    cout << sizeof(A) << endl;
    A b(2,3);

    cout << a.get_c() << " " << b.get_c() << endl;
    a.add_c(4);
    cout << a.get_c() << " " << b.get_c() << endl;

    return 0;
}

int get_test(){
    static a;
    return 0;
}