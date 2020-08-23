//代码迁移自密码库
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
	//显示大小是4，多次实验发现实际大小是26，为保险起见，使用大小是30
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
		cout << "账号名称：";
		cin >> username;
		cout << "相关网址：";
		cin >> url;
	}
	void setTag()
	{
		cout << "选择标签：1课内学习 2课外学习 3学校账户 4娱乐账户 5其它账户" << endl;
		cout << "其他选择跳过该步骤" << endl;
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
		long long now = time(0);		//当前系统的当前日期/时间
		char* temp = ctime(&now);	//把 now 转换为字符串形式ctime(&now);
		strcpy(localDate, temp);
	}
	void generatePassword(const int length = 16) {
		cout << "是否包含特殊符号？（Y/N）" << endl;
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
		cout << "此次随机的密码：";
		cout << password << "  " << strlen(password) << "位" << endl;
		while (1) {
			cout << "1重来一次 2自定义 3退出" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				generatePassword();
				cout << password << "  " << strlen(password) << "位" << endl;
				setLocalDate();
			}
			else if (choice == '2') {
				cin >> password;
				cout << password << "  " << strlen(password) << "位" << endl;
				setLocalDate();
			}
			else if (choice == '3') {
				setLocalDate();
				break;
			}
			else
			{
				cout << "请选择" << endl;
			}
		}
	}
	//公共接口
	virtual void setWeight()
	{
		cout << "请输入密码重要程度（0~100）：" << endl;
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
		cout << "=====================账户===================" << endl;
		cout << "用户名：" << username << endl;
		cout << "密码：" << password << endl;
		cout << "URL：" << url << endl;
		cout << "日期：" << localDate << endl;
		cout << "============================================" << endl;
	}
	friend ostream& operator<<(ostream& output, Password cipher);
	friend bool operator==(Password password1, Password password2);

	//随机函数
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
		if (flag)//无符号
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
//随机函数
/*
char random(const char min, const char max);
char randomNum();
char randomUpperLetter();
char randomLowerLetter();
char randomSymbol();
char randomKind(const bool flag = false);//默认为（数字+字母+符号）
*/
