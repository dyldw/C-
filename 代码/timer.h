#pragma once
#include "common.h"
class Timer
{
	int sec;
	unsigned char note[200];
public:
	void setALL()
	{
		sec = 0;
		cout << "����:" << "\t";
		int m;
		cin >> m;
		sec = m * 60;
		cout << "��:" << "\t";
		int s;
		cin >> s;
		sec = sec + s;
		cout << endl;
		cout << "Ҫ�������:" << endl;
		cin >> note;
		system("CLS");
		cout << m << "����" << s << "�������" << note << endl;
	}
	void clock()
	{
		Sleep(sec*1000);
		cout << "ʱ�䵽";
		cout << "�Ѿ�����" << sec / 60 << "����" << sec % 60 << "��" << endl;
		cout << note << endl;
		system("start C:\\Users\\Thinkpad\\source\\repos\\���˹��߿�\\���˹��߿�\\����֮��.mp3");
		system("pause");
	}
};