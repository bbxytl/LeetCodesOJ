# [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)

Write a function to find the longest common prefix string amongst an array of strings.
求字符串数组中字符串的最长公共前缀。
   
- **[String](https://leetcode.com/tag/string/)**


##Solutions

- **[1 Longest Common Prefix -- 11~13ms](https://leetcode.com/submissions/detail/22946463/)**
    - 第一个映入大脑的是对每一个字符串，按字符位逐个比较，直到发现不相同的或者是有个字符串已经比较完了时，说明最大公共前缀已经找到。则时间复杂度是：  $O(MN)$  其中 **M** 是字符数组的个数，**N** 是字符数组中最短字符串的长度。按这种思想的代码如下：
    ```cpp
    class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if(strs.size()<=0)return string();
            int idx=0;
            string res;
            char c;
            string s=strs.at(0); //以第一个字串作为比较的基
            int n=s.size(),ns=strs.size();
            while(idx<n){
                c=strs.at(0).at(idx); //获取一个字符
                for(int i=0;i<ns;++i){ //循环和其他字串中对应位的字符进行比较
                    s=strs.at(i);
                    if(idx<s.size())
                        if(s.at(idx)==c)continue;
                    idx=n; //如果出现不相等或有字符串已结束，则退出循环
                    break;
                }
                if(idx<n){
                    res.push_back(c);
                }
                ++idx;
            }
            return res;
        }
    };
    ```
    - 分析了一下，这里占用时间的有两个：
        1. 每一次迭代时的字符串拷贝；
        2. 如果最短的字符串在最后一个比较或靠后比较，则就白白浪费了太多比较了，特别是字符串数组很大的时候。
    - 所以对方案 1 进行了改进，有了下面的方案 2 。 

- **[2 Longest Common Prefix -- 8ms](https://leetcode.com/submissions/detail/22947207/)**
    - 这种方案首先找到字串数组中最短的那个，并记录下其在字符数组中的下标，不进行拷贝，减少空间复杂度，同时，节省一点时间。
    - 其次，去除掉所有的字符串拷贝操作，除用于在大字符串数组情况下的优化时需要的变量外，尽量减少空间使用。可以看到，运行时间一下子减到了 **8ms**。说明还是有效果的。
    - 代码如下：
    ```cpp
    class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if(strs.size()<=0)return string();
            int idx=0,base=0;
            string res;
            int ns=strs.size();
            while(idx<ns){
                if(strs.at(idx).size()<strs.at(base).size())
                    base=idx;
                ++idx;
            }
            idx=0;
            char c;
            int n=strs.at(base).size();
            while(idx<n){
                c=strs.at(base).at(idx);
                for(int i=0;i<ns;++i){
                    if(idx<strs.at(i).size())
                        if(strs.at(i).at(idx)==c)continue;
                    idx=n;
                    break;
                }
                if(idx<n){
                    res.push_back(c);
                }
                ++idx;
            }
            return res;
        }
    }; 
    ```
- **[3 Longest Common Prefix -- 8ms](https://leetcode.com/submissions/detail/22945770/)**
    - 查阅了网友的解答，发现这样一种思路：
    - 以第一个字串为比较基的长度判定，逐位判断，如果发现有一个字串的长度小于或等于当前位，说明这个字串结束了，自然也应该结束函数；
    - 如果没有结束，逐位判断的方式使用：判断当前字串的当前位和下一个字串的当前位比较是否相同，不相同则结束。可以看到，效率还是很高的。
    ```cpp
    class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if (strs.size() == 0) return "";
            string s;
            for (int i = 0; i < strs[0].length(); i++) {
                for (int j = 0; j < strs.size() - 1; j++) {
                    if (strs[j + 1].length() <= i || strs[j][i] != strs[j + 1][i]) {
                        return s;
                    }
                }
                s.push_back(strs[0][i]);
            }
            return s;
        }
    };
    ```   
    - 代码看起来很简洁，但我认为，代码还应该有改进方式，比如应该先遍历出最短的那个字串，同时，求`strs.size()`尽量放到循环外面来，因为其是一个常量，在内层循环中，如果字串数组很大，就会产生一定的无法消除的效率影响。同时，我更喜欢使用 `++i` 代替 `i++` ，因为这样，能减少一次寄存器存取。也许当数据量少时看不出来这些差距，但代码在手，能优尽优嘛！不过处理了这些，好像就没原来的好看了~~:smile: 
    - 那么优化后得到如下**[代码](https://leetcode.com/submissions/detail/22948616/)（8ms）**
    ```cpp
    class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if (strs.size() == 0) return "";
            string s;
            int minlen=strs[0].length(),ns=strs.size();
            for(int i=0;i<ns;++i){
                minlen<strs[i].length() ? minlen=strs[i].length() :0 ;
            }
            ns-=1;
            for (int i = 0; i < minlen; ++i) {
                for (int j = 0; j < ns; ++j) {
                    if (strs[j + 1].length() <= i || strs[j][i] != strs[j + 1][i]) {
                        return s;
                    }
                }
                s.push_back(strs[0][i]);
            }
            return s;
        }
    };
    ```

##**附录**
- **[开源GitHub](https://github.com/bbxytl/LeetCodesOJ/blob/master/README.md)** 
- **[GitHub博客](http://bbxytl.github.io/)**
