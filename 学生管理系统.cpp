 #define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

//�˵�����
void menu()
{
    cout << "********************" << endl;
    cout << "****1.�����ϵ��****" << endl;
    cout << "****2.��ʾ��ϵ��****" << endl;
    cout << "****3.ɾ����ϵ��****" << endl;
    cout << "****4.������ϵ��****" << endl;
    cout << "****5.�޸���ϵ��****" << endl;
    cout << "****6.�����ϵ��****" << endl;
    cout << "****0.�˳���ϵ��****" << endl;
    cout << "********************" << endl;
}

#define MAX 1000
//�����ϵ�˽ṹ��
struct Person
{
    string m_name;
    int m_sex;//1 ��  2 Ů
    int m_age;
    string m_phone;
    string m_address;
};
struct AddressBooks
{
    struct Person personArray[MAX];//ͨѶ¼�б������ϵ������
    int m_size;    //ͨѶ¼�е�ǰ��¼��ϵ�˵ĸ���
};//���ͨѶ¼�ṹ��

void addPerson(AddressBooks* abs)//1.�����ϵ��
{
    if (abs->m_size == MAX)
    {
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    }
    else
    {
        //�����ϵ��
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personArray[abs->m_size].m_name = name;
        cout << "�������Ա�" << endl;
        cout << "1  ��" << endl;
        cout << "2. Ů" << endl;
        int sex = 0;
        while (1)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_size].m_sex = sex;
                break;
            }
            cout << "�����������������" << endl;
        }

        int age = 0;
        cout << "����������" << endl;
        cin >> age;
        abs->personArray[abs->m_size].m_age = age;

        string phone;
        cout << "��������ϵ�绰" << endl;
        cin >> phone;
        abs->personArray[abs->m_size].m_phone = phone;

        string address;
        cout << "�������ͥסַ��" << endl;
        cin >> address;
        abs->personArray[abs->m_size].m_address = address;

        abs->m_size++;
        cout << "��ӳɹ�" << endl;
    }
    system("pause");//�밴���������
    system("cls");//����
}

//2.��ʾ������ϵ��
void showPerson(AddressBooks* abs)
{
    if (abs->m_size == 0)
    {
        cout << "��ǰ��¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_size; i++)
        {
            cout << "������" << abs->personArray[i].m_name << "\t";
            cout << "�Ա�" << (abs->personArray[i].m_sex == 1 ? "��" : "Ů") << "\t";//��Ŀ������
            cout << "���䣺" << abs->personArray[i].m_age << "\t";
            cout << "�绰��" << abs->personArray[i].m_phone << "\t";
            cout << "סַ��" << abs->personArray[i].m_address << endl;
        }
    }
    system("pause");
    system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1 ͨѶ¼  ����2 �Ա�����
int isExist(AddressBooks* abs, string name)
{
    for (int i = 0; i < abs->m_size; i++)
    {
        if (abs->personArray[i].m_name == name)
        {
            return i;//�ҵ��ˣ�����������������е��±���
        }
    }
    return -1;//�������������û���ҵ�������-1
}

//3.ɾ����ϵ��
void deletePerson(AddressBooks* abs)
{
    cout << "����������ɾ������ϵ�ˣ�" << endl;
    string name;
    cin >> name;
    // ret = -1  δ�鵽  ret != -1  �鵽��
    int ret = isExist(abs, name);
    if (ret != -1)
    {//���ҵ��ˣ�Ҫ����ɾ������
        for (int i = ret; i < abs->m_size; i++)
        {
            //����ǰ��
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_size--;//����ͨѶ¼
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

void findPerson(AddressBooks* abs)
{
    cout << "������������ҵ���ϵ�ˣ�" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "������" << abs->personArray[ret].m_name << "\t";
        cout << "�Ա�" << abs->personArray[ret].m_age << "\t";
        cout << "���䣺" << abs->personArray[ret].m_age << "\t";
        cout << "�绰��" << abs->personArray[ret].m_phone << "\t";
        cout << "סַ��" << abs->personArray[ret].m_address << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson(AddressBooks* abs)
{
    cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personArray[ret].m_name = name;

        cout << "�������Ա�" << endl;
        cout << "1  ��" << endl;
        cout << "2. Ů" << endl;
        int sex = 0;
        while (1)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_sex = sex;
                break;
            }
            cout << "�����������������" << endl;
        }
        int age = 0;
        cout << "����������" << endl;
        cin >> age;
        abs->personArray[ret].m_age = age;

        string phone;
        cout << "��������ϵ�绰" << endl;
        cin >> phone;
        abs->personArray[ret].m_phone = phone;

        string address;
        cout << "�������ͥסַ��" << endl;
        cin >> address;
        abs->personArray[ret].m_address = address;
        cout << "�޸ĳɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
    system("pause");
    system("cls");
}
void cleanPerson(AddressBooks* abs)
{
    abs->m_size = 0;
    cout << "ͨѶ¼�Ѿ����" << endl;
    system("pause");
    system("cls");
}

int main()//���ִ�boss-----ͨѶ¼����ϵͳ
{
    AddressBooks abs;//����ͨѶ¼�ṹ�����
    abs.m_size = 0;//��ʼ��ͨѶ¼�е�ǰ��Ա����
    int select = 0;
    while (1)
    {
        menu();
        cin >> select;
        switch (select)
        {
        case 1:
            addPerson(&abs);
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
            deletePerson(&abs);
            break;
        case 4:
            findPerson(&abs);
            break;
        case 5:
            modifyPerson(&abs);
            break;
        case 6:
            cleanPerson(&abs);
            break;
        case 0:
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
