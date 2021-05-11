#include<iostream>
#include<iomanip>
#define Max 1000
using namespace std;
struct contactor//联系人结构体
{
    string _name;
    int _age;
    int _sex;
    string _phonenumber;
    string _address;
};
struct addressbook
{ //通讯录数组
    struct  contactor personarray[Max];
  //当前人数个数
    int _size=0;
};
//添加联系人
void addcontactor(addressbook *abs)
{
 
    if (abs->_size == Max)
    {
        cout << "数据库已满" << endl; return;
    }
    else
//考虑容量
    {
        string name;
        cout << "添加姓名 " << endl;
        cin >> name;
        abs->personarray[abs->_size]._name = name;
    }//考虑性别双选，错误为死循环
        cout << "请输入性别" << endl;
        cout << "1--男" << endl;
        cout << "2--女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personarray[abs->_size]._sex = sex;
                break;
            }
            cout << "输出有误" << endl;
         }system("pause");
   system("cls");
    system("pause");
   system("cls");
        int age;
        cout << "请输入年龄" << endl;
        cin >> age;
        abs->personarray[abs->_size]._age = age;
        string phonenumber;
        cout << "请输入电话" << endl;
        cin >> phonenumber;
        abs->personarray[abs->_size]._phonenumber = phonenumber;
        string address;
        cout << "请输入地址" << endl;
        cin >> address;
        abs->personarray[abs->_size]._address = address;
        abs->_size++;
        cout << "添加成功" << endl;
        system("pause");//请按任意键
        system("cls");//清屏
}
//展示记录

void showcontactor(addressbook abs) 
{
    if (abs._size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs._size; i++)
        {
            cout << setw(8) << "姓名为" << abs.personarray[i]._name;
            cout << setw(8) << "性别为" << (abs.personarray[i]._sex == 1 ? "男" : "女");
            cout << setw(8) << "年龄为" << abs.personarray[i]._age;
            cout << setw(8) << "电话为" << abs.personarray[i]._phonenumber;
            cout << setw(8) << "地址为" << abs.personarray[i]._address << endl;
        }
        system("pause");//请按任意键
        system("cls");//清屏

    }
}
//查找联系人
int whetherExist(addressbook *abs, string name)
{
    for (int i = 0; i < abs->_size; i++)
    {
        //找到输入的姓名了
        if (abs->personarray[i]._name==name)
        {
            return i;   //找到了 就返回这个i的值；
        }
        return -1;
    }
    
}
//删除联系人
void deletename(addressbook *abs)
{
    cout << "请输入你要删除的联系人" << endl;
    string name;
    cin >> name;
    int rt=whetherExist(abs, name);
    if (rt != -1)
    {
        int app;
        cout << "查到此人" << endl;
        cout << "是否删除此人？" << endl;
        cout << "是输入1，不是输入0" << endl;
            cin >> app;
            if (app == 1)
            {
                for (int i = rt; i < abs->_size; i++)
                {
                    abs->personarray[i] = abs->personarray[i + 1];
                }
                abs->_size--;
                cout << "删除成功" << endl;
                system("cls");//清屏
            }
            else system("cls");
     
    }
    else
    {
        cout << "查无此人" << endl;
    }
    }


void changecontactor(addressbook* abs)
{
    string name; int p;
    cout << "请输入修改者姓名" << endl;
    cin >> name;
    p= whetherExist(abs, name);
    if (p!= -1)
    {
        cout << "请输入姓名" << endl;
        //姓名
        cin >> abs->personarray[p]._name;
        cout << "请输入性别" << endl;
        cout << "1--男" << endl;
        cout << "2--女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personarray[abs->_size]._sex = sex;
                break;
            }
            else
                cout << "输出有误" << endl;
        }
        //性别
        cout << "请输入年龄" << endl;
        cin >> abs->personarray[p]._age;
        string phonenumber;
        cout << "请输入电话" << endl;

        cin >> abs->personarray[p]._phonenumber;
        string address;
        cout << "请输入地址" << endl;
        cin >> abs->personarray[p]._address;
        cout << "修改成功" << endl;
    }
    else cout << "查无此人" << endl;
    system("pause");//请按任意键
    system("cls");//清屏
            system("pause");//请按任意键
        system("cls");//清屏
}

//清除
void clearcontactor(addressbook* abs)
{
    abs->_size = 0;
    cout << "删除完毕" << endl;
    system("pause");
    system("cls");
}
//查询特定
void searchcontactor(addressbook *abs)
{
    string name;
    cout << "请输入查询者姓名" << endl;
    cin >> name;
   int ret=whetherExist(abs, name);
   if (ret != -1)
   { 
   cout << "查到此人" << endl;
   cout << abs->personarray[ret]._name << endl;
   cout << abs->personarray[ret]._sex << endl;
   cout << abs->personarray[ret]._age << endl;
   cout << abs->personarray[ret]._phonenumber << endl;
   cout << abs->personarray[ret]._address << endl;
   }
   else
   {
       cout << "查无此人" << endl;
   }
   system("pause");
   system("cls");
}


void kiatou()
{
    for (int i = 0; i < 4; i++)
        cout << " ";
}
//菜单
system("pause");
   system("cls");
void showmenu()
{
    for (int i = 0; i < 28; i++)
    {
        cout << "*";
    }
    cout << endl;
    kiatou();
    cout << "****1 输入信息****" << endl;
    kiatou();
    cout << "****2 查看信息****" << endl;
    kiatou();
    cout << "****3 删除信息****" << endl;
    kiatou();
    cout << "****4 修改信息****" << endl;
    kiatou();
    cout << "****5 清空信息****" << endl;
    kiatou();
    cout << "****6 查找信息****" << endl;
    kiatou();
    cout << "****0 退出系统****" << endl;
}

int main()
{
    addressbook abs;
    while (true)
    {
        int score = 0;
        showmenu();
        cin >> score;
        switch (score)
        {
        case 1://添加信息
            addcontactor(&abs);//利用地址传递才能修改实参           
            break;
        case 2://查看信息
            showcontactor(abs);
            break;
        case 3://删除信息
            deletename(&abs);
       /* cin >> name;
        if (whetherExist(&abs, name) == -1)
        {
            cout << "不存在该用户" << endl;
        }
        else
        {
            cout << "存在该用户" << endl;
        }
        }*/
         break;
        case 4://修改信息
            changecontactor(&abs);  
            break;
        case 5://清空信息
            clearcontactor(&abs);
                break;
        case 6://查找信息
            searchcontactor(&abs);
            break;
        case 0://退出系统
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
}
}
