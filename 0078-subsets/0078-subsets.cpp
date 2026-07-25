class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> allSubsets;
        allSubsets.push_back(vector<int>({}));
        backtrack(allSubsets, nums, subset, 0);
        return allSubsets;
    }

    void backtrack(vector<vector<int>>& allSubsets, vector<int>& nums, vector<int>& subset, int pos) {
        for (int i = pos; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            allSubsets.push_back(subset);
            backtrack(allSubsets, nums, subset, i+1);
            if (!subset.empty()) subset.pop_back();
        }
    }
};