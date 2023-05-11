// ����һ���ַ������� names ����һ���� ������ͬ ����������ɵ����� heights ����������ĳ��Ⱦ�Ϊ n ��

// ����ÿ���±� i��names[i] �� heights[i] ��ʾ�� i ���˵����ֺ���ߡ�

// �밴��� ���� ˳�򷵻ض�Ӧ���������� names ��


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
        // iota() ���ڴ�����������(0, n)
        iota(indices.begin(), indices.end(), 0);
        // ͨ�����򣬽�heights����Ű��ո߶������ȥ
        sort(indices.begin(), indices.end(), [&](int x, int y) {
            return heights[x] > heights[y];
            });
        // ���������飬������indices�д洢�����˳��names�����ȥ
        vector<string> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = names[indices[i]];
        }
        return res;
    }
};