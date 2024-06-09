#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<iostream>

using namespace std;

class Date
{
public:
	Date(Date& d)//�����ñ����� �ſ��Կ�������
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	/*Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	int GetMonthDay(int year, int month)
	{
		int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && ((year % 4 == 0 || year % 100 != 0)) || (year % 400 == 0))
		{
			return 29;
		}
		return monthDays[month];
	}

	Date(int year = 1, int month = 1, int day = 1)//�Ż�һ��
	{
		if (year >= 0
			&& month >= 1 && month <= 12
			&& day >= 1 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "�Ƿ�����" << endl;
		}

	}

	void Print()
	{
		cout << _year << " " <<_month  << " "  <<_day << endl;
	}
	bool  operator==(const Date& d)
	{
		if (_year == d._year
			&& _month == d._month
			&& _day == d._day)
		{
			return true;
		}
		else
		{
			return false;
		}
		
		
	}
	bool operator>(const Date& d)//�ȱȽ����ٱȽ����ٱȽ��� ����һ��һ���ı���ȥ
	{
		if (_year > d._year)
		{
			return true;
		}
		else if (_year == d._year && _month > d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}

	bool operator<(const Date& d)//�ȱȽ����ٱȽ����ٱȽ��� ����һ��һ���ı���ȥ
	{
		if (_year < d._year)
		{
			return true;
		}
		else if (_year == d._year && _month < d._month)
		{
			return true;
		}
		else if (_year == d._year && _month == d._month && _day < d._day)
		{
			return true;
		}

		return false;
	}
	bool operator>=(const Date& d)
	{
		return *this > d || *this == d;
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);//�߼�ȡ��ȥ����֮ǰд�õĺ�����ʵ��
	}


	//Date  operator+(int day)
	//{
	//	Date ret = (*this);
	//	ret._day += day;
	//	//������Ϸ��ͽ�λ
	//	while (ret._day > GetMonthDay(ret._year, ret._month))
	//	{
	//		ret._day -= GetMonthDay(ret._year, ret._month);
	//		ret._month++;
	//		if (ret._month == 13)
	//		{
	//			ret._month = 1;
	//			ret._year++;
	//		}
	//	}
	//	return ret;
	//}


	//

	//Date operator+=(int day)
	//{
	//	
	//	(*this)._day += day;
	//	//������Ϸ��ͽ�λ
	//	while ((*this)._day > GetMonthDay((*this)._year, (*this)._month))
	//	{
	//		(*this)._day -= GetMonthDay((*this)._year, (*this)._month);
	//		(*this)._month++;
	//		if ((*this)._month == 13)
	//		{
	//			(*this)._month = 1;
	//			(*this)._year++;
	//		}
	//	}
	//	return (*this);
	//}


	Date& operator +=(int day)
	{
		_day += day;
		// ������Ϸ��ͽ�λ
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	Date& operator+(int day)
	{
		Date ret(*this); // ʹ�ø��ƹ��캯������һ���µĶ���
		ret += day; // ʹ�� += ����������������
		return ret; // �����µĶ���
	}

private:
	int _year;
	int _month;
	int _day;
};

class Stack
{
public:
	Stack(int capacity = 4)
	{
		cout << "Stack(int capacity = 4)" << endl;

		_a = (int*)malloc(sizeof(int)*capacity);
		if (_a == nullptr)
		{
			perror("malloc fail");
			exit(-1);
		}

		_top = 0;
		_capacity = capacity;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;

		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}


private:
	int* _a;
	int _top;
	int _capacity;
};

class MyQueue {
public:
	void push(int x)
	{
		//_pushST.Push(x);
	}

private:
	Stack _pushST;
	Stack _popST;
};
int main()
{
	Date d1(2024, 6, 8);
	
	Date d2 = d1 +=10000;
	
	d1.Print();
	
	d2.Print();
	
	/*bool ret=(d1 == d2);
	cout << ret << endl;
	bool ret2 = (d1 > d2);
	cout << ret2 << endl;*/
	//Date d2 = d1;
	//Date d3(d1);
	//d2.Print();
	//d3.Print();//thisָ��˵ʵ����������׵�ַ��ָ��������� ������˭����thisָ�� thisָ��ָ��˭
	//Stack s1;
	//s1.~Stack();
	//MyQueue q1;
	//q1.push(5);
	// �������󣺱�����Ĭ�����ɾͿ������㣬�Ͳ����Լ�д�����������Ҫ�Լ�д
// Date Stack�Ĺ��캯����Ҫ�Լ�д
// MyQueue���캯���Ͳ���Ҫ�Լ�д��Ĭ�����ɾͿ�����

// Stack��������������Ҫ�����Լ�д
// MyQueue Date�Ͳ���Ҫ�Լ�д����������Ĭ�����ɾͿ�����
}