#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
using namespace std;

void reserveString(string& s1)
{
	//�������ַ�����ת
	string::iterator s1itstr = s1.begin();
	string::iterator s1itend = s1.end() - 1;
	while (s1itstr < s1itend)
	{
		char tmp = *s1itstr;
		*s1itstr = *s1itend;
		*s1itend = tmp;
		s1itstr++;
		s1itend--;
	}
	//��ÿ�����ʽ��з�ת
	int i = 0;
	//��¼����ͷ
	int begin = 0;
	//��¼����β
	int end = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != ' ')
		{
			begin = i;
			while (s1[i] != ' ' && s1[i] != '\0')
				i++;
			i = i - 1;
			end = i;
		}
		while (begin < end)
		{
			char tmp = s1[begin];
			s1[begin] = s1[end];
			s1[end] = tmp;
			begin++;
			end--;
		}
		i++;
	}
}

int main()
{
	string s1;
	getline(cin, s1);
	reserveString(s1);
	cout << s1;
	system("pause");
	return 0;
}