/**
一，概述

       List将元素按顺序储存在链表中. 与向量(vectors)相比, 它允许快速的插入和删除，但是随机访问却比较慢。
       list 不仅是一个双向链表，而且是一个环状双向链表

二，使用

       #include <list>
       using namespace std;

       注意：list是一个“前闭后开”的区间，即
       list<int> lt(10,6);  //建立10个元素为6的链表
       cout<<*(lt.end()) ; //输出乱码
       cout<<*(--lt.end());//输出最后一个元素 6

三，主要函数

    assign()                         给list赋值
    back()                           返回最后一个元素
    begin()                          返回指向第一个元素的迭代器
    clear()                           删除所有元素
    empty()                         如果list是空的则返回true
    end()                            返回末尾的迭代器
    erase()                         删除一个元素
    front()                           返回第一个元素
    get_allocator()             返回list的配置器
    insert(iteator,10)          插入一个元素10到元素迭代其 iteator之前，一般iteator=find(list.begin(),list.end(),3)
    max_size()                   返回list能容纳的最大元素数量
    merge(list<T> &x)         将x合并到 *this
    pop_back()                   删除最后一个元素
    pop_front()                   删除第一个元素
    push_back()                 在list的末尾添加一个元素
    push_front()                 在list的头部添加一个元素
    rbegin()                        返回指向第一个元素的逆向迭代器
    remove()                      从list删除元素
    remove_if()                  按指定条件删除元素
    rend()                           指向list末尾的逆向迭代器
    resize()                        改变list的大小
    reverse()                      把list的元素倒转
    size()                           返回list中的元素个数
    sort()                            给list排序
    splice(iterator position ,list &x)                                       // list.splice(position,list2) //list2合并到list中position 之前
    splice(iterator position ,list &x，iterator i)                       //  元素插入到list中position 之前
    splice(iterator position ,list &x,iterator first,iterator last)  //first - last 之间的元素插入到 list中position之前
    swap()             交换两个list
    unique()           删除list中重复的元素

**/

#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
using namespace std;
//创建一个list容器的实例LISTINT
typedef list<int> LISTINT;
//创建一个list容器的实例LISTCHAR
typedef list<char> LISTCHAR;
int main(void)
{
    LISTINT listOne;//创建一个名为listOne的list对象

    LISTINT::iterator i;//声明i为迭代器
    listOne.push_front (2);//从list容器前面添加数据
    listOne.push_front (1);

    listOne.push_back (3);//从list容器后面添加数据
    listOne.push_back (4);

    cout<<"listOne.begin()--- listOne.end():"<<endl;//从后面显示数据
    for (i = listOne.begin(); i != listOne.end(); ++i)
        cout << *i << ""<<endl;

    //从后向后显示listOne中的数据
    LISTINT::reverse_iterator ir;
   cout<<"listOne.rbegin()---listOne.rend():"<<endl;
    for (ir =listOne.rbegin(); ir!=listOne.rend();ir++) {
        cout << *ir << "";
    }
    cout << endl;
    //使用STL的accumulate(累加)算法
    int result = accumulate(listOne.begin(), listOne.end(),0);
    cout<<"Sum="<<result<<endl;
    cout<<"------------------"<<endl;
    //--------------------------
    //用list容器处理字符型数据
    //--------------------------
    //用LISTCHAR创建一个名为listOne的list对象
    LISTCHAR listTwo;
    //声明i为迭代器
    LISTCHAR::iterator j;
    //从前面向listTwo容器中添加数据
    listTwo.push_front ('A');
    listTwo.push_front ('B');
    //从后面向listTwo容器中添加数据
    listTwo.push_back ('x');
    listTwo.push_back ('y');
    //从前向后显示listTwo中的数据
   cout<<"listTwo.begin()---listTwo.end():"<<endl;
    for (j = listTwo.begin(); j != listTwo.end(); ++j)
        cout << char(*j) <<" ";
    cout << endl;
    //使用STL的max_element算法求listTwo中的最大元素并显示
    j=max_element(listTwo.begin(),listTwo.end());
    cout << "The maximum element in listTwo is:"<<char(*j)<<endl;

    return 0;
}
