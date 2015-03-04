class Solution {
public:
	int lengthOfLongestSubstring(string s) {
            int len=s.length();
            if(len<=0)return 0;
            int beg=0,next=0,dis=0;
            string::iterator it;
            while(next<len){
#if 1
                //使用这段代码(迭代器)--30ms
                it=find(s.begin()+beg,s.begin()+next,s.at(next));
                if(it!=s.begin()+next){
                    int idx=it-s.begin();
                    if(idx>=0){
                        int newdis=next-beg;
                        if(dis<newdis)dis=newdis;
                        beg=beg+(idx-beg+1);
                    }
                }
#endif
#if 0
                //使用这段代码(手动)--48ms
                //                for(int i=next-1;i>=beg;--i){
                //                    if(s.at(i)==s.at(next)){
                //                        int newdis=next-beg;
                //                        if(dis<newdis)dis=newdis;
                //                        beg=beg+(i-beg+1);
                //                        break;
                //                    }
                //                }
#endif
                ++next;
            }
            int newdis=next-beg;
            if(dis<newdis)dis=newdis;
            return dis;
        }
};

/// 网友：https://oj.leetcode.com/discuss/8092/my-dp-o-n-solution-without-using-stack?show=8092#q8092
/// My solution uses DP. The main idea is as follows: I construct a array longest[], for any longest[i], it stores the longest length of valid parentheses which is end at i.
/// And the DP idea is :
/// If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.
/// Else if s[i] is ')'
///      If s[i-1] is '(', longest[i] = longest[i-2] + 2
///     Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]
/// For example, input "()(())", at i = 5, longest array is [0,2,0,0,2,0], longest[5] = longest[4] + 2 + longest[1] = 6.


int longestValidParentheses(string s) {
    if(s.length() <= 1) return 0;
    int curMax = 0;
    vector<int> longest(s.size(),0);
    for(int i=1; i < s.length(); i++){
        if(s[i] == ')' && i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
            longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
            curMax = max(longest[i],curMax);
        }
    }
    return curMax;
}
