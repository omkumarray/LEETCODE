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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!head || k == 1){

            return head;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* temp = head;
        int size = 0;

        while(temp){

            temp = temp->next;
            size++;
        }

        int times = size/k;

        ListNode* PrevTail = dummy;
        ListNode* GroupTail = head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for(int i = 0; i < times; i++){

            int cnt = 0;

            while(cnt < k){
                ListNode* fwd = curr->next;
                curr->next = prev;
                prev = curr;
                curr = fwd;

                cnt++;
            }

            PrevTail->next = prev;
            GroupTail->next = curr;

            PrevTail = GroupTail;
            GroupTail = curr;
        }
        return dummy->next;
    }
};