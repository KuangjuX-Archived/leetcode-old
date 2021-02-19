/*把二叉搜索树转化成累加树*/
/*
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 *
 * 例如：

输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13
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

/*我的非常naive的暴力做法*/
/*没看到是二叉搜索树*/
class Solution {
public:
    vector<int> node;
    TreeNode* convertBST(TreeNode* root) {
        if(root==nullptr){
            return root;
        }
        TreeNode* tree=new TreeNode;
        create(root,tree);
        dfs(root);
        add(root,tree);

        return tree;

    }
private:
    void dfs(TreeNode* tree){
        if(tree==nullptr)return;

        node.push_back(tree->val);
        dfs(tree->left);
        dfs(tree->right);
    }

    void add(TreeNode* root,TreeNode* tree){
        if(root==nullptr)return;
        for(int i=0;i<node.size();i++){
            if(node[i]>root->val){
                tree->val+=node[i];
            }
        }
        add(root->left,tree->left);
        add(root->right,tree->right);
    }

    void create(TreeNode* root, TreeNode*& tree){
        if(root==nullptr)return;
        if(tree==nullptr){tree=new TreeNode;}

        tree->val=root->val;

        create(root->left,tree->left);
        create(root->right,tree->right);
    }
};


/*官方解法*/

/*方法1：回溯*/
/*由于是二叉搜索树，因此，树的左子树总是比根节点小，右节点总是比根节点大
 * 递归地访问根节点的右子树节点，在回溯过程中将其累加起来，赋值给根节点*/
class Solution {
private:
    int sum=0;
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root!=nullptr){
            convertBST(root->right);
            sum+=root->val;
            root->val=sum;
            convertBST(root->left);
        }
        return root;
    }
};