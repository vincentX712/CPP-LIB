/**
��<queue>ͷ�ļ��У�����������һ���ǳ����õ�ģ����priority_queue(���ȶ��У������ȶ�
������еĲ���������ȶ��в��ǰ�����ӵ�˳����ӣ����ǰ��ն�����Ԫ�ص�����Ȩ˳��
���ӣ�Ĭ��Ϊ�������ȣ�Ҳ����ͨ��ָ��������ָ���Լ�������˳�򣩡�
priority_queue ģ����������ģ���������һ����Ԫ�����ͣ��ڶ����������ͣ��������Ǳ�
�����ӡ����к�����������ʡ�ԣ�Ĭ������Ϊvector��Ĭ������Ϊless����С����ǰ�ţ���
�������ţ�����ʱ����β��Ԫ�س��ӣ���

����priority_queue �����ʾ���������£�
priority_queue<int> q1;
priority_queue< pair<int, int> > q2; // ע��������������֮��һ��Ҫ���ո�
priority_queue<int, vector<int>, greater<int> > q3; // ����С���ȳ���
priority_queue �Ļ���������queue ��ͬ��
��ѧ����ʹ��priority_queue ʱ�������ѵĿ��ܾ�����ζ���Ƚ������ˡ�
����ǻ����������ͣ����Ѷ����˱Ƚ���������࣬����ֱ����STL ��less ���Ӻ�greater
���ӡ���Ĭ��Ϊʹ��less ���ӣ���С����ǰ�ţ�����ȳ��ӡ�
���Ҫ�����Լ��ıȽ����ӣ������ж��֣�����������е�һ�֣����رȽ�����������ȶ�
����ͼ������Ԫ��x ��y ����Ƚ������(��less ���ӣ�����x<y����greater ���ӣ�����x>y)��
�����Ϊ�棬��x ����y ǰ�棬y ������x ���ӣ���֮����y ����x ǰ�棬x ���ȳ��ӡ�
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
    return t1.z < t2.z; // ����z ��˳��������t1 ��t2 ��˳��
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
