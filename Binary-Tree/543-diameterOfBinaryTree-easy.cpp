/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
};
/*错误的解法，最长路径不一定穿过根节点*/
class Solution {
public:
    int depth(TreeNode* tree){
        if(tree==nullptr)return 0;

        int left=depth(tree->left);
        int right=depth(tree->right);

        return max(left,right)+1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;

        int left=depth(root->left);
        int right=depth(root->right);

        return (left+right);
    }
};



/*正确解法*/
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

    int ans=0;
public:
    /*这里求深度算法中递归地计算书中所有左右子树的深度且与ans的值进行对比*/
    int depth(TreeNode* tree){
        if(tree==nullptr)return 0;

        int left=depth(tree->left);
        int right=depth(tree->right);
        ans=max(ans,left+right);
        return max(left,right)+1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;

        ans=0;
        depth(root);
        return ans;

    }

};