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
		cout << "=======�ƻ�=======" << endl;
		cout << "1.��Ӽƻ�/����" << endl;//
		cout << "2.����ƻ�/����" << endl;
		cout << "3.������мƻ�/����" << endl;
		cout << "4.�����ƻ���¼��(δ���)" << endl;
		cout << "5.���Ҽƻ�/����" << endl;
		cout << "6.ɾ���ƻ�" << endl;
		cout << "7.�޸ļƻ�" << endl;
		cout << "Q.�˳�" << endl;
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
			cout << "�������" << endl;
			Sleep(500);
			system("pause");
			break;
		}
		case '3':
		{
			char ans;
			cout << "����1���������     ����2���������" << endl;
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
				cout << "û���ҵ�" << endl;
				Sleep(300);
				break;
			}
			cout << listOfPlan.find(plan)->content;
			system("pause");
			break;
		}
		case '6':
		{
			cout << "1�����ɾ���ƻ�   2��������Ӣ��ɾ��" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "������ţ�";
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
				cout << "�˳�" << endl;
			}
			system("pause");
			break;
		}
		case '7':
		{
			cout << "1������޸ļƻ�   2��������Ӣ���޸�" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "������ţ�";
				int i;
				cin >> i;
				cout << "�������µļƻ�" << endl;
				plan.setAll();
				listOfPlan.replace(i, plan);
			}
			else if (choice == '2')
			{
				cout << "������Ҫ�޸ĵļƻ�" << endl;
				plan.setAll();
				cout << "�������µļƻ�" << endl;
				Plan newPlan;
				newPlan.setAll();
				listOfPlan.replace(plan, newPlan);
			}
			else
			{
				cout << "�˳�" << endl;
			}

			system("pause");
			break;
		}
		case 'q':
		case 'Q':
		{
			return;//�˳�ǰ���ý���ģ��
		}
		default:
		{
			cout << "��ѡ��" << endl;
			Sleep(500);
		}
		}
	}
}
