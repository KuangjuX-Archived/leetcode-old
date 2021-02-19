/*树的层次遍历问题，使用BFS（宽度优先搜索）*/
/*本题很好的解析的URL：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/solution/bfs-de-shi-yong-chang-jing-zong-jie-ceng-xu-bian-l/*/

/**
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 * 示例：
   二叉树：[3,9,20,null,null,15,7],
     3
   / \
  9  20
    /  \
   15   7

   返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        /*空树时直接返回空vector*/
        if(root==nullptr){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int j=-1;//记录vector层数index
        /*宽度优先搜索*/
        while(q.size()!=0){
            j++;
            /*记录本层有多少个节点*/
            int size=q.size();
            /*初始化ans[j]*/
            ans.push_back(vector<int>(0));
            /*依次遍历该层所有节点，pop掉该层所有节点，push下一层所有节点*/
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();

                q.pop();

                ans[j].push_back(node->val);

                if(node->left!=nullptr){
                    q.push(node->left);
                }

                if(node->right!=nullptr){
                    q.push(node->right);
                }
            }
        }
        return ans;
    }
};