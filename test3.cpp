#include "stdio.h"
#include "malloc.h"
//函数声明
int* mergeSort(int* list,int* temp,int len); //合并排序算法函数
void copyArray(int* targetArra, int* tempArra, int len); //从临时数组中复制所有元素的值
到目标数组中
//测试数组
int myList[] = { 10, 0, 1131,123,12,4,1,5,234,12,13,14,1313,13,4231,2};
/*
@func: 
mergeSort --- 快速排序数组
@para：
int* list --- 待排序数组的首地址
int* temp --- 临时数组的首地址。临时数组的长度需要和原始数组一致
int len   --- 数组长度
@return:
int* list --- 排序完成后的数组首地址
*/
int* mergeSort(int* list,int* temp, int len) {
    //变量声明
    int middleLen, left_index, right_index;
    int *middlePointer, *list_left, *list_right;
    //如果只有数组只有1个元素，则返回该元素本身。退出递归
    if (len == 1){
        return list;
    }
    //将数组从中间分成两个。
    middleLen = int(len / 2);  //左边数组的长度
    middlePointer = list + middleLen;  //右边数组的首地址
    //对于新生成的两个数组，递归调用排序函数
    list_left = mergeSort(list,temp, middleLen);
    list_right = mergeSort(middlePointer,temp, (len - middleLen));
    //合并已经排序完成的两个数组
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
    //如果左边数组达到尾端，则把右边数组剩余的数据复制到temp中，并跳出循环
        if (left_index == middleLen) {
            copyArray(&temp[i], &list_right[right_index], (len - middleLen - right_index));
            break;
        }
    //如果右边数组达到尾端，则把左边数组剩余的数据复制到temp中，并跳出循环
        if (right_index == (len - middleLen)) {
            copyArray(&temp[i], &list_left[left_index], (middleLen - left_index));
            break;
        }
    }
    copyArray(list, temp, len);  //将临时数组中的数据复制回原始数组中
    return list;
}
/*
@func:
copyArray --- 复制数组内容
@para：
int* targetArra --- 目标数组的首地址
int* tempArra   --- 临时数组的首地址。临时数组的长度需要和目标数组一致
int len   --- 数组长度

@return:
N/A
*/
void copyArray(int* targetArra, int* tempArra, int len) {
    for (int i = 0; i < len; i++) {
        targetArra[i] = tempArra[i];
    }
}
/*****在主函数中调用排序算法进行测试****/
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
    //如果分配内存失败，则打印错误信息。
        printf("memory allocation failed.");
        getchar();
        return 0;
    }
}
