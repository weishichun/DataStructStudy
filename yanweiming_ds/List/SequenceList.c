#include <stdio.h>
#include <stdlib.h>
#include   "../../common.h"

//status code
#define TRUE    1
#define FALSE   0
#define YES     1
#define NO      0
#define SUCCESS     1
#define FAILURE     0
#define OK     1   //正确
#define ERROR       -1  //错误
#define OVER_FLOW   -2  //上溢
#define UNDER_FLOW  -3  //下溢

#define LIST_INIT_SIZE 20  //顺序表初始大小
#define LIST_INCREMENT  10  //扩容增量
typedef int SqL_ElemType;   //顺序表的元素类型为int
typedef int Status;  
typedef struct{
    SqL_ElemType *elem;     //顺序表存储空间基址, 即数组第一个元素的地址
    int nLength;            //当前顺序表长度
    int nSize;              //当前顺序表的存储容量 
}SqList;
Status CompareBig(SqL_ElemType a,SqL_ElemType b){
    return a > b ? TRUE : FALSE;
}
void PrintElem(SqL_ElemType e){
    printf("%d ",e);
}
//初始化空的顺序表L
Status Initial_SqL(SqList *L) {
    L->elem = (SqL_ElemType*)malloc(LIST_INIT_SIZE*sizeof(SqL_ElemType));
    if (NULL == L->elem){
        exit(OVER_FLOW);
    }
    L->nLength = 0;
    L->nSize = LIST_INIT_SIZE;
} 

//清空顺序表L,存储空间仍然存在, 只是nLenght是0
void Clear_SqL(SqList *L) {
    L->nLength = 0;
}     

//销毁顺序表L
void Destroy_SqL(SqList *L) {
    free(L->elem);
    L->elem = NULL;
    L->nLength = 0;
    L->nSize = 0;
}  

//顺序列是否为pow
Status Empty_SqL(SqList L){
    return L.nLength==0 ? TRUE : FALSE;
}

//返回顺序表L的长度
int Length_SqL(SqList L) {
    return L.nLength;
}  

//IN:L, i
//OUT:e
//用e接收顺序表L中位置i的元素
Status GetElem_SqL(SqList L,int i,SqL_ElemType *e){
   if(i < 1 || i > L.nLength) {
       return ERROR;
   }
   *e = L.elem[i-1];
   return OK;
}

//返回顺序表中首个与e相等的元素的位置
int Locate_Elem(SqList L,SqL_ElemType e, Status(Commpare)(SqL_ElemType,SqL_ElemType)){
    int i = 1;
    while(i <= L.nLength && !Commpare(e,L.elem[i-1])){
        i++;
    }
    if(i <= L.nLength){
        return i;
    }
    return 0;
}

//用pPre_e接收cur_e的直接前驱
Status PreElem_SqL(SqList L, SqL_ElemType cur_e, SqL_ElemType * pPre_e){
    if(cur_e == L.elem[0]){
        return ERROR;//第一个元素无前驱
    }
    int i = 1;
    while(i < L.nLength && cur_e != L.elem[i]){
        i++;
    }
    if(i < L.nLength){
        *pPre_e = L.elem[i-1];
        return i;
    }
    return ERROR;
}

//用pNext_e接收cur_e的直接后继
Status NextElem_SqL(SqList L, SqL_ElemType cur_e, SqL_ElemType * pNext_e){
   if(cur_e == L.elem[L.nLength-1]){
       return ERROR; //最后一个元素无后继
   } 
   int i  = 1;
   while(i < L.nLength && cur_e != L.elem[i]){
       i++;
   }
   if(i < L.nLength-1){
       *pNext_e = L.elem[i+1];
       return OK;
   }
   return ERROR;
}

//将e元素插入顺序表L的第i位置前面
Status Insert_SqL(SqList *L, int i, SqL_ElemType e){
    if(i < 1 || i > L->nLength + 1) {
        return ERROR;
    }
    if(L->nLength >= L->nSize){
        SqL_ElemType *pNew = (SqL_ElemType*)realloc(L->elem,
            sizeof(SqL_ElemType)*(L->nSize + LIST_INCREMENT));
        L->elem = pNew;
        L->nSize += LIST_INCREMENT;
    }
    SqL_ElemType *pInsert;
    pInsert = &(L->elem[i-1]); //指向插入位置元素的地址
    for(int k = L->nLength-1;k >= i; k--){
        L->elem[k] = L->elem[k-1]; //插入位置后的所有元素逐个后移
    }
    *pInsert = e;
    L->nLength++;
    return OK;
}

//删除顺序表L第i位置元素, 前用e返回
Status Delete_SqL(SqList *L, int i, SqL_ElemType *e){
    if (i < 0 || i > L->nLength){
        return ERROR;//位置错误
    }
    *e = L->elem[i-1];

    while(i < L->nLength){
        L->elem[i-1] = L->elem[i];
        i++;
    }
    L->nLength--;
}

//遍历访问顺序表L的所有元素
Status Traverse_SqL(SqList L, void (Visit)(SqL_ElemType)){
    int i = 0;
    while(i < L.nLength){
        Visit(L.elem[i]);
        i++;
    }
}

int main(){
    SqList L;
    SqL_ElemType e;
    printf("初始化........\n");
    Initial_SqL(&L);
    printf("初始化完成\n");
    printf("&elem:%x,nLength:%d,nSize:%d\n",L.elem,L.nLength,L.elem);

    Empty_SqL(L)?printf("空表\n"):printf("非空表\n");

    for (int i = 0; i < 10; i++) {
        Insert_SqL(&L,i,i+1);
    }
    printf("当前表元素: ");
    Traverse_SqL(L,PrintElem); 
    printf("\n");
    printf("&elem:%x,nLength:%d,nSize:%d\n",L.elem,Length_SqL(L),L.elem);

    printf("删除第3,7位置的元素\n");
    Delete_SqL(&L,3,&e);
    Delete_SqL(&L,7,&e);
    printf("当前表元素: ");
    Traverse_SqL(L,PrintElem); 
    printf("\n");
    printf("&elem:%x,nLength:%d,nSize:%d\n",L.elem,Length_SqL(L),L.elem);

    GetElem_SqL(L,5,&e);
    printf("第5个元素是:%d\n",e);
    int i = Locate_Elem(L,4,CompareBig);
    printf("第一个大于4元素的位置:%d\n", i);
    PreElem_SqL(L,6,&e);
    printf("6的前驱:%d\n",e);
    NextElem_SqL(L,6,&e);
    printf("6的后继:d\n",e);

    printf("加元素到触发扩容\n"); 
    for (int i = 11; i < 30; i++) {
        Insert_SqL(&L,0,i+1);
    }
    printf("当前表元素: ");
    Traverse_SqL(L,PrintElem); 
    printf("\n");
    printf("&elem:%x,nLength:%d,nSize:%d\n",L.elem,Length_SqL(L),L.elem);

    printf("清空表\n");
    Clear_SqL(&L);
    printf("当前表元素: ");
    Traverse_SqL(L,PrintElem); 
    printf("\n");
    printf("&elem:%x,nLength:%d,nSize:%d\n",L.elem,Length_SqL(L),L.elem);
    L.elem?"表存在!\n":"表不存在!\n";

    printf("销毁表\n");
    Destroy_SqL(&L);
    L.elem?"表存在!\n":"表不存在!\n";
    
    return 0;
}