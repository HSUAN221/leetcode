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
 private:
    bool isSame_ = true;
    void preorder(TreeNode* p, TreeNode* q) {
        if (p != nullptr && q != nullptr) {
            if (p->val != q->val) {
                isSame_ = false;
            }
            preorder(p->left, q->left);
            preorder(p->right, q->right);
        } else if (p != nullptr && q == nullptr) {
            isSame_ = false;
        } else if (p == nullptr && q != nullptr) {
            isSame_ = false;
        }
    }
 public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preorder(p, q);
        return isSame_;
     
        /// or this one
        if (p != nullptr && q == nullptr) {
            return false;
        } else if (p == nullptr && q != nullptr) {
            return false;
        } else if (p == nullptr && q == nullptr) {
            return true;
        } else if (isSameTree(p->left,q->left) && isSameTree(p->right,q->right) && p->val == q->val) {
            return true;
        } else {
            return false;
        }
    }
};
