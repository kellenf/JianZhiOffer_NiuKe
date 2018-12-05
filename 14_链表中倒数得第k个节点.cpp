/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
简单题，求得链表长度+双指针
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int length=0;
        ListNode* p=pListHead;
        while(p!=NULL)
        {
            length++;
            p=p->next;
        }
        if(k>length)
            return NULL;
        ListNode* q=pListHead;
        p=pListHead;
        while(k--)
            p=p->next;
        while(p!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        return q;
    }
};