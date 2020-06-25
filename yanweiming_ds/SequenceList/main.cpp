#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
#define TRUE 1
#define FALSE 0
typedef struct{
    int x;
    int y;
} Point2D;
typedef struct{
    Point2D *pt;//线性表数据项
    int length; //线性表当前长度
    int szie; //线性表总容量
}SequenceList;
//创建长为nLen的线性表
SequenceList *Creat(int nLen)
{
    SequenceList *pSL = (SequenceList *)malloc(sizeof(SequenceList));
    if(NULL == pSL){
        return NULL;
    }
    pSL->pt = (Point2D *)malloc(nLen*sizeof(Point2D));
    if(NULL == pSL->pt){
        free(pSL);
        return NULL;
    }
    pSL->length = 0;
    pSL->szie = nLen;
    return  pSL;
}
//销毁线性表
void Destroy(SequenceList* pSL)
{
    if(NULL == pSL){
        return;
    }
    free(pSL->pt);//先释放线性表元素pt
    free(pSL);
}
//清空线性表
void Clear(SequenceList* pSL)
{   //只是线性表的元素个数变成0, 空间并没有释放
    if(NULL == pSL){
        return;
    }
    pSL->length = 0;
}
//判断线性表是否为空.
int IsEmpty(SequenceList* pSL)
{
    if(NULL == pSL){
        return FALSE;
    }
    return  pSL->length == 0 ? TRUE : FALSE;
}
//获取线性表长度
int GetLength(SequenceList* pSL)
{
    if(NULL == pSL){
        return FALSE;
    }
    return pSL->length;
}
//获取线性表容量
int GetSize(SequenceList* pSL)
{
    if(NULL == pSL){
        return FALSE;
    }
    return pSL->szie;
}
//获取线性表中第n个元素
int GetElement(SequenceList* pSL,int n,Point2D *pt)
{
    if(NULL == pSL || n < 0 || n > pSL->length -1){
        return FALSE;
    }
    pt->x = pSL->pt[n].x;
    pt->y = pSL->pt[n].y;
}
//从nPos起查找元素pt第一次出现的位置.
int FindElement(SequenceList* pSL,int nPos,Point2D *pt)
{
    if(NULL == pSL){
        return -1;
    }
    for(int n = nPos; n < pSL->length; ++n)
    {
        if(pt->x == pSL->pt[n].x && pt->y == pSL->pt[n].y)
            return n;
    }
    return -1;
}
//获取元素pt的直接前驱prior_pt
int GetPriorElement(SequenceList* pSL,Point2D *pt, Point2D *prior_pt)
{
    if(NULL == pSL){
        return -1;
    }
    for(int n = 0; n < pSL->length;++n)
    {
        if(pt->x == pSL->pt[n].x && pt->y == pSL->pt[n].y){
            if(n <= 0){
                return -1; //目标节点是头节点, 无直接前驱
            } else{
                prior_pt->x = pSL->pt[n-1].x;
                prior_pt->y = pSL->pt[n-1].y;
                return n - 1;
            }
        }
    }
    return -1; //线性表中无该元素.
}
//获取元素pt的直接后继next_pt
int GetNextElement(SequenceList* pSL, Point2D* pt, Point2D* next_pt)
{
    if(NULL == pSL){
        return -1;
    }
    for(int n = 0; n < pSL->length;++n)
    {
       if(pt->x == pSL->pt[n].x && pt->y == pSL->pt[n].y){
           if(n >= pSL->length -1){
               return -1;//目标节点是尾节点,无直接后继
           }
           else{
               next_pt->x = pSL->pt[n+1].x;
               next_pt->y = pSL->pt[n+1].y;
               return n + 1;
           }
       }
    }
    return -1;
}
//将元素pt添加到线性表末尾处
int Append(SequenceList* pSL,Point2D* pt)
{
    if(NULL == pSL){
        return -1;
    }
    //检查扩容
    if(pSL->szie - pSL->length < 1){
        Point2D *p = (Point2D*)malloc(pSL->length*2*sizeof(Point2D));
        if(NULL == p){
            return -1;
        }
        memcpy(p,pSL->pt,pSL->length*sizeof(Point2D));
        pSL->szie = pSL->length * 2;
        free(pSL->pt);
        pSL->pt = p;
    }
    pSL->pt[pSL->length].x = pt->x;
    pSL->pt[pSL->length].y = pt->y;
    return ++pSL->length;
}
//将元素pt插入到线性表的nPos位置
int Insert(SequenceList* pSL,int nPos,Point2D* pt)
{
    if(NULL == pSL || nPos < 0 || nPos > pSL->length){
        return -1;
    }
    //检查扩容
    if(pSL->szie - pSL->length < 1){
        Point2D* p = (Point2D*)malloc(pSL->length*2*sizeof(Point2D));
        if(NULL == p){
            return -1;
        }
        memcpy(p,pSL->pt,pSL->length*sizeof(Point2D));
        pSL->szie = pSL->length*2;
        free(pSL->pt);
        pSL->pt = p;
    }
    for(int rightPos = pSL->length;rightPos > nPos; --rightPos){
        pSL->pt[rightPos].x = pSL->pt[rightPos-1].x;
        pSL->pt[rightPos].y = pSL->pt[rightPos-1].y;
    }
    pSL->pt[nPos].x = pt->x;
    pSL->pt[nPos].y = pt->y;
    return ++pSL->length;
}
//删除线性表上nPos位置的元素
int Delete(SequenceList* pSL, int nPos)
{
    if(NULL == pSL || nPos < 0 || nPos > pSL->length-1){
        return -1;
    }
    if(nPos == pSL->length-1){
        return --pSL->length;
    }
    for(nPos;nPos < pSL->length;++nPos){
        pSL->pt[nPos].x = pSL->pt[nPos+1].x;
        pSL->pt[nPos].y = pSL->pt[nPos+1].y;
    }
    return  --pSL->length;
}
//遍历线性表
void ForEach(SequenceList* pSL, void(*func)(Point2D* pt))
{
    if(NULL == pSL){
        return;
    }
    for(int i = 0; i < pSL->length; ++i)
    {
        func(&pSL->pt[i]);
    }
}
//复制线性表
int Copy(SequenceList* pSLdst,SequenceList* pSLsrc)
{
    if(NULL == pSLdst || NULL == pSLsrc){
        return -1;
    }
    //判断扩容
    if(pSLdst->szie - pSLsrc->length < 0){
        free(pSLdst->pt);
        pSLdst->pt  = (Point2D*)malloc(pSLsrc->length*sizeof(Point2D));
        pSLdst->szie = pSLsrc->length;
    }
    memcpy(pSLdst->pt,pSLsrc->pt,pSLsrc->length*sizeof(Point2D));
    pSLdst->length = pSLsrc->length;
    return pSLdst->length;
}
//拼接线性表
int Concat(SequenceList* pSLdst,SequenceList* pSLsrc)
{
    if(NULL == pSLdst || NULL == pSLsrc){
        return -1;
    }
    if(pSLdst->szie - pSLdst->length < pSLsrc->length){
        //dst的剩余元素空间小于src的长度, 需要扩容
        Point2D* p = (Point2D*)malloc((pSLdst->length+pSLsrc->length)*sizeof(Point2D));
        memcpy(p,pSLdst->pt,pSLdst->length*sizeof(Point2D));
        free(pSLdst->pt);
        pSLdst->pt = p;
        pSLdst->szie = pSLdst->length + pSLsrc->length;
    }
    for(int pos = 0;pos < pSLsrc->length; ++pos)
    {
        pSLdst->pt[pSLdst->length+pos].x = pSLsrc->pt[pos].x;
        pSLdst->pt[pSLdst->length+pos].y = pSLsrc->pt[pos].y;
    }
    pSLdst->length += pSLsrc->length;
    return pSLdst->length;
}
void PrintPosition(Point2D* pt)
{
    printf("(%d,%d) ",pt->x,pt->y);
}
int main()
{
    Point2D pt1,pt2;
    SequenceList *pLa = Creat(10);//创建一个容量为10的线性表
    printf("创建线性表A:len:%d,size:%d\n",GetLength(pLa),GetSize(pLa));
    for(int i = 0; i < 10; ++i)
    {
        pt1.x = i;
        pt1.y = i;
        Append(pLa,&pt1);
    }
    ForEach(pLa,PrintPosition);
    cout << endl;
    printf("线性表A填入10个元素后:len:%d,size:%d\n",GetLength(pLa),GetSize(pLa));
    cout << endl << "再填入10到35,共25个元素, 测试被动扩容" << endl;
    for(int i = 10;i < 35; ++i)
    {
        pt1.x = i;
        pt1.y = i;
        Append(pLa,&pt1);
    }
    ForEach(pLa,PrintPosition);
    cout << endl;
    printf("线性表A:len:%d,size:%d\n",GetLength(pLa),GetSize(pLa));

    cout << endl;
    cout << "在线性表A头部,尾部,中间插入(100,100)" << endl;
    pt1.x = 100;
    pt1.y = 100;
    Insert(pLa,0,&pt1);
    Insert(pLa,GetLength(pLa),&pt1);
    Insert(pLa,GetLength(pLa)/2,&pt1);
    ForEach(pLa,PrintPosition);
    cout << endl;
    printf("当前线性表A:len:%d,size:%d\n",GetLength(pLa),GetSize(pLa));
    cout << endl;
    Point2D pre_pt, next_pt;
    GetElement(pLa,5,&pt2);
    GetPriorElement(pLa,&pt2,&pre_pt);
    GetNextElement(pLa,&pt2,&next_pt);
    printf("获取线性表A第5位元素为:(%d,%d),前驱:(%d,%d),后继:(%d,%d)\n",
           pt2.x,pt2.y,pre_pt.x,pre_pt.y,next_pt.x,next_pt.y);
    printf("后继元素(%d,%d)第一次在线性表A中出现的位置:%d\n",next_pt.x,next_pt.y,
           FindElement(pLa,0,&next_pt));
    cout << endl;
    Delete(pLa,0);
    printf("删除线性表A第0位置元素\n");
    ForEach(pLa,PrintPosition);
    cout << endl;
    printf("当前线性表A:len:%d,size:%d\n",GetLength(pLa),GetSize(pLa));

    SequenceList *pLb = Creat(50);
    for(int i = 10;i < 60; ++i)
    {
        pt2.x = i;
        pt2.y = i;
        Append(pLb,&pt2);
    }
    printf("\n创建线性表B,并填入50个元素\n");
    ForEach(pLa,PrintPosition);
    printf("\n当前线性表B:len:%d,size:%d\n",GetLength(pLa),GetSize(pLa));
    printf("\n将线性表B复制到线性表A\n");
    Copy(pLa,pLb);
    ForEach(pLa,PrintPosition);
    cout << endl;
    printf("当前线性表A:len:%d,size:%d\n",GetLength(pLa),GetSize(pLa));
    cout << endl;
    printf("将线性表B连接到线性表A\n");
    Concat(pLa,pLb);
    ForEach(pLa,PrintPosition);
    cout << endl;
    printf("当前线性表A:len:%d,size:%d\n",GetLength(pLa),GetSize(pLa));

    printf("清空线性表A\n");
    Clear(pLa);
    ForEach(pLa,PrintPosition);
    cout << endl;
    printf("当前线性表A:len:%d,size:%d\n",GetLength(pLa),GetSize(pLa));
    printf("线性表A  IsEmpty=%d\n",IsEmpty(pLa));
    cout << "销毁线性表A,B" << endl;
    Destroy(pLa);
    Destroy(pLb);
    return 0;
}
