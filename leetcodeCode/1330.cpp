// 给你一个整数数组 nums 。「数组值」定义为所有满足 0 <= i < nums.length - 1 的  | nums[i] - nums[i + 1] | 的和。
//
// 你可以选择给定数组的任意子数组，并将该子数组翻转。但你只能执行这个操作 一次 。
//
// 请你找到可行的最大 数组值 。

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        for (int i = 0; i < n - 1; i++) {
            num += abs(nums[i] - nums[i + 1]);
        }
        int max1 = 0;
        for (int i = 0; i < n - 1; i++) {
            max1 = max(max1, abs(nums[0] - nums[i + 1]) - abs(nums[i] - nums[i + 1]));
            max1 = max(max1, abs(nums[n - 1] - nums[i]) - abs(nums[i] - nums[i + 1]));
        }
        int max2 = INT_MIN, min2 = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            int x = nums[i], y = nums[i + 1];
            max2 = max(max2, min(x, y));
            min2 = min(min2, max(x, y));
        }
        return num + max(max1, 2 * (max2 - min2));
    }
};