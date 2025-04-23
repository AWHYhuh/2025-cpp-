#pragma once //防止头文件重复包含
//管理类
//管理内容：
//与用户的沟通菜单界面
//对书本的增、删、查等操作
//与文件的读写交互

#include "CColective.h"
#include "CBook.h"		//一般图书
#include "CEBook.h"		//电子书
#include "CMagazine.h"	//杂志

#include<cstdlib>		//system 不明确	
#include <fstream>		//文件流头文件
#define FILENAME "BookFile.txt"

using namespace std;

class CLIbraryManager
{
public:
	CLIbraryManager();//构造函数

	//菜单显示
	void Show_Menu();

	//0.退出系统
	void ExitSystem();

	//1.添加实现
	int m_BookNum;//记录书本的数量
	CColective** m_BookArray;//书本数组指针
	void Add_Book();

	//保存文件
	void Save();

	//设置标志判断最开始文件是否存在
	bool m_isFile;

	//统计文件中已有书本数量
	int Get_BookNum();

	//初始化文件中已有书本数组、数量
	void init_Book();

	//2.显示书本
	void show_BookArray();

	//4.查找实现
	void find_Book();//函数

	//6.清空txt实现
	void clear_Txt();

	//3.删除书本信息实现
	void delete_Book();//函数
	int isBook(int Id);
	int isBook(string name);

	//5.按照书本序号排序
	void sort_BookArray();

	~CLIbraryManager();//析构函数
};


