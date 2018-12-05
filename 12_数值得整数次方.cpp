/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
处理特殊情况：
base=0
exponent为负数
*/
class Solution {
public:
    double Power(double base, int exponent) {
        if(base==0)
            return 0;
        double x=1;
        if(exponent>=0)
        {
            for(int i=0;i<exponent;++i)
                x=x*base; 
            return x;
        }
        else{
            for(int i=0;i<-exponent;++i)
                x=x*base;
            return 1/x;
        }    
    }
};