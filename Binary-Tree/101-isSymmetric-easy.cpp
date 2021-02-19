/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root,root);

    }
private:
    bool check(TreeNode* tree,TreeNode* root){
        if(!tree&&!root)return true;
        if(!tree||!root)return false;
        return (tree->val==root->val)&&check(tree->left,root->right)&&check(tree->right,root->left);
    }
};