//����Ǩ���������
#pragma warning(disable:4996)
#pragma once
//#include <time.h>
#include <cstdlib>
#include <ctime>
#include "common.h"

class Password :public Content
{
public:
	char username[50];
	char password[256];
	char url[256];
	int tag[5];
	char localDate[40];
	//��ʾ��С��4�����ʵ�鷢��ʵ�ʴ�С��26��Ϊ���������ʹ�ô�С��30
public:
	Password()
	{
		strcpy(username, "");
		strcpy(password, "");
		strcpy(url, "");
		tag[0] = 0; tag[1] = 0; tag[2] = 0; tag[3] = 0; tag[4] = 0;
		strcpy(localDate, "");
		
	}
	void setBasic()
	{
		cout << "�˺����ƣ�";
		cin >> username;
		cout << "�����ַ��";
		cin >> url;
	}
	void setTag()
	{
		cout << "ѡ���ǩ��1����ѧϰ 2����ѧϰ 3ѧУ�˻� 4�����˻� 5�����˻�" << endl;
		cout << "����ѡ�������ò���" << endl;
		while (1) {
			char choice;
			cin >> choice;
			if (choice <= '5' && choice >= '1') {
				tag[choice - '1'] = 1;
			}
			else {
				break;
			}

		}
	}
	void setLocalDate() {
		long long now = time(0);		//��ǰϵͳ�ĵ�ǰ����/ʱ��
		char* temp = ctime(&now);	//�� now ת��Ϊ�ַ�����ʽctime(&now);
		strcpy(localDate, temp);
	}
	void generatePassword(const int length = 16) {
		cout << "�Ƿ����������ţ���Y/N��" << endl;
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			for (int i = 0; i < length; i++)
			{
				password[i] = randomKind(false);
			}
		}
		else
		{
			for (int i = 0; i < length; i++)
			{
				password[i] = randomKind(true);
			}
		}
		password[length] = '\0';
	}
	void setPassword()
	{
		generatePassword();
		cout << "�˴���������룺";
		cout << password << "  " << strlen(password) << "λ" << endl;
		while (1) {
			cout << "1����һ�� 2�Զ��� 3�˳�" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				generatePassword();
				cout << password << "  " << strlen(password) << "λ" << endl;
				setLocalDate();
			}
			else if (choice == '2') {
				cin >> password;
				cout << password << "  " << strlen(password) << "λ" << endl;
				setLocalDate();
			}
			else if (choice == '3') {
				setLocalDate();
				break;
			}
			else
			{
				cout << "��ѡ��" << endl;
			}
		}
	}
	//�����ӿ�
	virtual void setWeight()
	{
		cout << "������������Ҫ�̶ȣ�0~100����" << endl;
		cin >> weight;
	}
	virtual void setAll() 
	{
		setBasic();
		setPassword();
		setLocalDate();
		setTag();
	}
	virtual void show() {
		cout << "=====================�˻�===================" << endl;
		cout << "�û�����" << username << endl;
		cout << "���룺" << password << endl;
		cout << "URL��" << url << endl;
		cout << "���ڣ�" << localDate << endl;
		cout << "============================================" << endl;
	}
	friend ostream& operator<<(ostream& output, Password cipher);
	friend bool operator==(Password password1, Password password2);

	//�������
	char random(const char min, const char max)
	{
		return ((rand() % (max - min + 1)) + min);
	}
	char randomNum()
	{
		return (random('0', '9'));
	}
	char randomUpperLetter()
	{
		return (random(65, 90));
	}
	char randomLowerLetter()
	{
		return (random(97, 122));
	}
	char randomSymbol()
	{
		return (random(33, 47));
	}
	char randomKind(const bool flag)
	{
		if (flag)//�޷���
		{
			int choice;
			choice = rand() % 3;
			if (choice == 0)
			{
				return randomNum();
			}
			else if (choice == 1)
			{
				return randomLowerLetter();
			}
			else
			{
				return randomUpperLetter();
			}
		}
		else
		{
			int choice;
			choice = rand() % 4;
			if (choice == 0)
			{
				return randomNum();
			}
			else if (choice == 1)
			{
				return randomLowerLetter();
			}
			else if (choice == 2)
			{
				return randomUpperLetter();
			}
			else
			{
				return randomSymbol();
			}
		}
	}
};

void passwordMenu();
void encryption();
//�������
/*
char random(const char min, const char max);
char randomNum();
char randomUpperLetter();
char randomLowerLetter();
char randomSymbol();
char randomKind(const bool flag = false);//Ĭ��Ϊ������+��ĸ+���ţ�
*/
