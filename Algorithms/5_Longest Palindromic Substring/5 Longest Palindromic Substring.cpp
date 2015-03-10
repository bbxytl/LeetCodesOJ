class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=0)return "";
        string t="^";
        string::iterator it=s.begin();
        while(it!=s.end()){
            t+="#";
            t+=*it;
            ++it;
        }
        t+="#$";
        int n=t.length();
        int *P=new int[n];
        int cent=0,R=0;
        for(int i=1;i<n-1;++i){
            int j=cent-(i-cent);
            P[i]=(R>i?min(P[j],R-i):0);
            while(t[i+P[i]+1]==t[i-P[i]-1]){
                ++P[i];
            }
            if(R<(i+P[i])){
                R=i+P[i];
                cent=i;
            }
        }

        int maxlen=0;
        cent=0;
        for(int i=1;i<n-1;++i){
            if(P[i]>maxlen){
                maxlen=P[i];
                cent=i;
            }
        }
        delete[] P;
        return s.substr((cent-1-maxlen)/2,maxlen);
    }
};
