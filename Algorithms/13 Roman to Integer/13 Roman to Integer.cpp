class Solution {
public:
    int romanToInt_1(string s) {
        int idx=0,n=s.length();
        if(s.length()<=0)return 0;

        string roman="IVXLCDM";
        int  nums[] ={1,5,10,50,100,500,1000};
        int  res=0;
        idx=roman.find(s.at(0));
        if(idx<0||idx>6)return 0;
        if(n==1){
            return nums[idx];
        }
        int num1,num2;
        idx=0;
        while(idx<n-1){
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
        if(n-1==idx){
            num1=roman.find(s[n-1]);
            res+=nums[num1];
        }
        return res;
    }
};


class Solution {
public:
    int romanToInt_2(string s) {
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

class Solution {
public:
    int romanToInt_3(string s) {
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
