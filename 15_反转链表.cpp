/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL)
            return NULL;
        ListNode* head=new ListNode(0);
        head->next=NULL;
        ListNode *p,*q;
        p=pHead;
        while(p!=NULL)
        {
            q=p->next;
            p->next=head->next;
            head->next=p;
            p=q;
        }
        return head->next;
    }
};