/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


 int getDepth(struct TreeNode *root){
     if(root == NULL)
     return 0;
     int l = getDepth(root->left),r = getDepth(root->right);
     return (l > r ? l : r) + 1;
 }
 
 //这里重点，看是如何存储每层节点个数
 void getCnt(struct TreeNode *root,int k,int *cnt){
     if(root == NULL)
     return ;
     cnt[k]++;
     getCnt(root->left, k  - 1,cnt);
     getCnt(root->right, k -  1 ,cnt );
     return;
 }
 void getResult(struct TreeNode *root,int k,int *cnt,int **ret){
     if(root == NULL || k < 0)
     return ;
     ret[k][cnt[k]++] = root->val;
     getResult(root->left,k - 1,cnt,ret);
     getResult(root->right,k - 1,cnt,ret);
     return;
 }
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

    int depth = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * depth);
    int *cnt = (int *)calloc(depth,sizeof(int));
    getCnt(root,depth - 1,cnt);
    for(int i = 0;i < depth;++i){
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;
    }
    getResult(root,depth - 1,cnt,ret);
    *returnSize = depth;
    *returnColumnSizes = cnt;
    return ret;


}
