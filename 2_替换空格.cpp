/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
length是str能容纳的字符总量，不能额外开辟空间
数出str中的空格数量以及str中本身有的字符数量，就可以求得变换后的字符数组长度。
然按照从后往前插入的方式原地替换。
*/
class Solution {
public:
	void replaceSpace(char *str,int length) {
       if(str == NULL||length<=0)
            return;
        int len = 0,count = 0,i=0;
        while(str[i]!='\0')
        {
            if(str[i]==' ')
                count++;//空格数
            len++;//str中含有的字符数
            i++;
        }
        int newlen=len+count*2;
        if(length<newlen)
            return;
        int a=len;
        int b=newlen;
        while(a>=0&&b>=0)
        {
            if(str[a]==' ')
            {
                str[b--]='0';
                str[b--]='2';
                str[b--]='%';
            }
            else{
                str[b]=str[a];
                b--;
            }
            a--;
        }
        return;
	}
};