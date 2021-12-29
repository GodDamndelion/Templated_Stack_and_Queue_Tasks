#include "STACK.h";
#include "Queue.h";
#include <fstream>
#include <Windows.h>
#include <string>

using std::cout;
using std::ifstream;
bool brackets_are_correct(ifstream& input);
int sumC(int a);
void all_max_sumC(ifstream& input);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	bool Error = false;
	ifstream input("formula.txt");
	if (!input)
	{
		cout << "���� formula.txt �� ��� ������!\n";
		system("pause");
		Error = true;
	}
	ifstream input2("input.txt");
	if (!input2)
	{
		cout << "���� input.txt �� ��� ������!\n";
		system("pause");
		Error = true;
	}
	if (!Error)
	{
		int choice;
		bool ext = false;
		while (!ext)
		{
			cout << "������� ����� ������������ ������\n";
			cout << "1. ���������� ���������.\n";
			cout << "0. ���������� ���������.\n\n";
			choice = _getwch();
			switch (choice)
			{
			case '1': //
			{
				if (brackets_are_correct(input))
					cout << "������� ���������.\n\n";
				else
					cout << "������� �����������.\n\n";
				all_max_sumC(input2);
			}
			break; //

			case '0': //���������� ���������
				ext = 1;
				break; //���������� ���������

			default:
				cout << "�������� ������ �����, ���������� ��� ���\n\n";
				break;
			}
		}
	}
	return 0;
}
//=================================================================================

bool brackets_are_correct(ifstream& input)
{
	STACK<char> st;
	bool mistake = false;
	char ch;
	while (input.get(ch) && !mistake)
	{
		if (ch == '(' || ch == '{' || ch == '[')
			st.push(ch);
		if (ch == ')')
		{
			if (!st.empty())
				mistake = !(st.pop() == '(');
			else
				if (st.empty()) mistake = true;
		}
		if (ch == '}')
		{
			if (!st.empty())
				mistake = !(st.pop() == '{');
			else
				if (st.empty()) mistake = true;
		}
		if (ch == ']')
		{
			if (!st.empty())
				mistake = !(st.pop() == '[');
			else
				if (st.empty()) mistake = true;
		}
	}
	return !mistake && st.empty();
}

int sumC(int a)
{
	int sum = 0;
	a = abs(a);
	while (a)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

void all_max_sumC(ifstream& input)
{
	QUEUE<int> qu;
	int el;
	int max = 0;
	int Sum;
	while (input >> el)
	{
		Sum = sumC(el);
		if (Sum > max)
		{
			qu.clear();
			qu.push(el);
			max = Sum;
		}
		else
			if (Sum == max)
				qu.push(el);
	}
	qu.view();
}