#include <iostream>

using namespace std;
void PrintArray(int arr[],int nStart,int nEnd)
{
    cout << "序号值: ";
    for(int i = nStart; i <= nEnd ; i++)
        printf("%3d ",i);
    cout << endl;
    cout << "元素值: ";
    for(int i = nStart; i <= nEnd ; i++)
        printf("%3d ",arr[i]);
    cout << endl;
}
void Swap(int arr[],int i, int j)
{
    cout << "交换位置: " << i << ", " << j  << endl;
    cout << "交换" << arr[i] << "和" << arr[j] << endl;
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
/* 快速排序递归版本:
 * 从序列中随机选择一个基准数,将基准移动到数据中间,
 * 使得基准左边的数都小于或等于基准数,
 * 使得基准右边的数都大于或等于基准数,
 * 并返回基准数的位置索引.
 * 然后再分别递归快速排序基准数左边和右边范围的序列
 */
void QuickSortRecursive(int arr[],int nLeft,int nRight)
{
    if(nLeft >= nRight)
    {
        printf("范围错误:(%d~%d),结束当前快速排序.\n",nLeft,nRight);
        return;
    }
    printf("当前待排序列:%d~%d号元素如下\n",nLeft,nRight);
    PrintArray(arr,nLeft,nRight);
    int nL = nLeft;
    int nR = nRight;
    int nPrivot = arr[nLeft];
    printf("--------选择第%d号元素%d作为基准数\n",nLeft,nPrivot);
    while(nL < nR)
    {
        while (nL < nR && nPrivot <= arr[nR]) {
            nR--;
        }
        printf("右边第%d号元素%d小于或等于基准数%d,所以将%d替换左边第%d号元素%d,当前右游标位置:%d,结果如下:\n",
               nR,arr[nR],nPrivot,arr[nR], nL,arr[nL],nR);
        arr[nL] = arr[nR];
        PrintArray(arr,nLeft,nRight);
        while (nL < nR && nPrivot >= arr[nL]) {
            nL++;
        }
        printf("左边第%d号元素%d大于或等于基准数%d,所以将%d替换右边第%d号元素%d,当前左游标位置:%d,结果如下:\n",
               nL,arr[nL],nPrivot,arr[nL], nR,arr[nR],nL);
        arr[nR] = arr[nL];
        PrintArray(arr,nLeft,nRight);
    }
    printf("基准数:%d归位,落在位置:%d,更新,结果如下:\n",nPrivot,nL);
    arr[nL] = nPrivot;
    PrintArray(arr,nLeft,nRight);
    printf("********递归快排基准数左边第%d~%d号元素\n",nLeft,nL-1);
    QuickSortRecursive(arr,nLeft,nL-1);
    printf("********递归快排基准数右边第%d~%d号元素\n",nL+1,nRight);
    QuickSortRecursive(arr,nL+1,nRight);
}
int main()
{
    int arr[10] = {89,32,38,487,43,0,5,893,13,3143};
    QuickSortRecursive(arr,0,9);
    PrintArray(arr,0,9);
    return 0;
}
