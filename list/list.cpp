/**
һ������

       List��Ԫ�ذ�˳�򴢴���������. ������(vectors)���, ��������ٵĲ����ɾ���������������ȴ�Ƚ�����
       list ������һ��˫������������һ����״˫������

����ʹ��

       #include <list>
       using namespace std;

       ע�⣺list��һ����ǰ�պ󿪡������䣬��
       list<int> lt(10,6);  //����10��Ԫ��Ϊ6������
       cout<<*(lt.end()) ; //�������
       cout<<*(--lt.end());//������һ��Ԫ�� 6

������Ҫ����

    assign()                         ��list��ֵ
    back()                           �������һ��Ԫ��
    begin()                          ����ָ���һ��Ԫ�صĵ�����
    clear()                           ɾ������Ԫ��
    empty()                         ���list�ǿյ��򷵻�true
    end()                            ����ĩβ�ĵ�����
    erase()                         ɾ��һ��Ԫ��
    front()                           ���ص�һ��Ԫ��
    get_allocator()             ����list��������
    insert(iteator,10)          ����һ��Ԫ��10��Ԫ�ص����� iteator֮ǰ��һ��iteator=find(list.begin(),list.end(),3)
    max_size()                   ����list�����ɵ����Ԫ������
    merge(list<T> &x)         ��x�ϲ��� *this
    pop_back()                   ɾ�����һ��Ԫ��
    pop_front()                   ɾ����һ��Ԫ��
    push_back()                 ��list��ĩβ���һ��Ԫ��
    push_front()                 ��list��ͷ�����һ��Ԫ��
    rbegin()                        ����ָ���һ��Ԫ�ص����������
    remove()                      ��listɾ��Ԫ��
    remove_if()                  ��ָ������ɾ��Ԫ��
    rend()                           ָ��listĩβ�����������
    resize()                        �ı�list�Ĵ�С
    reverse()                      ��list��Ԫ�ص�ת
    size()                           ����list�е�Ԫ�ظ���
    sort()                            ��list����
    splice(iterator position ,list &x)                                       // list.splice(position,list2) //list2�ϲ���list��position ֮ǰ
    splice(iterator position ,list &x��iterator i)                       //  Ԫ�ز��뵽list��position ֮ǰ
    splice(iterator position ,list &x,iterator first,iterator last)  //first - last ֮���Ԫ�ز��뵽 list��position֮ǰ
    swap()             ��������list
    unique()           ɾ��list���ظ���Ԫ��

**/

#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>
using namespace std;
//����һ��list������ʵ��LISTINT
typedef list<int> LISTINT;
//����һ��list������ʵ��LISTCHAR
typedef list<char> LISTCHAR;
int main(void)
{
    LISTINT listOne;//����һ����ΪlistOne��list����

    LISTINT::iterator i;//����iΪ������
    listOne.push_front (2);//��list����ǰ���������
    listOne.push_front (1);

    listOne.push_back (3);//��list���������������
    listOne.push_back (4);

    cout<<"listOne.begin()--- listOne.end():"<<endl;//�Ӻ�����ʾ����
    for (i = listOne.begin(); i != listOne.end(); ++i)
        cout << *i << ""<<endl;

    //�Ӻ������ʾlistOne�е�����
    LISTINT::reverse_iterator ir;
   cout<<"listOne.rbegin()---listOne.rend():"<<endl;
    for (ir =listOne.rbegin(); ir!=listOne.rend();ir++) {
        cout << *ir << "";
    }
    cout << endl;
    //ʹ��STL��accumulate(�ۼ�)�㷨
    int result = accumulate(listOne.begin(), listOne.end(),0);
    cout<<"Sum="<<result<<endl;
    cout<<"------------------"<<endl;
    //--------------------------
    //��list���������ַ�������
    //--------------------------
    //��LISTCHAR����һ����ΪlistOne��list����
    LISTCHAR listTwo;
    //����iΪ������
    LISTCHAR::iterator j;
    //��ǰ����listTwo�������������
    listTwo.push_front ('A');
    listTwo.push_front ('B');
    //�Ӻ�����listTwo�������������
    listTwo.push_back ('x');
    listTwo.push_back ('y');
    //��ǰ�����ʾlistTwo�е�����
   cout<<"listTwo.begin()---listTwo.end():"<<endl;
    for (j = listTwo.begin(); j != listTwo.end(); ++j)
        cout << char(*j) <<" ";
    cout << endl;
    //ʹ��STL��max_element�㷨��listTwo�е����Ԫ�ز���ʾ
    j=max_element(listTwo.begin(),listTwo.end());
    cout << "The maximum element in listTwo is:"<<char(*j)<<endl;

    return 0;
}
