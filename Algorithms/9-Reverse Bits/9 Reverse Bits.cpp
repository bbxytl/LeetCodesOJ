
#include<bitset>
// 9ms
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> num(n);
        bitset<32> res(0);
        for(int i=0;i<32;++i){
            num.test(i)? res.set(31-i) : 0;
        }
        return res.to_ulong();
    }
};

// 12ms --思想来源：http://blog.csdn.net/morewindows/article/details/7354571
#include<bitset>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
        n = ((n & 0xFFFFFFFF) >> 16) | ((n & 0xFFFFFFFF) << 16);
        return n;
    }
};
