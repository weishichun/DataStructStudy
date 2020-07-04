#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*//墙与门--队列应用--广度优先搜索
给定一个 m × n 的二维网格，网格中有以下三种可能的初始化值：
-1:表示墙或是障碍物
0:表示一扇门
INF:无限表示一个空的房间。
然后，我们用 2^31 - 1 = 2147483647 代表 INF。你可以认为通往门的距离总是小于 2147483647 的。
你要给每个空房间位上填上该房间到最近门的距离，如果无法到达门，则填INF即可.
For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be
3  -1   0   1
2   2   1  -1
1  -1   2  -1
0  -1   3   4
*/
const int INF = 2147483647;
void PrintGrid(vector<vector<int>> rooms)
{
   int m = rooms.size();
   int n = rooms[0].size();
   printf("行|列");
   for(int i = 0; i < m ; i++)
   {
       printf("               %d",i);
   }
   cout << endl << "--------------------------------------------------------------------------------" << endl;
   for(int i = 0; i < m ; i++)
   {
       for(int j = 0; j < n; j++)
       {
           if(j == 0)
           {
               printf("%d  | ",i);
           }
           if(rooms[i][j] == -1)
           {
                printf("墙                |");
           }
           else if(rooms[i][j] == INF)
           {
                printf("房 间             |");
           }
           else if(rooms[i][j] == 0)
           {
                printf("门                |");
           }
           else
           {
               printf("走到门最少步数:%d  |",rooms[i][j]);
           }

       }
       cout << endl;
   }
   cout << "--------------------------------------------------------------------------------" << endl;
}
/*思路:借助queue，首先把门的位置都排入queue中，然后开始循环，
对于门位置的四个相邻点，我们判断其是否在矩阵范围内，并且位置值是否大于上一位置的值加1，
如果满足这些条件，我们将当前位置赋为上一位置加1，并将次位置排入queue中，
这样等queue中的元素遍历完了，所有位置的值就被正确地更新了
*/
void wallsAndGates(vector<vector<int>>& rooms)
{
    if (rooms.empty() || rooms[0].empty())
    {
        return;
    }
    int m = rooms.size(), n = rooms[0].size();
    vector<pair<int, int>> directs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};//位置向量:下,右,上,左
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rooms[i][j] == 0)
            {
                q.push(make_pair(i, j));//先把门所有门入队
                printf("(%d,%d)位置可达,入队\n",i,j);
            }
        }
    }
    while (!q.empty())
    {
        //队列不为空,取出队头元素位置索引,对各个门进行处理.
        int x = q.front().first;
        int y = q.front().second;
        printf("\n广度优先搜索进行时,(%d,%d)出队,并处理它的4个方向\n",x,y);
        q.pop();
        for (auto d : directs)
        {
            if(d.first == -1)
            {
                printf("处理位置(%d,%d)上边",x,y);
            }
            if(d.first == 1)
            {
                printf("处理位置(%d,%d)下边",x,y);
            }
            if(d.second == -1)
            {
                printf("处理位置(%d,%d)左边",x,y);
            }
            if(d.second == 1)
            {
                printf("处理位置(%d,%d)右边",x,y);
            }
            int nx = x + d.first, ny = y + d.second;
            printf("+方向向量(%d,%d)=(%d,%d)位置\n",d.first,d.second,nx,ny);
            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
            {
                if(nx < 0)
                {
                    printf("超出上边界,不处理\n");
                }
                if(nx >= m)
                {
                    printf("超出下边界,不处理\n");
                }
                if(ny < 0)
                {
                    printf("超出左边界,不处理\n");
                }
                if(nx >= n)
                {
                    printf("超出右边界,不处理\n");
                }
                continue;
            }
            if(rooms[nx][ny] != INF)
            {
                printf("(%d,%d)位置不可达, 不处理\n",nx,ny);
                continue;
            }
            printf("(%d,%d)位置可达,入队,并且值+1\n",nx,ny);
            rooms[nx][ny] = rooms[x][y] + 1;
            q.push(make_pair(nx, ny));
            PrintGrid(rooms);
        }
    }
    return;
}
int main()
{
    vector<vector<int>> rooms =
    {
        {INF,-1,0,INF},
        {INF,INF,INF,-1},
        {INF,-1,INF,-1},
        {0,-1,INF,INF}
    };
    PrintGrid(rooms);
    wallsAndGates(rooms);
    PrintGrid(rooms);
    return 0;
}
