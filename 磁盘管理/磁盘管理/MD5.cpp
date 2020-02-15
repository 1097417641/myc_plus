#include<iostream>
#include<fstream>
#include"MD5.h"
using namespace std;

//�̶�ֵ(��Ҫ��ͷ�ļ��ж���  ��ֹ���ͷ�ļ�)
size_t MD5::s[] =
{
7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

void MD5::reset()
{
	//��ʼ��  A B C D
	count[0] = count[1] = 0;
	state[0] = 0x67452301;
	state[1] = 0xefcdab89;
	state[2] = 0x98badcfe;
	state[3] = 0x10325476;

	memset(chunk, 0, 64);

	count[0] = count[1] = 0;
}

void MD5::MD5Init()
{
	//��ʼ��k
	for (int i = 0; i < 64; ++i)
	{
		k[i] = static_cast<UINT4>(abs(sin(i + 1)) * pow(2, 32));
	}
	reset();
}

MD5::MD5()
{
	MD5Init();
}

void MD5::MD5Update(UINT4* chunk)
{
	int a = state[0], b = state[1], c = state[2], d = state[3];
	UINT4 f, g;
	for (int i = 0; i < 64; ++i)
	{
		if (0 <= i && i <= 15)
		{
			f = F(b, c, d);
			g = i;
		}
		else if (16 <= i && i <= 31)
		{
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (32 <= i && i <= 47)
		{
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else
		{
			f = I(b, c, d);
			g = (7 * i) % 16;
		}
		//���и���
		
		int tmp = d;
		d = c;
		c = b;
		b = b + shift(chunk[g] + a + f + k[i]  , s[i]);
		a = tmp;

	}
	state[0] += a;
	state[1] += b;
	state[2] += c;
	state[3] += d;
}

void MD5::MD5Final()
{
	//��ȻҪ���һ��byte
	//����ĩβ���һ�� 1000 0000
	char*p = chunk + count[1];
	*p++ = 0x80;
	//�鿴���һ�����С
	int last_info = TRUNK_INFO - count[1] - 1;
	//���ʣ���ֽڲ���8���ֽ�
	if (last_info < 8)
	{
		//ĩβȫ����0
		memset(p, 0, last_info);
		//����ǰ���ݿ�
		MD5Update((UINT4*)chunk);
		//�����ݿ���0
		memset(chunk, 0, TRUNK_INFO);
	}
	else
	{
		//��ĩβȫ����0
		memset(p, 0, last_info);
	}
	//count[0]��¼�ܳ���
	unsigned long long totalBits = count[0];
	//��ȡbitλ����
	totalBits *= 8;
	//���long long һ��8�ֽ� ��7ĩβ��䳤����Ϣ
	((unsigned long long*) chunk)[7] = totalBits;
	//������һ�����ݿ�
	MD5Update((UINT4*)chunk);
}

string MD5::change16(UINT4 n)
{
	static string strMap = "0123456789abcdef";
	string ret;
	for (int i = 0; i < 4; ++i)
	{
		//һ�λ��һ��byte
		int cur = (n >> (i * 8)) & 0xff;

		string curStr;
		//��λ��ǰ
		curStr += strMap[cur / 16];
		//��λ�ں�
		curStr += strMap[cur % 16];
		ret += curStr;
	}
	return ret;
}

std::string MD5::getStingMD5(const string& str)
{
	//�ж����Ϊ�� ֱ�ӷ���
	if (str.empty() == 1)
	{
		return change16(state[0]).append(change16(state[1])).append(change16(state[2]).append(change16(state[3])));
	}
	//��ȡ�ַ��ܳ���
	count[0] = str.size();
	UINT4 num = count[0] / TRUNK_INFO;
	const char* ptr = str.c_str();
	for (int i = 0; i < num; ++i)
	{
		//ÿ�ν�һ��������ݽ��и���
		memcpy(chunk, ptr + i * TRUNK_INFO, TRUNK_INFO);
		MD5Update((UINT4*)chunk);
	}
	//��ȡ���һ�����ݿ�Ĵ�С
	count[1] = count[0] % TRUNK_INFO;
	//��ȡ���һ��������
	memcpy(chunk, ptr + num * TRUNK_INFO,count[1] );
	MD5Final();
	return change16(state[0]).append(change16(state[1])).append(change16(state[2]).append(change16(state[3])));;
}

std::string MD5::getFile(const char* File)
{
	ifstream file(File, ifstream::binary);
	if (!file.is_open())
	{
		cout << File;
		perror(":not have is file");
		return change16(state[0]).append(change16(state[1])).append(change16(state[2]).append(change16(state[3])));
	}

	////IO������  ������������
	//while (!file.eof())
	//{
	//	file.seekg(0, file.end);
	//	UINT4 len = file.tellg();
	//	file.seekg(0, file.beg);
	//	char* Date = new char[len];
	//	file.read(Date, len);
	//}

	//һ�ζ�ȡһ������
	while (!file.eof())
	{
		file.read(chunk, TRUNK_INFO);
		//���һ����ܲ���һ�����С
		if (TRUNK_INFO != file.gcount())
		{
			break;
		}
		count[0] += TRUNK_INFO;
		MD5Update((UINT4*)chunk);
	}
	//�������һ�����ݿ�
	count[1] = file.gcount();
	count[0] += count[1];
	MD5Final();
	return change16(state[0]).append(change16(state[1])).append(change16(state[2]).append(change16(state[3])));
}

