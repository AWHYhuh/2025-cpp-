#include "CEBook.h"

CEBook::CEBook()
{
	this->m_Id = 0;
	this->m_Name = "";
	this->m_Press = "";
	this->m_Price = "";
	this->m_Page = "";
}

CEBook::CEBook(int Id, string Name, string Press, string Price, string Words)
{
	this->m_Format = "";
	this->m_Id = Id;
	this->m_Name = Name;
	this->m_Press = Press;
	this->m_Price = Price;
	this->m_Page = Words;
}

CEBook::~CEBook()
{
}

void CEBook::showInfo()
{
	cout << "书本编号：" << this->m_Id
		<< "\t书本类型：" << this->getClass()
		<< "\t书本名称：" << this->m_Name
		<< "\t书本出版社：" << this->m_Press
		<< "\t书本价格：" << this->m_Price
		<< "\t书本字数：" << this->m_Page
		<< "\t其他属性——书本格式：格式为 . " << this->m_Format;
}

string CEBook::getClass()
{
	return string("电子书");
}

void CEBook::SetOtherProperties(string Format)
{
	this->m_Format.append(Format);
}

string CEBook::GetOtherProperties()
{
	return this->m_Format;
	return string();
}

bool CEBook::Judge(string OtherProperties)
{
	return false;
}



