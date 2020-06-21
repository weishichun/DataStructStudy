#include <iostream>
#include <vector>
#include <stack>
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
void SwapV2(int &a, int &b)
{
    if(&a != &b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
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
    QuickSortRecursive(arr,nL+1,nRight);
}
//递归快速排序vector版本
int GetPartitions(vector<int> &vecNums,int low,int high)
{
    int keyVal = vecNums[low];
    while (low < high) {
        while (low < high && keyVal <= vecNums[high] ) {
            high--;
        }
        vecNums[low] = vecNums[high];
        while(low < high && keyVal >= vecNums[low]){
            low++;
        }
        vecNums[high] = vecNums[low];
    }
    vecNums[low] = keyVal;
    return low;
}
void QuickSortRecursiveV2(vector<int> &vecNums,int low,int high)
{
    if(low >= high)
    {
        return;
    }
    int nMid = GetPartitions(vecNums,low,high);
    QuickSortRecursiveV2(vecNums,low,nMid-1);
    QuickSortRecursiveV2(vecNums,nMid+1,high);
}
void PrintVec(vector<int> vecNums)
{
    cout << "当前vector序列:";
    for(auto num : vecNums)
    {
        cout << num << " ";
    }
    cout << endl;
}
void PrintVec2(vector<int> vec)
{
    cout << "当前vector序列: " << endl;
    cout << "序列号: ";
    int i = 0;
    for(auto it = vec.begin();it != vec.end(); it++,i++)
        printf("%3d ", i);
    cout << endl;
    cout << "元素值: ";
    for(auto it = vec.begin();it != vec.end(); it++)
        printf("%3d ", *it);
    cout << endl;
}
void QuickSortNonRecursive(vector<int>& vecNums,int low, int high)
{
    stack<int> stackNum;
    if(low < high)
    {
        PrintVec2(vecNums);
        printf("划分区域:[%d,%d]\n",low,high);
        int nMid = GetPartitions(vecNums,low,high);
        printf("基准数:%d,位置:%d,结果如下:\n",vecNums[nMid],nMid);
        PrintVec2(vecNums);
        if(nMid - 1 > low)
        {
            printf("基准数左边范围边界入栈:[%d,%d]\n",low,nMid-1);
            stackNum.push(low);
            stackNum.push(nMid -1);
        }
        if(nMid + 1 < high)
        {
            printf("基准数右边范围边界入栈:[%d,%d]\n",nMid+1,high);
            stackNum.push(nMid + 1);
            stackNum.push(high);
        }
        while (!stackNum.empty())
        {
            int qHeight = stackNum.top();
            stackNum.pop();
            int pLow = stackNum.top();
            stackNum.pop();
            printf("区域边界出栈,并划分区域:[%d,%d]\n",pLow,qHeight);
            int pqMid = GetPartitions(vecNums, pLow, qHeight);
            printf("基准数:%d,位置:%d,结果如下:\n",vecNums[pqMid],pqMid);
            PrintVec2(vecNums);
            if (pqMid - 1 > pLow)
            {
                printf("基准数左边范围边界入栈:[%d,%d]\n",pLow,pqMid-1);
                stackNum.push(pLow);
                stackNum.push(pqMid - 1);
            }
            if (pqMid + 1 < qHeight)
            {
                printf("基准数右边范围边界入栈:[%d,%d]\n",pqMid+1,qHeight);
                stackNum.push(pqMid + 1);
                stackNum.push(qHeight);
            }
        }
    }
}
int main()
{
    cout << "*******************快速排序递归数组版本***********************" << endl;
    int arr[10] = {89,32,38,487,43,0,5,893,13,3143};
    QuickSortRecursive(arr,0,9);
    PrintArray(arr,0,9);
    cout << endl <<  "*******************快速排序递归,vector版本***********************" << endl;
    vector<int> vecNums = {89,32,38,487,43,0,5,893,13,3143};
    PrintVec2(vecNums);
    QuickSortRecursiveV2(vecNums,0,vecNums.size()-1);
    PrintVec2(vecNums);
    cout <<  endl << "*******************快速排序非递归版本***********************" << endl;
    vecNums.clear();
    vecNums = {89,32,38,487,43,0,5,893,13,3143};
    QuickSortNonRecursive(vecNums,0, vecNums.size()-1);
    PrintVec2(vecNums);
    return 0;
}
