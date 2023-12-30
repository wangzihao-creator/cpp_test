#include <iostream>
#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, s, sum = 0, temp;
    cin >> n;
    set<int> points;
    for(int i = 0; i < n; i++){
        cin >> temp;
        points.emplace(temp);
    }
    cin >> s;
    for(int a : points){
        if(a < s){
            if(a < (s/2) + 1) sum += 2;
            else{
                if(!points.count(s-a)) sum += 2;
            }
        }
    }
    int res = s-1-sum;
    if(s != 1 && points.count(s/2)) res++; 
    cout << res <<endl;
}

// class A{
// public:
//     A(){
//         cout << "create" << endl;
//     }
//     A(const A& a){
//         cout << "copy" << endl;
//     }
//     ~A(){
//         cout << "delete" << endl;
//     }
// };

// A func(){
//     A a;
//     A b = a;
//     return b;
// }

// int main(){
//     A b = func();
// }