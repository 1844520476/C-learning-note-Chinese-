#include <stdio.h>
#include <iostream>
using namespace std;
//���캯���ķ��༰���ã�
/*
?	��������Ϊ�� �вι���  �޲ι��죨Ĭ�Ϲ��죩
?	�����ͷ�Ϊ�� ��ͨ����  ��������
���ֵ��÷�ʽ�����ŷ�  ��ʾ��  ��ʽת����
*/
class Person
{
    int age;

public:
    Person() //�޲ι��캯����Ĭ�ϣ�
    {
        cout << "Person���޲ι��캯��"
             << endl;
    }
    Person(int a) //�вι���
    {
        age = a;
        cout << "\nPerson���вι��캯��"
             << "\nage=" << age << endl;
    }
    Person(const Person &p) //�������캯��
    {
        age = p.age;
        cout << "\nPerson�Ŀ������캯��"
             << endl;
    }
    ~Person()
    {
        // cout << "Person��������������" << endl;
    }
    getAge()
    {
        return age;
    }
};

void test01()
{
    // 1.���ŷ�
    Person p1;     //�޲Σ�Ĭ�ϣ����캯���ĵ���
    Person p2(18); //�вι���ĵ���
    // p2.Person(18);//error: invalid use of 'Person::Person'
    Person p3(p2); //�������캯���ĵ���
    cout << "p3.age=" << p3.getAge() << "\n"
         << endl;
    //ע������1�������޲ι��캯��ʱ����Ҫ�ӣ���
    // Person p1()����������Ϊ��Ϊ��������

    //  2.��ʽ��
    Person p11;
    Person p12 = Person(19);
    Person p13 = Person(p2);
    Person(20); //�������� �ص㣺��ǰ��ִ�����ϵͳ������������������
    //ע������2���������� �������캯�� ��ʼ���������� ��������Ϊ�Ƕ�������
    // Person(p13)===(�ȼ���)Person p13

    //  3.��ʽת����
    Person p21 = 10; //������ת��ΪPerson p21=Person(10)
    Person p22 = p21;
}

int main()
{
    test01();
    system("pause");
    return 0;
}