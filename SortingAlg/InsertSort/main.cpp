#include <iostream>
#include <vector>
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
void InsertSort(vector<int> &vecNums)
{
    for(size_t i = 1; i < vecNums.size(); ++i)
    {
        printf("第%d趟:-----------------------------\n",i);
        int key = vecNums[i]; //待排序第一个元素
        int j = i - 1;  //代表已经排过序的元素最后一个索引数
        printf("基准元素Key:%d,位置:%d,已排序元素最后位置:%d\n",key,i,j);
        while (j >= 0 && key < vecNums[j])
        {
            //从后向前逐个比较已经排序过数组，如果比它小，则把后者用前者代替，
            printf("Key:%d < %d号元素%d,所以用%d号元素%d替换%d号元素%d的值.结果如下:\n",
                   key,j,vecNums[j],j,vecNums[j],j+1,vecNums[j+1]);
            vecNums[j + 1] = vecNums[j];
            PrintVec2(vecNums);
            j--;
        }
        printf("本趟结束,基准元素Key:%d,最终位置:%d,更新结果如下:\n",key,j+1);
        vecNums[j + 1] = key;
        PrintVec2(vecNums);
    }
}
int main()
{
    vector<int> vecNums = {73,42,316,5,562};
    PrintVec2(vecNums);
    InsertSort(vecNums);
    PrintVec2(vecNums);
    return 0;
}
