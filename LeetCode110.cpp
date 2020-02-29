/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int getDepth(struct TreeNode *root){
     if(root == NULL)
     return 0;
     int l = getDepth(root->left),r = getDepth(root->right);
     return (l > r ? l : r) + 1;
 }

bool isBalanced(struct TreeNode* root){
    if(root == NULL)
    return true;
    int l = getDepth(root->left),r = getDepth(root->right);
    if(l - r > 1 || r  -  l > 1)
    return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
