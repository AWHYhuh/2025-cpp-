#pragma once
//杂志书籍类
#include "CColective.h"
#include <iostream>
#include <string>

using namespace std;
class CMagazine : public CColective
{
private:
	string m_Issn = "ISSN-";//杂志期刊号 格式：ISSN XXXX-XXXX
public:
	CMagazine();
	CMagazine(int Id, string Name, string Press, string Price, string Page);
	~CMagazine();

	//显示书本信息
	virtual void showInfo();
	//获取书本类型
	virtual string getClass();
	//设置其他属性
	virtual void SetOtherProperties(string Issn);
	virtual string GetOtherProperties();//获得其他属性

	bool Judge(string OtherProperties);
};

