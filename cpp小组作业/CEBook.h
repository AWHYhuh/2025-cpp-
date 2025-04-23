#pragma once
//电子书类
#include "CColective.h"
#include <iostream>
#include <string>
using namespace std;

class CEBook : public CColective
{
private:
	string m_Format; //电子书的格式（txt、pdf、epub、azw3、kindle）
public:
	CEBook();
	CEBook(int Id, string Name, string Press, string Price, string Words);//Words电子书的字数
	~CEBook();

	//显示书本信息
	virtual void showInfo();
	//获取书本类型
	virtual string getClass();
	//设置其他属性
	virtual void SetOtherProperties(string Format);
	virtual string GetOtherProperties();//获得其他属性
	bool Judge(string OtherProperties);
};