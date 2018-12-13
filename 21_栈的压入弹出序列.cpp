/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
解决：
当前压入的等于弹出序列的第一个，则弹出这个元素在弹出序列访问下标+1
最后判断栈中元素和弹出序列是否符合（逐个判断就可以）
*/
class Solution {
public:
    stack<int>s;
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size())
            return false;
        int i=0,j=0;
        while(i<pushV.size())
        {
            s.push(pushV[i++]);
            if(s.top()==popV[j])
            {
                s.pop();
                j++;
            }
            if(j==popV.size())
                return true;
        }
        while(j<popV.size()&&!s.empty())
        {
            if(popV[j]==s.top())
            {
                j++;
                s.pop();
            }
            else
                return false;
        }
        return true;
    }
};