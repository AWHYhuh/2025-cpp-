#ifndef CCOLECTIVE
#define CCOLECTIVE
//书本基类
#include <iostream>
#include <string>
using namespace std;
class CColective
{
public:
	int m_Id;//书本编号
	string m_Name;  //书本名字
	string m_Press; //出版社
	string m_Price; //图书价格
	string m_Page;  //图书页数

	virtual void showInfo() = 0;	//显示书本信息,多态
	virtual string getClass() = 0;  //获取书本类型
	virtual void SetOtherProperties(string Other_Properties) = 0;//设置其他属性
	virtual string GetOtherProperties() = 0;//获得其他属性
	virtual bool Judge(string OtherProperties) = 0;
};
#endif;
