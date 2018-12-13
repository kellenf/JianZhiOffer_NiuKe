/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
判断下上下边界就可以，注意矩阵为空，只有一列或只有一行的情况
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int rows=matrix.size()-1;
        if(rows==-1)
            return {};
        int cols=matrix[0].size()-1;
        int ii=0,jj=0;
        vector<int>ans;
        if(matrix.size()==1)
            return matrix[0];
        while(ii<=rows&&jj<=cols)
        {
            int j=jj;
            for(;j<=cols;j++)
                ans.push_back(matrix[ii][j]);
            j=++ii;
            if(ii>rows||jj>cols)
                break;
            for(;j<=rows;j++)
                ans.push_back(matrix[j][cols]);
            j=--cols;
            if(ii>rows||jj>cols)
                break;
            for(;j>=jj;j--)
                ans.push_back(matrix[rows][j]);
            j=--rows;
             if(ii>rows||jj>cols)
                break;
            for(;j>=ii;j--)
                ans.push_back(matrix[j][jj]);
            ++jj;
        }
        return ans;
    }
};