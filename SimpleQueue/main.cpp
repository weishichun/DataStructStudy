#include <iostream>
#include <vector>
using namespace std;
class SimpleQueue
{
private:
    vector<int> data;//存放队列元素的数组
    int m_nStartPos; //存放队列头部位置
public:
    SimpleQueue() {
        m_nStartPos = 0;
    }
    bool EnQueue(int n) {
        data.push_back(n);//入队
        return true;
    }
    bool DeQueue() {
        if (IsEmpty()) {
            return false;
        }
        m_nStartPos++; //出队,头部位置指向下一个位置.
        return true;
    }
    bool IsEmpty() {
        if (m_nStartPos >= data.size()) {//注意边界条件是>=
            return true; //头部位置超过数组长度, 队列变空.
        }
        return false;
    }
    int Front() {
        return data[m_nStartPos];//返回头元素.
    }
};
int main()
{
    SimpleQueue q;
    q.EnQueue(10);
    q.EnQueue(5);
    if (!q.IsEmpty()) {
        cout << q.Front() << endl;
    }
    q.DeQueue();
    if (!q.IsEmpty()) {
        cout << q.Front() << endl;
    }
    q.DeQueue();
    if (!q.IsEmpty()) {
        cout << q.Front() << endl;
    }
    return 0;
}

