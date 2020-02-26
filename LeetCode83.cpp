/*************************************************************************
	> File Name: LeetCode83.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 13时01分28秒
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


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head;
    if(p == NULL){
        return head;
    }
    struct ListNode *q = head->next;
    while(q){
        if(q->val == p->val)
        {
            p->next = q->next;
            q = q->next;
        }else{
            p = p->next;
            q = q->next;
        }
    }
    return head;
    

}
