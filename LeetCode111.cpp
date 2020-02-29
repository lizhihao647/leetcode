/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    if(root == NULL)
    return 0;
    int l = minDepth(root->left),r = minDepth(root->right);
    if(l && r)
    return (l > r ? r : l) + 1;
    return (l == 0 ? r : l) + 1;

}
