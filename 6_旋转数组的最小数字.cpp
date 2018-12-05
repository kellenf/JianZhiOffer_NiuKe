/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
解法：
1）访问每一个值，取最小值
2）找到旋转衔接点，rotateArray[i]>rotateArray[i+1]的点
如果没有则返回rotateArray[0],
如果有则返回rotateArray[i+1]
*/
//下面这个 是最low的解法
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0)
            return 0;
        int x=INT_MAX;
        for(int i:rotateArray)
            if(i<x)
                x=i;
        return x;
        
    }
};
//解法2
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size()==0)
            return 0;
        int x=rotateArray[0];
        int i=0;
        while(i<rotateArray.size())
        {
            if(i+1<rotateArray.size()&&rotateArray[i]>rotateArray[i+1])
                break;
            i++;
        }
        if(i<rotateArray.size())
            return rotateArray[i+1];
        else
            return x;
    }
};