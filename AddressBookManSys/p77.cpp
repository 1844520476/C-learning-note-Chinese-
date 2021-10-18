//��ʾ����
#include <iostream>
using namespace std;
#define MAX 1000

struct Person //��ϵ������
{
    string m_Name;
    bool m_Sex; // 1�� 0.Ů
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct Addressbooks //ͨѶ¼�ṹ��(abs)
{
    struct Person personArray[MAX];
    int m_Size; //��ǰ��¼��ϵ�˸���
};

// 1.�����ϵ��
void addPerson(Addressbooks* abs)
{
    if (abs->m_Size == MAX)
    {
        cout << "ͨѶ¼��Ա����" << endl;
        return;
    }
    else
    {
        //����
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name; //�ǵ�,������abs��ָ��
        //�Ա�
        while (1)
        {
            cout << "������(����)�Ա�:"
                << "1-male\n"
                << "0-female" << endl;
            int gender = 0;
            cin >> gender;
            if (gender == 1 || gender == 0)
            {
                abs->personArray[abs->m_Size].m_Sex = gender; //��Ҫ����[abs->m_Size]
                break;
            }
            else
            {
                cout << "������0��1" << endl;
            }
        }
        //����
        cout << "����������" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;
        //�绰
        cout << "��������ϵ��ʽ" << endl;
        string Phone;
        cin >> Phone;
        abs->personArray[abs->m_Size].m_Phone = Phone;
        //��ͥסַ
        cout << "�������ͥסַ" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Addr = address;
        //����ͨѶ¼�ɹ�
        cout << "���ͨѶ¼��ϵ�˳ɹ�" << endl;
        abs->m_Size++;
    }
    system("pause");
    cout << "�밴���������" << endl;
    //��������
    system("cls");
}

// 2.��ʾ��ϵ��(������)
void showPerson(Addressbooks* abs)
{
    if (abs->m_Size == 0)
    {
        cout << "��ǰͨѶ¼������ϵ��" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            //����
            cout << "\t����" << abs->personArray[i].m_Name << endl;
            //�Ա�
            cout << "\tgender" << (abs->personArray[i].m_Sex == 1 ? "male" : "female") << endl; //�úÿ���look it seriously
            /*
            string sex;
            if(abs->personArray[i].m_Sex)
            {
                sex="male";
            }
            else
            {
                sex="female";
            }
            cout<<"\t�Ա�"<<sex<<endl;
            */
            //����
            cout << "\tage:" << abs->personArray[i].m_Age << endl;
            //�绰
            cout << "\tphone:" << abs->personArray[i].m_Phone << endl;
            //��ַ
            cout << "\taddress:" << abs->personArray[i].m_Addr << "\n"
                << endl; //\tˮƽ�Ʊ��
        }
    }
    system("pause");
    cout << "�밴���������" << endl;
    system("cls");
}

// 3.1�����ϵ���Ƿ���ڡ������ڣ�������ϵ�˺;���λ�ã��±꣩���������ڣ�����-1
int isExist(Addressbooks* abs, string name) //����1���ô���һ��ͨѶ¼������2.���Ҷ�������
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            // a[j]=i;j++;//��һ����
            return i; // return��ֱ�ӽ���������
        }
    }
    return -1;
}

// 3.2ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
    cout << "����������ɾ������ϵ������:" << endl;
    string name;
    cin >> name;
    // ret==-1 δ�ҵ�
    // ret��==-1 �鵽��
    int ret = isExist(abs, name); //�����abs��ָ��
    if (ret == -1)
    {
        cout << "���޴���" << endl;
    }
    else
    {
        for (int i = ret; i < abs->m_Size; i++)
        {
            //����ǰ��
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "ɾ���ɹ�" << endl;
    }
    system("pause");
    system("cls");
}

