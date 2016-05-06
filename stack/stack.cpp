/**
*****************
Stack是一种关联容器，是通过简单地修饰线性类deque的接口而获得的另一种“容器类”，往往被归结为配接器（adapter）而不是容器（Container）。
					stack不能遍历，所以没有迭代器！！！
					底层容器除了 deque外还可采用 list。
*****************
使用

                    需加载的头文件:   #include<stack>
                                      using namespace std;

                     template <class T, class Container = deque<T> >
*****************
主要的方法有如下：     

                          empty() 堆栈为空则返回真
	　　                  pop() 移除栈顶元素（不会返回栈顶元素的值） 
	　　                  push() 在栈顶增加元素
	　　                  size() 返回栈中元素数目
	　　                  top() 返回栈顶元素
  **/

#include <iostream>  
#include <stack>  
using namespace std;  
int main()  
{  
    stack <int> myStack;//定义栈  
    myStack.push(5);//压栈  
    myStack.push(6);  
    myStack.push(7);  
    myStack.pop(); //出栈  
    cout<<myStack.top()<<endl;  
    cout<<myStack.size()<<endl;  
    cout<<myStack.empty()<<endl;  
    return 0;  
}  