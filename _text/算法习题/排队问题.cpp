#define _CRT_SECURE_NO_WARNINGS 1
/*�����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
Ϊ�����ж����ˮƽֵ�ܺ����Ľⷨ��
Ҳ����˵ÿ������ĵڶ���ֵ�Ǿ����ܴ��ֵ��
����ʵ��ֵ�����ֵ�ŵ����ұߣ���С�Ƿŵ������*/

//��Ҫ˼·	̰���㷨
//����---->  һ�� 3n������ ��[0, n-1]��������ÿ������ߵ���
//�ұ�һ��ȡ������������

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	//���ܻ���ֶ����������
	while (cin >> n)
	{
		long sum = 0;
		vector<int> a;

		//��֤vector�Ĵ�С���Դ���
		a.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> a[i];
		}
		//����  ȡ�±�Ϊ3n-2 -4  ...

		std::sort(a.begin(), a.end());
		for (int i = n; i <= 3 * n - 2; i += 2)
		{
			sum += a[i];
		}
		cout << sum << endl;
	}
}

