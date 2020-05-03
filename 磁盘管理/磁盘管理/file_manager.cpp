#define _CRT_SECURE_NO_WARNINGS
#include"file_manager.h"
#include"file_tool.h"
#include<algorithm>
#include<set>
#include<fstream>

bool file_manager::write_in_file()
{
	std::set<std::string> sort_file;
	for (auto& e : file)
	{
		sort_file.insert(e);
	}
	std::cout << "input your path" << std::endl;
	std::string path;
	std::cin >> path;
	for (auto& e : sort_file)
	{
		std::ofstream outfile;
		outfile.open(path, std::ios::out | std::ios::app);
		outfile << e << ';' << std::endl;
		outfile.close();
	}
	return true;
}


//�Ե�ǰ��������ɨ��
void file_manager::scanning(const std::string & path)
{
	//��ԭ�����ļ����
	file.clear();

	//���ļ�������set��
	search_director(path, file);
	MD5_File();
	File_MD5();
}

//���MD5 ---> file
void file_manager::MD5_File()
{
	//��������
	Md5_Name.clear();
	for (const auto& f : file)
	{
		//����md5ֵ  �������µ�MD5ֵ����
		md5.reset();
		Md5_Name.insert(make_pair(md5.getFile(f.c_str()), f));
	}
}

//���file -->MD5(�����ظ����ļ�)
void file_manager::File_MD5()
{
	Name_MD5.clear();

	auto it = Md5_Name.begin();
	while (it != Md5_Name.end())
	{
		//�ж��Ƿ����һ��
		if (Md5_Name.count(it->first) > 1)
		{
			//��ȡ�ظ��ķ�Χ
			auto str = Md5_Name.equal_range(it->first);
			auto begin = str.first;
			while (begin != str.second)
			{
				Name_MD5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			it = begin;
		}
		else
		{
			++it;
			//it = Md5_Name.erase(it);
		}
	}
}

//��ͬ�ļ���ɾ��
void file_manager::delete_name(const std::string& name)
{
	if (Name_MD5.count(name) == 0)
	{
		std::cout << "the file is not exist" << std::endl;
		return;
	}
	//��ΪName_Md5��ֻ������ظ���Ԫ��  ���в�Ϊ0 �϶�����1
	std::string str = Name_MD5[name];

	auto it = Md5_Name.equal_range(str);
	auto beg = it.first;
	while (beg != it.second)
	{
		if (beg->second != name)
		{
			file.erase(beg->second);
			Name_MD5.erase(beg->first);
			delete_file(beg->second.c_str());
		}
		++beg;
	}

	// ɾ��MD5_Name�е�ӳ��
	beg = it.first;
	Md5_Name.erase(beg, it.second);
	Md5_Name.insert(make_pair(str, name));
}


//��ͬMD5ֵɾ��
void file_manager::delete_MD5(const std::string& md5)
{
	if (Md5_Name.count(md5) == 0)
	{
		std::cout << "the file is not exist" << std::endl;
		return;
	}
	auto it = Md5_Name.equal_range(md5);
	auto beg = it.first;
	//�洢��һ�ݲ���ɾ��
	++beg;
	while (beg != it.second)
	{
		//��Ҫɾ��file �� Name_MD5�е�ӳ��
		file.erase(beg->second);
		Name_MD5.erase(beg->second);
		delete_file(beg->second.c_str());
		++beg;
	}
	//ɾ��MD5_Name�е�ӳ��
	beg = it.first;
	++beg;
	Md5_Name.erase(beg, it.second);
}

void file_manager::deleteAllSame()
{
	//����ͨ��Name_Md5��ҪȥMd5_Name����Md5��  
	//����ֱ�ӱ���file,ÿһ��delete�����file
	//��������ʱ��
	auto it = file.begin();
	while (it != file.end())
	{
		delete_name(*it);
		++it;
	}
	std::cout << "ALL Same File is Delete" << std::endl;
}


//ɾ��������matchName���ļ�
void file_manager::delete_match_name(const std::string& matchName)
{
	//ɾ���ض����ֵ��ظ��ļ�  ������AllSame������������
	auto it = file.begin();
	while (it != file.end())
	{
		if ((*it).find(matchName) != 0)
			delete_name(*it);
		++it;
	}
}

void file_manager::clear_match_name(const std::string& matchName)
{
	//��ȥName_Md5��ɾ�����еĸ��� �ٻص�file��ɾ��ԭ��
	delete_match_name(matchName);
	auto it = file.begin();
	while(it != file.end())
	{
		if ((*it).find(matchName) != 0)
		{
			delete_file((*it).c_str());
			it = file.erase(it);
		}
		else
		{
			++it;
		}
	}
}


void file_manager::showAllFile()
{
	auto it = file.begin();
	while (it != file.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
	//��ʾ�ܵ��ļ���
	std::cout << "file number is :" << file.size() << std::endl;
}


void file_manager::showFile_MD5()
{
	//������ͬ���ļ���ʾ��һ��
	auto it = Md5_Name.begin();
	while (it != Md5_Name.end())
	{
		//��ʾ�ļ��ĸ���
		int index = 1;
		auto pairIt = Md5_Name.equal_range(it->first);
		auto tmp = pairIt.first;
		std::cout << "MD5:" << it->first << std::endl;
		while (tmp != pairIt.second)
		{
			std::cout << "��" << index << "���ļ���";
			std::cout << tmp->second << std::endl;
			++index;
			++tmp;
		}
		std::cout << "the same file is :" << index - 1 << std::endl;
		it = pairIt.second;
	}
}

bool file_manager::Find_File(const std::string& md5)
{
	return true;
}