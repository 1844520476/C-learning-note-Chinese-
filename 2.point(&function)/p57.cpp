#include<stdio.h>
#include<iostream>
using namespace std;
//ָ����ռ�ڴ�ռ�
	int main()
{
	int a=100;
	int*p=&a;//��a�ĵ�ַ��ָ��p	
	cout << "p=" <<p<< endl;
	cout << "a=" <<a<< endl;
	cout << "*p=" <<*p<< endl;//������(��ʾָ��ָ���ַ�洢������))
	//�ڴ�ռ�
    cout<<"size of(int*)="<<sizeof(int*)<<endl;
	cout<<"size of(float*)="<<sizeof(float*)<<endl;//p����int*����������
	cout<<"size of(double*)="<<sizeof(double*)<<endl;
	cout<<"size of(char*)="<<sizeof(char*)<<endl;
	cout<<"size of(short*)="<<sizeof(short*)<<endl;//��Ҫ��ָ���������Ͷ���8�ֽ�
	system("pause");
	return 0;
}//������֤Ϊ64λ��8�ֽڣ�����