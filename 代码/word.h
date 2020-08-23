#pragma once
#ifndef LengthOfWord
#define LengthOfWord 30
#endif
#include "common.h"

//代码迁移自桌面助手（英语单词本）项目
#pragma once
#pragma warning(disable:4996) 
class Word :public Content
{
public:
	char english[LengthOfWord];
	char chinese[LengthOfWord * 2];
	int isRemember;					/*0,1,2*/
	int tag[5];			/*最多五个标签*/
public:
	Word()
	{
		strcpy(english, "");
		strcpy(chinese, "");
		isRemember = 0;
		tag[0] = 0; tag[1] = 0; tag[2] = 0; tag[3] = 0; tag[4] = 0;
	}
	//show()是听写输出
	void setBasic()
	{
		cout << "请输入英语单词" << endl;
		cin >> english;/*以后还要完善输入检查和限制读入字符数*/

		cout << "请输入汉语释义" << endl;
		cin >> chinese;/*以后还要完善输入检查和限制读入字符数*/
	}
	void setTag()
	{
		while (1)
		{
			system("CLS");
			cout << "选择单词标签" << endl;
			cout << "1.学习\t2.考试\t3日常" << endl;
			cout << "4.重要\t5.四六级\t6.选完了" << endl;
			int t = 0;
			cin >> t;
			if (t >= 1 && t <= 5)
			{
				tag[t - 1] = 1;/*以后改成bool[5]会更好,用非来实现重复选取消*/
			}
			if (t == 6)
			{
				break;
			}
		}
	}
	virtual void setWeight()
	{
		cout << "请输入单词重要程度（0~100）：" << endl;
		cin >> weight;
	}
	virtual void show() {
		cout << "=============================================== " << endl;
		cout << "英语：" << english << "  (状态:";
		if (isRemember)
		{
			cout << "已记住)";
		}
		else
		{
			cout << "未记住)";
		}
		cout<< endl;
		cout << "重要程度：" << weight << endl;
		system("pause");
		cout << "汉语：" << chinese << endl;
		cout << "=============================================== " << endl;
	}
	virtual void setAll() 
	{
		setBasic();
		setTag();
		setWeight();
		cout << "设置完成" << endl;
		Sleep(500);
		system("CLS");
	}
	//友元函数
	friend istream& operator>>(istream& input, Word& word);
	friend ostream& operator<<(ostream& output, Word& word);//非听写输出
	friend bool operator==(Word word1, Word word2);
};
istream& operator>>(istream& input, Word& word);
ostream& operator<<(ostream& output, Word& word);
bool operator==(Word word1, Word word2);

void wordMenu();
