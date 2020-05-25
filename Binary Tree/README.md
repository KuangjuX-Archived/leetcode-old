# 树算法总结

## 在做题中关于树算法的总结

**求二叉树深度：**

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

