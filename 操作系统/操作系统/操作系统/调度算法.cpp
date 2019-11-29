#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Node
{
	string name = "1111111111";	//���̱�ʶ��
	int Tarrive = 0;	//����ʱ��
	float Tservice = 0;	//����ʱ��
	int Tsurplus = 0;	//ʣ��ʱ��
	int Tstart = 0;		//��ʼʱ��
	int Taccomplish = 0;//���ʱ��
	float TZz = 0;		//��תʱ��
	float TDqZz = 0;		//��Ȩ��תʱ��
	int prio = 0;		//���ȼ�-->����Խ�����ȼ�Խ��
	int if_finish = 0;	//�����Ƿ����
	//int num;		//���̸���
};

//������ʱ������
void Arrive_sort(int num, vector<Node*>& job)
{
	for (int i = job.size() - num; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i]->Tarrive > job[j]->Tarrive)
			{
				swap(job[i], job[j]);
			}
		}
	}
}

//������ʱ������
void Service_sort(int num, vector<Node*>& job)
{
	for (int i = job.size() - num; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i]->Tservice > job[j]->Tservice)
			{
				swap(job[i], job[j]);
			}
		}
	}
}

//�����ȼ�����
void Priority_sort(int num, vector<Node*>& job)//�����ȼ���С����
{
	for (int i = 1; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i]->prio < job[j]->prio)
			{
				swap(job[i], job[j]);
			}
		}
	}
}

//�������ʱ����ȣ�����ʱ�䰴��С��������
void Arrive_Short_sort(int num, vector<Node*>& job)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (job[i]->Tarrive >= job[j]->Tarrive)
			{
				if (job[i]->Tarrive > job[j]->Tarrive)
				{
					swap(job[i], job[j]);
				}
				else
				{
					if (job[i]->Tservice > job[j]->Tservice)
					{
						swap(job[i], job[j]);
					}
				}
			}
		}
	}
}

//FCFS�㷨
void fcfs(int num, vector<Node*>& job)//�����ȷ���
{
	//��һ����ʼʱ�� �����ĵ���ʱ��
	job[0]->Tstart = job[0]->Tarrive;
	//��һ�����ʱ�� �����Ŀ�ʼ+����ʱ��
	job[0]->Taccomplish = job[0]->Tstart + job[0]->Tservice;
	//��һ����תʱ�� == ���ķ���ʱ��
	job[0]->TZz = job[0]->Tservice;
	//��һ����Ȩ��תʱ�� == ��תʱ��/����ʱ��
	job[0]->TDqZz = job[0]->TZz / job[0]->Tservice;
	for (int i = 1; i < num; i++)
	{
		job[i]->Tstart = job[i - 1]->Taccomplish;//��һ����ҵ����ʱ��
		//�ж���һ�����̽���֮���Ƿ���һ�������Ѿ�����
		if (job[i]->Tstart < job[i]->Tarrive)
		{
			job[i]->Tstart = job[i]->Tarrive;
		}
		else
		{
			job[i]->Tstart = job[i - 1]->Taccomplish;
		}
		//���ʱ�� = ��ʼ + ����ʱ��
		job[i]->Taccomplish = job[i]->Tstart + job[i]->Tservice;
		//��תʱ�� == ���ʱ��-����ʱ��
		job[i]->TZz = job[i]->Taccomplish - job[i]->Tarrive;
		//��Ȩ��תʱ�� == ��תʱ��/����ʱ��
		job[i]->TDqZz = job[i]->TZz / job[i]->Tservice;
	}
}

//����ҵ����
void sjf(int num, vector<Node*> job)
{
	//��ǰ�Ľ���ʱ��
	float tmpnum = num;
	//������ʱ������
	Arrive_sort(tmpnum, job);
	//��һ��Ҫ���е�����
	for (int i = 1; i < num; ++i)
	{
		//����ҵ�ʱ�����һ����ͬ��ʱ�䵫����ʱ�����С ����
		if (job[0]->Tarrive == job[i]->Tarrive && job[0]->Tservice > job[i]->Tservice)
		{
			swap(job[0], job[1]);
		}
	}
	--tmpnum;
	//���ʱ�� = ��ʼ + ����ʱ��
	job[0]->Taccomplish = job[0]->Tstart + job[0]->Tservice;
	//��תʱ�� == ���ʱ��-����ʱ��
	job[0]->TZz = job[0]->Taccomplish - job[0]->Tarrive;
	//��Ȩ��תʱ�� == ��תʱ��/����ʱ��
	job[0]->TDqZz = job[0]->TZz / job[0]->Tservice;

	for (int i = 1; i < num; i++)
	{
		//��ʣ�µĽ��з�������
		Service_sort(tmpnum, job);
		//��¼��ǰ���е�λ��
		int tmp = i;
		//�жϵ�ǰ����С����ʱ���Ƿ����Ѿ�����
		for (int j = i; j < num; ++j)
		{
			//������Ѿ�����
			if (job[j]->Tstart < job[i - 1]->Taccomplish)
			{
				break;
			}
			//��û�н���
			else
			{

			}
		}
		job[i]->Tstart = job[i - 1]->Taccomplish;//��һ����ҵ����ʱ��
		if (job[i]->Tstart < job[i]->Tarrive)//����ҵ�Ŀ�ʼʱ��С�ڵ���ʱ��
		{
			job[i]->Tstart = job[i]->Tarrive;
		}
		else
		{
			job[i]->Tstart = job[i - 1]->Taccomplish;
		}
		job[i]->Taccomplish = job[i]->Tstart + job[i]->Tservice;
		job[i]->TZz = job[i]->Taccomplish - job[i]->Tarrive;
		job[i]->TDqZz = job[i]->TZz / job[i]->Tservice;
	}
}

