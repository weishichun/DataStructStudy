#include <iostream>
#include <vector>
using namespace std;
class CircleQueue
{
private:
    vector<int> data;//存放队列的数组
    int head;//队头指针
    int tail; //队尾指针
    int size;//循环队列大小
public:
    CircleQueue(int len){
        data.resize(len);
        head = -1;
        tail = -1;
        size = len;
    }
    bool IsFull(){
        if( (tail+1) % size == head){//尾指针+1 遇到head,队列就满了
            return true;
        }
        return false;
    }
    bool IsEmpty(){
        return head == -1;
    }
    bool EnQueue(int x){
        if(IsFull()){//入队,先判满
            return false;
        }
        if(IsEmpty()){ //入队,再判空, head指针由-1变0
            head = 0;
        }
        tail = (tail + 1) % size;//记住入队位置尾指针的算法, 才回首尾相接.
        data[tail] = x;
        return true;
    }
    bool DeQueue(){
        if(IsEmpty()){  //出队, 先判空
            return false;
        }
        if(head == tail){  //出队,再判是否是队列里的最后一个元素
            //头尾指针相等且不等于-1,就是队列中的最后一个元素.
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }
    int Front(){
        if(IsEmpty()){
            return -1;
        }
        return data[head];
    }
    int Rear(){
        if(IsEmpty()){
            return -1;
        }
        return data[tail];
    }
};
int main()
{
    CircleQueue q(3);
    q.EnQueue(10);
    q.EnQueue(20);
    cout << q.Front() << endl;
    cout << q.Rear() << endl;
    q.EnQueue(30);
    cout << q.IsFull() << endl;
    cout << q.Front() << endl;
    cout << q.Rear() << endl;
    q.DeQueue();
    q.DeQueue();
    q.EnQueue(40);
    q.DeQueue();
    q.DeQueue();
    cout << q.IsFull() << endl;
    cout << q.Front() << endl;
    cout << q.Rear() << endl;
    return 0;
}
