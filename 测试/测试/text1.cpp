#include<iostream>
using namespace std;

//���Ժ������� (���� ���� ˳��)
int Add(int left, double right)
{
	return left + right;
}

int Add(double right, int left)
{
	return left + right;
}


//����ģ��
template<class T>
T Add(const T& A, const T& B)
{
	return A + B;
}

int main()
{
	int a = 10, b = 20;
	double a1 = 10, b1 = 1;
	cout << Add(a, b) << endl;
	cout << Add(a1, b1) << endl;
	return 0;
}