#include <stdio.h>
#include <stdlib.h>
//��������
void _quick_sort(int a[],int left,int right) //ֱ���������飬����ֵΪvoid
{
	//��������ָ��ָ��������±�
	int i = left;
	int j = right;
	//�ݹ����
	if(i>j)
		return;
	//��¼���ֵ
	int pivot = a[i];
	//һ��ѭ�����Եõ�����˵���඼�ȱ��С����˵��Ҳ඼�ȱ�˴�
	while(i<j)
	{
		//��right��ʼ�ұȱ��С��Ϊֹ
		while(i<j && a[j]>=pivot)
			j--;
		//����С������ֵ��left��
		a[i] = a[j];
		//��left��ʼ�ұȱ�˴��Ϊֹ
		while(i<j && a[i]<=pivot)
			i++;
		//���ϴ������ֵ��right��
		a[j] = a[i];
	}
	//�����ֵ����������
	a[i] = pivot;
	//һ��ѭ�����
	//���������Ҳ�ĵݹ�
	_quick_sort(a,left,i-1);
	_quick_sort(a,i+1,right);
}
//���ÿ�������
void quick_sort(int a[],size_t len)
{
	_quick_sort(a,0,len-1);
}
//��ʾ����
void show(int a[],int len)
{
	for(int i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");
}
//������
int main()
{
	int arr[10]={1233,213,1233,-88,-88,454,2,-88,0,-22};
	show(arr,10);
	quick_sort(arr,10);
	show(arr,10);
}
