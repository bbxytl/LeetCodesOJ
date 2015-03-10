
// 44ms 使用STL
#include <vector>
class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<=1)return s;
        vector<string> vt;
        for(int i=0;i<nRows;++i){
            vt.push_back("");
        }
        string rs;
        int idx=0;
        bool sig=true;//递增
        string::iterator it=s.begin();
        while(it!=s.end()){
            vt[idx].push_back(*it);
            if(sig){
                if(++idx>=nRows){
                    sig=false;
                    idx=nRows-2;
                }
            }else{
                if(--idx<0){
                    sig=true;
                    idx=1;
                }
            }
            ++it;
        }
        for(int i=0;i<nRows;++i){
            rs+=vt[i];
        }
        return rs;
    }
};


/* The basic idea is to calculate the original index (pos) of the k-th char of the output string. The pos index formula is as below
/  for the first row and the last row: only one element in each zigzag block (i.e. go down from 0-th row to (nRows-1)-th row and then go back to the 1-th row) and for the other intermediate rows, two elements in each zigzag block.
                    pos = 2*(nRows-1)*col + row;  for row ==0 or row == nRows-1
                    pos = 2*(nRows-1)*(col/2) + row + (col%2)*2*(nRows - row -1); for row in [1, nRows-2]
if the calculated pos is larger than sSize-1, then it means it reaches the end of the current row, so just increase row and reset col=0 to its beginning; otherwise, move to the next col.

// As other contributors proposed, another way to do so is to use an offset array to calculate the original string index of the i-th char of the output string. Such version is also given here.

*/
class Solution {
public:
    // 29ms
    string convert(string s, int nRows) {
        unsigned int sSize = s.size();
        string res(s);
        unsigned int row=0,col=0, k=0, pos;

// if it is a single row or single column case, just return the original string
        if(sSize > nRows && nRows>1)
        {
            while(k<sSize)
            {  if(row==0 || row==nRows-1)
                {// first or last row, only one element in each zigzag block
                    pos = 2*(nRows-1)*col + row;
                }
                else
                { // intermediate rows, two elements in each zigzig block, even or odd columns have different way to caculate pos
                    pos = 2*(nRows-1)*(col/2) + row + (col%2)*2*(nRows - row -1);
                }
                if(pos<sSize)
                { // if pos is in the range, copy the char and update k and col
                    res[k] = s[pos];
                    k++;
                    col++;
                }
                else
                {// if pos is out of range, which means it reaches the end of the row, update row and reset col
                    row++;
                    col = 0;
                }
            }
        }

        return res;
    }
/*
 * // 22ms
// use an offset array to simplify the index calculation
string convert(string s, int nRows) {
    unsigned int sSize = s.size();
    string res(s);
    unsigned i, new_pos=0, old_pos;
    int offset[2];
    unsigned int odd_col;

    if( (sSize > nRows) && (nRows > 1))
    { // multiple row and column case
        offset[0] = 2*(nRows-1);
        offset[1] = 0;

        for(i=0;i<nRows; i++)
        {//go through each row
            old_pos = i;
            odd_col = 0;
            while(old_pos<sSize)
            {
                res[new_pos++] = s[old_pos];
                if(offset[odd_col]){
                    old_pos += offset[odd_col];
                    odd_col = 1 - odd_col;
                }
                else{
                    old_pos += offset[1 - odd_col];
                }
            }
            offset[0] = offset[0] - 2;
            offset[1] = offset[1] + 2;
        }
    }

    return res;
}
*/
};
