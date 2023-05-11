// 给定一个二进制字符串 s 和一个正整数 n，如果对于 [1, n] 范围内的每个整数，其二进制表示都是 s 的 子字符串 ，就返回 true，否则返回 false 。
// 子字符串 是字符串中连续的字符序列。

#include <iostream>
#include <bitset>
#include <string>

using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        for (int i = 1; i <= n; i++) {
            auto bin = bitset<32>(i).to_string();
            bin = bin.substr(bin.find('1'));
            if (s.find(bin) == string::npos)
                return false;
        }
        return true;
    }
};

// size_t find(const string& str, size_t pos = 0) const noexcept;
// 其中，str是要查找的子串，pos是搜索的起始位置，默认值为0。该函数返回子串在字符串中第一次出现的位置，如果未找到则返回string::npos。

// string substr(size_t pos = 0, size_t len = npos) const;
// pos是要截取的子串的起始位置，len是要截取的子串的长度，默认值为string::npos，表示截取从pos到字符串结尾的所有字符。

// bitset<32>(i)的作用是将整数i转换为一个32位的二进制串
// 转换为二进制串后，可以使用to_string函数将其转换为一个字符串