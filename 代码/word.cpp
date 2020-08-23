#include "word.h"

istream& operator>>(istream& input, Word& word)
{
	word.setAll();
	return input;
}
//非听写输出 -OK 
ostream& operator<<(ostream& output, Word& word)
{
	output << "英语：" << word.english << endl;
	output << "汉语：" << word.chinese << endl;
	return output;
}
bool operator==(Word word1, Word word2)
{
	return (strcmp(word1.english,word2.english)==0)||(strcmp(word1.chinese, word2.chinese) == 0);
}
void wordMenu() {
	Word word;
	List<Word> listOfWord;
	const char* wordFileDat = "d:\\wordFile.dat";
	listOfWord.loadDatFile(wordFileDat);
	while (1)
	{
		system("CLS");
		char choice;
		cout << "=======单词学习=======" << endl;
		cout << "1.添加单词" << endl;
		cout << "2.保存单词表" << endl;
		cout << "3.浏览所有单词" << endl;
		cout << "4.导出单词本(未完成)" << endl;
		cout << "5.查找单词" << endl;
		cout << "6.删除单词" << endl;
		cout << "7.修改单词" << endl;
		cout << "8.复习单词" << endl;
		cout << "Q.退出" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			cout << "默认密码长度为20" << endl;
			word.setAll();
			listOfWord.append(word);
			system("pause");
			break;
		}
		case '2':
		{
			listOfWord.saveDatFile(wordFileDat);
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
				listOfWord.print();
			}
			else {
				listOfWord.resPrint();
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
			word.setAll();
			if (listOfWord.find(word) == nullptr)
			{
				cout << "没有找到" << endl;
				Sleep(300);
				break;
			}
			cout << listOfWord.find(word)->content;
			system("pause");
			break;
		}
		case '6':
		{
			cout << "1按序号删除单词(第一个序号为0)   2按单词中英文删除" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "输入序号：";
				int i;
				cin >> i;
				listOfWord.remove(i);
			}
			else if (choice == '2')
			{
				word.setAll();
				listOfWord.remove(word);
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
			cout << "1按序号修改单词   2按单词中英文修改" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "输入序号：";
				int i;
				cin >> i;
				cout << "请输入新的单词" << endl;
				word.setAll();
				listOfWord.replace(i,word);
			}
			else if (choice == '2')
			{
				cout << "请输入要修改的单词" << endl;
				word.setAll();
				cout << "请输入新的单词" << endl;
				Word newWord;
				newWord.setAll();
				listOfWord.replace(word, newWord);
			}
			else
			{
				cout << "退出" << endl;
			}
			
			system("pause");
			break;
		}
		case '8':
		{
			__forest::Heap<Word, __forest::Greater<Word>> heap(listOfWord.getLength()+1);
			for (int i = 0; i < listOfWord.getLength(); i++)
			{
				heap.insert(listOfWord[i]);
			}
			for (int i = 0; i < listOfWord.getLength(); i++)
			{
				while (1)
				{
					heap.peek().show();
					char choice;
					cout << "是否记住？（Y/N）" << endl;
					cin >> choice;

					if (choice == 'Y' || choice == 'y')
					{
						heap.poll();
						break;
					}
				}
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
