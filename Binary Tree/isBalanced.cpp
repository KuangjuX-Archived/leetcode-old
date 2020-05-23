/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cmath>
struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
};
class Solution {
public:
    int depth(TreeNode* root)//计算数的深度（板子）
    {
        if(root==nullptr)return 0;

        int left=depth(root->left);
        int right=depth(root->right);

        return fmax(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {

        if(root==nullptr)return true;//如果为空则返回true

        /*如果根左右的深度小于2，则递归地检查其左右孩子的深度差,直到其左右子树全为空*/
        if(abs(depth(root->left)-depth(root->right))<2){
            return isBalanced(root->left)&&isBalanced(root->right);
        }

        return false;
    }


};