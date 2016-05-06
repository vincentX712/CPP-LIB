/**
vector是一个能够存放任意类型的动态数组
vector可用于代替C中的数组,vector是STL推荐使用的默认容器, vector中的元素的内存必须是连续的

使用原则:
1，尽量使用vector代替C风格的数组；
2，尽量使用算法代替手工写的循环；
3，尽量使用vector本身的函数代替其他泛型算法；

1. 初始化
 例如我们有数组int  v1[10] = {0,1,0,0,3,0,0,4,4,4};
 方式1：
 vector<int> v2(10); //初始化size为10可以避免数组动态增长的时候不断的分配内存
//v2.reserve(10);//同上，只要使用其中一个就可以了
for( int i=0; i<10; i++ )
{
       v2.push_back(v1[i]);//增加一个元素
}
 方式2：
 vector<int> v3(&v1[0],&v1[9]);//原始数组的元素指针可以作为迭代器来使用
 方式3：
 vector<int> v4;
 v4.reserve(10);
 v4.insert(v4.begin(), &v1[0], &v[9]);
 方式4：
 vector<int> v5(10);
 copy(v5.begin(), &v1[0], &v1[9]);

2. 遍历vector<int> v1
方式1：
for( int i=0; i<v1.size(); i++ )
{
       print(v1[i]);
}
方式2：
typedef  vector<int>:: iterator   VIntIterator;
VIntIterator  end = v1.end();
for( VIntIterator  i=v1.begin(); i != end;  ++i )
{
     print( *i );
}
注意：先计算end有好处，因为不必要每次去重复计算end；写算法的时候尽量使用!=比较迭代器，因为<对于很多非随机迭代器没有这个操作符
方式3：
for_each( v1.begin(),  v1.end(),  print );

//特别注意任何时候同时使用两个迭代器产生的将会是一个前闭后开的区间(具体见插入和删除的例子)
//特别注意begin()指向的是vec中的第0个元素，而end是指向最后一个元素的后面一个位置（不是最后一个元素）
//特别注意迭代器的时效性，如果一个迭代器所指向的内容已经被删除，而后又使用该迭代器的话，会造成意想不到的后果
**/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(vector<int> vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    //初始化,一般序列式容器初始化容量、内容，关联式容器初始化比较方法
    int num[10]={0,1,2,3,4,5,6,7,8,9};
    vector <int> vec(num,num+10);
    //特别注意如果使用两个迭代器产生的将会是一个前闭后开的区间
    vector<int>::iterator iter_int;
    //在第二个元素(vec[1])的位置上插入99
    iter_int=vec.begin()+1;
    vec.insert(iter_int,99);
    cout<<"在第二个元素(vec[1])的位置上插入99"<<endl;
    print(vec);
    //在第三个元素(vec[2])的位置上插入3个100
    iter_int=vec.begin()+2;
    vec.insert(iter_int,3,100);
    cout<<"在第三个元素(vec[1])的位置上插入三个100"<<endl;
    print(vec);
    vector<int>temp(num,num+10);
    cout<<"temp:"<<endl;
    print(temp);
    vector<int>::iterator t1=temp.begin()+1;
    vector<int>::iterator t2=temp.begin()+3;
    vec.insert(vec.begin(),t1,t2);
    cout<<"在第1个元素(vec[0])的位置上插入temp的[1,3)后的vec：";
    print(vec);

    cout<<"push插入操作"<<endl;
    vec.push_back(100);
    print(vec);

    //删除元素erase、clear(全删除)
    //特别注意如果使用两个迭代器产生的将会是一个前闭后开的区间
    iter_int=vec.begin();
    vec.erase(iter_int,iter_int+5);
    cout<<"删除操作，删除[0,5)区间的内容"<<endl;
    print(vec);

    //查找操作(序列式容器没有查找操作，只有关联式容器采用)

    //修改元素，修改元素先查找要修改的元素，如果查找返回引用则直接对引用进行修改，如果返回的是迭代器，需要使用迭代器的方法修改元素的值
    cout<<"修改元素操作"<<endl;
    vec[0]=8;//[]返回的是引用，所以直接操作
    print(vec);
    iter_int=vec.begin();
    *iter_int=9;//迭代器需要使用迭代器的方法修改元素的值
    print(vec);

    //和指定容器交换元素swap
    cout<<"交换内容"<<endl;
    vector <int> vec1(num,num+10);
    cout<<"交换前的元素vec:";
    print(vec);
    cout<<"交换前的元素vec1:";
    print(vec1);
    vec1.swap(vec);
    cout<<"交换后的元素vec:";
    print(vec);
    cout<<"交换后的元素vec1:";
    print(vec1);

    //容器之间可以比较，与string的比较一样
    if(vec>vec1)
    {
        cout<<"vec>vec1"<<endl;
    }
    else
    {
        cout<<"vec<=vec1"<<endl;
    }

    //排序
    cout<<"对vec1排序"<<endl;
    iter_int=vec1.begin();
    sort(iter_int,iter_int+vec1.size());
    print(vec1);

    //begin() end()
    //要特别注意begin()指向的是vec中的第0个元素，而end是指向最后一个元素的后面一个位置（不是最后一个元素）
    cout<<"begin and end"<<endl;
    iter_int=vec1.begin();
    cout<<*iter_int<<endl;
    iter_int=vec1.end()-1;//如果写成这样就错了iter_int=vec1.end();
    cout<<*iter_int<<endl;
    return 0;
}
