/*************************************************************************
	> File Name: Leetcode142.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 13时14分58秒
 ************************************************************************/

#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
   
    struct ListNode *fast_p=head,*p=head;
    while(fast_p!=0&&fast_p->next!=0){
        fast_p=fast_p->next->next;
        p=p->next;
        if(fast_p==p) break;
    }
    if(fast_p==0||fast_p->next==0) return 0;
    else{
        while(p!=head){
            p=p->next;
            head=head->next;
        }
        return head;
    }
}

