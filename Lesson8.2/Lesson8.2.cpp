#include <iostream>
using namespace std;
template<typename T>
struct Element
{
	T data;
	Element<T>* next;
	Element(T value)
	{
		data = value;
		next = nullptr;
	}
};
template<typename T>
class Queue
{
private:
	Element<T>* head;
	Element<T>* tail;
public:
	Queue() {
		head = tail = nullptr;
	}
	void enqueue(T value)
	{
		Element<T>* newElement = new Element<T>(value);
		if (tail == nullptr)
		{
			head = tail = newElement;
			return;
		}
		tail->next = newElement;
		tail = newElement;

	}
	T dequeue()
	{
		Element<T>* tmp = head;
		head = head->next;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		T val = tmp->data;
		delete tmp;
		tmp = nullptr;
		return val;
	}
	bool isEmpty() const
	{
		return head == nullptr;
	}
	Element<T>* getHead() const
	{
		return head;
	}
	T peek()
	{
		return head->data;
	}
	~Queue()
	{
		while (this->isEmpty() == false)
		{
			this->dequeue();
		}
		head = tail = nullptr;
	}
};
class Document
{
private:
	char* text;
	char* author;
public:
	Document() :text(nullptr), author(nullptr)
	{

	}
	Document(const char* text, const char* author)
	{
		this->text = new char[strlen(text) + 1];
		strcpy_s(this->text, strlen(text) + 1, text);

		this->author = new char[strlen(author) + 1];
		strcpy_s(this->author, strlen(author) + 1, author);
	}
	Document(const Document& other)
	{
		this->text = new char[strlen(other.text) + 1];
		strcpy_s(this->text, strlen(other.text) + 1, other.text);

		this->author = new char[strlen(other.author) + 1];
		strcpy_s(this->author, strlen(other.author) + 1, other.author);
	}
	Document& operator=(const Document& other)
	{
		if (this == &other)return *this;
		delete[]text;
		delete[]author;

		this->text = new char[strlen(other.text) + 1];
		strcpy_s(this->text, strlen(other.text) + 1, other.text);

		this->author = new char[strlen(other.author) + 1];
		strcpy_s(this->author, strlen(other.author) + 1, other.author);
		return *this;

	}
	char* getText() { return this->text; }
	char* getAuthor() { return this->author; }
	~Document()
	{
		if (text != nullptr)
		{
			delete[]text;
			text = nullptr;
		}
		if (author != nullptr)
		{
			delete[]author;
			author = nullptr;
		}
	}
};
class Printer
{
private:
	Queue<Document> documents;
public:
	void addDocument(const Document& doc)
	{
		documents.enqueue(doc);
	}
	bool isEmpty()const
	{
		return documents.isEmpty();
	}
	void printDocument()
	{
		if (isEmpty())
		{
			return;
		}
		Document doc = documents.dequeue();
		cout << "Printing..." << doc.getText() << " " << doc.getAuthor() << endl;
	}
};
int main()
{
	Document doc1("text1", "author1");
	Document doc2("text2", "author2");
	Document doc3("text3", "author3");

	Printer printer;
	printer.addDocument(doc1);
	printer.addDocument(doc2);
	printer.addDocument(doc3);

	while (!printer.isEmpty())
		printer.printDocument();
}
