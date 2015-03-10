#[Longest Substring Without Repeating Characters ](https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/)

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
- **Longest_1 -- 29ms(cpp)**
- [**Longest_2 -- 53ms(cpp)**](https://oj.leetcode.com/discuss/8092/my-dp-o-n-solution-without-using-stack?show=8092#q8092)
```
My solution uses DP. The main idea is as follows: I construct a array longest[], for any longest[i], it stores the longest length of valid parentheses which is end at i. 
And the DP idea is : 
If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one. 
Else if s[i] is ')' 
If s[i-1] is '(', longest[i] = longest[i-2] + 2 
Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2] 
For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6. 
```

