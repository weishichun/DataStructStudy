#include <iostream>
#include <vector>
#include <map>
using namespace std;
void PrintVec(vector<int> vec)
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
vector<int> twoSum(vector<int>& vecNums,int target)
{
    map<int, int> m;
    int i = 0;
    while(i < vecNums.size())
    {
        printf("第%d趟\n",i+1);
        int nCount = m.count(vecNums[i]);
        printf("vecNums[%d]=%d,m.cout(%d)=%d\n",i,vecNums[i],vecNums[i],nCount);
        if(nCount){
            printf("{m[vecNums[%d]]=%d,i=%d}\n",i,m[vecNums[i]],i);
            return {m[vecNums[i]],int(i)};
        }
        int Key = target - vecNums[i];
        m[Key] = i;
        printf("Key:%d-%d=%d,Value=%d\n",target,vecNums[i],Key,i);
        i++;
    }
    return {-1,-1};
}
vector<int> twoSum1(vector<int>& vecNums,int target)
{
    vector<int> vecRet(2,-1);//用于存放结果下标向量
    map<int,int> mHash;
    for(int i = 0; i < vecNums.size();i++)
    {
        auto find = mHash.find(target-vecNums[i]);
        if(find !=mHash.end() && find->second != i){
            vecRet[0] = find->second;
            vecRet[1] = i;
            break;
        }
        mHash[vecNums[i]] = i;
    }
    return vecRet;
}
vector<int> twoSum2(vector<int>& vecNums,int target)
{
    map<int,int> mHash;
    for(int i = 0; i < vecNums.size(); i++)
    {
        int key = target - vecNums[i];
        if(mHash.count(vecNums[i]))
        {
            return {mHash[vecNums[i]],i};
        }
        mHash[key] = i;
    }
    return {-1,-1};
}
int main()
{
    vector<int> vecNums = {2,7,11,15,4};
    cout << "twoSum............." << endl;
    PrintVec(vecNums);
    vector<int> vecRet = twoSum(vecNums,19);
    PrintVec(vecRet);
    cout << "twoSum1............" << endl;
    PrintVec(vecNums);
    vecRet = twoSum1(vecNums,19);
    PrintVec(vecRet);
    cout << "twoSum2............" << endl;
    PrintVec(vecNums);
    vecRet = twoSum2(vecNums,19);
    PrintVec(vecRet);
    return 0;
}
