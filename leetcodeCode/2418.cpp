// 给你一个字符串数组 names ，和一个由 互不相同 的正整数组成的数组 heights 。两个数组的长度均为 n 。

// 对于每个下标 i，names[i] 和 heights[i] 表示第 i 个人的名字和身高。

// 请按身高 降序 顺序返回对应的名字数组 names 。


#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> indices(n);
        // iota() 用于创建有序数组(0, n)
        iota(indices.begin(), indices.end(), 0);
        // 通过排序，将heights的序号按照高度输入进去
        sort(indices.begin(), indices.end(), [&](int x, int y) {
            return heights[x] > heights[y];
            });
        // 创建新数组，并按照indices中存储的序号顺序将names输出出去
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = names[indices[i]];
        }
        return res;
    }
};