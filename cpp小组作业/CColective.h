#ifndef CCOLECTIVE
#define CCOLECTIVE
//�鱾����
#include <iostream>
#include <string>
using namespace std;
class CColective
{
public:
	int m_Id;//�鱾���
	string m_Name;  //�鱾����
	string m_Press; //������
	string m_Price; //ͼ��۸�
	string m_Page;  //ͼ��ҳ��

	virtual void showInfo() = 0;	//��ʾ�鱾��Ϣ,��̬
	virtual string getClass() = 0;  //��ȡ�鱾����
	virtual void SetOtherProperties(string Other_Properties) = 0;//������������
	virtual string GetOtherProperties() = 0;//�����������
	virtual bool Judge(string OtherProperties) = 0;
};
#endif;
