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
    using MapType = std::unordered_map<int, int>;
 public:
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        int idx = 0;
        for (const auto& val : inorder) {
            inorder_val_idx_[val] = idx++;
        }
        return traversal(preorder, inorder, 0, 0, inorder.size()-1);
    }
 private:
    MapType inorder_val_idx_;
    TreeNode* traversal(const vector<int>& preorder, const vector<int>& inorder,
    int pre_start, int in_start, int in_end) {
        if (in_start > in_end || pre_start >= preorder.size()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int root_idx = inorder_val_idx_[root->val];
        root->left = traversal(preorder, inorder, pre_start+1, in_start, root_idx-1);
        root->right = traversal(preorder, inorder, pre_start+(root_idx-in_start+1), root_idx+1, in_end);
        return root;
    }
};