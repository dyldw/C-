#include "user.h"
//#include <string.h>
User::User()
{
	strcpy(username, "dyldw");
	strcpy(password, "Zw15vpm77Obj7cvH");
}
bool User::isUser() {
	cout << "�������û���������" << endl;
	cout << "�û�����";
	char input[30];
	cin >> input;
	if (strcmp(input, username) == 0) {
		cout << "���룺";
		cin >> input;
		if (strcmp(input, password) == 0)
		{
			return true;
		}
		else {
			cout << "�������" << endl;
			system("pause");
		}
	}
	else {
		cout << "�û�������" << endl;
		system("pause");
	}
	return false;
}
void User::mainMenu() {
	while (1)
	{
		system("CLS");
		char choice;
		cout << "========��������========" << endl;
		cout << "	1.�������" << endl;//
		cout << "	2.�ƻ�����" << endl;
		cout << "	3.Ӣ�ﵥ��" << endl;
		cout << "	4.��ԲΧ��" << endl;
		cout << "	5.3D̹��ս" << endl;
		cout << "	6.����ͻ���" << endl;
		cout << "	7.��������" << endl;
		cout << "	8.�ʼ�ת��ҳ" << endl;
		cout << "	9.��ʱ����" << endl;
		cout << "	Q.�˳�����" << endl;
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
			system("start D:\\�����ļ�\\����ѧϰ\\3D̹�˴�ս\\myTankGame.exe");
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
			cout << "˼ά��ͼת��ҳ" << endl;
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
			cout << "��ѡ��" << endl;
			Sleep(500);
		}
		}
	}
}
void User::welcome() {
	cout << "��ӭ��һ����������" << endl;
	//���ÿ���̨���ӣ���������
	system("pause");
	mainMenu();
}
void User::goodbye() {
	cout << "���������Σ����쾹Ȼ������˵Ĵ�����˧���������޵С�" << endl;
	cout << "�ո�һ����˧���к���������ǰ" << endl;
	cout << "���������˺ܾã�˭��û�д������ƽ��" << endl;
	cout << "-----ֱ�������Ҳ����������˾��ӡ�" << endl;
	cout << "Goodbye" << endl;
	system("pause");
}
