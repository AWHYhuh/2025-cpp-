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
	cout << "�鱾��ţ�" << this->m_Id
		<< "\t�鱾���ͣ�" << this->getClass()
		<< "\t�鱾���ƣ�" << this->m_Name
		<< "\t�鱾�����磺" << this->m_Press
		<< "\t�鱾�۸�" << this->m_Price
		<< "\t�鱾������" << this->m_Page
		<< "\t�������ԡ����鱾��ʽ����ʽΪ . " << this->m_Format;
}

string CEBook::getClass()
{
	return string("������");
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



