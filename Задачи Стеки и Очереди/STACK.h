#pragma once
#include <iostream>

using std::cout;

template<class TInfo>
struct NODE_S
{
	TInfo info;
	NODE_S* next;
	NODE_S(TInfo elem, NODE_S* next = nullptr) : info(elem)
	{
		this->next = next;
	}
	~NODE_S() { next = nullptr; }
};

template<class TInfo>
using ptrNODE_S = NODE_S<TInfo>*;

template<class TInfo>
struct STACK
{
private:
	ptrNODE_S<TInfo> head;
public:
	STACK();
	bool empty();
	void push(TInfo elem);
	TInfo pop();//библиотечный pop не возвращает значение
	TInfo top();
	void view();
	~STACK()
	{
		while (!empty())
			pop();
	}
};

template<class TInfo>
STACK<TInfo>::STACK()
{
	head = nullptr;
}

template<class TInfo>
bool STACK<TInfo>::empty()
{
	return head == nullptr;
}

template<class TInfo>
void STACK<TInfo>::push(TInfo elem) // 3(h)->4  5(h)->3->4
{
	ptrNODE_S<TInfo> ptr = new NODE_S<TInfo>(elem, head);
	head = ptr;
}

template<class TInfo>
TInfo STACK<TInfo>::pop()
{
	ptrNODE_S<TInfo> ptr = head;
	head = head->next;
	TInfo result = ptr->info;
	delete ptr;
	return result;
}

template<class TInfo>
TInfo STACK<TInfo>::top()
{
	return head->info;
}

template<class TInfo>
void STACK<TInfo>::view()
{
	ptrNODE_S<TInfo> ptr = head;
	while (ptr)
	{
		cout << ptr->info << ' ';
		ptr = ptr->next;
	}
}