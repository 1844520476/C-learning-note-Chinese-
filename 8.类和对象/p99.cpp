// C++���������������ԣ���װ���̳У���̬
// C++��������Զ����������Ժ���Ϊ
//������ͬ���ʵĶ��󣬿ɳ���Ϊ��
#include <stdio.h>
#include <iostream>
#define N 10
using namespace std;
const double PI = 3.14;
//��װ�����壺
// 1.1�����Ժ���Ϊ��Ϊһ�����壬���������е�����

//�﷨��class ����{   ����Ȩ�ޣ� ����  / ��Ϊ  };
class Circle
{
public:                  //����Ȩ��
    int m_r;             //����
    double calculateZC() //��Ϊ(ͨ���Ǻ���)����ȡ�ܳ�
    {
        return 2 * PI * m_r;
    }
}; //�ǵ�;
// 1.2�����Ժ���Ϊ����Ȩ�޿���(֮����˵)
int main()
{
    //ʵ����
    Circle c1;  //ͨ���ഴ���������
    c1.m_r = N; //���������ֵ
    cout << "Բ�ܳ�Ϊ��" << c1.calculateZC() << endl;
    system("pause");
    return 0;
}