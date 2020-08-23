#pragma once
#ifndef LengthOfWord
#define LengthOfWord 30
#endif
#include "common.h"

//����Ǩ�����������֣�Ӣ�ﵥ�ʱ�����Ŀ
#pragma once
#pragma warning(disable:4996) 
class Word :public Content
{
public:
	char english[LengthOfWord];
	char chinese[LengthOfWord * 2];
	int isRemember;					/*0,1,2*/
	int tag[5];			/*��������ǩ*/
public:
	Word()
	{
		strcpy(english, "");
		strcpy(chinese, "");
		isRemember = 0;
		tag[0] = 0; tag[1] = 0; tag[2] = 0; tag[3] = 0; tag[4] = 0;
	}
	//show()����д���
	void setBasic()
	{
		cout << "������Ӣ�ﵥ��" << endl;
		cin >> english;/*�Ժ�Ҫ��������������ƶ����ַ���*/

		cout << "�����뺺������" << endl;
		cin >> chinese;/*�Ժ�Ҫ��������������ƶ����ַ���*/
	}
	void setTag()
	{
		while (1)
		{
			system("CLS");
			cout << "ѡ�񵥴ʱ�ǩ" << endl;
			cout << "1.ѧϰ\t2.����\t3�ճ�" << endl;
			cout << "4.��Ҫ\t5.������\t6.ѡ����" << endl;
			int t = 0;
			cin >> t;
			if (t >= 1 && t <= 5)
			{
				tag[t - 1] = 1;/*�Ժ�ĳ�bool[5]�����,�÷���ʵ���ظ�ѡȡ��*/
			}
			if (t == 6)
			{
				break;
			}
		}
	}
	virtual void setWeight()
	{
		cout << "�����뵥����Ҫ�̶ȣ�0~100����" << endl;
		cin >> weight;
	}
	virtual void show() {
		cout << "=============================================== " << endl;
		cout << "Ӣ�" << english << "  (״̬:";
		if (isRemember)
		{
			cout << "�Ѽ�ס)";
		}
		else
		{
			cout << "δ��ס)";
		}
		cout<< endl;
		cout << "��Ҫ�̶ȣ�" << weight << endl;
		system("pause");
		cout << "���" << chinese << endl;
		cout << "=============================================== " << endl;
	}
	virtual void setAll() 
	{
		setBasic();
		setTag();
		setWeight();
		cout << "�������" << endl;
		Sleep(500);
		system("CLS");
	}
	//��Ԫ����
	friend istream& operator>>(istream& input, Word& word);
	friend ostream& operator<<(ostream& output, Word& word);//����д���
	friend bool operator==(Word word1, Word word2);
};
istream& operator>>(istream& input, Word& word);
ostream& operator<<(ostream& output, Word& word);
bool operator==(Word word1, Word word2);

void wordMenu();
