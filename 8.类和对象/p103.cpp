#include <stdio.h>
#include <iostream>
using namespace std;
/*��Ա��������Ϊ˽��

�ŵ�1�������г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��

�ŵ�2������д(set)Ȩ�ޣ����Լ�����ݵ���Ч��
*/

class Person
{
public:
    //���� �ɶ���д
    void setName(string name)
    {
        m_name = name;
    }
    void getName()
    {
        cout << "name:" << m_name << endl;
    }
    //���� ֻ��->�ɶ���д(���䷶Χ��0��150)
    void getAge()
    {
        // m_age = 18;
        cout << "age:" << m_age << endl;
    }
    void setAge(int *age)
    {
        if (*age < 0 || *age > 150)
        {
            m_age = 0;
            cout << "�����������" << endl;
            return; //��������
        }
        m_age = *age;
        // Person p1;
        // p1.getAge();//warning ����ʾage:5134304
        cout << "age(first print):" << m_age << endl;
    }
    //���� ֻд
    void setLover(string Lover)
    {
        m_lover = Lover;
    }

private:
    string m_name; //�ɶ���д

    int m_age; //ֻ��

    string m_lover; //ֻд
};

int main()
{
    Person p1;
    p1.setName("Jack");
    p1.getName();
    // p1.setAge(19);//class Person' has no member named 'setAge'
    int a;
    cin >> a;
    p1.setAge(&a);
    // p1.getAge();
    p1.setLover("Miyoki");
    // cout << "p1.Lover:" << p1.m_lover << endl;//private
    system("pause");
    return 0;
}