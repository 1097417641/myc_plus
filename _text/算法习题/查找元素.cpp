#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//һ���Ź�������飬����n��֤�飬�����������һ����λ��   ʱ�临�Ӷ�Ϊlog����
//ԭ���� [1,2,3,4,5,6]     ----->  ����5λ     [6,1,2,3,4,5]
#include<vector>
#include<iostream>
using namespace std;
class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		// write code here
		int left = 0;
		int right = n - 1;
		int mid = (left + right) / 2;
		while (A[mid] != x)
		{
			if (A[mid] < A[right])
			{
				if (A[mid] < x && x < A[right])
				{
					left = mid + 1;
					mid = (left + right) / 2;
				}
				else
				{
					right = mid - 1;
					mid = (left + right) / 2;
				}
			}
			else if (A[left] < x && A[mid] > x)
			{
				right = mid - 1;
				mid = (left + right) / 2;
			}
			else
			{
				mid = mid + 1;
			}
		}
		return mid;
	}
};