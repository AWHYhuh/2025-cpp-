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
	cout << "�鱾��ţ�" << this->m_Id
		<< "\t�鱾���ͣ�" << this->getClass()
		<< "\t�鱾���ƣ�" << this->m_Name
		<< "\t�鱾�����磺" << this->m_Press
		<< "\t�鱾�۸�" << this->m_Price
		<< "\t�鱾ҳ����" << this->m_Page
		<< "\t�������ԡ����鱾Issn�ţ�" << this->m_Issn;
}

string CMagazine::getClass()
{

	return string("��־�鼮");
}

void CMagazine::SetOtherProperties(string Issn)
{
	this->m_Issn.append(Issn);//append(),׷�Ӻ�����������string�ַ���ƴ����һ��
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
