#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//
//int main()
//{
//	unsigned char x, y;
//	x = 0x00000010;        //����Ǹ�ֵ �����ǵ�ַ ��������unsigned char ֻҪ�����λ
//	y = 0x00001010;
//	printf("%d\n", x & y);
//	printf("%d\n", x | y);
//	printf("%d\n", x ^ y);
//	system("pause");
//	return 0;
//}

//void *MyMemmove(void *dest, const void *src, size_t count)
#if 0
void *MyMemmove(void *dest, const void *src, size_t count)
{
	assert(dest != NULL && src != NULL);
	void *ret = dest;
	if((char *)dest < (char *)src || (char *)dest > ((char *)src + count))
		while (count != 0)
		{
		*(char*)dest = *(char *)src;
		((char *)dest)++;
		((char*)src)++;
		count--;
		}
	else
		while(count != 0)
		{
		*((char *)dest + count - 1) = *((char *)src + count - 1);
		count--;
		}
	return ret;
}
#endif

//void *MyMemcpy(void *dest, const void* src, int count)   
#if 0
void *MyMemcpy(void *dest, const void* src, int count)
{
	void *ret = dest;
	//char *p = (char *)dest;
	while (count != 0)
	{
		*(char*)dest =*(char *)src;
		((char *)dest)++;
		((char*)src)++;
		count--;
	}
	return ret;
}

int main()
{
	int arr1[20] = { 0 };
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	//memcpy(arr1, arr, 16);      //memcpy(Ҫ�������飬���������飬���Ƶ��ֽ���) �����ڴ濽���������ֽڿ���
	memcpy(arr+2, arr, 16);
	system("pause");
	return 0;
}
#endif

//int main()
//{
//	FILE *PF = fopen("test.txt", "r");
//	if (PF == NULL)
//	{
//		printf("%s\n", strerror(errno));   //errno���ִ�����Ϣ
//	}
//	system("pause");
//	return 0;
//}
//strtok()���ַ�����λ�ò���Ϊ\0 ����ǰ��ĵ�ַ

//int main()
//{
//	//strtok()���ַ�����λ�ò���Ϊ\0 ����ǰ��ĵ�ַ
//	//���Ա���ԭ����������
//	//��ΪNULLʱ����һ��ָ��λ�ü���Ѱ��,������û��ֵ ����null
//	char str[] = "TerryGaoBo@163.com";
//	//printf("%s\n", strtok(str, "@."));
//	//printf("%s\n", strtok(NULL, "@."));
//	//printf("%s", strtok(NULL,"@."));
//	char *ret = strtok(str, "@.");
//	while (ret != NULL)
//	{
//		printf("%s\n", ret);
//		ret = strtok(NULL, "@.");
//	}
//	system("pause");
//	return 0;
//}
//char *MyStrstr(const char* str1, const char* str2)   //����str1��str2 ��λ��

#if 0
char *MyStrstr(const char* str1, const char* str2)   //����str1��str2 ��λ��
{
	assert(*str1 != NULL && *str2 != NULL);
	const char *q = str2;
	const char *p = str1;
	while (*str1 != '\0')
	{
		str1 = p;
		while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
		{
			str1++;
			str2++;
		}
		if (*str1 == '\0')
		{
			return NULL;
		}
		if (*str2 == '\0')
		{
			return p;
		}
		p++;
		str2 = q;
	}
	return NULL;
}
int main()
{
	char *str1 = "abbbcdef";
	char *str2 = "bbc";
	char *p = MyStrstr(str1, str2);
	//char *p = strstr(str1, str2);
	// BF�����㷨   KMP�㷨
	printf("%s", p);
	system("pause");
	return 0;
}
#endif
//int MyStrncmp(const char *str1, const char *str2, int n)		�Ƚϴ�С

#if 0
int MyStrncmp(const char *str1, const char *str2, int n)
{
	assert(*str1 != NULL && *str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0' && n != 0)
	{
		if (*str1 > *str2)
			return 1;
		if (*str1 < *str2)
			return -1;
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		n--;
	}
	return 0;
}

int main()
{
	char *str1 = "abdef";
	char *str2 = "abcdef";
	int n = MyStrncmp(str1, str2, 2);
	printf("%d", n);
	system("pause");
	return 0;
}
#endif

//char *MyStrncat(char *dest, const char *src, int n)	���������ַ���		//	û���ж��Ƿ��ݵ���
#if 0
char *MyStrncat(char *dest, const char *src, int n)			//	û���ж��Ƿ��ݵ���
{
	assert(*src != NULL);
	char *p = *dest;
	while (*dest != '\0')
		dest++;
	while (n != 0)
	{
		*(dest++) = *(src++);
		n--;
	}
	return p;
}

int main()
{
	char str[10] = "abcd";
	char *str1 = "hello";
	//strncat(str, str1, 2);
	MyStrncat(str, str1, 2);
	printf("%s", str);
	system("pause");
	return 0;
}
#endif

//char *MyStrncpy(char *dest, const char* src, int n)	ǰn������
#if 0
char *MyStrncpy(char *dest, const char* src, int n)		//�Ѻ����copy��ǰ��
{
	assert(*src != NULL);
	char *p = dest;
	while (n != 0 && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	//while (*dest != '\0')
	//	dest++;
	//*dest = '\0';
	return p;
}

int main()
{
	char dest[20] = "abc";
	char *str = "hello";
	MyStrncpy(dest, str, 3);
	printf("%s", dest);
	system("pause");
	return 0;
}   //strncpy
#endif

//int MyStrcmp(const char *str1, const char *str2)    //�Ƚ������ַ���
#if 0
int MyStrcmp(const char *str1, const char *str2)    //�Ƚ������ַ���
{
	assert(*str1 != NULL && *str2 != NULL);
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 > *str2)
			return 1;
		if (*str1 < *str2)
			return -1;
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
	}
	return 0;
}

int main()
{
	char *str1 = "helloaa";
	char *str2 = "helloa";
	int n = MyStrcmp(str1,str2);
	printf("%d", n);
	system("pause");
	return 0;
}
#endif

//char *MyStrcat(char *dest,const char *str)     //��һ���ַ���������һ���ַ�������
#if 0
char *MyStrcat(char *dest,const char *str)     //��һ���ַ���������һ���ַ�������
{
	assert(dest != NULL);
	assert(str != NULL);
	char *p = dest;
	while (*dest != '\0')				//��ֹд��dest != '\0'
		dest++;
	while (*(dest++) = *(str++))
	{
		;
	}
	return p;
}

int main()
{
	char dest[20] = "hello";
	char *str = "ddd";
	MyStrcat(dest, str);
	printf("%s", dest);
	system("pause");
	return 0;
}
#endif
