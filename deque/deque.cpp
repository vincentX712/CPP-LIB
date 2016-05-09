/**
(1)    ���캯��
deque():����һ����deque
deque(int nSize):����һ��deque,Ԫ�ظ���ΪnSize
deque(int nSize,const T& t):����һ��deque,Ԫ�ظ���ΪnSize,��ֵ��Ϊt
deque(const deque &):���ƹ��캯��
(2)    ���Ӻ���
void push_front(const T& x):˫�˶���ͷ������һ��Ԫ��X
void push_back(const T& x):˫�˶���β������һ��Ԫ��x
iterator insert(iterator it,const T& x):˫�˶�����ĳһԪ��ǰ����һ��Ԫ��x
void insert(iterator it,int n,const T& x):˫�˶�����ĳһԪ��ǰ����n����ͬ��Ԫ��x
void insert(iterator it,const_iterator first,const_iteratorlast):˫�˶�����ĳһԪ��ǰ������һ����ͬ����������[forst,last)�������
(3)    ɾ������
Iterator erase(iterator it):ɾ��˫�˶����е�ĳһ��Ԫ��
Iterator erase(iterator first,iterator last):ɾ��˫�˶�����[first,last���е�Ԫ��
void pop_front():ɾ��˫�˶�������ǰһ��Ԫ��
void pop_back():ɾ��˫�˶��������һ��Ԫ��
void clear():���˫�˶��������һ��Ԫ��
(4)    ��������
reference at(int pos):����posλ��Ԫ�ص�����
reference front():������Ԫ�ص�����
reference back():����βԪ�ص�����
iterator begin():��������ͷָ�룬ָ���һ��Ԫ��
iterator end():����ָ�����������һ��Ԫ����һ��Ԫ�ص�ָ�루�������������У�
reverse_iterator rbegin():�����������ָ�����һ��Ԫ��
reverse_iterator rend():�����������ָ���һ��Ԫ�ص�ǰһ��Ԫ��
(5)    �жϺ���
bool empty() const:�����Ƿ�Ϊ�գ���true,����������Ԫ��
(6)    ��С����
Int size() const:����������Ԫ�صĸ���
int max_size() const:�������������˫�˶���Ԫ������ֵ
(7)    ��������
void swap(deque&):��������ͬ��������������
void assign(int n,const T& x):�����е�n��Ԫ�ص�ֵ����Ϊx
**/
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;
    d.push_back( 10 );
    d.push_back(20);
    d.push_back(30);
    cout<<"ԭʼ˫�˶��У�"<<endl;
    for(int i = 0; i < d.size(); i++)
    {
        cout<<d.at(i)<<"\t";
    }
    cout<<endl;
    d.push_front(5);
    d.push_front(3);
    d.push_front(1);

    cout<<"after push_front(5 3 1):"<<endl;
    for(int i = 0;i < d.size();i++)
    {
        cout<<d.at(i)<<"\t";
    }
    cout<<endl;
    d.pop_front();
    d.pop_front();
    cout<<"after pop_front() two times:"<<endl;
    for(int i = 0;i < d.size();i++)
    {
        cout<<d.at(i)<<"\t";
    }
    cout<<endl;
    return 0;
}
