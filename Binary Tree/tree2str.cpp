/*
 * 你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
 * 空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
*/

/*
 * 输入: 二叉树: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

输出: "1(2(4))(3)"

解释: 原本将是“1(2(4)())(3())”，
在你省略所有不必要的空括号对之后，
它将是“1(2(4))(3)”。
 *
 *
 *
 *
 * */

/*
 * 输入: 二叉树: [1,2,3,null,4]
 *      1
 *    /   \
 *   2     3
 *    \
 *     4
 *
 *输出: "1(2()(4))(3)"
 *
 *解释: 和第一个示例相似，
 *除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
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

/*
 * 这道题根据官方题解给了四种情况，
 * 第一种情况是该节点为空或者左右子树都为空，这时既不需要加左括号也不需要加右括号，
 * 第二种情况是右子树为空时，这时左子树需要加括号，右子树不需要加括号
 * 当三种情况是左子树为空时，这时仍需要给左子树加括号表示左子树为空
 * 第四种情况当左右子树均不为空时，此时左右子树均需加括号
 * 综上所述第三四种情况可以合并在一起*/
class Solution {
public:
    string str="";
    string tree2str(TreeNode* t) {

        if(t==nullptr)return "";
        if(t->left==nullptr&&t->right==nullptr){
            return to_string(t->val);
        }
        if(t->right==nullptr){
            return to_string(t->val)+("("+tree2str(t->left)+")");
        }
        return to_string(t->val)+("("+tree2str(t->left)+")"+"("+tree2str(t->right)+")");
    }
};

