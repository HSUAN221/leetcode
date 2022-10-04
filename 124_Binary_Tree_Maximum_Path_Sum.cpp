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


int PathSum(TreeNode* root, int& ans) {
    if (root == nullptr) {
        return 0;
    }
    int left = std::max(0, PathSum(root->left, ans));
    int right = std::max(0, PathSum(root->right, ans));
    ans = std::max(ans, left + right + root->val); 
    return std::max(left, right) + root->val;
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = std::numeric_limits<int>::min();
        PathSum(root, ans);
        return ans;
    }
};