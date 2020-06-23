#include <iostream>
#include <vector>
#include <string>
using namespace std;
void PrintArray(int arr[],int len)
{
    cout << "下标值: ";
    for(int i = 0; i < len ; i++)
        printf("%4d",i);
    cout << endl;
    cout << "元素值: ";
    for(int i = 0; i < len ; i++)
        printf("%4d",arr[i]);
    cout << endl;
}
void SelectionSort(int arr[], int len)
{
    int minIndex;//最小元素下标值
    int tmp;
    int m = len -1;
    for(int i = 0; i < m; i++)
    {
        minIndex = i;
        printf("第%d趟比较,假定初始最小元素为arr[%d]:%d,与%d号向后的各元素比较\n",i+1,i,arr[i],i+1);
        for(int j = i + 1; j < len; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                printf("arr[%d]:%d < 最小元素arr[%d]:%d,更新最小元素下标为:%d\n",
                       j,arr[j],minIndex,arr[minIndex],j);
                minIndex = j;
            }
            else
            {
                printf("arr[%d]:%d >= 最小元素arr[%d]:%d,最小元素下标不更新.\n",
                       j,arr[j],minIndex,arr[minIndex]);
            }
        }
        if(i != minIndex)
        {
            printf("本趟最小元素下标有更新为:%d,交换初始最小元素arr[%d]:%d和本趟最终最小元素arr[%d]:%d\n",
                   minIndex,minIndex,arr[minIndex],i,arr[i]);
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
            PrintArray(arr,len);
        }
    }
}
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    PrintArray(arr,10);
    SelectionSort(arr,10);
    return 0;
}
