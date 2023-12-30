#include "bits/stdc++.h"
#include <iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size(), x = 0, y = 1;
    int left = 0, right = n-1, count = 0;
    while(left < right){
        if(s[left] != s[right]){
            if(left - 'a' > right - 'a'){
                s[left] = s[right];
            }
            else s[right] = s[left];
            count++;
        }
        left++;
        right--;
    }
    if(count == 2){cout << s << endl; return 0;}
    for(int i = 2; i < n; i++){
        int temp1 = x;
        x = s[i] - 'a' > s[x] - 'a' ? i : x;
        int temp2 = i==x ? temp1 : i;
        y = s[temp2] - 'a' > s[y] - 'a' ? temp2 : y;
    }
    if(x + y == n - 1){
        s[x] = 'a';
        s[y] = 'a';
    }
    cout << s <<endl;
    return 0;
}
