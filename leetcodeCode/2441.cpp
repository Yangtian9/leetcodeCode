#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int k = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (find(nums.begin(), nums.end(), -nums[i]) != nums.end()) {
                k = max(k, nums[i]);
            }
        }
        return k;
    }
};