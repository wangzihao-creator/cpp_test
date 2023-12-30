#include <iostream>
#include <string>
#include<vector>
using namespace std;

// #define numberOfNodes 11

uint32_t numberOfNodes = 11;

std::vector<std::vector<bool>> Matrix((int)numberOfNodes, std::vector<int>(numberOfNodes));

class A{
public:
    int a;
    int solveA();
    int solveB();
    static int b;
};

static int A::b = 30;

int A::solveA(){
    a =  10;
    return a;
}

int A::solveB(){
    a = 20;
    b = 40;
    return b;
}

int main(){
    A a;
    int a = a.solveA();
    int b = a.solveB();
    return 0;
}



int max(int a, int b){
    
}