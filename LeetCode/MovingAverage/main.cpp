#include <iostream>
#include <deque>
using namespace std;
/*
 * 题目：
给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。
示例:
MovingAverage m = new MovingAverage(3);
m.next(1) = 1 // 返回 1.00000
m.next(10) = (1 + 10) / 2 // 返回 5.50000
m.next(3) = (1 + 10 + 3) / 3 // 返回 4.66667
m.next(5) = (10 + 3 + 5) / 3 // 返回 6.0000
*/
class MovingAverage
{
private:
    int size;//窗口大小
    deque<unsigned long long> dequeSlidingWindow;
    unsigned long long sum;
public:
    MovingAverage(int size)
    {
        this->size = size;
        sum = 0;
    }
    double next(int val)
    {
        cout << "next(" << val << ")" << "....................." << endl;
        cout << "cur sum:" << sum << endl;
        cout << "slideWindow size:" << dequeSlidingWindow.size() << endl;
        if(dequeSlidingWindow.size() < size)
        {//当前队列元素个数小于滑动窗口大小,还可以入队
            dequeSlidingWindow.push_back(val);
            cout << "入队:" << val << endl;
            cout << "sum = sum + val = " << sum << " + " << val << endl;
            sum += val;
            cout << "sum:" << sum << endl;
        }
        else
        {//当前队列元素个数已经大于或等于滑动窗口大小,所以要先出队一个元素, 才能入队一个元素.
            cout << "sum = sum - (队头元素) = " << sum << " - " << dequeSlidingWindow.front() << endl;
            sum -= dequeSlidingWindow.front();
            cout << "sum:" << sum << endl;
            cout << "sum = sum + val = " << sum << " + " << val << endl;
            sum += val;
            cout << "sum:" << sum << endl;
            cout << "出队:" << dequeSlidingWindow.front() << endl;
            dequeSlidingWindow.pop_front();
            dequeSlidingWindow.push_back(val);
            cout << "入队:" << val << endl;
        }
        double ret = (sum * 1.0)/dequeSlidingWindow.size(); //*1.0的目的是不进行隐式转换
        cout << "average = sum / 窗口大小(3) = " << ret << endl;
        return ret;
    }
};

int main()
{
    MovingAverage mv(3);
    mv.next(1);
    mv.next(10);
    mv.next(13);
    mv.next(5);
    mv.next(8);
    mv.next(9);
    return 0;
}
