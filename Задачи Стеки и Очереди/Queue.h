#pragma once
#include <iostream>

template<class TInfo>
struct NODE_Q
{
	TInfo info;
	NODE_Q* next;
	NODE_Q(TInfo elem, NODE_Q* next = nullptr) : info(elem), next(next) {};
	~NODE_Q() { next = nullptr; }
};

template<class TInfo>
using ptrNODE_Q = NODE_Q<TInfo>*;

template<class TInfo>
struct QUEUE
{
private:
	ptrNODE_Q<TInfo> head, tail;
public:
	QUEUE();
	bool empty();
	void push(TInfo elem);
	TInfo pop();
	TInfo first();
	void view();
	void clear()
	{
		while (!empty())
			pop();
	}
	//можно добавить деструктор на случай сбоя в программе
};

template<class TInfo>
QUEUE<TInfo>::QUEUE()
{
	head = nullptr;
	tail = nullptr;
}

template<class TInfo>
bool QUEUE<TInfo>::empty()
{
	return head == nullptr;
}

template<class TInfo>
void QUEUE<TInfo>::push(TInfo elem)
{
	ptrNODE_Q<TInfo> ptr = new NODE_Q<TInfo>(elem);
	if (empty())
		head = ptr;
	else
		tail->next = ptr;
	tail = ptr;
}

template<class TInfo>
TInfo QUEUE<TInfo>::pop()
{
	ptrNODE_Q<TInfo> ptr = head;
	head = head->next;
	TInfo result = ptr->info;
	delete ptr;
	return result;
}

template<class TInfo>
TInfo QUEUE<TInfo>::first()
{
	return head->info;
}

template<class TInfo>
void QUEUE<TInfo>::view()
{
	ptrNODE_Q<TInfo> ptr = head;
	while (ptr)
	{
		std::cout << ptr->info << ' ';
		ptr = ptr->next;
	}
	std::cout << '\n';
}