/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））
解决：
开一个最小数的栈，保存当前栈中的最小值，且和存储栈s保持相同的元素个数，同时压栈、进栈。
*/
class Solution {
public:
    stack<int>s;
    stack<int>mins;
    void push(int value) {
        s.push(value);
        if(mins.empty())
            mins.push(value);
        else if(mins.top()>value)
            mins.push(value);
        else
            mins.push(mins.top());
    }
    void pop() {
        int v=s.top();
        s.pop();
        mins.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return mins.top();
    }
};