#include "stdio.h"
#include "malloc.h"
//��������
int* mergeSort(int* list,int* temp,int len); //�ϲ������㷨����
void copyArray(int* targetArra, int* tempArra, int len); //����ʱ�����и�������Ԫ�ص�ֵ
��Ŀ��������
//��������
int myList[] = { 10, 0, 1131,123,12,4,1,5,234,12,13,14,1313,13,4231,2};
/*
@func: 
mergeSort --- ������������
@para��
int* list --- ������������׵�ַ
int* temp --- ��ʱ������׵�ַ����ʱ����ĳ�����Ҫ��ԭʼ����һ��
int len   --- ���鳤��
@return:
int* list --- ������ɺ�������׵�ַ
*/
int* mergeSort(int* list,int* temp, int len) {
    //��������
    int middleLen, left_index, right_index;
    int *middlePointer, *list_left, *list_right;
    //���ֻ������ֻ��1��Ԫ�أ��򷵻ظ�Ԫ�ر����˳��ݹ�
    if (len == 1){
        return list;
    }
    //��������м�ֳ�������
    middleLen = int(len / 2);  //�������ĳ���
    middlePointer = list + middleLen;  //�ұ�������׵�ַ
    //���������ɵ��������飬�ݹ����������
    list_left = mergeSort(list,temp, middleLen);
    list_right = mergeSort(middlePointer,temp, (len - middleLen));
    //�ϲ��Ѿ�������ɵ���������
    left_index = 0;
    right_index = 0;
    int i = 0;
    while (1) {
        if (list_left[left_index] > list_right[right_index]){
            temp[i++] = list_left[left_index++];
        }
        else {
            temp[i++] = list_right[right_index++];
        }
    //����������ﵽβ�ˣ�����ұ�����ʣ������ݸ��Ƶ�temp�У�������ѭ��
        if (left_index == middleLen) {
            copyArray(&temp[i], &list_right[right_index], (len - middleLen - right_index));
            break;
        }
    //����ұ�����ﵽβ�ˣ�����������ʣ������ݸ��Ƶ�temp�У�������ѭ��
        if (right_index == (len - middleLen)) {
            copyArray(&temp[i], &list_left[left_index], (middleLen - left_index));
            break;
        }
    }
    copyArray(list, temp, len);  //����ʱ�����е����ݸ��ƻ�ԭʼ������
    return list;
}
/*
@func:
copyArray --- ������������
@para��
int* targetArra --- Ŀ��������׵�ַ
int* tempArra   --- ��ʱ������׵�ַ����ʱ����ĳ�����Ҫ��Ŀ������һ��
int len   --- ���鳤��

@return:
N/A
*/
void copyArray(int* targetArra, int* tempArra, int len) {
    for (int i = 0; i < len; i++) {
        targetArra[i] = tempArra[i];
    }
}
/*****���������е��������㷨���в���****/
int main()
{
    int* temp, len;
    len = sizeof(myList) / sizeof(int);
    temp = (int*)malloc(len * sizeof(int));
    if (temp) {
        mergeSort(myList, temp, len);
        for (int i = 0; i < len; i++) {
            printf("%d ", myList[i]);
        }
        free(temp);
        getchar();
        return 0;
    }
    else {
    //��������ڴ�ʧ�ܣ����ӡ������Ϣ��
        printf("memory allocation failed.");
        getchar();
        return 0;
    }
}
