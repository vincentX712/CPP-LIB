/**
vector��һ���ܹ�����������͵Ķ�̬����
vector�����ڴ���C�е�����,vector��STL�Ƽ�ʹ�õ�Ĭ������, vector�е�Ԫ�ص��ڴ������������

ʹ��ԭ��:
1������ʹ��vector����C�������飻
2������ʹ���㷨�����ֹ�д��ѭ����
3������ʹ��vector����ĺ����������������㷨��

1. ��ʼ��
 ��������������int  v1[10] = {0,1,0,0,3,0,0,4,4,4};
 ��ʽ1��
 vector<int> v2(10); //��ʼ��sizeΪ10���Ա������鶯̬������ʱ�򲻶ϵķ����ڴ�
//v2.reserve(10);//ͬ�ϣ�ֻҪʹ������һ���Ϳ�����
for( int i=0; i<10; i++ )
{
       v2.push_back(v1[i]);//����һ��Ԫ��
}
 ��ʽ2��
 vector<int> v3(&v1[0],&v1[9]);//ԭʼ�����Ԫ��ָ�������Ϊ��������ʹ��
 ��ʽ3��
 vector<int> v4;
 v4.reserve(10);
 v4.insert(v4.begin(), &v1[0], &v[9]);
 ��ʽ4��
 vector<int> v5(10);
 copy(v5.begin(), &v1[0], &v1[9]);

2. ����vector<int> v1
��ʽ1��
for( int i=0; i<v1.size(); i++ )
{
       print(v1[i]);
}
��ʽ2��
typedef  vector<int>:: iterator   VIntIterator;
VIntIterator  end = v1.end();
for( VIntIterator  i=v1.begin(); i != end;  ++i )
{
     print( *i );
}
ע�⣺�ȼ���end�кô�����Ϊ����Ҫÿ��ȥ�ظ�����end��д�㷨��ʱ����ʹ��!=�Ƚϵ���������Ϊ<���ںܶ�����������û�����������
��ʽ3��
for_each( v1.begin(),  v1.end(),  print );

//�ر�ע���κ�ʱ��ͬʱʹ�����������������Ľ�����һ��ǰ�պ󿪵�����(����������ɾ��������)
//�ر�ע��begin()ָ�����vec�еĵ�0��Ԫ�أ���end��ָ�����һ��Ԫ�صĺ���һ��λ�ã��������һ��Ԫ�أ�
//�ر�ע���������ʱЧ�ԣ����һ����������ָ��������Ѿ���ɾ����������ʹ�øõ������Ļ�����������벻���ĺ��
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
    //��ʼ��,һ������ʽ������ʼ�����������ݣ�����ʽ������ʼ���ȽϷ���
    int num[10]={0,1,2,3,4,5,6,7,8,9};
    vector <int> vec(num,num+10);
    //�ر�ע�����ʹ�����������������Ľ�����һ��ǰ�պ󿪵�����
    vector<int>::iterator iter_int;
    //�ڵڶ���Ԫ��(vec[1])��λ���ϲ���99
    iter_int=vec.begin()+1;
    vec.insert(iter_int,99);
    cout<<"�ڵڶ���Ԫ��(vec[1])��λ���ϲ���99"<<endl;
    print(vec);
    //�ڵ�����Ԫ��(vec[2])��λ���ϲ���3��100
    iter_int=vec.begin()+2;
    vec.insert(iter_int,3,100);
    cout<<"�ڵ�����Ԫ��(vec[1])��λ���ϲ�������100"<<endl;
    print(vec);
    vector<int>temp(num,num+10);
    cout<<"temp:"<<endl;
    print(temp);
    vector<int>::iterator t1=temp.begin()+1;
    vector<int>::iterator t2=temp.begin()+3;
    vec.insert(vec.begin(),t1,t2);
    cout<<"�ڵ�1��Ԫ��(vec[0])��λ���ϲ���temp��[1,3)���vec��";
    print(vec);

    cout<<"push�������"<<endl;
    vec.push_back(100);
    print(vec);

    //ɾ��Ԫ��erase��clear(ȫɾ��)
    //�ر�ע�����ʹ�����������������Ľ�����һ��ǰ�պ󿪵�����
    iter_int=vec.begin();
    vec.erase(iter_int,iter_int+5);
    cout<<"ɾ��������ɾ��[0,5)���������"<<endl;
    print(vec);

    //���Ҳ���(����ʽ����û�в��Ҳ�����ֻ�й���ʽ��������)

    //�޸�Ԫ�أ��޸�Ԫ���Ȳ���Ҫ�޸ĵ�Ԫ�أ�������ҷ���������ֱ�Ӷ����ý����޸ģ�������ص��ǵ���������Ҫʹ�õ������ķ����޸�Ԫ�ص�ֵ
    cout<<"�޸�Ԫ�ز���"<<endl;
    vec[0]=8;//[]���ص������ã�����ֱ�Ӳ���
    print(vec);
    iter_int=vec.begin();
    *iter_int=9;//��������Ҫʹ�õ������ķ����޸�Ԫ�ص�ֵ
    print(vec);

    //��ָ����������Ԫ��swap
    cout<<"��������"<<endl;
    vector <int> vec1(num,num+10);
    cout<<"����ǰ��Ԫ��vec:";
    print(vec);
    cout<<"����ǰ��Ԫ��vec1:";
    print(vec1);
    vec1.swap(vec);
    cout<<"�������Ԫ��vec:";
    print(vec);
    cout<<"�������Ԫ��vec1:";
    print(vec1);

    //����֮����ԱȽϣ���string�ıȽ�һ��
    if(vec>vec1)
    {
        cout<<"vec>vec1"<<endl;
    }
    else
    {
        cout<<"vec<=vec1"<<endl;
    }

    //����
    cout<<"��vec1����"<<endl;
    iter_int=vec1.begin();
    sort(iter_int,iter_int+vec1.size());
    print(vec1);

    //begin() end()
    //Ҫ�ر�ע��begin()ָ�����vec�еĵ�0��Ԫ�أ���end��ָ�����һ��Ԫ�صĺ���һ��λ�ã��������һ��Ԫ�أ�
    cout<<"begin and end"<<endl;
    iter_int=vec1.begin();
    cout<<*iter_int<<endl;
    iter_int=vec1.end()-1;//���д�������ʹ���iter_int=vec1.end();
    cout<<*iter_int<<endl;
    return 0;
}
