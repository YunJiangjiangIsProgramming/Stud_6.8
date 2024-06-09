#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

//using namespace std;
//
//class Date
//{
//public:
//	Date(Date& d)//用引用别名搞 才可以拷贝调用
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	/*Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	int GetMonthDay(int year, int month)
//	{
//		int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		if (month == 2 && ((year % 4 == 0 || year % 100 != 0)) || (year % 400 == 0))
//		{
//			return 29;
//		}
//		return monthDays[month];
//	}
//
//	Date(int year = 1, int month = 1, int day = 1)//优化一下
//	{
//		if (year >= 0
//			&& month >= 1 && month <= 12
//			&& day >= 1 && day <= GetMonthDay(year, month))
//		{
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else
//		{
//			cout << "非法日期" << endl;
//		}
//
//	}
//
//	void Print()
//	{
//		cout << _year << " " << _month << " " << _day << endl;
//	}
//	bool  operator==(const Date& d)
//	{
//		if (_year == d._year
//			&& _month == d._month
//			&& _day == d._day)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//
//
//	}
//	bool operator>(const Date& d)//先比较年再比较月再比较日 这样一级一级的比下去
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month > d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day)
//		{
//			return true;
//		}
//
//		return false;
//	}
//
//	bool operator<(const Date& d)//先比较年再比较月再比较日 这样一级一级的比下去
//	{
//		if (_year < d._year)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month < d._month)
//		{
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day < d._day)
//		{
//			return true;
//		}
//
//		return false;
//	}
//	bool operator>=(const Date& d)
//	{
//		return *this > d || *this == d;
//	}
//	bool operator!=(const Date& d)
//	{
//		return !(*this == d);//逻辑取反去调用之前写好的函数来实现
//	}
//
//
//	Date  operator+(int day)
//	{
//		Date ret = (*this);
//		ret._day += day;
//		//如果不合法就进位
//		while (ret._day > GetMonthDay(ret._year, ret._month))
//		{
//			ret._day -= GetMonthDay(ret._year, ret._month);
//			ret._month++;
//			if (ret._month == 13)
//			{
//				ret._month = 1;
//				ret._year++;
//			}
//		}
//		return ret;
//	}
//
//
//
//
//	Date operator+=(int day)
//	{
//
//		(*this)._day += day;
//		//如果不合法就进位
//		while ((*this)._day > GetMonthDay((*this)._year, (*this)._month))
//		{
//			(*this)._day -= GetMonthDay((*this)._year, (*this)._month);
//			(*this)._month++;
//			if ((*this)._month == 13)
//			{
//				(*this)._month = 1;
//				(*this)._year++;
//			}
//		}
//		return (*this);
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1(2024, 6, 8);
//
//	Date d2 = d1 + 1000;
//
//	d1.Print();
//
//	d2.Print();
//}
//这段代码跑不过去 d2编译有问题