#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class Date
{
public:

	//���캯��
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
	}
	
	//�������캯��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//��ֵ���������
	Date& operator=(const Date& d)
	{
		if (&d != this)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	//�ӷ����������
	Date operator+(int days)
	{
		//1 3 5 7 8 10 12  31��λ
		//4 6 9 11  30��λ
		//2  ƽ��28  ����29
		Date tmp = *this;
		tmp._day = days + _day;
		while ((tmp._month == 2 && tmp._day >= 29) || (tmp._month != 2 && tmp._day >= 31))
		{
			if (tmp._month == 2)
			{
				if ((tmp._year % 4 == 0 && tmp._year % 100 != 0) || (tmp._year % 400 == 0))
				{
					if (tmp._day == 29)
						break;
					tmp._day -= 29;
					++tmp._month;
				}
				else
				{
					tmp._day -= 28;
					++tmp._month;
				}
			}
			else if (tmp._month == 4 || tmp._month == 6 || tmp._month == 9 || tmp._month == 11)
			{
				tmp._day = tmp._day - 30;
				++tmp._month;
			}
			else
			{
				if (tmp._day == 31)
					break;
				tmp._day = tmp._day - 31;
				++tmp._month;
			}
		}
		tmp._year += (tmp._month % 12);
		tmp._month = tmp._month % 13 + tmp._month / 12;
		return tmp;
	}

	//�������������
	Date operator-(int days)
	{
		//1 3 5 7 8 10 12  31��ȥ
		//4 6 9 11  30��ȥ
		//2  ƽ��28  ����29
		Date tmp;
		tmp = *this;
		tmp._day = _day - days;
		while (tmp._day < 0)
		{
			--tmp._month;
			if (tmp._month == 2)
			{
				//������
				if ((tmp._year % 4 == 0 && tmp._year % 100 != 0) || (tmp._year % 400 == 0))
				{
					tmp._day += 29;
				}
				else
				{
					tmp._day += 28;
				}
			}
			else if (tmp._month == 4 || tmp._month == 6 || tmp._month == 9 || tmp._month == 11)
			{
				tmp._day += 30;
			}
			else
			{
				tmp._day += 31;
			}
		}
		while (tmp._month < 0)
		{
			--tmp._year;
			tmp._month += 12;
		}
		return tmp;
	}

	//����ǰ
	int operator-(const Date& d)
	{
		if (*this == d)
			return 0;
		int count = 0;
		Date max = *this;
		Date min = d;
		if (max < d)
		{
			max = d;
			min = *this;
		}
		while (min < max)
		{
			--max;
			count++;
		}
		return count;
	}

	//ǰ��++
	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}

	//����++
	Date operator++(int)
	{
		Date tmp = *this;
		*this = *this + 1;
		return tmp;
	}
	
	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}
	
	Date operator--(int)
	{
		Date tmp = *this;
		*this = *this - 1;
		return tmp;
	}

	bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return true;
			}
		}
		return false;
	}

	bool operator>=(const Date& d)const
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day >= d._day)
					return true;
			}
		}
		return false;
	}

	bool operator<(const Date& d)const
	{
		return !(*this >= d);
	}

	bool operator<=(const Date& d)const
	{
		return !(*this > d);
	}

	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	Date& operator+=(int days)
	{
		*this = *this + days;
		return *this;
	}
	
	Date& operator-=(int days)
	{
		*this = *this - days;
		return *this;
	}

	void show()
	{
		cout << _year << " " << _month << " " << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void text()
{
	Date my = Date(2019,12,23);
	Date my1 = Date(2019,12,24);
	int num = my1 - my;
	my--;
	--my1;
	my.show();
	my1.show();
	my = my1;
	my += 30;
	my.show();
}

int main()
{
	text();
	system("pause");
	return 0;
}
