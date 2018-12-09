

/**
 * 题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
没什么好说的，堆栈存储后放到queue中
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<int>s;
        vector<int>q;
        while(head!=NULL)
        {
            s.push(head->val);
            head=head->next;
        }
        while(!s.empty())
        {
            q.push_back(s.top());
            s.pop();
        }
        return q;
    }
};