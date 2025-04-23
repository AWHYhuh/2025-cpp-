#pragma once
//��־�鼮��
#include "CColective.h"
#include <iostream>
#include <string>

using namespace std;
class CMagazine : public CColective
{
private:
	string m_Issn = "ISSN-";//��־�ڿ��� ��ʽ��ISSN XXXX-XXXX
public:
	CMagazine();
	CMagazine(int Id, string Name, string Press, string Price, string Page);
	~CMagazine();

	//��ʾ�鱾��Ϣ
	virtual void showInfo();
	//��ȡ�鱾����
	virtual string getClass();
	//������������
	virtual void SetOtherProperties(string Issn);
	virtual string GetOtherProperties();//�����������

	bool Judge(string OtherProperties);
};

