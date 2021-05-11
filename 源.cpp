#include<iostream>
#include<iomanip>
#define Max 1000
using namespace std;
struct contactor//��ϵ�˽ṹ��
{
    string _name;
    int _age;
    int _sex;
    string _phonenumber;
    string _address;
};
struct addressbook
{ //ͨѶ¼����
    struct  contactor personarray[Max];
  //��ǰ��������
    int _size=0;
};
//�����ϵ��
void addcontactor(addressbook *abs)
{
 
    if (abs->_size == Max)
    {
        cout << "���ݿ�����" << endl; return;
    }
    else
//��������
    {
        string name;
        cout << "������� " << endl;
        cin >> name;
        abs->personarray[abs->_size]._name = name;
    }//�����Ա�˫ѡ������Ϊ��ѭ��
        cout << "�������Ա�" << endl;
        cout << "1--��" << endl;
        cout << "2--Ů" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personarray[abs->_size]._sex = sex;
                break;
            }
            cout << "�������" << endl;
         }
        int age;
        cout << "����������" << endl;
        cin >> age;
        abs->personarray[abs->_size]._age = age;
        string phonenumber;
        cout << "������绰" << endl;
        cin >> phonenumber;
        abs->personarray[abs->_size]._phonenumber = phonenumber;
        string address;
        cout << "�������ַ" << endl;
        cin >> address;
        abs->personarray[abs->_size]._address = address;
        abs->_size++;
        cout << "��ӳɹ�" << endl;
        system("pause");//�밴�����
        system("cls");//����
}
//չʾ��¼
void showcontactor(addressbook abs) 
{
    if (abs._size == 0)
    {
        cout << "��ǰ��¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < abs._size; i++)
        {
            cout << setw(8) << "����Ϊ" << abs.personarray[i]._name;
            cout << setw(8) << "�Ա�Ϊ" << (abs.personarray[i]._sex == 1 ? "��" : "Ů");
            cout << setw(8) << "����Ϊ" << abs.personarray[i]._age;
            cout << setw(8) << "�绰Ϊ" << abs.personarray[i]._phonenumber;
            cout << setw(8) << "��ַΪ" << abs.personarray[i]._address << endl;
        }
        system("pause");//�밴�����
        system("cls");//����

    }
}
//������ϵ��
int whetherExist(addressbook *abs, string name)
{
    for (int i = 0; i < abs->_size; i++)
    {
        //�ҵ������������
        if (abs->personarray[i]._name==name)
        {
            return i;   //�ҵ��� �ͷ������i��ֵ��
        }
        return -1;
    }
    
}
//ɾ����ϵ��
void deletename(addressbook *abs)
{
    cout << "��������Ҫɾ������ϵ��" << endl;
    string name;
    cin >> name;
    int rt=whetherExist(abs, name);
    if (rt != -1)
    {
        int app;
        cout << "�鵽����" << endl;
        cout << "�Ƿ�ɾ�����ˣ�" << endl;
        cout << "������1����������0" << endl;
            cin >> app;
            if (app == 1)
            {
                for (int i = rt; i < abs->_size; i++)
                {
                    abs->personarray[i] = abs->personarray[i + 1];
                }
                abs->_size--;
                cout << "ɾ���ɹ�" << endl;
                system("cls");//����
            }
            else system("cls");
     
    }
    else
    {
        cout << "���޴���" << endl;
    }
    }


void changecontactor(addressbook* abs)
{
    string name; int p;
    cout << "�������޸�������" << endl;
    cin >> name;
    p= whetherExist(abs, name);
    if (p!= -1)
    {
        cout << "����������" << endl;
        //����
        cin >> abs->personarray[p]._name;
        cout << "�������Ա�" << endl;
        cout << "1--��" << endl;
        cout << "2--Ů" << endl;
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
                cout << "�������" << endl;
        }
        //�Ա�
        cout << "����������" << endl;
        cin >> abs->personarray[p]._age;
        string phonenumber;
        cout << "������绰" << endl;

        cin >> abs->personarray[p]._phonenumber;
        string address;
        cout << "�������ַ" << endl;
        cin >> abs->personarray[p]._address;
        cout << "�޸ĳɹ�" << endl;
    }
    else cout << "���޴���" << endl;
    system("pause");//�밴�����
    system("cls");//����
}

//���
void clearcontactor(addressbook* abs)
{
    abs->_size = 0;
    cout << "ɾ�����" << endl;
    system("pause");
    system("cls");
}
//��ѯ�ض�
void searchcontactor(addressbook *abs)
{
    string name;
    cout << "�������ѯ������" << endl;
    cin >> name;
   int ret=whetherExist(abs, name);
   if (ret != -1)
   { 
   cout << "�鵽����" << endl;
   cout << abs->personarray[ret]._name << endl;
   cout << abs->personarray[ret]._sex << endl;
   cout << abs->personarray[ret]._age << endl;
   cout << abs->personarray[ret]._phonenumber << endl;
   cout << abs->personarray[ret]._address << endl;
   }
   else
   {
       cout << "���޴���" << endl;
   }
   system("pause");
   system("cls");
}


void kiatou()
{
    for (int i = 0; i < 4; i++)
        cout << " ";
}
//�˵�
void showmenu()
{
    for (int i = 0; i < 28; i++)
    {
        cout << "*";
    }
    cout << endl;
    kiatou();
    cout << "****1 ������Ϣ****" << endl;
    kiatou();
    cout << "****2 �鿴��Ϣ****" << endl;
    kiatou();
    cout << "****3 ɾ����Ϣ****" << endl;
    kiatou();
    cout << "****4 �޸���Ϣ****" << endl;
    kiatou();
    cout << "****5 �����Ϣ****" << endl;
    kiatou();
    cout << "****6 ������Ϣ****" << endl;
    kiatou();
    cout << "****0 �˳�ϵͳ****" << endl;
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
        case 1://�����Ϣ
            addcontactor(&abs);//���õ�ַ���ݲ����޸�ʵ��           
            break;
        case 2://�鿴��Ϣ
            showcontactor(abs);
            break;
        case 3://ɾ����Ϣ
            deletename(&abs);
       /* cin >> name;
        if (whetherExist(&abs, name) == -1)
        {
            cout << "�����ڸ��û�" << endl;
        }
        else
        {
            cout << "���ڸ��û�" << endl;
        }
        }*/
         break;
        case 4://�޸���Ϣ
            changecontactor(&abs);  
            break;
        case 5://�����Ϣ
            clearcontactor(&abs);
                break;
        case 6://������Ϣ
            searchcontactor(&abs);
            break;
        case 0://�˳�ϵͳ
            cout << "��ӭ�´�ʹ��" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
}
}
