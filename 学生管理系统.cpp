 #define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include <string>

//菜单界面
void menu()
{
    cout << "********************" << endl;
    cout << "****1.添加联系人****" << endl;
    cout << "****2.显示联系人****" << endl;
    cout << "****3.删除联系人****" << endl;
    cout << "****4.查找联系人****" << endl;
    cout << "****5.修改联系人****" << endl;
    cout << "****6.清空联系人****" << endl;
    cout << "****0.退出联系人****" << endl;
    cout << "********************" << endl;
}

#define MAX 1000
//设计联系人结构体
struct Person
{
    string m_name;
    int m_sex;//1 男  2 女
    int m_age;
    string m_phone;
    string m_address;
};
struct AddressBooks
{
    struct Person personArray[MAX];//通讯录中保存的联系人数组
    int m_size;    //通讯录中当前记录联系人的个数
};//设计通讯录结构体

void addPerson(AddressBooks* abs)//1.添加联系人
{
    if (abs->m_size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        //添加联系人
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[abs->m_size].m_name = name;
        cout << "请输入性别" << endl;
        cout << "1  男" << endl;
        cout << "2. 女" << endl;
        int sex = 0;
        while (1)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_size].m_sex = sex;
                break;
            }
            cout << "输入错误，请重新输入" << endl;
        }

        int age = 0;
        cout << "请输入年龄" << endl;
        cin >> age;
        abs->personArray[abs->m_size].m_age = age;

        string phone;
        cout << "请输入联系电话" << endl;
        cin >> phone;
        abs->personArray[abs->m_size].m_phone = phone;

        string address;
        cout << "请输入家庭住址：" << endl;
        cin >> address;
        abs->personArray[abs->m_size].m_address = address;

        abs->m_size++;
        cout << "添加成功" << endl;
    }
    system("pause");//请按任意键操作
    system("cls");//清屏
}

//2.显示所有联系人
void showPerson(AddressBooks* abs)
{
    if (abs->m_size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_size; i++)
        {
            cout << "姓名：" << abs->personArray[i].m_name << "\t";
            cout << "性别：" << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";//三目操作符
            cout << "年龄：" << abs->personArray[i].m_age << "\t";
            cout << "电话：" << abs->personArray[i].m_phone << "\t";
            cout << "住址：" << abs->personArray[i].m_address << endl;
        }
    }
    system("pause");
    system("cls");
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1 通讯录  参数2 对比姓名
int isExist(AddressBooks* abs, string name)
{
    for (int i = 0; i < abs->m_size; i++)
    {
        if (abs->personArray[i].m_name == name)
        {
            return i;//找到了，返回这个人在数组中的下标编号
        }
    }
    return -1;//如果遍历结束都没有找到，返回-1
}

//3.删除联系人
void deletePerson(AddressBooks* abs)
{
    cout << "请输入你想删除的联系人：" << endl;
    string name;
    cin >> name;
    // ret = -1  未查到  ret != -1  查到了
    int ret = isExist(abs, name);
    if (ret != -1)
    {//查找到人，要进行删除操作
        for (int i = ret; i < abs->m_size; i++)
        {
            //数据前移
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_size--;//更新通讯录
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void findPerson(AddressBooks* abs)
{
    cout << "请输入你想查找的联系人：" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].m_name << "\t";
        cout << "性别：" << abs->personArray[ret].m_age << "\t";
        cout << "年龄：" << abs->personArray[ret].m_age << "\t";
        cout << "电话：" << abs->personArray[ret].m_phone << "\t";
        cout << "住址：" << abs->personArray[ret].m_address << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson(AddressBooks* abs)
{
    cout << "请输入你要修改的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[ret].m_name = name;

        cout << "请输入性别" << endl;
        cout << "1  男" << endl;
        cout << "2. 女" << endl;
        int sex = 0;
        while (1)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_sex = sex;
                break;
            }
            cout << "输入错误，请重新输入" << endl;
        }
        int age = 0;
        cout << "请输入年龄" << endl;
        cin >> age;
        abs->personArray[ret].m_age = age;

        string phone;
        cout << "请输入联系电话" << endl;
        cin >> phone;
        abs->personArray[ret].m_phone = phone;

        string address;
        cout << "请输入家庭住址：" << endl;
        cin >> address;
        abs->personArray[ret].m_address = address;
        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}
void cleanPerson(AddressBooks* abs)
{
    abs->m_size = 0;
    cout << "通讯录已经清空" << endl;
    system("pause");
    system("cls");
}

int main()//新手村boss-----通讯录管理系统
{
    AddressBooks abs;//创建通讯录结构体变量
    abs.m_size = 0;//初始化通讯录中当前人员个数
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
            cout << "欢迎下次使用" << endl;
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
