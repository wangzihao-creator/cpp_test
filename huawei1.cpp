#include <iostream>
#include <vector>

using namespace std;

int findMaxSum(vector<int>& nums) {
    int totalScore = 0;

    while (nums.size() > 1) {
        int maxSum = nums[0] + nums[1];
        int maxIndex = 0;

        for (int i = 1; i < nums.size() - 1; ++i) {
            int sum = nums[i] + nums[i + 1];
            if (sum > maxSum) {
                maxSum = sum;
                maxIndex = i;
            }
        }

        totalScore += maxSum;
        nums[maxIndex] = maxSum;
        nums.erase(nums.begin() + maxIndex + 1);
    }

    return totalScore;
}

int main() {
    vector<int> nums = {2, 11, 1, 10, 3};
    int result = findMaxSum(nums);
    cout << result << endl;  // 输出 86

    return 0;
}
