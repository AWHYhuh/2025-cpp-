#pragma once
//��������
#include "CColective.h"
#include <iostream>
#include <string>
using namespace std;

class CEBook : public CColective
{
private:
	string m_Format; //������ĸ�ʽ��txt��pdf��epub��azw3��kindle��
public:
	CEBook();
	CEBook(int Id, string Name, string Press, string Price, string Words);//Words�����������
	~CEBook();

	//��ʾ�鱾��Ϣ
	virtual void showInfo();
	//��ȡ�鱾����
	virtual string getClass();
	//������������
	virtual void SetOtherProperties(string Format);
	virtual string GetOtherProperties();//�����������
	bool Judge(string OtherProperties);
};