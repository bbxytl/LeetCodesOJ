
// https://oj.leetcode.com/discuss/26692/6ms-c-solution-with-self-implemented-hash-table
// As there is no hash table implementation in C standard library
// (as far as I know - maybe I'm wrong?), I wrote it on my own.
// It takes 6ms to compute, so it's quite fast.

#include <stdio.h>
#include <stdlib.h>

static inline int hash(int x, int size){
    int tmp = x % size;
    return tmp > 0 ? tmp : (-tmp);
}

struct node {
    int val;
    int key;
    struct node *next;
};

int *twoSum(int numbers[], int n, int target) {
    int *ret = malloc(sizeof(int)*2);
    struct node **hashtable = (struct node **)malloc(sizeof(struct node *)*n);
    int i, index;
    struct node *it, *tmp;
    int to_find;
    for(i=0;i<n;i++){
        hashtable[i] = NULL;
    }
    ret[0] = 111;
    ret[1] = 111;
    for(i=0;i<n;i++){
        index = hash(numbers[i], n);
        it = hashtable[index];
        tmp = NULL;
        while(it!=NULL){
            tmp = it;
            it = it->next;
        }
        it = (struct node *)malloc(sizeof(struct node));
        if(tmp)
            tmp->next = it;
        else
            hashtable[index] = it;
        it->val = numbers[i];
        it->key = i;
        it->next = NULL;
    }
    for(i=0;i<n;i++){
        to_find = target - numbers[i];
        index = hash(to_find, n);
        it = hashtable[index];
        while(it!=NULL){
            if(it->val == to_find && it->key != i){
                ret[0] = (it->key < i ? it->key : i) + 1;
                ret[1] = (it->key > i ? it->key : i) + 1;
                for(int j=0;j<n;j++){
                    it = (struct node *) hashtable[j];
                    tmp = NULL;
                    while(it!=NULL){
                        free(it);
                        it = tmp;
                        if(it!=NULL)
                            tmp = it->next;
                    }
                }
                free(hashtable);
                return ret;
            }
            it = it->next;
        }
    }
    return ret;
}
