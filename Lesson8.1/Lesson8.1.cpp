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
template<typename T>
void printReverse(Element<T>* element)
{
	if (element == nullptr)
		return;
	printReverse(element->next);
	cout << element->data << endl;
}
template<typename T>
void  printQueueReverse(const Queue<T>& q)
{
	Element<T>* head = q.getHead();
	printReverse(head);
}
int main()
{
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	printQueueReverse(q);
}