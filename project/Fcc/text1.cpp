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
		cout << "�û��������޷��������" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������: ";
		cin >> name;
		abs->peoplenumber[abs->Maxnumber].name = name;
		char sex;
		cout << "�������Ա�: (�����롰w��[Ů]���ߡ�m��[��])";
		while (true)
		{
			cin >> sex;
			if (sex == 'm' || sex == 'w')
			{
				abs->peoplenumber[abs->Maxnumber].sex = sex;
				break;
			}
			cout << "�����ʽ��������������:";
		}
		cout << "����������: ";
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age >= 0 && age <= 100)
			{
				abs->peoplenumber[abs->Maxnumber].age = age;
				break;
			}
			cout << "�����ʽ��������������:";
		}
		string contant;
		cout << "��������ϵ��ʽ: ";
		cin >> contant;
		abs->peoplenumber[abs->Maxnumber].contant = contant;
		string origin;
		cout << "�����뼮��: ";
		cin >> origin;
		abs->peoplenumber[abs->Maxnumber].origin = origin;
		cout << "�����������ϢΪ:" <<"����:"<< name << "\t" <<"�Ա�:"<< sex << "\t" <<"����:"<< age << "\t" <<"��ϵ��ʽ"<< contant << "\t" <<"����:" <<origin << endl;
		abs->Maxnumber++;
		system("pause");
		system("cls");
	}
};
	void showContant(Contant * abs)
	{
		cout << "\n";
		cout << "�Ѵ洢���û�����:" << endl;
		cout << "\n";
		for (int i = 0; i < abs->Maxnumber; i++)
		{
			cout<<"����: " << abs->peoplenumber[i].name << "\t";
			cout <<"�Ա�: " << abs->peoplenumber[i].sex << "\t";
			cout <<"����: " << abs->peoplenumber[i].age << "\t";
			cout <<"��ϵ��ʽ: " << abs->peoplenumber[i].contant << "\t";
			cout <<"����: " << abs->peoplenumber[i].origin << "\t" << endl;
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
		cout << "��������Ҫɾ�����û�: ";
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
			cout << "�ѳɹ�ɾ�����û���Ϣ��" << endl;
		}
		else cout << "δ���ҵ����û���Ϣ" << endl;
		system("pause");
		system("cls");
	}
	void findpeople(Contant* abs)
	{
		cout << "��������Ҫ���ҵ��û�����:" << endl;
		string name;
		cin >> name;
		int b = exist(abs, name);
		if (b != -1)
		{
			
				cout << "����:" << abs->peoplenumber[b].name << "�Ա�:" << abs->peoplenumber[b].sex << "����:" << abs->peoplenumber[b].age 
				<< "��ϵ��ʽ:" << abs->peoplenumber[b].contant << "����:" << abs->peoplenumber[b].origin << endl;
		}
		else
				cout << "δ���ҵ����û���Ϣ!" << endl;
		system("pause");
		system("cls");

	}
	void modifypeople(Contant* abs)
	{
		cout << "��������Ҫ�޸ĵ��û�������" << endl;
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
			cout << "������޸�:";
			cout << "����:";
			cin >> name;
			abs->peoplenumber[abs->Maxnumber].name = name;
			char sex;
			cout << "�Ա�:(����m��w)";
			cin >> sex;
			abs->peoplenumber[abs->Maxnumber].sex = sex;
			int age = 0;
			cout << "����:";
			while (true)
			{
				cin >> age;
				if (age >= 0 && age <= 100)
				{
					abs->peoplenumber[abs->Maxnumber].age = age;
					break;
				}
				cout << "�����ʽ��������������:";
			}
			string contant;
			cout << "��ϵ��ʽ:";
			cin >> contant;
			abs->peoplenumber[abs->Maxnumber].contant = contant;
			string origin;
			cout << "����:";
			cin >> origin;
			abs->peoplenumber[abs->Maxnumber].origin = origin;
			abs->Maxnumber++;
		}
		else cout << "δ���ҵ����û���Ϣ!" << endl;
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
		cout << "\t\t\t\t\t\t\t\t�û�ϵͳ" << endl;
		cout << "\n" << endl;
		cout << "\t\t\t\t\t\t\t\t1.����û�" << endl;
		cout << "\t\t\t\t\t\t\t\t2.�鿴�û���Ϣ" << endl;
		cout << "\t\t\t\t\t\t\t\t3.ɾ���û�" << endl;
		cout << "\t\t\t\t\t\t\t\t4.�����û�" << endl;
		cout << "\t\t\t\t\t\t\t\t5.�޸��û���Ϣ" << endl;
		cout << "\t\t\t\t\t\t\t\t0.�˳�ϵͳ" << endl;
		cout << "��ѡ�����Ĳ���:";
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
			cout << "��л����ʹ��" << endl;
			system("pause");
			system("cls");
			break;
		default:
			break;

		}
	}
}

