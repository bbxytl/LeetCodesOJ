class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m==0&&n==0)return 0;
        if(m+n==1) return m==1?A[0]:B[0];
        int mid=0,next=0,cont=0;
        int sum=(m+n+1)/2+1;
        int a=0,b=0;
        while(a<m&&b<n){
            mid=next;
            A[a]<B[b] ? (next=A[a],++a) : (next=B[b],++b);
            ++cont;
            if(cont==sum){
                break;
            }
        }
        if(a>=m){
            while(cont<sum){
                mid=next;
                next=B[b];
                ++b;
                ++cont;
            }
        }
        else if(b>=n){
            while(cont<sum){
                mid=next;
                next=A[a];
                ++a;
                ++cont;
            }
        }
        if((m+n)%2!=0)return mid;
        return (mid+next)/2.0;
    }
};
