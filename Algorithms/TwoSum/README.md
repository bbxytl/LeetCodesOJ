# [Two Sum](https://oj.leetcode.com/problems/two-sum/)
---
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

**Input**: ` numbers={2, 7, 11, 15}, target=9 `   
**Output**: ` index1=1, index2=2 `

- **[Array](https://oj.leetcode.com/tag/array/)**   
- **[Hash Table](https://oj.leetcode.com/tag/hash-table/)**


##Slou

- **TwoSum**
- **[TwoSum1](https://oj.leetcode.com/discuss/17487/got-right-answer-in-my-vs2005-but-wrong-in-oj-in-two-sum-case-3-0?show=17487#q17487)**
    - 主要使用了迭代器**[`vector<int>::iterator`](http://www.cplusplus.com/reference/iterator/iterator/?kw=iterator) **
- **[TwoSum2](https://oj.leetcode.com/discuss/26254/my-c-code-unordered_map-used-o-n-space-o-n-time)**
    - 使用了c++11新STL模板类**[`unordered_map`](http://www.cplusplus.com/reference/unordered_map/unordered_map/) **

