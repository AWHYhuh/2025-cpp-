#pragma once

//һ��ͼ����
#include "CColective.h"
#include <iostream>
#include <string>
using namespace std;

class CBooks : public CColective
{
private:
	string m_Isbn = "ISBN-";  //�鱾Isbn��
	int njudge;//�ж�Ibsn��Ϸ���
public:
	CBooks();//�޲ι��캯��
	CBooks(int Id, string Name, string Press, string Price, string Page); //�вι��캯��
	~CBooks();
	bool Judge(string OtherProperties);

	//��ʾ�鱾��Ϣ
	virtual void showInfo();
	//��ȡ�鱾����
	virtual string getClass();
	//������������
	virtual void SetOtherProperties(string Isbn);
	virtual string GetOtherProperties();//�����������
};