#define _CRT_SECURE_NO_WARNINGS 1

//ɾ�������ַ�

//���ڶ����ַ������ַ���ӳ�䵽һ��������
//�ж�һ���ַ��ڵڶ����ַ����У���ӵ�һ���µ��ַ���
//��󷵻��µ��ַ���

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2;
	//���ﲻ��ʹ��cin ��Ϊcin�����ո�ͽ�����
	getline(cin, str1);
	getline(cin, str2);

	//���ڶ����ַ������ֵ��ַ�ͳ�Ƶ�hashtable��
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}

	//����str1,��hashtable��Ϊ0��д���µı���
	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret << endl;
	return 0;
}