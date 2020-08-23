#include "user.h"
//#include <string.h>
User::User()
{
	strcpy(username, "dyldw");
	strcpy(password, "Zw15vpm77Obj7cvH");
}
bool User::isUser() {
	cout << "请输入用户名和密码" << endl;
	cout << "用户名：";
	char input[30];
	cin >> input;
	if (strcmp(input, username) == 0) {
		cout << "密码：";
		cin >> input;
		if (strcmp(input, password) == 0)
		{
			return true;
		}
		else {
			cout << "密码错误" << endl;
			system("pause");
		}
	}
	else {
		cout << "用户名错误" << endl;
		system("pause");
	}
	return false;
}
void User::mainMenu() {
	while (1)
	{
		system("CLS");
		char choice;
		cout << "========桌面助手========" << endl;
		cout << "	1.密码管理" << endl;//
		cout << "	2.计划待办" << endl;
		cout << "	3.英语单词" << endl;
		cout << "	4.方圆围棋" << endl;
		cout << "	5.3D坦克战" << endl;
		cout << "	6.聊天客户端" << endl;
		cout << "	7.聊天服务端" << endl;
		cout << "	8.笔记转网页" << endl;
		cout << "	9.定时任务" << endl;
		cout << "	Q.退出程序" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			system("CLS");
			passwordMenu();
			system("pause");
			break;
		}
		case '2':
		{
			system("CLS");
			planMenu();
			system("pause");
			break;
		}
		case '3':
		{
			system("CLS");
			wordMenu();
			system("pause");
			break;
		}
		case '4':
		{
			system("CLS");
			Go();
			system("pause");
			break;
		}
		case '5':
		{
			system("CLS");
			system("start D:\\个人文件\\课外学习\\3D坦克大战\\myTankGame.exe");
			system("pause");
			break;
		}
		case '6':
		{
			system("CLS");
			system("start C:\\Users\\Thinkpad\\source\\repos\\SecurityChat\\Debug\\client.exe");
			system("pause");
			break;
		}
		case '7':
		{
			system("CLS");
			system("start C:\\Users\\Thinkpad\\source\\repos\\SecurityChat\\Debug\\server.exe");
			system("pause");
			break;
		}
		case '8':
		{
			system("CLS");
			cout << "思维导图转网页" << endl;
			md2html test;
			test.setAll();
			system("pause");
			break;
		}
		case '9':
		{
			system("CLS");
			Timer timer;
			timer.setALL();
			timer.clock();
			break;
		}
		case 'q':
		case 'Q':
		{
			return;
		}
		default:
		{
			cout << "请选择" << endl;
			Sleep(500);
		}
		}
	}
}
void User::welcome() {
	cout << "欢迎董一龙大王回来" << endl;
	//设置控制台样子，字体样子
	system("pause");
	mainMenu();
}
void User::goodbye() {
	cout << "唉，真无奈，今天竟然还是如此的聪明，帅气，天下无敌。" << endl;
	cout << "刚刚一个很帅的男孩子在我面前" << endl;
	cout << "我们相视了很久，谁都没有打破这份平静" << endl;
	cout << "-----直到手累我才慢慢放下了镜子。" << endl;
	cout << "Goodbye" << endl;
	system("pause");
}