//ʱ��Ƭ��ת�㷨
void RR(int num, vector<Node*> job)//RR�㷨
{
	int q;
	cout << "������ʱ��Ƭ���ȣ�" << endl;
	cin >> q;
	int flag = 1;//��־�������Ƿ��н���
	int finish_pro = 0;//��ɵĽ�����
	cout << "��������\t" << "��ʼʱ��\t" << "����ʱ��\t" << "ʣ�����ʱ��\t" << "����ʱ��\t" << endl;
	int time;//��¼��ǰʱ��ʱ��
	int c = 0;
	while (finish_pro < num)
	{
		flag = 0;//����������û����
		for (int i = c; i < num; i++)
		{
			//��������
			Arrive_sort(num, job);
			//�ѷ���ʱ���ʣ��ʱ��
			job[i]->Tsurplus = job[i]->Tservice;
			//��ǰ�Ŀ�ʼʱ�� = ��һ����ҵ����ʱ��
			job[i]->Tstart = job[i - 1]->Taccomplish;
			//����ҵ�Ŀ�ʼʱ��С�ڵ���ʱ��
			if (job[i]->Tstart < job[i]->Tarrive)
			{
				job[i]->Tstart = job[i]->Tarrive;
			}
			else
			{
				job[i]->Tstart = job[i - 1]->Taccomplish;
			}
			time = job[i]->Tstart;
			if (job[i]->if_finish == 1) 
				continue;//�ý��������
			else
			{
				if (job[i]->Tsurplus <= q && time >= job[i]->Tarrive)//δ���������һ��ʱ��Ƭ
				{
					flag = 1;
					time = time + job[i]->Tsurplus;
					job[i]->if_finish = 1;//�ý������
					job[i]->Taccomplish = time;
					cout << job[i]->name << "\t\t" << job[i]->Taccomplish - job[i]->Tsurplus << "\t\t" << job[i]->Tsurplus << "\t\t" << 0 << "\t\t" << job[i]->Taccomplish << endl;
					job[i]->Tsurplus = 0;
				}
				else if (job[i]->Tsurplus > q && time >= job[i]->Tarrive)
				{
					flag = 1;
					time = time + q;
					job[i]->Tsurplus -= q;
					job[i]->Taccomplish = time;
					cout << job[i]->name << "\t\t" << time - q << "\t\t" << q << "\t\t" << job[i]->Tsurplus << "\t\t" << job[i]->Taccomplish << endl;
					job[num]->name = job[i]->name;
					job[num]->Tarrive = time;
					job[num]->Tservice = job[i]->Tsurplus;
					num++;
				}
				if (job[i]->if_finish == 1) finish_pro++;//һ��������ɼ�һ
			}
			c++;
		}break;
		if (flag == 0 && finish_pro < num)//ûִ������û�����������
		{
			for (int i = 0; i < num; i++)
			{
				if (job[i]->if_finish == 0)
				{
					time = job[i]->Tarrive;
					break;
				}
			}
		}
	}
}

//�������
void print(int num, vector<Node*>& job)
{
	cout << "������" << "\t" << "����ʱ��" << "\t" << "����ʱ��" << "\t" << "���ʱ��" 
		<< "\t" << "��תʱ��" << "\t" << "��Ȩ��ת" << endl;

	for (int i = 0; i < num; i++)
	{
		cout << job[i]->name << "\t" << job[i]->Tarrive << "\t\t" << job[i]->Tservice << "\t\t" << job[i]->Taccomplish 
			<< "\t\t" << job[i]->TZz << "\t\t"  << job[i]->TDqZz << endl;
	}
}



void display(int num,vector<Node*> job)
{
	int ch = 0;
	cout << "��������������������������������������������������" << endl;
	cout << "��������������������1��FCFS�㷨 ������������������" << endl;
	cout << "��������������������2��SJF�㷨��������������������" << endl;
	cout << "��������������������3��ʱ��Ƭ��ת�㷨 ������������" << endl;
	cout << "��������������������4�����ȼ��㷨 ����������������" << endl;
	cout << "��������������������5���˳� ����������������������" << endl;
	cout << "��������������������������������������������������" << endl;
	do {
		cout << "��ѡ������Ҫ���㷨��" << endl;
		cin >> ch;
		switch (ch) {
		case 1:
			Arrive_sort(num, job);
			fcfs(num, job);
			print(num, job);
			break;
		case 2:
			sjf(num, job);
			print(num, job);
			break;
		case 3:
			RR(num, job);
			break;
		case 4:
			/*Priority_sort(num);*/
			break;
		case 5:
			exit;
		default:
			cout << "����������������룡" << endl;
			break;
		}
	} while (ch != 5);
}

int main()
{
	int num;
	cout << "��������̸�����" << endl;
	cin >> num;
	//��num�����Nodeָ�������
	vector<Node*> job;
	job.resize(num);
	for (int i = 0; i < num; i++)
	{
		job[i] = new Node;
		cout << "�����������������ʱ�䡢����ʱ�䡢���ȼ�" << endl;
		//��ȡ������
		cin >> job[i]->name;
		//��ȡ����ʱ��
		cin >> job[i]->Tarrive;
		//��ȡ����ʱ��
		cin >> job[i]->Tservice;
		//��ȡ���ȼ�
		cin >> job[i]->prio;
	}
	display(num, job);
	system("pasue");
	return 0;
}