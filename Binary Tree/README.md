# 树算法总结

## 在做题中关于树算法的总结

**关于树的做法一般都有递归和循环两种做法可以做，目前做题仅用递归做**

### **求二叉树深度：**

**e.g. [`04.04-isBalanced-easy`](04.04-isBalanced-easy.cpp) [`1022-sumRootToLeaf-easy`](1022-sumRootToLeaf-easy.cpp)**

```c++
int depth(TreeNode* tree)
{
	if(tree==nullptr)return 0;
    
    int left=depth(tree->left);
    int right=depth(tree->right);
    
    int res=max(left,right)+1;
    return res;
}
```

如果想求该树任意子树左右子树的长度路径的最大值，则可以定义全局变量。

```c++
int ans;
int depth(TreeNode* tree)
{
	if(tree==nullptr)return 0;
    
    int left=depth(tree->left);
    int right=depth(tree->right);
    
    ans=max(ans,left+right+1);
    int res=max(left,right)+1;
    return res;
}
```

### 二叉树转化成字符串

一般涉及到树的的三种遍历，并且会根据字符串创建的不同进行讨论。

**e.g.  [`606-tree2str-easy`](606-tree2str-easy.cpp)**

### 层次遍历

**e.g.  [`102-levelOrder-medium`](102-levelOrder-medium.cpp)**

**宽度优先搜索**

宽度优先搜索顺序与层次遍历顺序完全一致

**宽度优先搜索模板：**

```c++
void BFS(TreeNode* root)
{
	queue<TreeNode*> q;
    q.push(root);
    while(q.size()){
        TreeNode* node=q.front();
        q.pop();
        
        if(node->left!==nullptr){
            q.push(node->left);
        }
        if(node->right!==nullptr){
            q.push(node->right);
        }
    }
}
```

### 翻转二叉树

**e.g.  [`226-invertTree-easy`](226-InvertTree-easy.cpp)**  [`951-flipEquiv-medium`](951-flipEquiv-medium.cpp)

**简单的翻转二叉树算法：**

```c++
void Invert(TreeNode*& tree)
    {
        if(tree==nullptr)return;
        TreeNode* leftTree=tree->left;
        tree->left=tree->right;
        tree->right=leftTree;
        Invert(tree->left);
        Invert(tree->right);

    }
```

**层次翻转二叉树（即不一定几次翻转）**

每次翻转后都进行检查：

```c++
bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==root2){
            return true;
        }

        if(root1==nullptr||root2==nullptr||root1->val!=root2->val){
            return false;
        }

        return ((flipEquiv(root1->left,root2->right)&&flipEquiv(root1->right,root2->left))
                ||(flipEquiv(root1->left,root2->left)&&flipEquiv(root1->right,root2->right)));
    }
```

