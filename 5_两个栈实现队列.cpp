/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
常规题：
栈1负责push数据，栈2负责pop数据。
使用哪个栈就把另外一个栈中的数据倒入当前栈。
*/
class Solution
{
public:
    void push(int node) {
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(node);
    }
    int pop() {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int x=stack2.top();
        stack2.pop();
        return x;
    }
private:
    stack<int> stack1;
    //stack1用来压数据
    stack<int> stack2;
    //stack2用来输出数据
};