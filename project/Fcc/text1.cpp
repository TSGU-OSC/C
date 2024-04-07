#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
struct people
{
	string name;
	char sex;
	int age;
	string contant;
	string origin;
};

struct Contant
{
	struct people peoplenumber[1000];
	int Maxnumber;
};
void addpeolpe(Contant* abs)
{
	if (abs->Maxnumber == 1000)
	{
		cout << "用户已满，无法进行添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名: ";
		cin >> name;
		abs->peoplenumber[abs->Maxnumber].name = name;
		char sex;
		cout << "请输入性别: (请输入“w”[女]或者“m”[男])";
		while (true)
		{
			cin >> sex;
			if (sex == 'm' || sex == 'w')
			{
				abs->peoplenumber[abs->Maxnumber].sex = sex;
				break;
			}
			cout << "输入格式错误，请重新输入:";
		}
		cout << "请输入年龄: ";
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 100)
			{
				abs->peoplenumber[abs->Maxnumber].age = age;
				break;
			}
			cout << "输入格式有误，请重新输入:";
		}
		string contant;
		cout << "请输入联系方式: ";
		cin >> contant;
		abs->peoplenumber[abs->Maxnumber].contant = contant;
		string origin;
		cout << "请输入籍贯: ";
		cin >> origin;
		abs->peoplenumber[abs->Maxnumber].origin = origin;
		cout << "您所输入的信息为:" <<"姓名:"<< name << "\t" <<"性别:"<< sex << "\t" <<"年龄:"<< age << "\t" <<"联系方式"<< contant << "\t" <<"籍贯:" <<origin << endl;
		abs->Maxnumber++;
		system("pause");
		system("cls");
	}
};
	void showContant(Contant * abs)
	{
		cout << "\n";
		cout << "已存储的用户数据:" << endl;
		cout << "\n";
		for (int i = 0; i < abs->Maxnumber; i++)
		{
			cout<<"姓名: " << abs->peoplenumber[i].name << "\t";
			cout <<"性别: " << abs->peoplenumber[i].sex << "\t";
			cout <<"年龄: " << abs->peoplenumber[i].age << "\t";
			cout <<"联系方式: " << abs->peoplenumber[i].contant << "\t";
			cout <<"籍贯: " << abs->peoplenumber[i].origin << "\t" << endl;
		}
		system("pause");
		system("cls");
	}
	int exist(Contant* abs, string name)
	{
		for (int i = 0; i < abs->Maxnumber; i++)
		{
			if (abs->peoplenumber[i].name == name)
			{
				return i;
			}
		
		}
		return -1;
	}
	void deletepeople(Contant* abs)
	{
		cout << "请输入您要删除的用户: ";
		string name;
		cin >> name;
		int a = exist(abs ,name);
		if (a != -1)
		{
			for (int i = a; i < abs->Maxnumber; i++)
			{
				abs->peoplenumber[i] = abs->peoplenumber[i + 1];
			}
			abs->Maxnumber--;
			cout << "\n";
			cout << "已成功删除该用户信息！" << endl;
		}
		else cout << "未查找到该用户信息" << endl;
		system("pause");
		system("cls");
	}
	void findpeople(Contant* abs)
	{
		cout << "请输入您要查找的用户名字:" << endl;
		string name;
		cin >> name;
		int b = exist(abs, name);
		if (b != -1)
		{
			
				cout << "姓名:" << abs->peoplenumber[b].name << "性别:" << abs->peoplenumber[b].sex << "年龄:" << abs->peoplenumber[b].age 
				<< "联系方式:" << abs->peoplenumber[b].contant << "籍贯:" << abs->peoplenumber[b].origin << endl;
		}
		else
				cout << "未查找到该用户信息!" << endl;
		system("pause");
		system("cls");

	}
	void modifypeople(Contant* abs)
	{
		cout << "请输入您要修改的用户的名字" << endl;
		string name;

		cin >> name;
		int c = exist(abs, name);
		if (c != -1)
		{
			for (int i = c; i < abs->Maxnumber; i++)
			{
				abs->peoplenumber[i] = abs->peoplenumber[i + 1];
			}
			abs->Maxnumber--;
			cout << "请进行修改:";
			cout << "姓名:";
			cin >> name;
			abs->peoplenumber[abs->Maxnumber].name = name;
			char sex;
			cout << "性别:(输入m或w)";
			cin >> sex;
			abs->peoplenumber[abs->Maxnumber].sex = sex;
			int age = 0;
			cout << "年龄:";
			while (true)
			{
				cin >> age;
				if (age >= 0 && age <= 100)
				{
					abs->peoplenumber[abs->Maxnumber].age = age;
					break;
				}
				cout << "输入格式有误，请重新输入:";
			}
			string contant;
			cout << "联系方式:";
			cin >> contant;
			abs->peoplenumber[abs->Maxnumber].contant = contant;
			string origin;
			cout << "籍贯:";
			cin >> origin;
			abs->peoplenumber[abs->Maxnumber].origin = origin;
			abs->Maxnumber++;
		}
		else cout << "未查找到该用户信息!" << endl;
		system("pause");
		system("cls");
	}

int main()
{

		system("color 3E");
		Contant abs;
		abs.Maxnumber = 0;
		int select = 0;
		while (true)
		{
		cout << "\t\t\t\t\t\t\t\t用户系统" << endl;
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t\t\t1.添加用户" << endl;
		cout << "\t\t\t\t\t\t\t\t2.查看用户信息" << endl;
		cout << "\t\t\t\t\t\t\t\t3.删除用户" << endl;
		cout << "\t\t\t\t\t\t\t\t4.查找用户" << endl;
		cout << "\t\t\t\t\t\t\t\t5.修改用户信息" << endl;
		cout << "\t\t\t\t\t\t\t\t0.退出系统" << endl;
		cout << "请选择您的操作:";
		cin >> select;
		switch (select)
		{
		case 1:
			addpeolpe(&abs);
			break;
		case 2:
			 showContant(&abs);
			break;
		case 3:
			 deletepeople(&abs);
			break; 
		case 4:
			findpeople(&abs);
			break;
		case 5:
			modifypeople(&abs);
			break;
		case 0:
			cout << "\n";
			cout << "感谢您的使用" << endl;
			system("pause");
			system("cls");
			break;
		default:
			break;

		}
	}
}

