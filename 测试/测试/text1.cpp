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

int main()
{
	int left = 1;
	double right = 1;
	cout << Add(left, right) << endl;
	cout << Add(right, left) << endl;
	return 0;
}