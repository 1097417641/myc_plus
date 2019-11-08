#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;

//����string��ӿڵ�ѧϰʹ�ã�


// ��һ�֣����캯��
//default(1)
//string();
//copy(2)
//string(const string& str);
//substring(3)
//string(const string& str, size_t pos, size_t len = npos);
//from c - string(4)
//string(const char* s);
//from sequence(5)
//string(const char* s, size_t n);
//fill(6)
//string(size_t n, char c);
//range(7)
//template <class InputIterator>
//string(InputIterator first, InputIterator last);

//����string��
void Makestring()
{
	//���캯��
	string s1;
	string s2("hello world");
	//��������
	string s3(s2);
	string s4(s2, 0, 5);	//hello
	string s5("hello world", 5); //hello
	string s7(10, 'a');		//aaaaaaaaaa
	string s6(s2, 1);	//ello world
	//��ֵ����
	string s8 = "hello";
}

//������:�����ƻ�����	�������ݽ����� ��һ��λ�þ�++
void TextIterators()
{
	string s("hello world");
	/*
		������:һ���������ݵķ�����ʽ
		ʹ�÷�ʽ:������ָ���ʹ�÷�ʽ
		begin():ָ�������ĵ�һ��Ԫ�ص�λ��
		end():ָ�����������һ��Ԫ�ص���һ��λ��
		����ҿ�
	*/
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	//forѭ����ʽ
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << "";
	}
	cout << endl;

	//��Χforѭ����ʽ
	for (const auto& ch : s)
	{
		cout << ch << "";
	}
	cout << endl;

	//const ������
	const string s1("hello world");
	string::const_iterator s1it = s1.begin();
	while (s1it != s1.end())
	{
		cout << *s1it ;
		s1it++;
	}
	cout << endl;


	/*
		���������
		rbegin()
		rend()
		����ƶ����� ++ ����
	*/

	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit;
		rit++;
	}
	cout << endl;

	const string s3("hello world");
	string::const_reverse_iterator s3it = s3.rbegin();
	while (s3it != s3.rend())
	{
		cout << *s3it;
		s3it++;
	}
	cout << endl;

}

// �����ӿ�
void TextCapacity()
{
	string s1("hello world");
	//��ǰ�ַ�����С ����\0
	cout << s1.size() << endl;
	//���Ĵ�С
	cout << s1.max_size() << endl;
	//���Դ���ַ��Ŀռ�
	cout << s1.capacity() << endl;
	//�ı��ַ����Ĵ�С ���������޸�
	s1.resize(20);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1 << "end" << endl;
	//�ı������Ĵ�С ֻ�����������������������
	s1.reserve(50);
	cout << s1.capacity() << endl;
	//�жϵ�ǰ�ַ����Ƿ�Ϊ��
	cout << s1.empty() << endl;
	//�������  ����ı������Ĵ�С
	s1.clear();
	cout << s1.empty() << endl;
	cout << s1.capacity() << endl;
	//��С�����Ľӿ�	ϵͳ�Զ��жϼ�С����
	s1.shrink_to_fit();
	cout << s1.capacity() << endl;
}

//Ԫ�ط��ʵĽӿ� + ��ɾ��Ľӿ�
void TextElement()
{
	string s1("hello world");
	cout << s1[2] << endl;
	cout << s1.at(2) << endl;
	//��ʾ���һ���ַ�
	cout << s1.back() << endl;
	//��ʾ��һ���ַ�
	cout << s1.front() << endl;

	//β�嵥���ַ� + βɾ�����ַ�
	s1.push_back('a');
	s1.pop_back();
	cout << s1 << endl;

	/*
string (1)
	string& append (const string& str);
substring (2)
	string& append (const string& str, size_t subpos, size_t sublen);
c-string (3)
	string& append (const char* s);
buffer (4)
	string& append (const char* s, size_t n);
fill (5)
	string& append (size_t n, char c);
range (6)
	template <class InputIterator>
   string& append (InputIterator first, InputIterator last);
	*/
	string s2;

	s2.append("012");
	cout << s2 << endl;
	
	s2.append("345", 3);
	cout << s2 << endl;
	
	string s3("678");
	s2.append(s3);
	cout << s2 << endl;

	string s4("91011");
	s2.append(s4, 0, 5);
	cout << s2 << endl;
	//������Ȼ���ǵ�����
	char str[] = { "121314" };
	s2.append(str, str + sizeof(str) / sizeof(str[0]));
	cout << s2 << endl;
}

void TextInsert()
{
	/*
string (1)
	string& insert (size_t pos, const string& str);
substring (2)
	string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
c-string (3)
	string& insert (size_t pos, const char* s);
buffer (4)
	string& insert (size_t pos, const char* s, size_t n);
fill (5)
	string& insert (size_t pos, size_t n, char c);
	void insert (iterator p, size_t n, char c);
single character (6)
	iterator insert (iterator p, char c);
range (7)
	template <class InputIterator>
   void insert (iterator p, InputIterator first, InputIterator last)
	*/
	string s("123");
	cout << s << endl;
	//�ڵ�ǰλ�õ�ǰ�����
	s.insert(0, "0");
	cout << s << endl;
	s.insert(0, "-2-1");
	cout << s << endl;
	string s2("456");
	s.insert(8, s2);
	cout << s << endl;
	s.insert(s.begin() + 4, '-');
	cout << s << endl;
	char str[] = { "1112" };
	s.insert(s.end(),str, str + sizeof(str) / sizeof(str[0]));
	cout << s << endl;


}

//���ǽӿ� (�������  ��������=)
void TextAssign()
{
	string s1("123");
	cout << s1 << endl;
	string s2("4");
	s1.assign(s2);
	cout << s1 << endl;
}

// += �ӿ� (�ر���)
// replace�ӿ�
//cin �� getline()
void TextUsuall()
{
	string s1;
	s1 += '0';
	cout << s1 << endl;
	s1 += "123";
	cout << s1 << endl;

	string s("01234");
	cout << s << endl;
	string s2("56789");
	s.replace(3, 1, s2);	//��һ���ַ��滻����������ַ���
	cout << s << endl;


	string s3;
	//cin ���� �ո�ֹͣ����
	cin >> s3;
	cout << s3 << endl;
	//getline()Ĭ�������س�ֹͣ����
	//����ͨ�������������޸�ֹͣ���յķ���
	getline(cin, s3);
	cout << s3 << endl;
}



int main()
{
	//Makestring();
	//TextIterators();
	//TextCapacity();
	//TextElement();
	//TextInsert();
	//TextAssign();
	TextUsuall();
	system("pause");
	return 0;
}