#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


class Solution {
public:
    int fun(vector<int>& nums, int firstLen, int secondLen) {
        int num = nums.size();
        int sum1 = accumulate(nums.begin(), nums.begin() + firstLen, 0);
        int sum1_max = sum1;
        int sum2 = accumulate(nums.begin() + firstLen, nums.begin() + firstLen + secondLen, 0);
        int max_sum = sum1_max + sum2;
        for (int i = firstLen, j = firstLen + secondLen; j < num; i++, j++) {
            sum1 += nums[i] - nums[i - firstLen];
            sum1_max = max(sum1_max, sum1);
            sum2 += nums[j] - nums[j - secondLen];
            max_sum = max(max_sum, sum1_max + sum2);
        }
        return max_sum;

    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(fun(nums, firstLen, secondLen), fun(nums, secondLen, firstLen));
    }
};