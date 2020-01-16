#include <stdio.h>    
#include <iostream>    
#include<algorithm>  
using namespace std;  
#define N 1000  
struct bag{    
    int w;//物品的重量    
    int v;//物品的价值    
    double c;//物品的性价比     
}a[1001];     
bool cmp(bag a,bag b)    
{    
 return a.c>=b.c;    
}    
double backpack(int n,bag a[],double c)//n表示物品的数量，a表示按照物品性价比排序后的数组，c表示剩余空间     
{    
    double cleft=c;  
    int i=0;    
    double b=0;//获得的价值    
    //当物品i可以装入背包中    
    while(i<n&&a[i].w<c)    
    {    
        c=c-a[i].w;    
        b+=a[i].v;    
        i++;        
    }       
    //说明物品不能完全装入背包     
    if(i<n)    
        b+=1.0*a[i].v*c/a[i].w ;    
    return b;    
}     
int main()    
{    
    int c;    
    int n;    
    int i;   
    printf("请输入物品的容量：\n");    
    scanf("%d",&c);  
    printf("请输入每个物品的数量：\n");  
    scanf("%d",&n);    
    printf("请输入每个物品的重量,价值：\n");  
        for(i=0; i<n; i++)    
        {    
            cin>>a[i].w>>a[i].v;    
            a[i].c = 1.0*a[i].v/a[i].w;    
        }    
        sort(a, a+n, cmp);//按照性价比排序   
        printf("输出贪心算法最优解：\n");  
        cout<<backpack(n,a,c);    
    return 0;       
} 
