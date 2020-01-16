#include <stdio.h>
#include <stdlib.h>
//快速排序
void _quick_sort(int a[],int left,int right) //直接排序数组，返回值为void
{
	//定义左右指针指向数组的下标
	int i = left;
	int j = right;
	//递归出口
	if(i>j)
		return;
	//记录标杆值
	int pivot = a[i];
	//一次循环可以得到：标杆的左侧都比标杆小，标杆的右侧都比标杆大
	while(i<j)
	{
		//从right开始找比标杆小的为止
		while(i<j && a[j]>=pivot)
			j--;
		//将较小的数赋值到left上
		a[i] = a[j];
		//从left开始找比标杆大的为止
		while(i<j && a[i]<=pivot)
			i++;
		//将较大的数赋值到right上
		a[j] = a[i];
	}
	//将标杆值补到数组中
	a[i] = pivot;
	//一次循环完成
	//进行左侧和右侧的递归
	_quick_sort(a,left,i-1);
	_quick_sort(a,i+1,right);
}
//调用快速排序
void quick_sort(int a[],size_t len)
{
	_quick_sort(a,0,len-1);
}
//显示函数
void show(int a[],int len)
{
	for(int i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");
}
//主函数
int main()
{
	int arr[10]={1233,213,1233,-88,-88,454,2,-88,0,-22};
	show(arr,10);
	quick_sort(arr,10);
	show(arr,10);
}
