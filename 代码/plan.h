#pragma once
#pragma warning(disable:4996)
#include "common.h"
#include <time.h>
#include <cstdlib>
#include <ctime>

class Plan :public Content
{
public:
	char title[50];
	char description[300];
	bool isImportant;
	bool isEmergency;
	char deadline[30];
	char startDate[30];
public:
	Plan()
	{
		strcpy(title, "");
		strcpy(description, "");
		strcpy(deadline, "");
		strcpy(startDate, "");
		isImportant = false;
		isEmergency = false;

	}
	void setTitle() {
		cout << "����ƻ�/������⣺";
		cin >> title;
		cout<< endl;
	}
	void setDescription() {
		cout << "�����ƻ�/���������û�пո�,������\\���棩";
		cin >> description;
		cout << endl;
	}
	void setTag() {
		char choice;
		cout << "�Ƿ���Ҫ����Y/N��";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			isImportant = true;
		}
		else {
			isImportant = false;
		}
		cout << endl;
		cout << "�Ƿ��������Y/N��";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			isEmergency = true;
		}
		else {
			isEmergency = false;
		}
		cout << endl;
	}
	void setStartDate() {
		time_t now = time(0);		//��ǰϵͳ�ĵ�ǰ����/ʱ��
		char* temp = ctime(&now);	//�� now ת��Ϊ�ַ�����ʽctime(&now);
		strcpy(startDate, temp);
	}
	void setDeadline() {
		cout << "�����ֹ���ڣ�" << endl;
		cin >> deadline;
	}
	virtual void setWeight()
	{
		cout << "������ƻ���Ҫ�̶ȣ�0~100����" << endl;
		cin >> weight;
	}
	virtual void setAll() {
		setTitle();
		setDescription();
		setTag();
		setStartDate();
		setDeadline();
		setWeight();
	}
	virtual void show() {
		cout << "=====================�ƻ�===================" << endl;
		cout << "	���⣺" <<title << endl;
		cout << "	������" << description << endl;
		cout << "	���ʣ�"; 
		if (isImportant) {
			cout << "��Ҫ\t";
		}
		else {
			cout << "����Ҫ\t";
		}
		if (isEmergency)
		{
			cout << "����\n";
		}
		else {
			cout << "������\n";
		}
		cout << "	��ʼʱ�䣺" << startDate << endl;
		cout << "	��ֹʱ�䣺" << deadline << endl;
		cout << "============================================" << endl;
	}
	friend ostream& operator<<(ostream& output, Plan plan);
	friend bool operator==(Plan plan1,Plan plan2);
};
ostream& operator<<(ostream& output, Plan plan);
bool operator==(Plan plan1, Plan plan2);
void planMenu();
