#include <iostream>
using namespace std;
void PrintArray(int arr[],int len)
{
    cout << "下标值: ";
    for(int i = 0; i < len ; i++)
        printf("%3d",i);
    cout << endl;
    cout << "元素值: ";
    for(int i = 0; i < len ; i++)
        printf("%3d",arr[i]);
    cout << endl;
}
const int GAPINCR = 3;
int ShellSort(int arr[],int len)
{
    int nInsertNum = 0;
    int gap = len/GAPINCR + 1; //加1是因为len小于GAPINCR的情况,gap值为1
    printf("初始步长gap=len/3+1:%d\n",gap);
    while(gap) //gap >= 1
    {
        for(int i = gap;i < len; i++)
        {
            nInsertNum = arr[i];  //当前元素作为本分组插入排序的基准数
            printf("插入排序基准值为%d号元素%d\n",i,arr[i]);
            int j = i;
            while (j >= gap && nInsertNum < arr[j-gap])
            {
                if(nInsertNum < arr[j-gap])
                {
                    printf("基准数:%d < (基准下标%d-步长%d)%d号元素%d,所以用%d替换%d,结果如下:\n",nInsertNum,j,gap,j-gap,arr[j-gap],arr[j-gap],arr[j]);
                    arr[j] = arr[j-gap];
                    j = j - gap;
                }
                PrintArray(arr,len);
            }
            if(j < gap){
                printf("下标:%d < 步长gap:%d\n",j, gap);
            }
            if(nInsertNum >= arr[j-gap])
            {
                printf("基准数:%d >= (基准下标%d减步长%d)%d号元素%d,位置不变\n",nInsertNum,j,gap,j-gap,arr[j-gap]);
            }
            printf("基准数:%d 归位于%d号位置,结果如下:\n",nInsertNum,j);
            arr[j] = nInsertNum;
            PrintArray(arr,len);
        }
        gap = gap/GAPINCR;
        printf("更新步长:gap=gap/3:%d\n",gap);
    }
}
int main()
{
    int arr[11] = {2, 1, 4, 3, 11, 6, 5, 7, 8, 10, 15};
    PrintArray(arr,11);
    ShellSort(arr, 11);
    PrintArray(arr,11);
    return 0;
}
