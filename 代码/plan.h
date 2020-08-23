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
		cout << "输入计划/待办标题：";
		cin >> title;
		cout<< endl;
	}
	void setDescription() {
		cout << "简述计划/待办事项：（没有空格,换行用\\代替）";
		cin >> description;
		cout << endl;
	}
	void setTag() {
		char choice;
		cout << "是否重要？（Y/N）";
		cin >> choice;
		if (choice == 'y' || choice == 'Y')
		{
			isImportant = true;
		}
		else {
			isImportant = false;
		}
		cout << endl;
		cout << "是否紧急？（Y/N）";
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
		time_t now = time(0);		//当前系统的当前日期/时间
		char* temp = ctime(&now);	//把 now 转换为字符串形式ctime(&now);
		strcpy(startDate, temp);
	}
	void setDeadline() {
		cout << "输入截止日期：" << endl;
		cin >> deadline;
	}
	virtual void setWeight()
	{
		cout << "请输入计划重要程度（0~100）：" << endl;
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
		cout << "=====================计划===================" << endl;
		cout << "	标题：" <<title << endl;
		cout << "	简述：" << description << endl;
		cout << "	性质："; 
		if (isImportant) {
			cout << "重要\t";
		}
		else {
			cout << "不重要\t";
		}
		if (isEmergency)
		{
			cout << "紧急\n";
		}
		else {
			cout << "不紧急\n";
		}
		cout << "	开始时间：" << startDate << endl;
		cout << "	截止时间：" << deadline << endl;
		cout << "============================================" << endl;
	}
	friend ostream& operator<<(ostream& output, Plan plan);
	friend bool operator==(Plan plan1,Plan plan2);
};
ostream& operator<<(ostream& output, Plan plan);
bool operator==(Plan plan1, Plan plan2);
void planMenu();
