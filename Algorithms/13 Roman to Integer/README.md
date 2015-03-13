# [Roman to Integer](https://leetcode.com/problems/integer-to-roman/)
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
意思就是：
给出一个罗马数字，返回其对应的整数 num( 0<=num<=3999)表示；
罗马数字范围从 0-->3999 
罗马数字有：  

|I |V |X |L |C |D |M |   
|--|--|--|--|--|--|--|   
|1 |5 |10|50|100|500|1000|   
   
- **[Math](https://leetcode.com/tag/math/)** 
- **[String](https://leetcode.com/tag/string/)**


##Solutions

- **[1 Roman to Integer -- 59ms](https://leetcode.com/submissions/detail/22923182/)**
    - 这种方法是对罗马数字从头到尾的扫描一遍。分析一下可以知道，只有 **4** 和 **9** 才会出现小一点的罗马数字出现在大的罗马数字的前面！比如：`CD=400` 其中 `C=100 , D=500` ，此时需要的后一个罗马数字减去前面一个罗马数字，其他情况都是一直加的。代码如下：
    ```cpp
    class Solution {
    public:
        int romanToInt(string s) {
            int idx=0,n=s.length();
            if(s.length()<=0)return 0;
    
            string roman="IVXLCDM";
            int  nums[] ={1,5,10,50,100,500,1000};
            int  res=0;
            //idx=roman.find(s.at(0));
            //if(idx<0||idx>6)return 0;
            //if(n==1){
                //return nums[idx];
            //}
            int num1,num2;
            idx=0;
            while(idx<n-1){ // 需要考虑 idx+1 的越界情况
                num1=roman.find(s[idx]);
                num2=roman.find(s[idx+1]);
                if(num2>num1){
                    res=res+(nums[num2]-nums[num1]);
                    idx+=2;
                }else{
                    res=res+nums[num1];
                    ++idx;
                }
            }
            if(n-1==idx){ //需要考虑可能剩下的最后一个罗马数字
                num1=roman.find(s[n-1]);
                res+=nums[num1];
            }
            return res;
        }
    };

    ```

- **[2 Roman to Integer -- 49ms](https://leetcode.com/submissions/detail/22924998/)**
    - 方案1中需要考虑 idx+1 的越界情况，所以还要在最后再增加一个判断，且使用的是从前向后扫描罗马数字字串；那如果是从后向前扫描罗马数字字串呢？思想会不会简单一点呢？分析一下可以看出，从后向前扫描，可以一直加下去，除了一种情况：当前扫描的数小于上一个扫描的数！也就是说只有这一个条件了，不需要再判断什么越不越界的问题了。如：`MCMVI=1906` ， 扫描 `V` 时 `V>I`(在罗马数字中，以下同)，所以直接加，结果为：**6**，扫描 `M` 也一样，结果为**1006**,接下来扫描到 `C` ，此时 `C<M` ,所以应是减去 `C` ，结果是**906**，最后再加 `M` ，得到结果：**1906**。要做的，只是记录下上一次的罗马数字。代码如下：
    ```cpp
    class Solution {
    public:
        int romanToInt(string s) {
            if(s.length()<=0)return 0;
            string roman="IVXLCDM";
            int  nums[] ={1,5,10,50,100,500,1000};
            int  n=s.length();
            int  res=0, idx=n-1, pre=0, ndx;
            while(idx>=0){
                ndx=roman.find(s[idx]);
                if(pre>ndx){
                    res-=nums[ndx];
                }else{
                    res+=nums[ndx];
                }
                pre=ndx;
                --idx;
            }
            return res;
        }
    }; 
    ```
- **[3 Roman to Integer -- 53ms](https://leetcode.com/submissions/detail/22928879/)**
    - 查阅了网友的解答，发现这一个方式挺好的，思路也很简单：
        - 逐个遍历罗马数字串，根据当前遍历到的字符，进行对应的累加操作。
        - 罗马数字共 7 个符号，`IVXLCDM` ，如果遍历到罗马数字 w ，则判断之前已经求出的数字 res 是否小于 w ，如果小于，则 加上 w ：`res=res+w`，否则减去 w  。原因是：因为是从后向前遍历，所以我们已经遍历出来的数字肯定是会小于下一进位的数字的，比如 189 ，89再大，也没有100大！所以此算法使用的就是这种思想，一旦出现违法了这种情况，那就是出现了 **4** 或者 **9** 的情况。说明我们加多了，那就要减去。说的可能比较不好完全理解，看代码：
    ```cpp
    class Solution {
    public:
        int romanToInt(string s) {
            int res = 0 ,n=s.length();
            for (int i = n - 1; i >= 0; --i) {
                char c = s.at(i);
                switch (c) {
                case 'I':
                    res += (res >= 5 ? -1 : 1);
                    break;
                case 'V':
                    res += 5;
                    break;
                case 'X':
                    res += 10 * (res >= 50 ? -1 : 1);
                    break;
                case 'L':
                    res += 50;
                    break;
                case 'C':
                    res += 100 * (res >= 500 ? -1 : 1);
                    break;
                case 'D':
                    res += 500;
                    break;
                case 'M':
                    res += 1000;
                    break;
                }
            }
            return res;
        }
    };
    ```    

- 看了一下其他的代码，大致的思想都是上面的方法，可能还有我没发现的。只是代码编写的形式不同而已。