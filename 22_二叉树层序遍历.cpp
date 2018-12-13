/*
层序遍历，上到下，左到右
用队列，常规题
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode*>que;
        vector<int>ans;
        if(!root)
            return {};
        que.push(root);
        while(!que.empty())
        {
            TreeNode *r=que.front();
            que.pop();
            ans.push_back(r->val);
            if(r->left)
                que.push(r->left);
            if(r->right)
                que.push(r->right);
        }
        return ans;
    }
};