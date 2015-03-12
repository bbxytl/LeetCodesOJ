# [Integer to Roman](https://leetcode.com/problems/integer-to-roman/)

Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
意思就是：
给出一个整数 num( 0<=num<=3999)，返回其对应的罗马数字表示；
罗马数字有：  

|I |V |X |L |C |D |M |   
|--|--|--|--|--|--|--|   
|1 |5 |10|50|100|500|1000|   
   
- **[Math](https://leetcode.com/tag/math/)** 
- **[String](https://leetcode.com/tag/string/)**


##Solutions

- **[1 Integer to Roman -- 143ms](https://leetcode.com/submissions/detail/22860328/)**
    - 这个方式不知道为什么很慢，是我第一个想出的几乎相当于暴力的方法。
    ```cpp
    class Solution {
    public:
        string intToRoman(int num) {
            if(num<=0||num>3999)return string();
            map<int,string> one,two,three,four;  //这里使用的是 Map
            one[0]="";      two[0]="";      three[0]=""; 
            one[1]="I";     two[1]="X";     three[1]="C";       four[1]="M";
            one[2]="II";    two[2]="XX";    three[2]="CC";      four[2]="MM";
            one[3]="III";   two[3]="XXX";   three[3]="CCC";     four[3]="MMM";
            one[4]="IV";    two[4]="XL";    three[4]="CD";  
            one[5]="V";     two[5]="L";     three[5]="D";  
            one[6]="VI";    two[6]="LX";    three[6]="DC";  
            one[7]="VII";   two[7]="LXX";   three[7]="DCC";  
            one[8]="VIII";  two[8]="LXXX";  three[8]="DCCC";  
            one[9]="IX";    two[9]="XC";    three[9]="CM";
            
            int mod=0,idx=1;
            string rs="",tmp="";
            while(num>0){
                mod=num%10;
                switch(idx){
                    case 1:{
                        tmp=one[mod];
                        rs=tmp+rs;
                        break;
                    }
                    case 2:{
                        tmp=two[mod];
                        rs=tmp+rs;
                        break;
                    }
                    case 3:{
                        tmp=three[mod];
                        rs=tmp+rs;
                        break;
                    }
                    case 4:{
                        tmp=four[mod];
                        rs=tmp+rs;
                        break;
                    }
                }
                num=num/10;
                ++idx;
            }
            return rs;
        }
    };
    ```

    后来经过了测试，发现貌似主要原因在于使用了 **map**，所以在第二次测试中将 **map** 改为了 **string** 数组 
- **[2 Integer to Roman -- 68ms](https://leetcode.com/submissions/detail/22864442/)**
    - 果然，改进后，运行时间从原来的 **143ms** 变成了 **68ms** ,这是第一个改进：
    ```cpp
    //原来的 map
    map<int,string> one,two,three,four;  //这里使用的是 Map
    //改进后
    string* one=new string[10],*two=new string[10],*three=new string[10],*four=new string[4];  
    ```
- **[3 Integer to Roman -- 54ms](https://leetcode.com/submissions/detail/22862788/)**
    - 方法1和2中，使用了很大的空间来存储全部的罗马特殊数字，增加了空间复杂性，所以我就想，能不能不存储这些特殊数字，只存储最基本的罗马基数数字 `IVXLCDM` ，然后根据当前数字进行判断，生成对应的罗马数字。下面是这一思想的代码：
    ```cpp
    class Solution {
    public:
        string intToRoman(int num) {
            if(num<=0||num>3999)return string();
            string roman="IVXLCDM";  //存储基数
            string rs="",tmp="";
            int ndx=0,mod=0;  // ndx 用来记录当前基数（即第n位对应的最小罗马数字坐标）
            while(num>0){
                mod=num%10; //求余数
                if(ndx==6){ //千位只有 M
                    rs=string(mod,'M')+rs;
                    break;
                }
                if(mod==0){
                    tmp="";
                }else if(mod<4){
                    tmp=string(mod,roman[ndx]);
                }else if(mod==4){
                    tmp=string(1,roman[ndx])+string(1,roman[ndx+1]);
                }else if(mod<9){
                    tmp=string(1,roman[ndx+1])+string(mod-5,roman[ndx]);
                }else if(mod==9){
                    tmp=string(1,roman[ndx])+string(1,roman[ndx+2]);
                }
                rs=tmp+rs;
                ndx+=2; //基数向前进2个
                num/=10;
            }
            return rs;
        }
    };
    ```    

    - 这一思想中，有两点是需要考虑的：
        1. 千位只有 `M` ；
        2. 数字**`4 , 9`**很特殊；
    - 对于数字 **4** 来说，如果当前基数坐标为 **ndx** ，则其对应的罗马数字为：
    ```cpp
    string(1,roman[ndx])+string(1,roman[ndx+1]);
    ```
    比如当前位为十位，则 `ndx=2; roman[ndx]='X'; roman[ndx+1]='L' ;` 对应罗马数字为： **`XL`** 
    - 对于数字 **9** 来说，对应罗马数字为：
    ```cpp
    string(1,roman[ndx])+string(1,roman[ndx+2]);
    ```
    比如当前位为十位，则 `ndx=2; roman[ndx]='X'; roman[ndx+2]='C' ;` 对应罗马数字为： **`XC`** 
    - 小于 4 的数字 **mod**，则为 **mod** 个连续基数；
    - 大于 4 小于 9 的数字 **mod** ， 则为 一个 `roman[ndx+1]` 和 **mode-5** 个连续基数；
    - 同时，这个版本中，我发觉还是可以改进一下的，对于代码的改进，所以出现了方法4
- **[4 Integer to Roman -- 48ms](https://leetcode.com/submissions/detail/22863368/)**
    - 对于代码的进行，方法3中会产生大量的**string**临时变量，因此这里尽量的使用了迭代器和 string 的**insert**方法进行处理。代码运行效率得以再次提高：48ms
    ```cpp
    class Solution {
    public:
        string intToRoman(int num) {
            if(num<=0||num>3999)return string();
            char roman[]="IVXLCDM";
            string rs="";
            int ndx=0,mod=0;
            while(num>0){
                mod=num%10;
                if(ndx==6){
                    rs=string(mod,'M')+rs;
                    break;
                }
                if(mod<4){
                    rs=string(mod,roman[ndx])+rs;
                }else if(mod==4){
                    rs.insert(rs.begin(),roman[ndx+1]);
                    rs.insert(rs.begin(),roman[ndx]);
                    // rs=string(1,roman[ndx])+string(1,roman[ndx+1])+rs;
                }else if(mod<9){
                    // rs=string(1,roman[ndx+1])+string(mod-5,roman[ndx])+rs;
                    rs=string(mod-5,roman[ndx])+rs;
                    rs.insert(rs.begin(),roman[ndx+1]);
                }else if(mod==9){
                    rs.insert(rs.begin(),roman[ndx+2]);
                    rs.insert(rs.begin(),roman[ndx]);
                    // rs=string(1,roman[ndx])+string(1,roman[ndx+2])+rs;
                }
                ndx+=2;
                num/=10;
            }
            return rs;
        }
    };
    ```
   
- **[5 Integer to Roman -- 57ms](https://leetcode.com/submissions/detail/22863515/)**
    - 这是LeetCode上网友的答案，感觉跟简洁，同时算法也很容易理解，和这里第一种的思想很像：
    ```cpp
    class Solution {
    public:
        string intToRoman(int num) {
            string M[] = {"", "M", "MM", "MMM"};
            string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
            string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
            string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
            return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
        }
    };
    ```
    - 但这里有一个问题，就是这种方法的思想和第二种很像，但是运行时间却更少，于是我将第二种的方法又进行了改进，我感觉差异应该是出现在：第二种方法在赋值时是先定义后赋值，且使用了 **new** 操作符，这里没有！所以有了下一个简单的改进：
    - 方法二的四个字符串数组，使用方法 5 的方式定义赋值。运行后时间为 **58ms**，果然这个是原因！看来以后对于内容不是很多的字符数组应该优先不使用 new ，这里还要注意的是，我在第二种方法里 new 的那些个字符数组~~~，忘了一个很重要的操作：**delete** 。:scream:
- **[6 Integer to Roman -- 49ms](https://leetcode.com/submissions/detail/22863691/)**
    - 这个是网友的答案：
    ```cpp
    class Solution {
    public:
        string intToRoman(int num) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.    
            string result = "";
            int base[] = {1000,500,100,50,10,5,1,0};
            char baseC[] = {'M','D','C','L','X','V','I'};
            int basen = 0;
            while(num) {
                if(basen%2 == 0 && num/base[basen] == 4) {
                    result += baseC[basen];
                    result += baseC[basen-1];
                    num -= base[basen] * 4;
                } else if(num >= base[basen]) {
                    result += baseC[basen];
                    num -= base[basen];
                } else if(basen%2 == 0 && num / base[basen+2] == 9) {
                    result += baseC[basen+2];
                    result += baseC[basen];
                    num -= base[basen+2]*9;
                } else {
                    basen++;
                }
            }
            return result;
        }
    };
    ```
    - 代码呢，一下子看思路不是很清楚，感觉思想好像有点复杂。
    - 网友给出的思路是这样的：
        1. 如果 num 是 x 的 4 的倍数（其中，x=1000,100,10,1），则增加一个 x 对应的罗马数字和 5x 对应的对应的罗马数字；
            如：400是100的4倍，则增加一个100对应的罗马数字 C ，和5*100=500对应的罗马数字 D，则 400=CD  ;
        2. 如果 num > x ，则添加一个 x 对应的罗马数字；
            如: 6 > 5 ，则添加一个 5 对应的罗马数字 V ;
        3. 如果 num < x （x=1000,100,10,1），但是 num 是 x/10 的 9 倍，则添加一个 x/10 对应的数字和 x 对应的数字。
            如： 90 < 100 ，但 90==9*(100/10) ，则添加一个 (100/10)=10 对应的罗马数字 X 和一个 100 对应的罗马数字 C  ，则 90=XC；
    - 个人觉得这个算法有点复杂！不过还是挺高效的。这里学习一下思想。

