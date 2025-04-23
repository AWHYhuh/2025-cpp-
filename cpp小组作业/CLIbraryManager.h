#pragma once //��ֹͷ�ļ��ظ�����
//������
//�������ݣ�
//���û��Ĺ�ͨ�˵�����
//���鱾������ɾ����Ȳ���
//���ļ��Ķ�д����

#include "CColective.h"
#include "CBook.h"		//һ��ͼ��
#include "CEBook.h"		//������
#include "CMagazine.h"	//��־

#include<cstdlib>		//system ����ȷ	
#include <fstream>		//�ļ���ͷ�ļ�
#define FILENAME "BookFile.txt"

using namespace std;

class CLIbraryManager
{
public:
	CLIbraryManager();//���캯��

	//�˵���ʾ
	void Show_Menu();

	//0.�˳�ϵͳ
	void ExitSystem();

	//1.���ʵ��
	int m_BookNum;//��¼�鱾������
	CColective** m_BookArray;//�鱾����ָ��
	void Add_Book();

	//�����ļ�
	void Save();

	//���ñ�־�ж��ʼ�ļ��Ƿ����
	bool m_isFile;

	//ͳ���ļ��������鱾����
	int Get_BookNum();

	//��ʼ���ļ��������鱾���顢����
	void init_Book();

	//2.��ʾ�鱾
	void show_BookArray();

	//4.����ʵ��
	void find_Book();//����

	//6.���txtʵ��
	void clear_Txt();

	//3.ɾ���鱾��Ϣʵ��
	void delete_Book();//����
	int isBook(int Id);
	int isBook(string name);

	//5.�����鱾�������
	void sort_BookArray();

	~CLIbraryManager();//��������
};


