#include "word.h"

istream& operator>>(istream& input, Word& word)
{
	word.setAll();
	return input;
}
//����д��� -OK 
ostream& operator<<(ostream& output, Word& word)
{
	output << "Ӣ�" << word.english << endl;
	output << "���" << word.chinese << endl;
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
		cout << "=======����ѧϰ=======" << endl;
		cout << "1.��ӵ���" << endl;
		cout << "2.���浥�ʱ�" << endl;
		cout << "3.������е���" << endl;
		cout << "4.�������ʱ�(δ���)" << endl;
		cout << "5.���ҵ���" << endl;
		cout << "6.ɾ������" << endl;
		cout << "7.�޸ĵ���" << endl;
		cout << "8.��ϰ����" << endl;
		cout << "Q.�˳�" << endl;
		cin >> choice;

		switch (choice)
		{
		case '1':
		{
			cout << "Ĭ�����볤��Ϊ20" << endl;
			word.setAll();
			listOfWord.append(word);
			system("pause");
			break;
		}
		case '2':
		{
			listOfWord.saveDatFile(wordFileDat);
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
				cout << "û���ҵ�" << endl;
				Sleep(300);
				break;
			}
			cout << listOfWord.find(word)->content;
			system("pause");
			break;
		}
		case '6':
		{
			cout << "1�����ɾ������(��һ�����Ϊ0)   2��������Ӣ��ɾ��" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "������ţ�";
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
				cout << "�˳�" << endl;
			}
			system("pause");
			break;
		}
		case '7':
		{
			cout << "1������޸ĵ���   2��������Ӣ���޸�" << endl;
			char choice;
			cin >> choice;
			if (choice == '1') {
				cout << "������ţ�";
				int i;
				cin >> i;
				cout << "�������µĵ���" << endl;
				word.setAll();
				listOfWord.replace(i,word);
			}
			else if (choice == '2')
			{
				cout << "������Ҫ�޸ĵĵ���" << endl;
				word.setAll();
				cout << "�������µĵ���" << endl;
				Word newWord;
				newWord.setAll();
				listOfWord.replace(word, newWord);
			}
			else
			{
				cout << "�˳�" << endl;
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
					cout << "�Ƿ��ס����Y/N��" << endl;
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
			cout << "��ѡ��" << endl;
			Sleep(500);
		}
		}
	}
}
