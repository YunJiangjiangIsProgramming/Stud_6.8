#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<iostream>

using namespace std;

class Date
{
public:
	Date(Date& d)//用引用别名搞 才可以拷贝调用
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

	Date(int year = 1, int month = 1, int day = 1)//优化一下
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
			cout << "非法日期" << endl;
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
	bool operator>(const Date& d)//先比较年再比较月再比较日 这样一级一级的比下去
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

	bool operator<(const Date& d)//先比较年再比较月再比较日 这样一级一级的比下去
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
		return !(*this == d);//逻辑取反去调用之前写好的函数来实现
	}


	//Date  operator+(int day)
	//{
	//	Date ret = (*this);
	//	ret._day += day;
	//	//如果不合法就进位
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
	//	//如果不合法就进位
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
		// 如果不合法就进位
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
		Date ret(*this); // 使用复制构造函数创建一个新的对象
		ret += day; // 使用 += 操作符来增加日期
		return ret; // 返回新的对象
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
	//d3.Print();//this指针说实例化对象的首地址会指向这个对象 所以是谁调用this指针 this指针指向谁
	//Stack s1;
	//s1.~Stack();
	//MyQueue q1;
	//q1.push(5);
	// 面向需求：编译器默认生成就可以满足，就不用自己写，不满足就需要自己写
// Date Stack的构造函数需要自己写
// MyQueue构造函数就不需要自己写，默认生成就可以用

// Stack的析构函数，需要我们自己写
// MyQueue Date就不需要自己写析构函数，默认生成就可以用
}