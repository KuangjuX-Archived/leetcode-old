/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        /*这个方法会报超时，很神奇*/
        /*
       ListNode* pre=nullptr;
       ListNode* curr=head;
       ListNode* next=head->next;
       curr->next=pre;
       while(next!=nullptr){
           pre=curr;
           curr=next;
           curr->next=pre;
           next=next->next;
       }
       return curr;*/

        /*双指针链表反转*/
        ListNode* prev=nullptr, *cur=head;
        while(cur!=nullptr){
            ListNode* next=cur->next;

            cur->next=prev;

            prev=cur;

            cur=next;
        }
        return prev;

    }
};
