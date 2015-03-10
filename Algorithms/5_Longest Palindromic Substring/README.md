# [Longest Palindromic Substring](https://oj.leetcode.com/problems/longest-palindromic-substring/)

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

- **[String](https://oj.leetcode.com/tag/string/](https://oj.leetcode.com/tag/linked-list/)** 


##Solutions

- **[LongestSub -- 54ms](https://oj.leetcode.com/submissions/detail/22234254/)**
- **[LongestSub2 -- 56ms](https://oj.leetcode.com/discuss/26141/cpp-solution-56ms)**


##Analysis

1. [Longest Palindromic Substring Part I](http://leetcode.com/2011/11/longest-palindromic-substring-part-i.html)
2. [Longest Palindromic Substring Part II](http://www.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html)

###算法1：
**时间复杂度（$O(N^2)$**
**空间复杂度（$O(N^2)$**
```cpp
string longestPalindromeDP(string s) {
  int n = s.length();
  int longestBegin = 0;
  int maxLen = 1;
  bool table[1000][1000] = {false};//代表table[i][j]是否为回文串，s[i]和s[j]之间
  //所有元素本身都是长度为1的回文串
  for (int i = 0; i < n; i++) {
    table[i][i] = true;
  }
  //判断相邻的两个元素是否相同，如果相同，则这两个元素为长度为2的回文串，并设置最大回文长度为2，此时，仅检查相邻的两个元素
  for (int i = 0; i < n-1; i++) {
    if (s[i] == s[i+1]) {
      table[i][i+1] = true;
      longestBegin = i;
      maxLen = 2;
    }
  }
  //将回文长度递增，假设最大回文长度为 len ,判断是否有符合的回文
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i < n-len+1; i++) {
      int j = i+len-1;
      //对齐相等，且两元素之间的串为回文串
      if (s[i] == s[j] && table[i+1][j-1]) {
        table[i][j] = true;
        longestBegin = i;
        maxLen = len;
      }
    }
  }
  // 返回最大回文字串
  return s.substr(longestBegin, maxLen);
}
```

###算法2：
**时间复杂度（$O(N^2)$**
**空间复杂度（$O(1)$**
```cpp
/// 函数功能：
/// 给定一个字符串 s 和两个下标，以两个下标为中心进行左右扩展，
/// 查找相同元素
string expandAroundCenter(string s, int c1, int c2) {
  int l = c1, r = c2; //左，右
  int n = s.length();
  // 左下标向左移动，右下标向右移动，知道移动到出界或两下标对应的元素不相同
  while (l >= 0 && r <= n-1 && s[l] == s[r]) {
    l--;
    r++;
  }
  return s.substr(l+1, r-l-1);
  // 返回从最后一个相同的下标(l+1)开始，
  // 到对应的另一个元素之间的字串（长度为：r-(l+1)）
}
 
string longestPalindromeSimple(string s) {
  int n = s.length();
  if (n == 0) return "";
  string longest = s.substr(0, 1);  // a single char itself is a palindrome
  for (int i = 0; i < n-1; i++) {
    // 以当前下标为中心，查找回文串
    string p1 = expandAroundCenter(s, i, i); 
    if (p1.length() > longest.length())
      longest = p1;
    
    // 以 i 和 i+1 为中心，查找回文串
    string p2 = expandAroundCenter(s, i, i+1);
    if (p2.length() > longest.length())
      longest = p2;
  }
  return longest;
}
```

###算法3：（Manacher’s Algorithm）
**时间复杂度（$O(N)$**
**空间复杂度（$O(N)$**
算法将一个字符串**S**首先转换为另一个字符串**T**,对**T**求回文串。如在**S**的每两个元素之间插入一个字符**#**，并在首尾也插入一个**#**，生成新串**T**，这样，不论**S**的长度是奇数还是偶数，现在的**T**都是奇数。查找到最大回文串后，在去掉所有奇数位的**#**号即为所求**S**的最大回文串。
设置一个数组**P**用来存储以当前下标元素为中心的最大回文串长度，如：
```
T = # a # b # a # a # b # a #
P = 0 1 0 3 0 1 6 1 0 3 0 1 0
```
可以看到，最长串为:
```
P[6]=6;
maxSubStr="#a#b#a#a#b#a#";
去掉 # 号后为： "abaaba"
```
code:
```cpp
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    // 如果当前下标小于最右下标，则以P[i]为中心的回文串的半径长度至少为min(R-i, P[i_mirror])
    // 否则半径至少为0
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
  delete[] P;
  
  // T[centerIndex]=S[(centerIndex-1)/2]
  // T中最长字串为：T[centerIndex-maxLen] 到 T[ceterIndex+maxLen]
  // 对应S中为： S[((centerIndex-1)-maxLen)/2] 到 S[((centerIndex-1)+maxLen)/2]
  // 即求S的字串，从 ((centerIndex-1)-maxLen)/2 下标位开始，长度为maxLen。
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}
```