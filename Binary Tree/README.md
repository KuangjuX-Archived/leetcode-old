# 树算法总结

## 在做题中关于树算法的总结

**关于树的做法一般都有递归和循环两种做法可以做，目前做题仅用递归做**

### **求二叉树深度：**

**e.g. `isBalanced` `sumRootToLeaf`**

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

**e.g.  tree2str**