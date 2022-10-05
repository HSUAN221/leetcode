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
    int maxPathSum(TreeNode* root) {
        ans_ = std::numeric_limits<int>::min();
        PathSum(root);
        return ans_;
    }
 private:
    int ans_ = std::numeric_limits<int>::min();
    int PathSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = std::max(0, PathSum(root->left));
        int right = std::max(0, PathSum(root->right));
        ans_ = std::max(ans_, left + right + root->val);
        std::cout << "Ans= " << left + right + root->val << std::endl;
        return std::max(left, right) + root->val;
    }
};
