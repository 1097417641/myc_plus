#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;


//�Է�������ģ��

//template <typename T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
////����һ�����͵Ķ���
////template <class T>
////void swap(T& a, T& b)
////{
////	T tmp = a;
////	a = b;
////	b = tmp;
////}
//
//template <typename T>
//T add(const T& a, const T& b)
//{
//	return a + b;
//}
//
//int add(int a, int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	float c = 3.1, d = 4.1;
//	//��ʽʵ����
//	Swap(c, d);
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//	//��ʾʵ����
//	//Swap(a, (int)d);	//��ǿת  ����Ϊ��ʱ��������ʱ�������г��� �� &�����г�ͻ
//	add(a, (int)d);		//��Ϊconst & ���;Ϳ�����
//
//	//��ģ�庯����ģ�庯�����棬����ʹ�÷�ģ�庯��
//	//���������ȫƥ�䣬ʵ�����������ɸ���ƥ��ĺ���������ʵ����
//	add(a, b);
//	add(a, c);
//	//���������ʾʵ������һ�������ʵ����
//	add<int>(a, c);
//	system("pause");
//	return 0;
//}


//�������ģ��

template<class DateType>
class SeqList
{
public:
	SeqList(int num = 10)
	{
		:_date(new DateType[num])
			, _size(num)
			, _capacity(num)
		{
		}
	}

	SeqList<DateType>& operator=(const SeqList<DateType>& sq)
	{
		//������ǳ����  ��ͬһƬ�ڴ�
		if (this != &sq)
		{
			_date = sq._date;
			_size = sq._size;
			_capacity = sq._capacity;
		}
	}

	int Size()
	{
		return _size;
	}

	DateType& operator[] (size_t pos)
	{
		return _date[pos];
	}

	~SeqList()
	{
		if (_date)
		{
			delete[] _date;
			_date = nullptr;
			_size = _capacity = 0;
		}
	}
private:
	DateType* _date;
	size_t _size;
	size_t _capacity;
};

int main()
{
	// ��ֻ����ʾʵ����
	//��ģ����  SeqList<int> Ϊ����  SeqListΪ����
  	SeqList<int> s1;
	for (int i = 0; i < s1.Size(); ++i)
	{
		s1[i] = i;
		cout << s1[i] << endl;
	}
	system("pause");
	return 0;
}