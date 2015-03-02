#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;
//自解法 1
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> index(numbers);
        sort(index.begin(),index.end());
        int ns=numbers.size();
        int mid=target/2;
        bool bl=false;

        for(int i=0;i<ns;++i){
            for(int j=ns-1;j>i;--j){
                if(index.at(i)+index.at(j)==target){
                    ns=index.at(i);
                    mid=index.at(j);
                    bl=true;
                    break;
                }
                if(index.at(i)+index.at(j)<target)
                    break;
            }
            if(bl)break;
        }
        vector<int>::iterator i1 = find(numbers.begin(), numbers.end(), ns );
        vector<int>::iterator i2;
        if(ns!=mid)
            i2 = find(numbers.begin(), numbers.end(), mid );
        else
            i2 = find(i1+1, numbers.end(), mid);
        int d1=i1 - numbers.begin()+1;
        int d2=i2 - numbers.begin()+1;

        index.clear();
        index.push_back(d1);
        index.push_back(d2);
        sort(index.begin(),index.end());
        return index;
    }
// 源自网友：
// https://oj.leetcode.com/discuss/17487/got-right-answer-in-my-vs2005-but-wrong-in-oj-in-two-sum-case-3-0?show=17487#q17487

    vector<int> twoSum2(vector<int> &numbers, int target) {
        vector<int> tmpvi(numbers);
        int tb=0,te=0;
        sort(tmpvi.begin(),tmpvi.end());

        vector<int>::iterator begin = tmpvi.begin(),end = tmpvi.end()-1;

        while (begin<end)
        {
            if ((*begin)+(*end) == target)
            {
                tb = *begin;
                te = *end;
                break;
            }else{
                if ((*begin)+(*end)<target)
                    ++begin;
                else
                    --end;
            }
        }
        vector<int>::iterator i1 = find(numbers.begin(), numbers.end(), tb );
        vector<int>::iterator i2 = find(numbers.begin(), numbers.end(), te );

        if (tb==te)
        {
            i2 = find(i2+1, numbers.end(), te );
        }

        int index1 = i1 - numbers.begin()+1;
        int index2 = i2 - numbers.begin()+1;
        if (index1>index2)
        {
            int tmp = index1;
            index1 = index2;
            index2 = tmp;
        }
        tmpvi.clear();
        tmpvi.push_back(index1);
        tmpvi.push_back(index2);
        return tmpvi;
    }

#include <unordered_map> //c++11
        vector<int> twoSum3(vector<int> &numbers, int target) {
            vector<int> res;
            int i, vSize;
            unordered_map<int, int> numMap;
            vSize = numbers.size();
            unordered_map<int,int>::const_iterator fIdx;

            if(vSize>1)
            {
                for(i=0;i<vSize; i++)
                {
                    fIdx = numMap.find(target - numbers[i]);
                    if(fIdx != numMap.end())
                    { // if its pal is already in the map, then return
                        res.push_back(fIdx->second);
                        res.push_back(i+1);
                        break;
                    }
                    else
                    { // insert itself to the map
                        numMap[numbers[i]] = i+1;
                    }
                }
            }
            return res;
        }


#include <utility>
        vector<int> twoSum4(vector<int> &numbers, int target) {
            int n=numbers.size(),l=0,r=n-1;
            vector< pair<int,int> > ans;

            for(int i=0;i<n;i++) ans.push_back(make_pair(numbers[i],i+1));
            sort(ans.begin(),ans.end());

            while(l<r)
            {
                int x=ans[l].first+ans[r].first;
                if(x<target) l++;
                else if(x>target) r--;

                else
                {
                    vector<int> a=vector<int>(ans[l].second,ans[r].second);
                    sort(a.begin(),a.end());
                    return a;
                }

            }
        }

        // 15ms
        // https://oj.leetcode.com/discuss/23734/my-15ms-accepted-c-o-n-log-n-solution
        vector<int> twoSum5(vector<int> &numbers, int target) {
            vector<int> v = numbers;
            sort(v.begin(), v.end());
            int left = 0;
            int right = (int) v.size() - 1;
            while (left < right) {
                int middle = v[left] + v[right];
                if (middle == target) break;
                if (middle < target)
                    ++left;
                else
                    --right;
            }

            int result_index1;
            int result_index2;
            for (int i=0;i<v.size();++i) {
                if (numbers[i] == v[left]) {
                    result_index1 = i;
                    break;
                }
            }

            for (int i=(int)v.size()-1;i >= 0;--i) {
                if (numbers[i] == v[right]) {
                    result_index2 = i;
                    break;
                }
            }

            if (result_index1 > result_index2)
                swap(result_index1,result_index2);

            vector<int> result {result_index1 + 1, result_index2 + 1};
            return result;
        }

int main()
{
    cout << "Hello World!" << endl;

    vector<int> index;//-3,4,3,90
    index.push_back(-3);
    index.push_back(4);
    index.push_back(3);
    index.push_back(90);

    index=twoSum(index,0);
    for(int i=0;i<index.size();++i){
        cout<<index.at(i)<<endl;
    }
    return 0;
}

