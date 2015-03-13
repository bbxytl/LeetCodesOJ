class Solution {
public:
    string longestCommonPrefix_1(vector<string> &strs) {
        if(strs.size()<=0)return string();
        int idx=0;
        string res;
        char c;
        string s=strs.at(0);
        int n=s.size(),ns=strs.size();
        while(idx<n){
            c=strs.at(0).at(idx);
            for(int i=0;i<ns;++i){
                s=strs.at(i);
                if(idx<s.size())
                    if(s.at(idx)==c)continue;
                idx=n;
                break;
            }
            if(idx<n){
                res+=string(1,c);
            }
            ++idx;
        }
        return res;
    }
};

class Solution {
public:
    string longestCommonPrefix_2(vector<string> &strs) {
        if(strs.size()<=0)return string();
        int idx=0,base=0;
        string res;
        int ns=strs.size();
        while(idx<ns){
            if(strs.at(idx).size()<strs.at(base).size())
                base=idx;
            ++idx;
        }
        idx=0;
        char c;
        int n=strs.at(base).size();
        while(idx<n){
            c=strs.at(base).at(idx);
            for(int i=0;i<ns;++i){
                if(idx<strs.at(i).size())
                    if(strs.at(i).at(idx)==c)continue;
                idx=n;
                break;
            }
            if(idx<n){
                res.push_back(c);
            }
            ++idx;
        }
        return res;
    }
};


class Solution {
public:
    string longestCommonPrefix_3(vector<string> &strs) {
        if (strs.size() == 0) return "";
        string s;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 0; j < strs.size() - 1; j++) {
                if (strs[j + 1].length() <= i || strs[j][i] != strs[j + 1][i]) {
                    return s;
                }
            }
            s.push_back(strs[0][i]);
        }
        return s;
    }
};


class Solution {
public:
    string longestCommonPrefix_4(vector<string> &strs) {
        if (strs.size() == 0) return "";
        string s;
        int minlen=strs[0].length(),ns=strs.size();
        for(int i=0;i<ns;++i){
            minlen<strs[i].length() ? minlen=strs[i].length() :0 ;
        }
        ns-=1;
        for (int i = 0; i < minlen; ++i) {
            for (int j = 0; j < ns; ++j) {
                if (strs[j + 1].length() <= i || strs[j][i] != strs[j + 1][i]) {
                    return s;
                }
            }
            s.push_back(strs[0][i]);
        }
        return s;
    }
};
