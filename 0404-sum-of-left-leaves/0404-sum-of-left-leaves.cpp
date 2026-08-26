/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void calcsum(TreeNode* root, int &ans) {
        if(root==nullptr) return;
        if(root->left && root->left->left==nullptr && root->left->right==nullptr) ans+=root->left->val;
        calcsum(root->left, ans);
        calcsum(root->right, ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        calcsum(root, ans);  
        return ans;      
    }
};