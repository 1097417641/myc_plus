#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<iomanip>	//����setw,setfill
//setw����  �������ֱ�ʾһ�����ٸ��ַ� �����ÿո���
//setfill(x)����   ǰ����x����
using namespace std;


int main()
{
	//���õ�ǰʱ��
	int hour = 0, min = 0, sec = 0;
	while (1)
	{
		sec++;
		if (sec == 60)
		{
			sec = 0;
			++min;
		}
		if (60 == min)
		{
			min = 0;
			++hour;
		}
		if (60 == hour)
		{
			hour = 0;
		}
		//һ����һ����Ļ
		Sleep(1000);
		system("cls");

		//��ʾ����
		cout << "---------------" << endl;
		cout << "   " << setfill('0') << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << sec << endl;
		cout << "---------------" << endl;
	}
	return 0;
}