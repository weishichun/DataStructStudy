#include <iostream>
#include <vector>
using namespace std;
void PrintVec(vector<int> vec)
{
    cout << "当前序列: ";
    for(auto it = vec.begin();it != vec.end(); it++)
        cout << *it  << " ";
    cout << endl;
}
void PrintArray(int *arr,int len)
{
    cout << "当前序列: ";
    for(int i = 0; i < len ; i++)
        cout << *(arr+i)  << " ";
    cout << endl;
}
void BubbleSortByVector(vector<int>& vec)
{
    cout << "************冒泡排序非优化版本>>待排序元素个数:" << vec.size() << endl;
    PrintVec(vec);
    for(size_t i = 0; i < vec.size() -1; i++) //总共需要循环vec.size()-1趟
    {
        cout << "第" << i+1 << "趟:" << endl;
        for(size_t j = 0; j < vec.size() -1; j++) //每一趟需要比较的次数也为vec.size()-1次
        {
            cout << "..第" << j+1 << "个元素比较: ";
            if(vec[j] > vec[j+1])//这不是优版本,因为遇到1,2,3,4已有序的情况,仍然是O(n^2).
            {
                cout << vec[j] << " > " << vec[j+1] << ",交换" <<  endl;
                swap(vec[j],vec[j+1]);
            }
            else
            {
                cout << vec[j] << " <= " << vec[j+1] << ",不交换" <<  endl;
            }
            PrintVec(vec);
        }
    }
}
void BubbleSortByVector2(vector<int>& vec)
{
    cout << "***********冒泡排序优化V1>>待排序元素个数:" << vec.size() << endl;
    PrintVec(vec);
    for(size_t i = 0; i < vec.size() -1; i++) //总共需要循环vec.size()-1趟
    {
        bool bSwap = false; //本趟是否发生交换,如果未发生交换, 说明序列已有序
        cout << "第" << i+1 << "趟:" << endl;
        for(size_t j = 0; (j < vec.size() -1); j++) //每一趟需要比较的次数也为vec.size()-1次
        {
            cout << "..第" << j+1 << "个元素比较: ";
            if(vec[j] > vec[j+1])
            {
                cout << vec[j] << " > " << vec[j+1] << ",交换" <<  endl;
                swap(vec[j],vec[j+1]);
                bSwap = true;
            }
            else
            {
                cout << vec[j] << " <= " << vec[j+1] << ",不交换" <<  endl;
            }
            PrintVec(vec);
        }
        if(!bSwap)
        {
            cout << "本趟未发生交换,序列已经有序" << endl;
            break;//该趟未发生交换,已有序, 终止比较
        }
    }
}

void BubbleSortByVector3(vector<int>& vec)
{
    cout << "***********冒泡排序优化V2>>待排序元素个数:" << vec.size() << endl;
    PrintVec(vec);
    bool bSwap = true; //本趟是否发生交换,如果未发生交换, 说明序列已有序,初始是乱序的, 需要遍历交换
    for(size_t i = 0; i < vec.size() -1 && bSwap; i++) //总共需要循环vec.size()-1趟
    {
        bSwap = false; //假定第趟扫描完成,没有发生交换,序列已有序
        cout << "第" << i+1 << "趟:" << endl;
        for(size_t j = 0; (j < vec.size() -1); j++) //每一趟需要比较的次数也为vec.size()-1次
        {
            cout << "..第" << j+1 << "个元素比较: ";
            if(vec[j] > vec[j+1])
            {
                cout << vec[j] << " > " << vec[j+1] << ",交换" <<  endl;
                swap(vec[j],vec[j+1]);
                bSwap = true;
            }
            else
            {
                cout << vec[j] << " <= " << vec[j+1] << ",不交换" <<  endl;
            }
            PrintVec(vec);
        }
    }
}
//待排序数组arr,元素个数为len
void BubbleSort(int *arr,int len)
{
    cout << "**********C语言版本冒泡排序>>从后冒泡,元素个数: " << len << endl;
    PrintArray(arr,len);
    int i = 0, j = 0,tmp = 0;
    bool bSwap = true;
    for(i = 0; i < len-1 && bSwap; i++)
    {
        bSwap = false;
        cout << "第" << i+1 << "趟:" << endl;
        for(j = len - 1; j > 0; j--)
        {
            cout << "..第" << j+1 << "个元素比较: ";
            if(arr[j] < arr[j-1])
            {
                cout << arr[j] << " < " << arr[j-1] << ",交换" <<  endl;
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
                bSwap = true;
            }
            else
            {
                cout << arr[j] << " >= " << arr[j-1] << ",不交换" <<  endl;
            }
            PrintArray(arr,len);
        }
    }
}
int main()
{
    vector<int> VecData = {1,2,3,4};
    BubbleSortByVector(VecData);

    VecData.clear();
    VecData = {9,1,2,3};
    BubbleSortByVector2(VecData);

    VecData.clear();
    VecData = {9,1,2,3};
    BubbleSortByVector3(VecData);

    VecData.clear();
    VecData = {1,2,3,4};
    BubbleSortByVector2(VecData);

    VecData.clear();
    VecData = {1,2,3,4};
    BubbleSortByVector3(VecData);

    int arr[4] = {94,22,531,4};
    BubbleSort(arr,4);
    int arr1[4] = {2,3,9,4};
    BubbleSort(arr1,4);
    int arr2[4] = {1,2,3,4};
    BubbleSort(arr2,4);
    return 0;
}
