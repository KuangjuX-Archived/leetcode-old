/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*首先中序遍历将所有树节点遍历一遍存储到数组中，
 * 然后将这些节点逐次遍历求得两个节点绝对值差最小值*/
class Solution {
    vector<int> node;
public:
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        Inorder(root);
        for(int i=0;i<node.size();i++){
            for(int j=i+1;j<node.size();j++){
                ans=min(ans,abs(node[j]-node[i]));
            }
        }
        return ans;
    }

private:
    void Inorder(TreeNode* tree)
    {
        if(tree==nullptr)return;
        node.push_back(tree->val);
        Inorder(tree->left);
        Inorder(tree->right);
    }
};