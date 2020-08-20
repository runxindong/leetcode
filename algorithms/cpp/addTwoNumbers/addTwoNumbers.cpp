// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author :	Raymond 
// Date   : 2020-08-19

/********************************************************************************** 
* 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*               
**********************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

bool initList(ListNode *l){
	if(!l) return false;
	l->next = NULL;
	return true;
}

void printList(ListNode *l){
	if(!l) return;
	ListNode *last = l;
	while(last->next){
		last = last->next;
		printf("%d\t",last->val);
	}
	cout << endl;
}

bool listInsertBack(ListNode *l,int e){
	if(!l) return false;
	ListNode *node = new ListNode(e);

	ListNode *last = l;
	while(last->next){
		last = last->next;
	}
	last->next = node;
	return true;
}

class Solution {
    
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x=0, y=0, carry=0, sum=0;
        ListNode *h=NULL, **t=&h;
        
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            
            sum = carry + x + y;
            
            ListNode *node = new ListNode(sum%10);
            *t = node;
            t = (&node->next);
            
            carry = sum/10;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry%10);
            *t = node;
        }
        
        return h;
    }
private:
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if (l != NULL){
            x = l->val;
            l = l->next;
        }
        return x;
    }
};

int main(){
	ListNode *l1 = new ListNode(-1);
	listInsertBack(l1,2);
	listInsertBack(l1,4);
	listInsertBack(l1,3);
	printList(l1);		

	ListNode *l2 = new ListNode(-1);
    listInsertBack(l2,5);
    listInsertBack(l2,6);
    listInsertBack(l2,4);
    printList(l2);    

	Solution solution;
	ListNode *result = solution.addTwoNumbers(l1,l2);
	printList(result);	

	return 0;
}
