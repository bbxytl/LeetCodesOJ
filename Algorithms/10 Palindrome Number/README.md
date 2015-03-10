# [Palindrome Number](https://leetcode.com/problems/palindrome-number/)
Determine whether an integer is a palindrome. Do this without extra space.
###Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

- **[Math](https://leetcode.com/tag/math/)** 


##Solutions

- **[Palindrome -- 133ms](https://leetcode.com/submissions/detail/22699575/)**
    - 如果是负数，由于有`-`号，所以肯定不是回文整型。所以只能是**0**或正数。
    - 如果是回文的，则从前向后看和从后向前看这两个整数都是应该相同的。如果不同，则一定不是回文的。
- **[Palindrome -- 122ms](https://leetcode.com/submissions/detail/22699691/)**
    - 此种思想，是类似于判断一个字符串是否为回文字符串。从两头向中间比较对应位上的数字是否相同，如果直到中间都相同，则是回文，否则有任一个不同的，就不是回文。