// 4.������ϵ��(ĳ����)
void findPerson(Addressbooks* abs)
{
    cout << "��������Ҫ���ҵ���ϵ��" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1)
    {
        cout << "���޴���" << endl;
    }
    else
    {
        cout << "name:" << abs->personArray[ret].m_Name << endl;
        cout << "sex:" << (abs->personArray[ret].m_Sex == 1 ? "male" : "female") << endl;
        cout << "age:" << abs->personArray[ret].m_Age << endl;
        cout << "phone:" << abs->personArray[ret].m_Phone << endl;
        cout << "address:" << abs->personArray[ret].m_Addr << endl;
    }
    system("pause");
    system("cls");
}

// 5.�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
    cout << "���������޸ĵ���ϵ������" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret == -1)
    {
        cout << "���޴���" << endl;
        return;
    }
    else
    {
        //����
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name; //�ǵ�,������abs��ָ��
        //�Ա�
        while (1)
        {
            cout << "�������Ա�:"
                << "1-male\n"
                << "0-female" << endl;
            int gender = 0;
            cin >> gender;
            if (gender == 1 || gender == 0)
            {
                abs->personArray[ret].m_Sex = gender; //��Ҫ����[abs->m_Size]
                break;
            }
            else
            {
                cout << "������0��1" << endl;
            }
        }
        //����
        cout << "����������" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_Age = age;
        //�绰
        cout << "��������ϵ��ʽ" << endl;
        string Phone;
        cin >> Phone;
        abs->personArray[ret].m_Phone = Phone;
        //��ͥסַ
        cout << "�������ͥסַ" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Addr = address;
        //����ͨѶ¼�ɹ�
        cout << "�޸�ͨѶ¼��ϵ�˳ɹ�" << endl;
    }
    system("pause");
    cout << "�밴���������" << endl;
    system("cls");
}

// 6.�����ϵ��
void emptyPerson(Addressbooks* abs)
{
    cout << "������1��ȷ��ɾ��ȫ����ϵ��" << endl;
    int redf = 0;
    cin >> redf;
    if (redf != 1)//C�����в����ڣ�!=,���ڣ�==
    {
        return;
    }
    else if (abs->m_Size != 0)
    {
        for (int i = 0; i < abs->m_Size; abs->m_Size--)
        {
            for (int j = 0; j < abs->m_Size; j++)
            {
                //����ǰ��
                abs->personArray[j] = abs->personArray[j + 1];
            }
        }
        cout << "��ճɹ�" << endl;
    }
    system("pause");
    system("cls");
}

//��ʾ���˵�
void showMenu()
{
    cout << "************************" << endl;
    cout << "***** 1.�����ϵ�� *****" << endl;
    cout << "***** 2.��ʾ��ϵ�� *****" << endl;
    cout << "***** 3.ɾ����ϵ�� *****" << endl;
    cout << "***** 4.������ϵ�� *****" << endl;
    cout << "***** 5.�޸���ϵ�� *****" << endl;
    cout << "***** 6.�����ϵ�� *****" << endl;
    cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
    cout << "************************" << endl;
}

//������
int main()
{
    Addressbooks abs; //����ͨѶ¼�ṹ�����
    abs.m_Size = 0;

    int seclect = 0; //�����û�ѡ������ı���
    while (1)
    {
        //�˵�����
        showMenu();
        cin >> seclect;
        switch (seclect)
        {
        case 1: // 1.�����ϵ��
            addPerson(&abs);
            break;
        case 2: // 2.��ʾ��ϵ��
            showPerson(&abs);
            break;
        case 3: // 3.ɾ����ϵ��
            // 3.1��װ�����ϵ���Ƿ���ں���
            // 3.2��װɾ����ϵ�˺���
            deletePerson(&abs);
            break;
        case 4: // 4.������ϵ��
            findPerson(&abs);
            break;
        case 5: // 5.�޸���ϵ��
            modifyPerson(&abs);
            break;
        case 6: // 6.�����ϵ��
            emptyPerson(&abs);
            break;
        case 0: // 0.�˳�ͨѶ¼
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}