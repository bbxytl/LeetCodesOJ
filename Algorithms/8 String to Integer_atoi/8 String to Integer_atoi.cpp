class Solution {
public:
       int atoi(string str) {
        if(str.length()<=0)return 0;
        int n=0,sig=1,idx=0;
        string::iterator it=str.begin();
        bool star=false;
        while(it!=str.end()){
            if(!star){
                if(*it==32){ ++it;continue; }
                if(*it=='-'){     sig=-1;star=true;idx=it-str.begin()+1;++it;continue;}
                else if(*it=='+'){sig=1; star=true;idx=it-str.begin()+1;++it;continue;}
                if((*it-'0')>9 || (*it-'0'<0)) return 0;
                else{
                    idx=it-str.begin();
                    sig=1;
                    star=true;
                    ++it;
                    continue;
                }
            }
            if((*it-'0')>9 || (*it-'0'<0))break;
            ++it;
        }
        string s=str.substr(idx,it-str.begin()-idx);
        it=s.begin();
        while(it!=s.end()){
            idx=*it-'0';
            if(sig==1){
                if(n>(INT_MAX-idx)/10)return INT_MAX;
            }else{
                if((n*sig)<(INT_MIN+idx)/10)return INT_MIN;
            }
            n=n*10+(*it-'0');
            ++it;
        }
        return n*sig;
    }
};

#include <sstream>
class Solution {
public:
    int atoi_2(string str) {
        int rs;
        stringstream strStream;
        strStream<<str;
        strStream>>rs;
        return rs;
    }
};


class Solution {
public:
    int atoi_3(string str) {
        int sign = 1, base = 0, i = 0;
        while (str[i] == ' ') { i++; }
        if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i++] == '-');
        }
        while (str[i] >= '0' && str[i] <= '9') {
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            base  = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};
