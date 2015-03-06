class Solution {
public:
    int reverse(int x) {
        if(x==0)return x;
        int h=x>>31;    //获取 x 的最高位，如果 x 为正，h=0 ，否则 h=-1
        x=(x^h)-h;      //求 x 的绝对值,否则下面的 (INT_MAX-one)因为one为一个负数，所以会越界
        int rs=0;
        while(x!=0){        //循环遍历 x 的每一位数字
            int one=x%10;   //求 x 的个位数字
            if(rs>(INT_MAX-one)/10)return 0;    //判断如果执行下一步是否越界，越界返回 0
            rs=one+rs*10;   //不越界则执行
            x=x/10;
        }
        return h?(~rs+1):rs;    //h=0,返回rs h=-1 返回rs的负值
    }
};


//2---14ms
class Solution {
public:
    int reverse(int x) {
        static const int overflow = INT_MAX / 10;
        const char mod = x < 0 ? -10 : 10;
        int r = 0;

        while (x) {
            if (r > overflow || r < -overflow)
                return 0;
            r = (x % mod) + (r * 10);
            x /= 10;
        }
        return r;
    }
};

//3--15ms
class Solution {
public:
    int reverse(int x) {
        static const int overflow = INT_MAX / 10;
        const char mod = x < 0 ? -10 : 10;
        int r = 0;

        while (x) {
            if (r > overflow || r < -overflow)
                return 0;
            r = (x % mod) + (r * 10);
            x /= 10;
        }
        return r;
    }
};
