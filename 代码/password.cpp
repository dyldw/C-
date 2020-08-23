#include "password.h"
/*
已经被转移位置的随机函数系列
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
	if (flag)//无符号
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
	cout << "=====================账户===================" << endl;
	cout << "	用户名： " << cipher.username << endl;
	cout << "	密码： "<<cipher.password << endl;
	cout << "	网址： " << cipher.url << endl;
	cout << "	日期： " << cipher.localDate << endl;
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
//文件加密
void encryption()
{
	cout << "请输入要加密/解密的文件路径" << endl;
	char filePath[300];
	cin >> filePath;
	//数组的插入
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

	cout << "确认filePath（Y/N）：" << endl;
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
	cout << "加密/解密完成" << endl;
	f.close();
}
//账户管理部分的交互菜单
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
		cout << "======密码管理======" << endl;
		cout << "1.添加账户        " << endl;
		cout << "2.保存当前密码    " << endl;
		cout << "3.浏览所有密码    " << endl;
		cout << "4.导出密码记录本  " << endl;
		cout << "5.查找账户        " << endl;
		cout << "6.加密文件        " << endl;
		cout << "7.解密文件        " << endl;
		cout << "8.删除密码        " << endl;
		cout << "9.修改密码        " << endl;
		cout << "Q.退出            " << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			cout << "默认密码长度为16" << endl;
			password.setAll();
			listOfPassword.append(password);
			system("pause");
			break;
		}
		case '2':
		{
			listOfPassword.saveDatFile(passwordFileDat);
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
				cout << "没有找到" << endl;
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
			cout << "1按序号删除   2按单词中英文删除" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "输入序号：";
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
				cout << "退出" << endl;
			}
			system("pause");
			break;
		}
		case '9':
		{
			cout << "1按序号修改   2按单词中英文修改" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "输入序号：";
				int i;
				cin >> i;
				cout << "请输入新的账户" << endl;
				password.setAll();
				listOfPassword.replace(i, password);
			}
			else if (choice == '2')
			{
				cout << "请输入要修改的账户" << endl;
				password.setAll();
				cout << "请输入新的账户" << endl;
				Password newPassword;
				newPassword.setAll();
				listOfPassword.replace(password, newPassword);
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
			return;
		}
		default:
		{
			cout << "请选择" << endl;
			Sleep(500);
		}
		}
	}
}
