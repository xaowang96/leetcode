#include <stdio.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode {
      int val;
      struct ListNode *next;
 };

 struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *tempListNode, *headNode, *calNode;
    int l1Val = l1->val;
    int l2Val = l2->val;
    calNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    calNode->val = 0;
    calNode->next = calNode;
    headNode = calNode;
    do{
        
        calNode = calNode->next;
        printf("l1->val %d l2->val %d calNode->val %d\n", l1Val, l2Val, calNode->val);
        calNode->val = calNode->val + l1Val + l2Val;
        tempListNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        if (calNode->val >= 10) {
            calNode->val -= 10;
            tempListNode->val = 1;
        }
        else
        {
            tempListNode->val = 0;
        }
        tempListNode->next = NULL;
        calNode->next = tempListNode;        

        l1 = ((l1 == NULL)? NULL: l1->next);
        l2 = ((l2 == NULL)? NULL: l2->next);
        l1Val = (l1 == NULL)? 0: l1->val;
        l2Val = (l2 == NULL)? 0: l2->val;
    }while(l1 != NULL || l2 != NULL);
    calNode->next = (tempListNode->val == 1)? tempListNode : NULL;
    return headNode;
}

int main(void)
{
    struct ListNode l1[4] = {{2, &l1[1]} , {4, &l1[2]}, {4, &l1[3]}, {3, NULL}};
    struct ListNode l2[3] = {{5, &l2[1]} , {6, &l2[2]}, {5, NULL}};
    struct ListNode* pListNode = addTwoNumbers(l1, l2);
    do
    {
        printf("%d ", pListNode->val);
        pListNode = pListNode->next;
    } while (pListNode != NULL);
    
    
}