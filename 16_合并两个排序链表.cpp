/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *head,*tail;
        head=new ListNode(0);
        tail=head;
        while(pHead1!=NULL&&pHead2!=NULL)
        {
            if(pHead1->val>pHead2->val)
            {
                tail->next=pHead2;
                pHead2=pHead2->next;
                tail=tail->next;
            }
            else
            {
                tail->next=pHead1;
                pHead1=pHead1->next;
                tail=tail->next;
            }
        }
        while(pHead1!=NULL)
        {
            tail->next=pHead1;
            pHead1=pHead1->next;
            tail=tail->next;
        }
        while(pHead2!=NULL)
        {
            tail->next=pHead2;
            pHead2=pHead2->next;
            tail=tail->next;
        }
        tail->next=NULL;
        return head->next;
    }
};