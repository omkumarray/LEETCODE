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
    void Order(TreeNode* root, vector<vector<int>>& ans, int count){
        if(root == NULL)return;

        if (ans.size() == count) {
            ans.push_back({});
        }

        ans[count].push_back(root->val);
        
        Order(root->left, ans, count+1);
        Order(root->right, ans, count+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       Order(root, ans, 0);
       return ans; 
    }
};