#include "plan.h"

ostream& operator<<(ostream& output, Plan plan)
{
	plan.show();
	return output;
}
bool operator==(Plan plan1, Plan plan2)
{
	return strcmp(plan1.title, plan2.title) == 0;
}
void planMenu()
{
	Plan plan;
	List<Plan> listOfPlan;
	const char* planFileDat = "d:\\planFile.dat";
	listOfPlan.loadDatFile(planFileDat);
	while (1)
	{
		system("CLS");
		char choice;
		cout << "=======计划=======" << endl;
		cout << "1.添加计划/待办" << endl;//
		cout << "2.保存计划/待办" << endl;
		cout << "3.浏览所有计划/待办" << endl;
		cout << "4.导出计划记录本(未完成)" << endl;
		cout << "5.查找计划/待办" << endl;
		cout << "6.删除计划" << endl;
		cout << "7.修改计划" << endl;
		cout << "Q.退出" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			plan.setAll();
			listOfPlan.append(plan);
			system("pause");
			break;
		}
		case '2':
		{
			listOfPlan.saveDatFile(planFileDat);
			cout << "保存完成" << endl;
			Sleep(500);
			system("pause");
			break;
		}
		case '3':
		{
			char ans;
			cout << "输入1，正序输出     输入2，倒序输出" << endl;
			cin >> ans;
			if (ans == '1')
			{
				listOfPlan.print();
			}
			else {
				listOfPlan.resPrint();
			}
			system("pause");
			break;
		}
		case '4':
		{

			system("pause");
			break;
		}
		case '5':
		{
			plan.setAll();
			if (listOfPlan.find(plan) == nullptr)
			{
				cout << "没有找到" << endl;
				Sleep(300);
				break;
			}
			cout << listOfPlan.find(plan)->content;
			system("pause");
			break;
		}
		case '6':
		{
			cout << "1按序号删除计划   2按单词中英文删除" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "输入序号：";
				int i;
				cin >> i;
				listOfPlan.remove(i);
			}
			else if (choice == '2')
			{
				plan.setAll();
				listOfPlan.remove(plan);
			}
			else
			{
				cout << "退出" << endl;
			}
			system("pause");
			break;
		}
		case '7':
		{
			cout << "1按序号修改计划   2按单词中英文修改" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "输入序号：";
				int i;
				cin >> i;
				cout << "请输入新的计划" << endl;
				plan.setAll();
				listOfPlan.replace(i, plan);
			}
			else if (choice == '2')
			{
				cout << "请输入要修改的计划" << endl;
				plan.setAll();
				cout << "请输入新的计划" << endl;
				Plan newPlan;
				newPlan.setAll();
				listOfPlan.replace(plan, newPlan);
			}
			else
			{
				cout << "退出" << endl;
			}

			system("pause");
			break;
		}
		case 'q':
		case 'Q':
		{
			return;//退出前调用结束模块
		}
		default:
		{
			cout << "请选择" << endl;
			Sleep(500);
		}
		}
	}
}
