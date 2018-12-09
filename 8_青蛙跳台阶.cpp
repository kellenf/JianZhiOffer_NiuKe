/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
简单题
1)递归法：跳到n阶，只能从n-1跳1阶到n，或者从n-2跳2阶到n，按这个思路递归
n==1则return 1,n==2时则return 2;
2)非递归法：
*/
class Solution {
public:
    int jumpFloor(int number) {
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        return jumpFloor(number-1)+jumpFloor(number-2);
        
    }
};
//解法2：非递归，和斐波那契一样
class Solution {
public:
    int jumpFloor(int number) {
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        int a=1,b=2,s;
        for(int i=2;i<number;i++)
        {
            s=a+b;
            a=b;
            b=s;
        }
        return s;
    }
};