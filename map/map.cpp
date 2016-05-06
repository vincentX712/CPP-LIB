/**
C++��map�����ṩһ����ֵ�ԣ�key/value��������map��multimap����������multiple����һ������Ӧ���ֵ��
��Ҫ����ͷ�ļ�map�����ڵ�������˵�������޸�ʵֵ���������޸�key��Map�����key�Զ�����

1.����ͳ�ʼ��
vector<int> vec1;    //Ĭ�ϳ�ʼ����vec1Ϊ��
vector<int> vec2(vec1);  //ʹ��vec1��ʼ��vec2
vector<int> vec3(vec1.begin(),vec1.end());//ʹ��vec1��ʼ��vec2
vector<int> vec4(10);    //10��ֵΪ0��Ԫ��
vector<int> vec5(10,4);  //10��ֵΪ4��Ԫ��

2.���ò�������
vec1.push_back(100);            //���Ԫ��
int size = vec1.size();         //Ԫ�ظ���
bool isEmpty = vec1.empty();    //�ж��Ƿ�Ϊ��
cout<<vec1[0]<<endl;        //ȡ�õ�һ��Ԫ��
vec1.insert(vec1.end(),5,3);    //��vec1.backλ�ò����ֵΪ��Ԫ��
//vec1.pop_back();              //ɾ��ĩβԪ��
//vec1.erase(vec1.begin(),vec1.end());//ɾ��֮���Ԫ�أ�����Ԫ��ǰ��
cout<<(vec1==vec2)?true:false;  //�ж��Ƿ����==����=��>=��<=...
vector<int>::iterator iter = vec1.begin();    //��ȡ�������׵�ַ
vector<int>::const_iterator c_iter = vec1.begin();   //��ȡconst���͵�����
//vec1.clear();                 //���Ԫ��

3.����
//�±귨
int length = vec1.size();
for(int i=0;i<length;i++)
{
   cout<<vec1[i];
}
cout<<endl<<endl;
//��������
vector<int>::const_iterator iterator = vec1.begin();
for(;iterator != vec1.end();iterator++)
{
   cout<<*iterator;
}

**/
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<int,string> map1;                  //��map

    map1[3] = "Saniya";                    //���Ԫ��
    map1.insert(map<int,string>::value_type(2,"Diyabi"));//����Ԫ��
    map1.insert(make_pair<int,string>(4,"V5"));
    string str = map1[3];                  //����keyȡ��value��key�����޸�
    cout<<str<<endl;

    //����
    for(map<int,string>::iterator iter = map1.begin();iter!=map1.end();iter++)
    {
       int keyk = iter->first;
       string valuev = iter->second;
       cout<<keyk<<" "<<valuev<<endl;
    }

    return 0;
}
