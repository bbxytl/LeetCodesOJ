#include <algorithms.h>

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(num.size()<4) return res;//参数检验
        sort(num.begin(),num.end()); //先排序

        int beg , end , sum;
        vector<int> tmp(4,0);
        for(int i = 0;i<num.size()-3;++i){
            for(int j=i+1;j<num.size-2;++j){

            }

            if((i>0) && num[i]==num[i-1]) continue;
            beg = i + 1;
            end = num.size()-1;
            while(beg < end){
                sum=num[beg] + num[end] + num[i];
                if( sum< target)        ++beg;
                else if(sum > target)   --end;
                else{
                    tmp[0] = num[i];
                    tmp[1] = num[beg];
                    tmp[2] = num[end];
                    res.push_back(tmp);
                    // 同样是去除重复数字的再次查找，避免结果集合中出现重复解
                    while(beg<end && num[beg]==tmp[1]) ++beg;
                    if(beg>=end) break;
                }
            }
        }
        return res;
    }
};
