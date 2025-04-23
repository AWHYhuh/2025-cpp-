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
	cout << "�鱾��ţ�" << this->m_Id
		<< "\t�鱾���ͣ�" << this->getClass()
		<< "\t�鱾���ƣ�" << this->m_Name
		<< "\t�鱾�����磺" << this->m_Press
		<< "\t�鱾�۸�" << this->m_Price
		<< "\t�鱾ҳ����" << this->m_Page
		<< "\t�������ԡ����鱾Ibsn�ţ�" << this->m_Isbn;
}
string CBooks::getClass()
{
	return string("һ��ͼ��");
}


void CBooks::SetOtherProperties(string Isbn)
{
	this->m_Isbn.append(Isbn);//append(),׷�Ӻ�����������string�ַ���ƴ����һ��
}

string CBooks::GetOtherProperties()
{
	return this->m_Isbn;
	//return string();
}

