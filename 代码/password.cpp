#include "password.h"
/*
�Ѿ���ת��λ�õ��������ϵ��
char random(const char min, const char max)
{
	return ((rand() % (max - min + 1)) + min);
}
char randomNum()
{
	return (random('0', '9'));
}
char randomUpperLetter()
{
	return (random(65, 90));
}
char randomLowerLetter()
{
	return (random(97, 122));
}
char randomSymbol()
{
	return (random(33, 47));
}
char randomKind(const bool flag)
{
	if (flag)//�޷���
	{
		int choice;
		choice = rand() % 3;
		if (choice == 0)
		{
			return randomNum();
		}
		else if (choice == 1)
		{
			return randomLowerLetter();
		}
		else
		{
			return randomUpperLetter();
		}
	}
	else
	{
		int choice;
		choice = rand() % 4;
		if (choice == 0)
		{
			return randomNum();
		}
		else if (choice == 1)
		{
			return randomLowerLetter();
		}
		else if (choice == 2)
		{
			return randomUpperLetter();
		}
		else
		{
			return randomSymbol();
		}
	}
}
*/
ostream& operator<<(ostream& output, Password cipher)
{
	cout << "=====================�˻�===================" << endl;
	cout << "	�û����� " << cipher.username << endl;
	cout << "	���룺 "<<cipher.password << endl;
	cout << "	��ַ�� " << cipher.url << endl;
	cout << "	���ڣ� " << cipher.localDate << endl;
	cout << "============================================" << endl;

	return output;
}
bool operator==(Password password1, Password password2)
{
	int score = 0;
	for (int i = 0; i < 5; i++)
	{
		if (password1.tag[i] == password2.tag[i])
		{
			score++;
		}
	}
	int flag = 0;
	if (password1.username == password2.username)
	{
		flag = 1;
	}
	if (password1.url == password2.url)
	{
		flag = 1;
	}
	return (score > 3 || flag);
}
//�ļ�����
void encryption()
{
	cout << "������Ҫ����/���ܵ��ļ�·��" << endl;
	char filePath[300];
	cin >> filePath;
	//����Ĳ���
	int insertIndex;
	for (int i = 0; i < 300; i++)
	{
		if (filePath[i] == '\\')
		{
			insertIndex = i;
			for (int j = 298; j >= insertIndex; j--)
			{
				filePath[j + 1] = filePath[j];
			}
			filePath[insertIndex] = '\\';
			i = i + 1;
		}
	}

	cout << "ȷ��filePath��Y/N����" << endl;
	cout << filePath << endl;
	char choice;
	cin >> choice;
	if (choice != 'Y' && choice != 'y')
	{
		return;
	}
	fstream f(filePath, ios::in | ios::out | ios::binary);
	f.seekp(0, ios::beg);
	int i;
	int r = 13;
	unsigned char cleartext;
	for (i = 0; i < 1000; i++)
	{
		r = (25171 * r + 13859) % 127;
		f.seekg(long(sizeof(char) * i));
		f.read((char*)&cleartext, sizeof(char));
		cleartext ^= r;
		f.seekp(-long(sizeof(char)), ios::cur);
		f.write((char*)&cleartext, sizeof(char));
	}
	cout << "����/�������" << endl;
	f.close();
}
//�˻������ֵĽ����˵�
void passwordMenu()
{

	Password password;
	//Content* content = new Password;
	List<Password> listOfPassword;
	const char* passwordFileDat = "d:\\passwordFile.dat";
	listOfPassword.loadDatFile(passwordFileDat);
	while (1)
	{
		system("CLS");
		char choice;
		cout << "======�������======" << endl;
		cout << "1.����˻�        " << endl;
		cout << "2.���浱ǰ����    " << endl;
		cout << "3.�����������    " << endl;
		cout << "4.���������¼��  " << endl;
		cout << "5.�����˻�        " << endl;
		cout << "6.�����ļ�        " << endl;
		cout << "7.�����ļ�        " << endl;
		cout << "8.ɾ������        " << endl;
		cout << "9.�޸�����        " << endl;
		cout << "Q.�˳�            " << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			cout << "Ĭ�����볤��Ϊ16" << endl;
			password.setAll();
			listOfPassword.append(password);
			system("pause");
			break;
		}
		case '2':
		{
			listOfPassword.saveDatFile(passwordFileDat);
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
				listOfPassword.print();
			}
			else {
				listOfPassword.resPrint();
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
			password.setAll();
			if (listOfPassword.find(password) == nullptr)
			{
				cout << "û���ҵ�" << endl;
				Sleep(300);
				break;
			}
			cout << listOfPassword.find(password)->content;
			system("pause");
			break;
		}
		case '6':
		{
			encryption();
			system("pause");
			break;
		}
		case '7':
		{
			encryption();
			system("pause");
			break;
		}
		case '8':
		{
			cout << "1�����ɾ��   2��������Ӣ��ɾ��" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "������ţ�";
				int i;
				cin >> i;
				listOfPassword.remove(i);
			}
			else if (choice == '2')
			{
				password.setAll();
				listOfPassword.remove(password);
			}
			else
			{
				cout << "�˳�" << endl;
			}
			system("pause");
			break;
		}
		case '9':
		{
			cout << "1������޸�   2��������Ӣ���޸�" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "������ţ�";
				int i;
				cin >> i;
				cout << "�������µ��˻�" << endl;
				password.setAll();
				listOfPassword.replace(i, password);
			}
			else if (choice == '2')
			{
				cout << "������Ҫ�޸ĵ��˻�" << endl;
				password.setAll();
				cout << "�������µ��˻�" << endl;
				Password newPassword;
				newPassword.setAll();
				listOfPassword.replace(password, newPassword);
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
