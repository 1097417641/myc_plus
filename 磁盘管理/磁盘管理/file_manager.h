#pragma once
#include<fstream>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include"MD5.h"

class file_manager
{
public:
	//�Ե�ǰ��������ɨ��
	void scanning(const std::string & path);
	//���MD5 ---> file
	void MD5_File();
	//���file -->MD5
	void File_MD5();

	//��ͬ�ļ���ɾ��
	void delete_name(const std::string& name);
	//��ͬMD5ֵɾ��
	void delete_MD5(const std::string& md5);
	//ɾ�������ظ����ļ�
	void deleteAllSame();
	//ɾ��������matchName���ļ�
	void delete_match_name(const std::string& matchName);

	//ɾ��������matchName���ļ�(һ�ݶ�������)
	void clear_match_name(const std::string& matchName);

	//��ʾ�����ļ�
	void showAllFile();
	//��ʾ���ظ��ļ�
	void showFile_MD5();
	void showMD5();

	//�ж����Ƿ�������ļ�
	bool Find_File(const std::string& md5);

	bool write_in_file();
private:
	//��������ļ��ľ���·��
	std::unordered_set<std::string> file;
	//��������ļ���md5--->name��ӳ��
	std::unordered_multimap<std::string, std::string> Md5_Name;

	//����ظ��ļ�
	std::unordered_map<std::string, std::string> Name_MD5;
	
	MD5 md5;
};
