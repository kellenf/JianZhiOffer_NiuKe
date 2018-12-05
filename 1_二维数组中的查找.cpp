/*
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
关键的还是矩阵的左下角点和右下角点与target的值进行比较，根据比较结果来移动坐标范围
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()==0)
            return false;
        int i,j;
        int rows=array.size()-1;
        int cols=array[0].size()-1;
        i=j=0;
        while(i<=rows&&j<=cols)
        {
            if(array[i][cols]>target)
                cols--;
            else if(array[i][cols]<target)
                i++;
            else return true;
            if(array[rows][j]<target)
                j++;
            else if(array[rows][j]>target)
                rows--;
            else return true;
        }
        return false;
    }
};
/*
其实还有更好的方法，就是我只判断左上角点array[i][j],大于target则j--,小于target则i++,
等于返回true，如果存在target，则array[i][j]一定能访问到target
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.size()==0)
            return false;
        int i,j;
        int rows=array.size()-1;
        int cols=array[0].size()-1;
        i=0,j=cols;
        while(i<=rows&&j>=0)
        {
           if(array[i][j]==target)
               return true;
           else if(array[i][j]<target)
               i++;
           else
               j--;
        }
        return false;
    }
};