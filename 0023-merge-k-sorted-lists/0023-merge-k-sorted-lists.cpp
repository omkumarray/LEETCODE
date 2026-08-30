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
#include<queue>
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>q;
        if(lists.size()==0) return NULL;

        int n = lists.size();
        for(int i=0;i<n;i++){
            ListNode* temp = lists[i];
            while(temp!=NULL){
                q.push(temp->val);
                temp=temp->next;
            }
        }
        //now make a newLinked list
        ListNode* head=NULL;
        ListNode* tail=NULL;

        while(!q.empty()){
            int a = q.top();
            q.pop();
            ListNode* newNode = new ListNode(a);
            if(head==NULL && tail==NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        return head;

    }
};