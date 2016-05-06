/**
在<queue>头文件中，还定义了另一个非常有用的模板类priority_queue(优先队列）。优先队
列与队列的差别在于优先队列不是按照入队的顺序出队，而是按照队列中元素的优先权顺序
出队（默认为大者优先，也可以通过指定算子来指定自己的优先顺序）。
priority_queue 模板类有三个模板参数，第一个是元素类型，第二个容器类型，第三个是比
较算子。其中后两个都可以省略，默认容器为vector，默认算子为less，即小的往前排，大
的往后排（出队时序列尾的元素出队）。

定义priority_queue 对象的示例代码如下：
priority_queue<int> q1;
priority_queue< pair<int, int> > q2; // 注意在两个尖括号之间一定要留空格。
priority_queue<int, vector<int>, greater<int> > q3; // 定义小的先出队
priority_queue 的基本操作与queue 相同。
初学者在使用priority_queue 时，最困难的可能就是如何定义比较算子了。
如果是基本数据类型，或已定义了比较运算符的类，可以直接用STL 的less 算子和greater
算子——默认为使用less 算子，即小的往前排，大的先出队。
如果要定义自己的比较算子，方法有多种，这里介绍其中的一种：重载比较运算符。优先队
列试图将两个元素x 和y 代入比较运算符(对less 算子，调用x<y，对greater 算子，调用x>y)，
若结果为真，则x 排在y 前面，y 将先于x 出队，反之，则将y 排在x 前面，x 将先出队。
**/

#include <iostream>
#include <queue>
using namespace std;
class T
{
    public:
    int x, y, z;
    T(int a, int b, int c):x(a), y(b), z(c)
    {
    }
};
bool operator < (const T &t1, const T &t2)
{
    return t1.z < t2.z; // 按照z 的顺序来决定t1 和t2 的顺序
}
main()
{
    priority_queue<T> q;
    q.push(T(4,4,3));
    q.push(T(2,2,5));
    q.push(T(1,5,4));
    q.push(T(3,3,6));
    while (!q.empty())
    {
        T t = q.top(); q.pop();
        cout << t.x << " " << t.y << " " << t.z << endl;
    }
    return 1;
}

/**
bool operator > (const T &t1, const T &t2)
{
return t1.z > t2.z;
}
main()
{
priority_queue<T, vector<T>, greater<T> > q;
q.push(T(4,4,3));
q.push(T(2,2,5));
q.push(T(1,5,4));
q.push(T(3,3,6));
**/
