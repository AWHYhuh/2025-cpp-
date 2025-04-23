#pragma once

//一般图书类
#include "CColective.h"
#include <iostream>
#include <string>
using namespace std;

class CBooks : public CColective
{
private:
	string m_Isbn = "ISBN-";  //书本Isbn码
	int njudge;//判断Ibsn码合法性
public:
	CBooks();//无参构造函数
	CBooks(int Id, string Name, string Press, string Price, string Page); //有参构造函数
	~CBooks();
	bool Judge(string OtherProperties);

	//显示书本信息
	virtual void showInfo();
	//获取书本类型
	virtual string getClass();
	//设置其他属性
	virtual void SetOtherProperties(string Isbn);
	virtual string GetOtherProperties();//获得其他属性
};