#include <stdio.h>    
#include <iostream>    
#include<algorithm>  
using namespace std;  
#define N 1000  
struct bag{    
    int w;//��Ʒ������    
    int v;//��Ʒ�ļ�ֵ    
    double c;//��Ʒ���Լ۱�     
}a[1001];     
bool cmp(bag a,bag b)    
{    
 return a.c>=b.c;    
}    
double backpack(int n,bag a[],double c)//n��ʾ��Ʒ��������a��ʾ������Ʒ�Լ۱����������飬c��ʾʣ��ռ�     
{    
    double cleft=c;  
    int i=0;    
    double b=0;//��õļ�ֵ    
    //����Ʒi����װ�뱳����    
    while(i<n&&a[i].w<c)    
    {    
        c=c-a[i].w;    
        b+=a[i].v;    
        i++;        
    }       
    //˵����Ʒ������ȫװ�뱳��     
    if(i<n)    
        b+=1.0*a[i].v*c/a[i].w ;    
    return b;    
}     
int main()    
{    
    int c;    
    int n;    
    int i;   
    printf("��������Ʒ��������\n");    
    scanf("%d",&c);  
    printf("������ÿ����Ʒ��������\n");  
    scanf("%d",&n);    
    printf("������ÿ����Ʒ������,��ֵ��\n");  
        for(i=0; i<n; i++)    
        {    
            cin>>a[i].w>>a[i].v;    
            a[i].c = 1.0*a[i].v/a[i].w;    
        }    
        sort(a, a+n, cmp);//�����Լ۱�����   
        printf("���̰���㷨���Ž⣺\n");  
        cout<<backpack(n,a,c);    
    return 0;       
} 
