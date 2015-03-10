/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

///
/// First:(56ms)

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int a=0,b=0,tmp=0;
        ListNode *rs=new ListNode(0);
        ListNode *r=rs;
        ListNode *p=l1;
        ListNode *q=l2;
        while(p!=NULL||q!=NULL){
            a=(p==NULL?0:p->val);
            b=(q==NULL?0:q->val);
            tmp=tmp+a+b;
            r->next=new ListNode(tmp%10);
            r=r->next;
            if(p!=NULL)p=p->next;
            if(q!=NULL)q=q->next;
            tmp=tmp/10;
        }
        if(tmp!=0){
            r->next=new ListNode(tmp);
        }
        r=rs->next;
        delete rs;
        return r;
    }
};

///
/// Second: (54ms)

class Solution {
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            int tmp=0;
            ListNode rs(0), *r=&rs, *p=l1, *q=l2;
            while(p!=NULL||q!=NULL||tmp){
                tmp=tmp+(p==NULL?0:p->val)+(q==NULL?0:q->val);
                r->next=new ListNode(tmp%10);
                r=r->next;
                p=(p==NULL?p:p->next);
                q=(q==NULL?q:q->next);
                tmp=tmp/10;
            }
            return rs.next;
        }
    };
