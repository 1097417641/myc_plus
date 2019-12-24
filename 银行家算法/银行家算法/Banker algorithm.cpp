#include <iostream>
using namespace std;

//ȫ�ֱ�������
#define M 100				//���̵����
#define N 50				//��Դ�����
int Available[M];			//��������Դ����

int Max[N][M];				//����������
int Allocation[N][M];       //�������
int Need[N][M];             //�������

int Request[N][M];			//M�����̻���ҪN����Դ����Դ��
bool Finish[N];				//��ʾ�Ƿ����
int p[50];					//��¼��ɵ�˳��
int m, n;   //M������,N����Դ

//��ȫ���㷨
int Safe()
{
	// l ���ڼ��㵱ǰ��ɵĸ���
	int i, j, l = 0;

	//��������Դ����
	int Work[100]; 

	//��ȡ��ǰ�Ŀ�����Դ����
	for (i = 0; i < n; i++)
		Work[i] = Available[i];

	//��ʼ��Finish
	for (i = 0; i < m; i++)
		Finish[i] = false;

	for (i = 0; i < m; i++)
	{
		if (Finish[i] == 1)
			continue;
		else
		{
			//�����������һ���������
			for (j = 0; j < n; j++)
			{
				if (Need[i][j] > Work[j])
				{
					cout << "��" << i << "������";
					break;
				}
			}

			//�����ϵ����
			if (j == n)
			{
				Finish[i] = true;
				for (int k = 0; k < n; k++)
					Work[k] += Allocation[i][k];
				p[l++] = i;
				i = -1;
			}
			else continue;
		}
		if (l == m)
		{
			cout << "ϵͳ�ǰ�ȫ��" << '\n';
			cout << "ϵͳ��ȫ������:\n";
			for (i = 0; i < l; i++)
			{
				cout << p[i];
				if (i != l - 1)
					cout << "-->";
			}
			cout << endl;

			cout << "������" << "     " << "Max" << "     " <<
				"Allocation" << "     " << "Need" << "     "<< 
				"Finish" << endl;
			for (i = 0; i < m; ++i)
			{
				cout << "  " << "P" << i;
				cout << "       ";
				for (j = 0; j < n; ++j)
				{
					cout << Max[i][j] << ' ';
				}
				cout << "     ";
				for (j = 0; j < n; ++j)
				{
					cout << Allocation[i][j] << ' ';
				}
				cout << "     ";
				for (j = 0; j < n; ++j)
				{
					cout << Need[i][j] << ' ';
				}
				cout << "     ";

				cout << Finish[i] << ' ';
				
				cout << endl;
			}
			cout << endl;
			return 1;
		}
	}
	return 0;
}


bool Init()
{
	int i, j;

	//��ȡ��ǰ����  ��Դ
	cout << "������̵���Ŀ:\n";
	cin >> m;
	cout << "������Դ������:\n";
	cin >> n;

	//��ʼ�� Max   Allocation �����Need �ļ���
	cout << "����ÿ�������������ĸ�����Դ��,����" << m << "x" << n << "��������\n";
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			cin >> Max[i][j];
	cout << "����ÿ�������Ѿ�����ĸ�����Դ��,����" << m << "x" << n << "��������\n";
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> Allocation[i][j];
			Need[i][j] = Max[i][j] - Allocation[i][j];
			if (Need[i][j] < 0)
			{
				cout << "������ĵ�" << i + 1 << "��������ӵ�еĵ�" << j + 1 << "����Դ��������������:\n";
				j--;
				continue;
			}
		}
	}

	//�Ե�ǰ���е���Դ��ȡ
	cout << "�����������Դ�ܹ�����Ŀ:\n";
	for (i = 0; i < n; i++)
		cin >> Available[i];

	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			Available[j] -= Max[i][j];
			if (Available[j] < 0)
			{
				cout << "�����ֵ�����⣬�޷����м���" << endl;
				return false;
			}
		}
	}

	cout << "������Դ���е���Ŀ:" << endl;
	for(i = 0; i < n; ++i)
		cout << Available[i] << ' ';
	cout << endl;
	return true;
}

void need_soursce(char* Flag)
{
	//mi Ϊ���̺�
	int i, mi = 0;
	while (1)
	{
		cout << "����Ҫ�������Դ�Ľ��̺ţ�����һ�����̺�Ϊ0���ڶ������̺�Ϊ1���������ƣ�" << endl;
		cin >> mi;

		cout << "�������������ĸ�����Դ������\n";
		for (i = 0; i < n; i++)
			cin >> Request[mi][i];

		for (i = 0; i < n; i++)
		{
			//Ӧ�����ж��Ƿ񳬹�ӵ�������ж��Ƿ񳬹�������
			if (Request[mi][i] > Available[i])
			{
				cout << "��������Դ������ϵͳ���е���Դ����\n";
				return;
			}
			if (Request[mi][i] > Need[mi][i])
			{
				cout << "��������Դ���������̵���������\n";
				return ;
			}
			
		}

		for (i = 0; i < n; i++)
		{
			Available[i] -= Request[mi][i];
			Allocation[mi][i] += Request[mi][i];
			Need[mi][i] -= Request[mi][i];
		}

		//�ж��Ƿ񻹰�ȫ
		if (Safe())
			cout << "ͬ���������\n";
		else
		{
			cout << "SORRY����������󱻾ܾ���\n";
			for (i = 0; i < n; i++)
			{
				Available[i] += Request[mi][i];
				Allocation[mi][i] -= Request[mi][i];
				Need[mi][i] += Request[mi][i];
			}
		}
		//����״̬
		for (i = 0; i < m; i++)
			Finish[i] = 0;


		cout << "�Ƿ��ٴ�������䣿���밴Y/y�����밴N/n" << endl;
		while (1)
		{
			cin >> *Flag;
			cout << endl;
			if (*Flag == 'Y' || *Flag == 'y' || *Flag == 'N' || *Flag == 'n')
				break;
			else
			{
				cout << "�밴Ҫ����������:\n";
				continue;
			}
		}
		if (*Flag == 'Y' || *Flag == 'y')
			continue;
		else break;
	}
}

//���м��㷨
int main()
{
	bool pa = Init();
	
	//��ʼ��ʧ��
	if (pa == false)
		return 0;
	//��ȫ���ж�
	Safe();
	char Flag = 'Y';       //��־λ
	while(Flag != 'n' && (Flag != 'N'))
		need_soursce(&Flag);
	
	return 0;
}