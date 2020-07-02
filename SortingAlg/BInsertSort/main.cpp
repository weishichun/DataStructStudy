#include <iostream>
using namespace std;

void PrintArray(int arr[],int len)
{
    cout << "当前序列: \n";
    cout << "元素值: ";
    for(int i = 0; i < len ; i++)
        printf("%4d ",arr[i]);
    cout << endl;
    cout << "下标值: ";
    for(int i = 0; i < len ; i++)
        printf("%4d ",i);
    cout << endl;
}
void BinaryInsertSort(int *arr,int len)
{
    for(int i = 1; i < len; i++)
    {
        printf("第%d趟\n",i);
        int low = 0;
        int high = i-1;
        int key = arr[i];
        printf("low:%d,high:%d,key:%d\n",low,high,key);
        while(low <= high){
            int mid = (low+high)/2;
            printf("(%d <= %d)成立,mid:%d\n",
                   low,high,mid);
            if(key < arr[mid]){
                high = mid -1;
                printf("key:%d < arr[mid]:%d,high:%d\n",
                       key,arr[mid],mid-1);
            }else{
                low = mid + 1;
                printf("key:%d >= arr[mid]:%d,low:%d\n",
                       key,arr[mid],mid+1);
            }
        }
        for(int j = i; j > low; --j){
            printf("---------------------------------------------------------------\n");
            printf("确认插入位置:%d,之后元素逐位向后移\n",low);
            arr[j] = arr[j-1];
            PrintArray(arr,10);
            printf("---------------------------------------------------------------\n");
        }
        printf("key元素%d替换low:%d位置元素\n",key,low);
        arr[low] = key;
        PrintArray(arr,len);
    }
}

int main()
{
    int arr[10] = {23,1,14,8,9,7,87,53,78,54};
    PrintArray(arr,10);
    BinaryInsertSort(arr,10);
    return 0;
}
