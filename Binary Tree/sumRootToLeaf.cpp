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


class Solution {
    int sum=0;
public:
    //深度优先搜索
    void dfs(TreeNode* tree, int num){
        if(tree==nullptr)return;

        num=(num<<1)+tree->val;
        if(tree->left==nullptr&&tree->right==nullptr)
        {
            sum+=num;
            return;
        }

        dfs(tree->left,num);
        dfs(tree->right,num);
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        sum=0;

        dfs(root,0);

        return sum;
    }
};

