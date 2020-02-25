/*************************************************************************
	> File Name: Leetcode19.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时09分20秒
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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int j = 0, i = 1;
    int length;
    struct ListNode *p,*temp;
    p =(struct ListNode *)malloc(sizeof(struct ListNode));
    p = head;
    while(p != NULL){

        p =p->next;
        j++;
    }
    length = j;
    p = head;
    if(length == 1){
        head = NULL;
        return head;
    }
    if(length == n){
        temp = head;
        head = head->next;
        temp = NULL;
    }
    
    while(i != length-n+1 && p != NULL && p->next != NULL){

        if(i != length - n){
            p = p->next;
            i++;
        }
        else if(i == length-1){
            p->next = NULL;
            return head;
        }
        
        else{
            temp = p->next;
            p->next = temp->next;
            i++;
        }
    }
    printf("%d %d",length,i);
    
    return head;

}

作者：phoenix-45
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/cyu-yan-ke-yun-xing-shan-chu-dao-shu-jie-dian-by-p/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
