#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        long long n = 1;
        int m = 1;
        while (n % k != 0) {
            n = (n * 10 + 1) % k;
            m++;
        }
        return m;
    }
};