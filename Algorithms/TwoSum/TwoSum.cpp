#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;
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
        int d1=i1 - numbers.begin();
        int d2=i2 - numbers.begin();

        index.clear();
        index.push_back(d1+1);
        index.push_back(d2+1);
        sort(index.begin(),index.end());
        return index;
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

