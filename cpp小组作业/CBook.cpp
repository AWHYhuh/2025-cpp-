#include "CBook.h"

CBooks::CBooks()
{
	this->m_Id = 0;
	this->m_Name = "";
	this->m_Press = "";
	this->m_Price = "";
	this->m_Page = "";
}

CBooks::CBooks(int Id, string Name, string Press, string Price, string Page)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_Press = Press;
	this->m_Price = Price;
	this->m_Page = Page;
}

CBooks::~CBooks()
{

}

bool CBooks::Judge(string OtherProperties)
{
	int tmp = 0;
	int ss[20] = { 0 };
	for (int i = 0, j = 0; i < OtherProperties.length(); i++) {
		if (OtherProperties.substr(i, 1) >= "0" && OtherProperties.substr(i, 1) <= "9") {
			ss[j] = atoi(OtherProperties.substr(i, 1).c_str());
			j++;
		}
	}
	for (int i = 0; i < 12; i++) {
		if (i % 2 == 0)
		{
			tmp += ss[i] * 1;
		}
		else {
			tmp += ss[i] * 3;
		}
	}
	if (tmp % 10 == 0 && tmp % 10 == ss[12] || 10 - (tmp % 10) == ss[12])
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CBooks::showInfo()
{
	cout << "书本编号：" << this->m_Id
		<< "\t书本类型：" << this->getClass()
		<< "\t书本名称：" << this->m_Name
		<< "\t书本出版社：" << this->m_Press
		<< "\t书本价格：" << this->m_Price
		<< "\t书本页数：" << this->m_Page
		<< "\t其他属性——书本Ibsn号：" << this->m_Isbn;
}
string CBooks::getClass()
{
	return string("一般图书");
}


void CBooks::SetOtherProperties(string Isbn)
{
	this->m_Isbn.append(Isbn);//append(),追加函数，将两个string字符串拼接在一起
}

string CBooks::GetOtherProperties()
{
	return this->m_Isbn;
	//return string();
}

