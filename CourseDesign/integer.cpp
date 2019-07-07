#include "Integer.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

using namespace std;

Integer::Integer()
{

}

void Integer::input(string s)
{
    int clength = 0;
    for(int i = 0; i < 101; i++)
    {
        num[i] = 0;
    }
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '0') clength += 1;
        else break;
    }
    if(clength == s.length())
    {
        num[0] = 0;
        length = 1;
    }
    else {
        s.erase(0, clength);
        length = s.length();
        for(int i = 0, j = length - 1; j >= 0; j--)
        {
            num[i++] = s[j] - '0';

        }
    }
}

void Integer::print()
{
    if(num[length-1] == 0) cout << "0" << endl;
    else
    {
        for(int i = length-1; i >= 0; i--)
        {
            cout << num[i];
        }
        cout << endl;
    }
}


int Integer::compare(Integer a)   //比较a和b的大小关系，若a>b则为1，a<b则为-1,a=b则为0
{
    int i;
    if (length > a.length) return 1;//a的位数大于b则a比b大
    if (length < a.length) return -1;//a的位数小于b则a比b小
    for(i = length-1; i>=0; i--) //从高位到低位比较
    {
        if (num[i] > a.num[i]) return 1;
        if (num[i] < a.num[i]) return -1;
    }
    return 0;//各位都相等则两数相等。
}
void Integer::add(Integer b) //计算a=a+b
{
    int k;
    k = length > b.length?length:b.length; //k是a和b中位数最大的一个的位数
    for(int i=0; i < k; i++)
    {
        num[i+1] += (num[i] + b.num[i])/10;  //若有进位，则先进位
        num[i] = (num[i] + b.num[i])%10;
    }  //计算当前位数字,注意：这条语句与上一条不能交换。
    if(num[k] > 0) length = k+1;  //修正新的a的位数（a+b最多只能的一个进位）
    else length = k;
}

void Integer::subtract(Integer b)//计算a=a-b，返加符号位0:正数 1:负数
{
    int flag;
    flag=this->compare(b); //调用比较函数判断大小
    if (flag==0)//相等
    {
        for(int i = 0; i < length;i++)
        {
            num[i] = 0;
        }//若a=b，则a=0,也可在return前加一句a[0]=1,表示是 1位数0
        while(num[length-1]==0) length--;
        length = 1;
    }
    if(flag==1) //大于
    {
        for(int i=0; i<length; i++)
        {
            if(num[i]<b.num[i])
            {
                num[i+1]--;    //若不够减则向上借一位
                num[i]+=10;
            }
            num[i]=num[i]-b.num[i];
        }
        while(num[length-1]==0) length--; //修正a的位数
    }
    if (flag == -1)//小于  则用a=b-a,返回-1
    {
        length = b.length;
        int i = 0;
        for(i=0; i<length; i++)
        {
            if(b.num[i]<num[i])
            {
                b.num[i+1]--;    //若不够减则向上借一位
                b.num[i]+=10;
            }
            num[i]=b.num[i]-num[i];
        }
        while(num[length-1]==0) --length; //修正a的位数
        cout << "-";
    }
}

Integer Integer::divide(Integer b)
{
    int i, j;
    int qu[101];
    Integer c;
    string s = "";
    for(i = 0; i < 101; i++)
    {
        qu[i] = 0;
    }
    int len1 = length, len2 = b.length;
    len1 = sub(b,len1,len2,0);
    if (len1 == -1)
    {
        c.input("0");
        return c;
    }
    else if (len1==0)
    {
        c.input("1");
        return c;
    }
    qu[0] = 1;
    int times = len1 - len2;
    for(i = len1 - 1; i >= 0; i--)
    {
        if(i >= times)
            b.num[i] = b.num[i-times];
        else
            b.num[i] = 0;
    }
    len2 = len1;
    for(j = 0; j <= times; j++)
    {
        int tmp;
        while((tmp=sub(b, len1, len2-j, j))>=0)
        {
            len1 = tmp;
            qu[times-j]++;
        }
    }
    for(i = 0; i < 101; i++)
    {
        if(qu[i] > 9)
        {
            qu[i+1] += qu[i]/10;
            qu[i] %= 10;
        }
    }
    int k;
    for(k = 100; qu[k] == 0&& k >= 0; k--);
    while(k >= 0)
    {
        s += char(qu[k--] + 48);
    }
    c.input(s);
    return c;
}

int Integer::sub(Integer b, int len1, int len2, int key)
{
    int i;
    if(len1 < len2)  return -1;
    else if(len1 == len2)
        for(i = len1-1; i >= 0; i--)
        {
            if(num[i] < b.num[i + key])return -1;
            else if (num[i] > b.num[i + key])break;
        }
    for(i = 0; i < len1; i++)
    {
        num[i] -= b.num[i + key];
        if (num[i]<0)
        {
            num[i]+=10;
            num[i+1]--;
        }
    }
    for (i = len1-1; i >= 0; i--)
        if(num[i])break;
    return i+1;
}

Integer Integer::multiply(Integer b)
{
    int c[10010],t;
    memset(c , 0 , sizeof(c));
    string s = "";

    for(int i = 0 ; i < length ;i++ )
    {
        t=0;
        for(int j = 0 ; j < b.length ; j++ )
        {
            c[i+j] += num[i] * b.num[j] + t;
            t = c[i+j] / 10;
            c[i+j] %= 10;
        }
        c[ i+ b.length ] = t;
    }
    int len3 = length + b.length + 1;

    while(c[len3-1] == 0 && len3 > 0)
        -- len3 ;
    for(int i = 0 ; i < len3 ; i++)
    {
        s += char(c[len3 - 1 - i] + 48);
    }
    Integer d;
    d.input(s);
    return d;
}

int Integer::check()
{
    for(int i = 0; i < length; i++)
    {
        if(num[i] < 0 || num[i] > 9) return -1;
    }
    return 1;
}

int Integer::isZero()
{
    for(int i = 0; i < length; i++)
    {
        if(num[i] != 0) return 1;
    }
    return 0;
}
