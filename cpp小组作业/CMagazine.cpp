#include "CMagazine.h"

CMagazine::CMagazine()
{
	this->m_Id = 0;
	this->m_Name = "";
	this->m_Press = "";
	this->m_Price = "";
	this->m_Page = "";
}

CMagazine::CMagazine(int Id, string Name, string Press, string Price, string Page)
{
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_Press = Press;
	this->m_Price = Price;
	this->m_Page = Page;
}

CMagazine::~CMagazine()
{
}

void CMagazine::showInfo()
{
	cout << "书本编号：" << this->m_Id
		<< "\t书本类型：" << this->getClass()
		<< "\t书本名称：" << this->m_Name
		<< "\t书本出版社：" << this->m_Press
		<< "\t书本价格：" << this->m_Price
		<< "\t书本页数：" << this->m_Page
		<< "\t其他属性——书本Issn号：" << this->m_Issn;
}

string CMagazine::getClass()
{

	return string("杂志书籍");
}

void CMagazine::SetOtherProperties(string Issn)
{
	this->m_Issn.append(Issn);//append(),追加函数，将两个string字符串拼接在一起
}

string CMagazine::GetOtherProperties()
{
	return this->m_Issn;
	return string();
}

bool CMagazine::Judge(string OtherProperties)
{
	return false;
}
