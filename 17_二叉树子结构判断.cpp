/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool f(TreeNode* r1,TreeNode* r2)
    {
        if(r2==NULL)//r2遍历完了则返回true
            return true;
        if(r1==NULL)//r2还有r1却遍历完了，返回false
            return false;
        if(r1->val!=r2->val)
            return false;
        else{
            //当前节点相等的化判断左右子树是否也一样
            bool left=f(r1->left,r2->left);
            bool right=f(r1->right,r2->right);
            return left&&right;
        }
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool f1=false;
        //必要要保证两个都不能我空，否则直接返回false
        if(pRoot1!=NULL&&pRoot2!=NULL)
        {
            if(pRoot1->val==pRoot2->val)
            {
                f1=f(pRoot1->left,pRoot2->left)&&f(pRoot1->right,pRoot2->right);
            }
            //多次判断f1可以避免找到子结构后还继续运行导致浪费时间
            if(f1)
                return f1;
           f1=HasSubtree(pRoot1->left,pRoot2);
            if(f1)
                return f1;
           f1=HasSubtree(pRoot1->right,pRoot2);
            return f1;
        }
       return f1;
    }
};