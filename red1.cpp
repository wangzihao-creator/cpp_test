#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_max(vector<bool> & post, int left , int k){
    auto pos_l = post.begin() + left;
    auto pos_r = pos_l + k;
    return (int)std::count(pos_l, pos_r, true);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> postList(n, 0);
    int maxEssence = 0;

    // 输入精华区间并标记帖子为精华状态
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l - 1; j < r-1; j++) {
            postList[j] = 1;
        }
    }

    maxEssence = get_max(postList, 0, k);

    for (int i = k; i < n; i++) {
        int temp = maxEssence;
        if(postList[i] == true) temp++;
        if(postList[i-k] == true) temp--;
        maxEssence = max(maxEssence, temp);
    }

    cout << maxEssence << endl;

    return 0;
}


//red1
// int main(){
//     int n, k;
//     cin >> n >> k;
//     long long res;
//     res = ((n*(k + n*k))/2);
//     cout << res << endl;
//     return 0;
// }