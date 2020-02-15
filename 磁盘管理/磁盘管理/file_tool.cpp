#define _CRT_SECURE_NO_WARNINGS
#include"file_tool.h"

void search_director(const std::string& path, std::unordered_set<std::string>& File)
{
	//count���������ļ�������
	int count = 0;
	std::string match_file = path + "\\" + "*.*";
	_finddata_t file_attribute;
	long handle = _findfirst(match_file.c_str(), &file_attribute);
	if (handle == -1)
	{
		perror("failed");
		return;
	}
	//_findnext == 0��ʾ����
	do
	{
		//�����Ŀ¼
		if (file_attribute.attrib & _A_SUBDIR)
		{
			//�������ĵ�ǰĿ¼ ���Ҳ�ȥ�����ϲ�Ŀ¼
			if (strcmp(file_attribute.name, ".") != 0 && strcmp(file_attribute.name, "..") != 0)
				search_director(path + "\\" + file_attribute.name, File);
		}
		else
		{
			//��ʾ�����ļ�����·������Ȼ���ܳ���һ�����ļ���
			File.insert(path + "\\" + file_attribute.name);
			++count;
		}
	} while (_findnext(handle, &file_attribute) == 0);
	_findclose(handle);
}


void delete_file(const char* file_name)
{
	if (remove(file_name) == 0)
	{
		std::cout << "delete file success" << std::endl;
	}
	else
	{
		std::cout << "some problem arise, you need to see delete_file f(x)" << std::endl;
	}
}