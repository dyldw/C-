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
		cout << "分钟:" << "\t";
		int m;
		cin >> m;
		sec = m * 60;
		cout << "秒:" << "\t";
		int s;
		cin >> s;
		sec = sec + s;
		cout << endl;
		cout << "要办的事情:" << endl;
		cin >> note;
		system("CLS");
		cout << m << "分钟" << s << "秒后将提醒" << note << endl;
	}
	void clock()
	{
		Sleep(sec*1000);
		cout << "时间到";
		cout << "已经过了" << sec / 60 << "分钟" << sec % 60 << "秒" << endl;
		cout << note << endl;
		system("start C:\\Users\\Thinkpad\\source\\repos\\个人工具库\\个人工具库\\华工之歌.mp3");
		system("pause");
	}
};