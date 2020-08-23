#pragma once
#include <iostream>
#include <fstream>
using namespace std;

/// <summary>
/// This is a Node template.
/// 
/// Node template has next_ptr, prev_ptr and content.
/// </summary>
/// <typeparam name="T"> T can be Password class, Plan class and Word class.</typeparam>
template<typename T> class Node{
public:
	Node<T>* next;
	Node<T>* prev;
	T content;

public:
	/// <summary>
	/// This is the constructor for the node class.
	/// It requires at least one parameter of type T.
	/// </summary>
	/// <param name="content">T can be Password class, Plan class and Word class.</param>
	/// <returns>Build node object</returns>
	Node(T content) {
		next = nullptr;
		prev = nullptr;
		this->content = content;
	}
	~Node() {
		next = nullptr;
		prev = nullptr;
	}
};

/// <summary>
/// This is a bi-directional linked list class template.
/// 
/// This linked list provides most common methods, such as saving, adding, deleting, modifying, and finding data.
/// </summary>
/// <typeparam name="T">T can be Password class, Plan class and Word class.</typeparam>
template<typename T> class List {
public:
	Node<T>* head;
	Node<T>* tail;
	/// <summary>
	/// The length of the list
	/// </summary>
	int length;
public:
	/// <summary>
	/// This is the constructor for the linked list class, where it initializes the pointer to null and sets the length to one.
	/// </summary>
	/// <returns>list object</returns>
	List() {
		head = nullptr;
		tail = nullptr;
		length = 0;
	}
	~List() {
		if (isEmpty()) {
			cout << "空链表" << endl;
			return;
		}
		while (tail != nullptr)
		{
			Node<T>* temp = tail;
			tail = tail->prev;
			temp->prev = nullptr;
			delete temp;
			length--;
		}
	}
	/// <summary>
	/// Add a new node from the end of the list
	/// </summary>
	/// <param name="content">The contents of the node to be added</param>
	void append(const T content) {
		if (head == nullptr)
		{
			head = new Node<T>(content);
			tail = head;
			length = 1;
		}
		else {
			Node<T>* temp = tail;
			tail=new Node<T>(content);
			temp->next = tail;
			tail->prev = temp;
			length++;
		}
	}
	/// <summary>
	/// Remove nodes from the linked list.
	/// </summary>
	/// <param name="content">content</param>
	void remove(const T content) {
		if (isEmpty()) {
			cout << "空链表" << endl;
			return;
		}
		for (Node<T>* temp = tail; temp != nullptr; temp = temp->prev) 
		{
			if (temp->content == content)
			{
				if (temp == tail)
				{
					tail = tail->prev;
					temp->prev = nullptr;
					if (tail != nullptr)
					{
						tail->next = nullptr;
					}
					delete temp;
					length--;
					return;
				}
				else if (temp == head) {
					head = head->next;
					temp->next = nullptr;
					if (head != nullptr)
					{
						head->prev = nullptr;
					}
					delete temp;//此处误写成head导致析构时发生BUG
					length--;
					return;
				}
				else {
					temp->next->prev = temp->prev;
					temp->prev->next = temp->next;
					temp->next = nullptr;
					temp->prev = nullptr;
					delete temp;
					length--;
					return;
				}
			}
			else
			{
				;
			}
		}
	}
	/// <summary>
	/// Remove nodes from the linked list.
	/// </summary>
	/// <param name="index">The index of Node</param>
	void remove(const int index) {
		if (isEmpty()) {
			cout << "空链表" << endl;
			return;
		}
		Node<T>* temp = find(index);
		if (temp == tail)
		{
			tail = tail->prev;
			temp->prev = nullptr;
			if (tail != nullptr)
			{
				tail->next = nullptr;
			}
			delete temp;
			length--;
			return;
		}
		else if (temp == head) {
			head = head->next;
			temp->next = nullptr;
			if (head != nullptr)
			{
				head->prev = nullptr;
			}
			delete temp;//此处误写成head导致析构时发生BUG
			length--;
			return;
		}
		else {
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = nullptr;
			temp->prev = nullptr;
			delete temp;
			length--;
			return;
		}
	}
	/// <summary>
	/// Modify node content
	/// </summary>
	/// <param name="oldContent">The content before modification</param>
	/// <param name="newContent">The new content</param>
	void replace(const T oldContent, const T newContent)
	{
		if (isEmpty()) {
			cout << "空链表" << endl;
			return;
		}
		remove(oldContent);
		append(newContent);
	}
	/// <summary>
	/// Modify the NTH node.
	/// </summary>
	/// <param name="index">the index of Node</param>
	/// <param name="newContent">newContent</param>
	void replace(int index, const T newContent)
	{
		if (isEmpty()) {
			cout << "空链表" << endl;
			return;
		}
		remove(index);
		append(newContent);
	}
	/// <summary>
	/// Print the list
	/// </summary>
	void print() {
		if (isEmpty()) {
			cout << "空链表" << endl;
			return;
		}
		for (int i = 0; i < length; i++)
		{
			cout << (find(i)->content)<<" ";
		}
	}
	/// <summary>
	/// Print the list in reverse order
	/// </summary>
	void resPrint() {
		if (isEmpty()) {
			cout << "空链表" << endl;
			return;
		}
		for (int i = length - 1; i >= 0; i--)
		{
			cout << (find(i)->content) << " ";
		}
	}
	/// <summary>
	/// Look for nodes in the linked list
	/// </summary>
	/// <param name="index">The index of the content you are looking for</param>
	/// <returns>
	/// Pointer to the node found. 
	/// Returns a null pointer if the index is out of bounds
	/// </returns>
	Node<T>* find(const int index) {
		//越界返回nullptr，使用时注意
		if (isEmpty()) {
			cout << "空链表" << endl;
			return nullptr;
		}
		if (index < 0)
		{
			return nullptr;
		}
		Node<T>* temp = head;
		for (int i = 0; i < index && temp != nullptr; i++)
		{
			temp = temp->next;
		}
		return temp;
	}
	/// <summary>
	/// Look for nodes in the linked list
	/// </summary>
	/// <param name="content">content</param>
	/// <returns>
	/// Pointer to the node found. 
	/// Returns a null pointer if not found in the linked list
	/// </returns>
	Node<T>* find(const T content) {
		if (isEmpty()) {
			cout << "空链表" << endl;
			return nullptr;
		}
		for (Node<T>* temp = tail; temp != nullptr; temp = temp->prev)
		{
			if (temp->content == content)
			{
				return temp;
			}
		}
		cout << "没有找到" << endl;
		return nullptr;
	}
	/// <summary>
	/// get the length of the list
	/// </summary>
	/// <returns>the length of the list</returns>
	int getLength() { return length; };
	/// <summary>
	/// Determines if the list is empty
	/// </summary>
	/// <returns>true or false</returns>
	bool isEmpty() {
		return (length == 0);
	}
	/// <summary>
	/// Save the data in the linked list to a binary file.
	/// List's file operation (Save will overwrite the original file, so it's better to load it automatically).
	/// </summary>
	/// <param name="fileName">The file path</param>
	void saveDatFile(const char* fileName = "listFile.dat") {
		T tempContent;
		ofstream outFile(fileName, ios::out | ios::binary);
		for (int i = 0; i < length; i++)
		{
			tempContent = (find(i)->content);
			outFile.write((char*)&tempContent,sizeof(tempContent));
		}
		outFile.close();
	}
	/// <summary>
	/// Load data from binary file to linked list.
	/// </summary>
	/// <param name="fileName">The file path</param>
	void loadDatFile(const char* fileName = "listFile.dat") {
		T tempContent;
		ifstream inFile(fileName, ios::in | ios::binary);
		if (!inFile) {
			cout << "打开文件失败" << endl;
		}
		while (inFile.read((char*)&tempContent, sizeof(tempContent))){
			append(tempContent);
		}
	}
	/// <summary>
	/// Initializes the data for the binary file
	/// </summary>
	/// <param name="fileName">The file path</param>
	void initialDatFile(const char* fileName = "listFile.dat") {
		ofstream outFile(fileName, ios::out | ios::binary);
		outFile.close();
	}
	/// <summary>
	/// Export TXT file from datFile
	/// This method has not been implemented yet
	/// </summary>
	/// <param name="datFileName">datFileName</param>
	/// <param name="txtFileName">txtFileName</param>
	void exportTxtFile(const char* datFileName = "listFile.dat", const char* txtFileName = "listFile.txt") {
		T tempContent;
		ifstream inFile(datFileName, ios::in | ios::binary);
		if (!inFile) {
			cout << "打开文件失败" << endl;
		}
		while (inFile.read((char*)&tempContent, sizeof(tempContent))) {
			//未完成
		}
	}
	/// <summary>
	/// Operator[] overloading 
	/// </summary>
	/// <param name="index">index</param>
	/// <returns>content</returns>
	T& operator[](const int index){
		return (find(index)->content);
	}
};
