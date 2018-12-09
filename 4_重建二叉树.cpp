/**
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结
 * 果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * 
 * 常规题：前中序重建，递归重建即可，注意分割左右子树的时候的边界范围就可以了。
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* build(vector<int>&pre,vector<int>&vin,int pi,int pj,int vi,int vj)
    {
        if(pi>pj||vi>vj)
            return NULL;
        TreeNode* r=new TreeNode(pre[pi]);
        int v=pre[pi],dex=0;
        for(;dex+vi<=vj;++dex)
            if(vin[dex+vi]==v)
                break;
        r->left=build(pre,vin,pi+1,pi+dex,vi,vi+dex-1);
        r->right=build(pre,vin,pi+dex+1,pj,vi+dex+1,vj);
        return r;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        TreeNode *Root=build(pre,vin,0,pre.size()-1,0,vin.size()-1);
        return Root;
    }
};