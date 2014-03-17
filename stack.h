#ifndef STACK_H
#define STACK_H


#include<iostream>

using  std::cout;
using  std::endl;

template <class T> class Stack
{
	struct Node
	{
		T data;
		Node *prev;
	};
	Node *top;

public:

	Stack();
	void push(T val);
	T pop();
	void display();
	bool isEmpty();
	T peek();
	~Stack();
};


//--------------------------Implementation--------------------------------

template <class T>
Stack<T>::Stack()
{
	top = NULL;
};

template <class T>
void Stack<T>::push(T val)
{
	Node *temp;
	temp = new Node;
	temp->data = val;
	temp->prev = top;
	top = temp;
};

template <class T>
T Stack<T>::pop()
{
	if (top == NULL) 
	{ 
		return NULL; 
	}

	T ret = top->data;
	Node *temp = top;
	top = top->prev;
	delete temp;
	return ret;

};

template <class T>
void Stack<T>::display()
{
	if (top == NULL) 
	{ 
		return; 
	}
	Node *temp = top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
};

template <class T>
Stack<T>::~Stack()
{
	while (top != NULL)
	{
		Node *temp = top;
		top = top->prev;
		delete temp;
	}
};

template <class T>
bool Stack<T>::isEmpty()
{
	return (top == NULL);
};


template <class T>
T Stack<T>::peek()
{
	if (top == NULL)
	{
		return NULL;
	}
	return top->data;
};



#endif // STACK_H