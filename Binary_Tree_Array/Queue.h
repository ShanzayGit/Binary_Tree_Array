#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
using namespace std;
template<typename T>
class Queue
{
	int rear;
	int front;
	int capacity;
	int noOfElements;
	T* data;
	void reSize(int c);
public:
	Queue();
	~Queue();
	Queue(const Queue<T>&);
	Queue<T>& operator=(const Queue<T>&);
	void enQueue(T a);
	T deQueue();
	T getElementAtFront();
	bool isEmpty()const;
	bool isFull()const;
	int getNoOfElements()const;
	int getCapacity()const;
	void print();
};
template<typename T>
void Queue<T>::print()
{
	for (int i = 0; i < getNoOfElements(); i++)
	{
		cout << "   i==" << i << " ";
		cout << data[i];
	}
	cout << "\nfront = " << front << '\n';
	cout << "rear = " << rear << '\n';
	cout << "capacity = " << capacity << '\n';
	cout << "no of elements = " << noOfElements << '\n';
}
template<typename T>
Queue<T>::Queue()
{
	rear = front = capacity = noOfElements = 0;
	data = nullptr;
}
template<typename T>
Queue<T>::~Queue()
{
	if (!data)
		return;
	delete[]data;
	capacity = 0;
	rear = 0;
	front = 0;
	noOfElements = 0;
	data = nullptr;
}
template<typename T>
void Queue<T>::reSize(int c)
{
	T* temp = new T[c];
	int f = front;
	int j, i, k = 0;
	if (capacity != 0)
	{
		temp[0] = data[front];
		k = (f + 1) % capacity;

	}
	for (i = 1, j = 1; i < noOfElements; i++, j++)
	{
		temp[j] = data[k];
		f++;
		k = (f + 1) % capacity;
	}
	int ele = noOfElements;
	this->~Queue();
	data = temp;
	noOfElements = ele;
	capacity = c;
	rear = ele;
	front = 0;
}
template<typename T>
bool Queue<T>::isEmpty()const
{
	if ((rear == front) && (noOfElements == 0))
		return true;
	else if (!data)
		return true;
	return false;
}
template<typename T>
bool Queue<T>::isFull()const
{
	if ((rear == front) && (noOfElements == capacity))
		return true;
	return false;
}
template<typename T>
int Queue<T>::getNoOfElements()const
{
	return noOfElements;
}
template<typename T>
int Queue<T>::getCapacity()const
{
	return capacity;
}
template<typename T>
void Queue<T>::enQueue(T a)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	if (rear + 1 == capacity)
	{
		data[rear] = a;
		noOfElements++;
		rear = 0;
	}
	else
	{
		data[rear] = a;
		rear++;
		noOfElements++;

	}
}
template<typename T>
T Queue<T>::deQueue()
{
	if (isEmpty())
		exit(0);
	T val = data[front];
	if (front + 1 == capacity)
		front = 0;
	else
		front++;
	noOfElements--;
	if (noOfElements > 0 && noOfElements == (capacity / 4))
	{
		reSize(capacity / 2);
	}
	return val;
}

template<typename T>
T Queue<T>::getElementAtFront()
{
	return data[front];
}
template<typename T>
Queue<T>::Queue(const Queue<T>& ref)
{
	if (ref.isEmpty())
	{
		return;
	}
	data = new T[ref.getCapacity()];
	int ele = ref.getNoOfElements();
	for (int i = 0; i < ele; i++)
	{
		data[i] = ref.data[i];
	}
	capacity = ref.getCapacity();
	front = ref.front;
	rear = ref.rear;
	noOfElements = ele;
}
template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& ref)
{
	if ((&ref == this))
	{
		return *this;
	}
	this->~Queue();
	capacity = ref.getCapacity();
	data = new T[capacity];
	int ele = ref.getNoOfElements();
	for (int i = 0; i < ele; i++)
	{
		data[i] = ref.data[i];
	}
	front = ref.front;
	rear = ref.rear;
	noOfElements = ele;
	return *this;

}

#endif