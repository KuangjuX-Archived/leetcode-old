/*翻转一棵二叉树。*/
/**
 *
 * 示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*我的naive的做法,直接暴力递归*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        Invert(root);
        return root;
    }

private:
    void Invert(TreeNode*& tree)
    {
        if(tree==nullptr)return;
        TreeNode* leftTree=tree->left;
        tree->left=tree->right;
        tree->right=leftTree;
        Invert(tree->left);
        Invert(tree->right);

    }
};
