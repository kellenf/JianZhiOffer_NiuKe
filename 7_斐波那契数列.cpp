/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。 
n<=39 
递归方法太简单，就不写了。
给一个非递归的。
*/
class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int a=0,b=1,ans;
        for(int i=1;i<n;i++)
        {
            ans=a+b;
            a=b;
            b=ans;
        }
        return ans;
    }
};