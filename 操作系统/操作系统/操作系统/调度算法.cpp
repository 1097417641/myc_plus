#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
	string name = "1111111111";	//���̱�ʶ��
	float Tarrive = 0;	//����ʱ��
	float Tservice = 0;	//����ʱ��
	float Tsurplus = 0;	//ʣ��ʱ��
	float Tstart = 0;		//��ʼʱ��
	float Taccomplish = 0;//���ʱ��
	float TZz = 0;		//��תʱ��
	float TDqZz = 0;		//��Ȩ��תʱ��
	int prio = 0;		//���ȼ�-->����Խ�����ȼ�Խ��
	bool flag = false;	//�Ƿ����ʱ��Ƭ�Ķ���
	//int num;		//���̸���
};
//��ʣ��ʱ�����óɷ���ʱ��
void SetTime(int num, vector<Node*>& job)
{
	for (int i = 0; i < num; ++i)
	{
		job[i]->Tsurplus = job[i]->Tservice;
	}
}

//������ʱ������
void Arrive_sort(int num, vector<Node*>& job)
{
	int tmp = job.size();
	for (int i = tmp - num; i < tmp; i++)
	{
		for (int j = i + 1; j < tmp; j++)
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
	int tmp = job.size();
	for (int i = tmp - num; i < tmp; i++)
	{
		for (int j = i + 1; j < tmp; j++)
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
	int tmp = job.size();
	for (int i = tmp - num; i < tmp; i++)
	{
		for (int j = i + 1; j < tmp; j++)
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
	//������ʱ������
	Arrive_sort(num, job);
	//��һ��Ҫ���е�����
	for (int i = 1; i < num; ++i)
	{
		//����ҵ�ʱ�����һ����ͬ��ʱ�䵫����ʱ�����С ����
		if (job[0]->Tarrive == job[i]->Tarrive && job[0]->Tservice > job[i]->Tservice)
		{
			swap(job[0], job[1]);
		}
	}
	job[0]->Tstart = job[0]->Tarrive;
	//���ʱ�� = ��ʼ + ����ʱ��
	job[0]->Taccomplish = job[0]->Tstart + job[0]->Tservice;
	//��תʱ�� == ���ʱ��-����ʱ��
	job[0]->TZz = job[0]->Taccomplish - job[0]->Tarrive;
	//��Ȩ��תʱ�� == ��תʱ��/����ʱ��
	job[0]->TDqZz = job[0]->TZz / job[0]->Tservice;

	for (int i = 1; i < num; i++)
	{
		//Ѱ�ҵ�i������Ľ���
		//��ʣ�µĽ��з�������
		Service_sort(num - i, job);
		//��¼��ǰ���е�λ��
		int tmp = i;
		//�жϵ�ǰ����С����ʱ���Ƿ����Ѿ�����
		for (int j = i; j < num; ++j)
		{
			//�������ʱ����С�ĵ���ʱ�� < ǰһ����ɵ����ʱ��
			if (job[j]->Tarrive < job[i - 1]->Taccomplish)
			{
				swap(job[j], job[tmp]);
				break;
			}
		}
		if (job[i]->Tarrive < job[i - 1]->Taccomplish)
			job[i]->Tstart = job[i - 1]->Taccomplish;//��һ����ҵ����ʱ��
		else
		{
			//���еĶ��������֮��Ҫ��  �ٴν���ʱ������
			Arrive_sort(num, job);
			for (int k = tmp + 1; k < num; ++k)
			{
				//����ҵ�ʱ�����һ����ͬ��ʱ�䵫����ʱ�����С ����
				if (job[tmp]->Tarrive == job[k]->Tarrive && job[tmp]->Tservice > job[k]->Tservice)
				{
					swap(job[tmp], job[k]);
				}
			}
			job[i]->Tstart = job[i]->Tarrive;

		}

		job[i]->Taccomplish = job[i]->Tstart + job[i]->Tservice;
		job[i]->TZz = job[i]->Taccomplish - job[i]->Tarrive;
		job[i]->TDqZz = job[i]->TZz / job[i]->Tservice;
	}
}

//�����ȼ�����
void High_level(int num, vector<Node*> job)
{
	//������ʱ������
	Arrive_sort(num, job);
	//��һ��Ҫ���е�����
	for (int i = 1; i < num; ++i)
	{
		//����ҵ�ʱ�����һ����ͬ��ʱ�䵫Ȩ�ޱ������ ����
		if (job[0]->Tarrive == job[i]->Tarrive && job[0]->prio < job[i]->prio)
		{
			swap(job[0], job[1]);
		}
	}
	job[0]->Tstart = job[0]->Tarrive;
	//���ʱ�� = ��ʼ + ����ʱ��
	job[0]->Taccomplish = job[0]->Tstart + job[0]->Tservice;
	//��תʱ�� == ���ʱ��-����ʱ��
	job[0]->TZz = job[0]->Taccomplish - job[0]->Tarrive;
	//��Ȩ��תʱ�� == ��תʱ��/����ʱ��
	job[0]->TDqZz = job[0]->TZz / job[0]->Tservice;

	for (int i = 1; i < num; i++)
	{
		//Ѱ�ҵ�i������Ľ���
		//��ʣ�µĽ������ȼ�����
		Priority_sort(num - i, job);
		//��¼��ǰ���е�λ��
		int tmp = i;
		//�жϵ�ǰ�����Ȩ���Ƿ����Ѿ�����
		for (int j = i; j < num; ++j)
		{
			//���Ȩ�����ĵ���ʱ�� < ǰһ����ɵ����ʱ��
			if (job[j]->Tarrive <= job[i - 1]->Taccomplish)
			{
				swap(job[j], job[tmp]);
				break;
			}
		}
		if (job[i]->Tarrive <= job[i - 1]->Taccomplish)
			job[i]->Tstart = job[i - 1]->Taccomplish;//��һ����ҵ����ʱ��
		else
		{
			//���еĶ��������֮��Ҫ��  �ٴν���ʱ������
			Arrive_sort(num, job);
			for (int k = tmp + 1; k < num; ++k)
			{
				//����ҵ�ʱ�����һ����ͬ��ʱ�䵫Ȩ�ޱ������ ����
				if (job[tmp]->Tarrive == job[k]->Tarrive && job[tmp]->Tservice < job[k]->Tservice)
				{
					swap(job[tmp], job[k]);
				}
			}
			job[i]->Tstart = job[i]->Tarrive;

		}

		job[i]->Taccomplish = job[i]->Tstart + job[i]->Tservice;
		job[i]->TZz = job[i]->Taccomplish - job[i]->Tarrive;
		job[i]->TDqZz = job[i]->TZz / job[i]->Tservice;
	}

}

//ʱ��Ƭ��ת�㷨
void RR(int num, vector<Node*> job)//RR�㷨
{
	//����ʣ��ʱ��
	SetTime(num, job);
	//��ȡʱ��Ƭ
	int q;
	cout << "������ʱ��Ƭ���ȣ�" << endl;
	cin >> q;
	//���ȴ����з��������
	queue<Node*> job_que;
	//��ǰ��ʱ��
	int time = 0;
	//����ʱ������
	Arrive_sort(num, job);
	//��ʼʱ��Ϊ��һ����ҵ�ĵ���ʱ��
	time = job[0]->Tarrive;
	//���õ�һ����ʼʱ��
	job[0]->Tstart = time;
	//����һ���������
	job_que.push(job[0]);
	job[0]->flag = true;
	while (!job_que.empty())
	{
		//��ȡ��ǰ��Ҫ���е���ҵ
		Node* tmp_job = job_que.front();
		job_que.pop();
		//�����ʼʱ��û���趨������ǰʱ����Ϊ��ʼʱ��
		if ((tmp_job->Tstart == 0 && (tmp_job != job[0])))
		{
			tmp_job->Tstart = time;
		}
		//�жϵ�ǰ����Ҫ��ʱ���Ƿ�ȵ�ǰ��ʱ��ƬС
		if (tmp_job->Tsurplus <= q)
		{
			//ʱ����ϵ�ǰʣ��ʱ��
			time += tmp_job->Tsurplus;
			tmp_job->Tsurplus = 0;
			//�������ʱ��
			tmp_job->Taccomplish = time;
		}
		//����Ҫ��ֹһ��ʱ��Ƭ
		else
		{
			//ʱ�� ֱ�Ӽ���ʱ��Ƭ
			tmp_job->Tsurplus -= q;
			time += q;
		}
		for (int i = 0; i < num; ++i)
		{
			//���ǵ�ǰ����   δ���	 �Ѿ�����   û�н������
			if (job[i] != tmp_job && job[i]->Taccomplish == 0 && job[i]->Tarrive <= time && job[i]->flag == false)
			{
				job_que.push(job[i]);
				job[i]->flag = true;
			}
		}
		//û�����ʱ��
		if(tmp_job->Taccomplish == 0)
			job_que.push(tmp_job);
	}
	for (int i = 0; i < num; ++i)
	{
		//job[i]->Taccomplish = job[i]->Tstart + job[i]->Tservice;
		job[i]->TZz = job[i]->Taccomplish - job[i]->Tarrive;
		job[i]->TDqZz = job[i]->TZz / job[i]->Tservice;
	}
}

void ave_time(int num, vector<Node*>& job)
{
	int ave_t1 = 0;
	int ave_t2 = 0;
	for (int i = 0; i < num; ++i)
	{
		ave_t1 += job[i]->TZz;
		ave_t2 += job[i]->TDqZz;
	}
	ave_t1 /= num;
	ave_t2 /= num;
	cout << "ƽ����ת����" << "\t\t" << "ƽ����Ȩ��ת����" << endl;
	cout << "\t" << ave_t1 << "\t\t" << ave_t2 << endl;
}

//�������
void print(int num, vector<Node*>& job)
{
	cout << "������" << "\t" << "����ʱ��" << "\t" << "����ʱ��" << "\t" << "��ʼʱ��" <<
		"\t" << "���ʱ��" << "\t" << "��תʱ��" << "\t" << "��Ȩ��ת" << endl;

	for (int i = 0; i < num; i++)
	{
		cout << job[i]->name << "\t" << job[i]->Tarrive << "\t\t" << job[i]->Tservice 
			<< "\t\t"  << job[i]->Tstart << "\t\t" << job[i]->Taccomplish
			<< "\t\t" << job[i]->TZz << "\t\t"  << job[i]->TDqZz << endl;
	}
	ave_time(num, job);
}

//������
void clear(int num, vector<Node*>& job)
{
	for (int i = 0; i < num; ++i)
	{
		job[i]->Tstart = 0;
		job[i]->Taccomplish = 0;
		job[i]->TZz = 0;
		job[i]->TDqZz = 0;
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
		clear(num, job);
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
			print(num, job);
			break;
		case 4:
			High_level(num, job);
			print(num, job);
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