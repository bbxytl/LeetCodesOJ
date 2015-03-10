class Solution {
public:
    double findMedianSortedArrays_1(int A[], int m, int B[], int n) {
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

    int getkth(int s[], int m, int l[], int n, int k){
        // let m <= n
        if (m > n)
        return getkth(l, n, s, m, k);
        if (m == 0)
            return l[k - 1];
        if (k == 1)
            return min(s[0], l[0]);

        int i = min(m, k / 2), j = min(n, k / 2);
        if (s[i - 1] > l[j - 1])
            return getkth(s, m, l + j, n - j, k - j);
        else
            return getkth(s + i, m - i, l, n, k - i);
        return 0;
    }

    double findMedianSortedArrays_2(int A[], int m, int B[], int n) {
        int l = (m + n + 1) >> 1;
        int r = (m + n + 2) >> 1;
        return (getkth(A, m ,B, n, l) + getkth(A, m, B, n, r)) / 2.0;
    }
};
