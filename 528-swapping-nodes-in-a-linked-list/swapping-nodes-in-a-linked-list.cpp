/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt=0;ListNode* temp=head;
        while(temp!=NULL){
            cnt++;temp=temp->next;
        }
        ListNode* first=head;
        ListNode* last=head;
        int forw=k-1;
        while(forw){
            first=first->next;
            forw--;
        }
        forw=cnt-k;
        while(forw){
            last=last->next;
            forw--;
        }
        int tempv=first->val;
        first->val=last->val;
        last->val=tempv;
        return head;
    }
};