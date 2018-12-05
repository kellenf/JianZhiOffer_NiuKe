/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
//解法1：时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int>tmp;
        int j=0;
        for(int i=0;i<array.size();++i)
        {
            if(array[i]%2==1)
                array[j++]=array[i];
            else
                tmp.push_back(array[i]);

        }
        for(int i=0;i<tmp.size();++i)
        {
            array[j++]=tmp[i];
        }
        return;
    }
};
//解法2：插入法，时间复杂度O(n^2),空间复杂度O（1）
class Solution {
public:
    void insert(vector<int>&array,int i,int j,int n)
    {
        for(int t=j;t>i;t--)
        {
            array[t]=array[t-1];
        }
        array[i]=n;
    }
    void reOrderArray(vector<int> &array) {
        int j=0;
       for(int i=0;i<array.size();++i)
       {
           if(array[i]%2!=0)
           {
               if(i!=j)
               {
                   int x=array[i];
                   insert(array,j,i,x);
               }
               j++;
           }
       }
    }
};
//解法3：冒泡排序的思想，遇到前面偶数后面奇数得时候就交换
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        for(int i=0;i<array.size();++i)
        {
            bool flag=false;
            for(int j=array.size()-1;j>i;--j)
            {
                if(array[j-1]%2==0&&array[j]%2==1)
                {
                    swap(array[j-1],array[j]);
                    flag=true;
                }
            }
            if(!flag)
                return;
        }
    }
};