/**
*****************
Stack��һ�ֹ�����������ͨ���򵥵�����������deque�Ľӿڶ���õ���һ�֡������ࡱ�����������Ϊ�������adapter��������������Container����
					stack���ܱ���������û�е�����������
					�ײ��������� deque�⻹�ɲ��� list��
*****************
ʹ��

                    ����ص�ͷ�ļ�:   #include<stack>
                                      using namespace std;

                     template <class T, class Container = deque<T> >
*****************
��Ҫ�ķ��������£�     

                          empty() ��ջΪ���򷵻���
	����                  pop() �Ƴ�ջ��Ԫ�أ����᷵��ջ��Ԫ�ص�ֵ�� 
	����                  push() ��ջ������Ԫ��
	����                  size() ����ջ��Ԫ����Ŀ
	����                  top() ����ջ��Ԫ��
  **/

#include <iostream>  
#include <stack>  
using namespace std;  
int main()  
{  
    stack <int> myStack;//����ջ  
    myStack.push(5);//ѹջ  
    myStack.push(6);  
    myStack.push(7);  
    myStack.pop(); //��ջ  
    cout<<myStack.top()<<endl;  
    cout<<myStack.size()<<endl;  
    cout<<myStack.empty()<<endl;  
    return 0;  
}  