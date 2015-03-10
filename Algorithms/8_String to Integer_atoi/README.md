# [String to Integer (atoi)](https://oj.leetcode.com/problems/string-to-integer-atoi/)
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.  

**Requirements for atoi:**
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

- **[Math](https://oj.leetcode.com/tag/math/)** 
- **[String](https://oj.leetcode.com/tag/string/)**


##Solutions

- **[String to Integer -- 16ms](https://leetcode.com/submissions/detail/22695579/)**
    - 首先判断字符串是否为空，然后去除字符串首部的空格，判断第一个非空字符是否为：` - , + , 数字 `。如果第一个非空字符不是这三种，则返回**0**。
    - 如果是`-`，则最终数字为负数；
    - 如果是`+，数字 `，则最终数字为正数；
    - 这里要考虑数字以`0`开头的，要在最后数字的处理中去除其影响。
    - 同时要考虑到字符串中的数字，如果全部转成整型，会不会出现越界溢出的情况，所以要进行溢出判断，这里根据整型是正数还是负数进行了判断，大于最大正数，则返回最大数，小于最小负数，则返回最小负数。
- **[String to Integer (atoi) 2 -- 17ms](https://leetcode.com/submissions/detail/22697529/)**  
    - 使用了`stringstream`类，包含在头文件`#include <sstream>`
    - **STL**及其简洁的代码。
- **[String to Integer (atoi) 3 -- 15ms](https://leetcode.com/submissions/detail/22698066/)**  
    - 及其巧妙的防溢出判断，如果末尾大于7，则如果是正数，肯定溢出，返回**INT_MAX**；如果是负数，即使不溢出，也是要返回**INT_MIN**。
