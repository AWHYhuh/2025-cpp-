#include "CLIbraryManager.h"
#include<cstdlib>
using namespace std;
CLIbraryManager::CLIbraryManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	//�ļ�������
	if (!ifs.is_open())//ifs.is_open()����ֵΪbool���ͣ�����ܴ򿪷���true
	{
		this->m_isFile = false;//�ļ������ڣ���m_isFile��ֵΪfalse
		this->m_BookNum = 0;//��ʼ����ı���
		this->m_BookArray = NULL;//��ʼ��������ָ��
		ifs.close();
		return;
	}

	//�ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch;//������ַ�
	if (ifs.eof())//����ļ��ǿգ��򷵻�true
	{
		this->m_isFile = false;//�ļ����ڣ��������ݣ���m_isFile��ֵΪfalse
		this->m_BookNum = 0;//��ʼ����ı���
		this->m_BookArray = NULL;//��ʼ��������ָ��
		ifs.close();
		return;
	}

	//�ļ������Ҳ�Ϊ��
	else if (!ifs.eof())
	{
		this->m_isFile = true;//�ļ������������ݣ���m_isFile��ֵΪtrue
		int num = this->Get_BookNum();
		this->m_BookNum = num;
		this->m_BookArray = new CColective * [this->m_BookNum];
		//����ȡ�����ݴ���������
		this->init_Book();
	}
}

//��ʾ�˵�����
void CLIbraryManager::Show_Menu()
{
	cout << "������������������������������������������������" << endl;
	cout << "������������  ��ӭʹ��ͼ�����ϵͳ��������������" << endl;
	cout << "���������������� 0.�˳�������� ����������������" << endl;
	cout << "���������������� 1.�����鱾��Ϣ ����������������" << endl;
	cout << "���������������� 2.��ʾ�鱾��Ϣ ����������������" << endl;
	cout << "���������������� 3.ɾ���鱾��Ϣ ����������������" << endl;
	cout << "���������������� 4.�����鱾��Ϣ ����������������" << endl;
	cout << "���������������� 5.���ձ������ ����������������" << endl;
	cout << "���������������� 6.��������ĵ� ����������������" << endl;
	cout << "������������������������������������������������" << endl;
	cout << endl;

}

//�˳�������
void CLIbraryManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//�����麯��
void CLIbraryManager::Add_Book()
{
	cout << "����������鱾��������" << endl;
	int add_number = 0;
	cin >> add_number;//�����û�����Ĵ�С
	if (add_number > 0) //����������ִ�����Ӳ���
	{
		//ִ�����
		int newSize = this->m_BookNum + add_number;//������Ҫ���ٵĿռ��С���µ����� = ԭ����¼�� + �������
		CColective** newspace = new CColective * [newSize];//����ռ�

		//���ԭ�������鲻Ϊ�գ�����ӵ��¿��ٵ�������
		if (this->m_BookArray != NULL)
		{
			for (int i = 0; i < this->m_BookNum; i++)
			{
				newspace[i] = this->m_BookArray[i];
			}
		}

		//���������
		for (int i = 0; i < add_number; i++)
		{
			int d_Id = 0;//�鱾���
			string d_Name;  //�鱾����
			string d_Press; //������
			string d_Price; //ͼ��۸�
			string d_Page_Words;  //ͼ��ҳ��������
			string d_OtherProperties;//�����������(Isbn,Issn,Format)

			cout << "��ѡ��Ҫ��ӵ����ͣ�" << endl;
			cout << "1.һ��ͼ��" << endl;
			cout << "2.��־" << endl;
			cout << "3.������" << endl;
			int select;//�û���ѡ��
			cin >> select;

			CColective* book = NULL;//����book�β�
			cout << "�������" << i + 1 << "�����ţ�" << endl;
			cin >> d_Id;
			cout << endl;
			cout << "�������" << i + 1 << "����������" << endl;
			cin >> d_Name;
			cout << endl;
			cout << "�������" << i + 1 << "��������磺" << endl;
			cin >> d_Press;
			cout << endl;
			cout << "�������" << i + 1 << "����۸�" << endl;
			cin >> d_Price;
			cout << endl;

			switch (select)
			{
			case 1:
			{
				// ע��: һ�´������ж�ISBN���Ƿ�Ϸ������ѽ��жϲ���ע��
				cout << "�������" << i + 1 << "����ҳ����" << endl;//һ��ͼ���ҳ��
				cin >> d_Page_Words;
				cout << endl;
				book = new CBooks(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
				cout << "�������" << i + 1 << "����Ibsn�ţ�" << endl;
				cin >> d_OtherProperties;

				//do
				//{
				//	cout << "�������" << i + 1 << "����ҳ����" << endl;//һ��ͼ���ҳ��
				//	cin >> d_Page_Words;
				//	cout << endl;
				//	book = new CBooks(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
				//	cout << "�������" << i + 1 << "����Ibsn�ţ�" << endl;
				//	cin >> d_OtherProperties;
				//	if (!book->Judge(d_OtherProperties)) {
				//		cout << "ISBN�벻�Ϸ���" << endl
				//			<< "���������룺" << endl << endl;
				//		cout << "�������" << i + 1 << "�����ţ�" << endl;
				//		cin >> d_Id;
				//		cout << endl;
				//		cout << "�������" << i + 1 << "����������" << endl;
				//		cin >> d_Name;
				//		cout << endl;
				//		cout << "�������" << i + 1 << "��������磺" << endl;
				//		cin >> d_Press;
				//		cout << endl;
				//		cout << "�������" << i + 1 << "����۸�" << endl;
				//		cin >> d_Price;
				/*	}
				} while (!book->Judge(d_OtherProperties));*/
				cout << endl;
				book->SetOtherProperties(d_OtherProperties);
				break;
			}

			case 2:
			{
				cout << "�������" << i + 1 << "����ҳ����" << endl;
				cin >> d_Page_Words;
				cout << endl;
				book = new CMagazine(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
				cout << "�������" << i + 1 << "����Issn�ţ�" << endl;
				cin >> d_OtherProperties;
				cout << endl;
				book->SetOtherProperties(d_OtherProperties);
				break;
			}

			case 3:
			{
				cout << "�������" << i + 1 << "����������" << endl;//�����������
				cin >> d_Page_Words;
				cout << endl;
				book = new CEBook(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
				cout << "�������" << i + 1 << "�����ʽ��" << endl;//������ĸ�ʽ
				cout << "������ĸ�ʽ�У�txt��pdf��epub��azw3��kindle" << endl;
				cin >> d_OtherProperties;
				cout << endl;
				book->SetOtherProperties(d_OtherProperties);
				break;
			}

			default:
				break;
			}
			//�������õ��鱾���ӵ�������
			newspace[this->m_BookNum + i] = book;
		}
		delete[]this->m_BookArray;//�ͷ�ԭ���Ŀռ�
		this->m_BookArray = newspace;//���µĿռ�ָ��m_BookArrary
		this->m_BookNum = newSize;//�����µ��鱾����

		//�������ݵ��ļ���
		//this->delete_txt();
		this->Save();
		this->m_isFile = true;//��ӳɹ�����˵���ļ������ɹ������ݲ�Ϊ��
		cout << "�ɹ����" << add_number << "������" << endl;

	}
	else
	{
		cout << "�������������" << endl;
	}
	system("pause");
	system("cls");
}

//�����鱾����
void CLIbraryManager::Save()
{
	ofstream ofs;//����
	ofs.open(FILENAME, ios::out);//������ķ�ʽ�ļ�����д�ļ�
	//��ÿ���������д�뵽�ļ���

	for (int i = 0; i < this->m_BookNum; i++)
	{
		ofs << this->m_BookArray[i]->m_Id << " "
			<< this->m_BookArray[i]->m_Name << " "
			<< this->m_BookArray[i]->m_Press << " "
			<< this->m_BookArray[i]->m_Price << " "
			<< this->m_BookArray[i]->m_Page << " "
			<< this->m_BookArray[i]->GetOtherProperties() << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//��ȡ�ļ��������鱾������
int CLIbraryManager::Get_BookNum()
{
	int d_Id = 0;//�鱾���
	string d_Name;  //�鱾����
	string d_Press; //������
	string d_Price; //ͼ��۸�
	string d_Page_Words;  //ͼ��ҳ��������
	string d_OtherProperties;//�����������(Isbn,Issn,Format)

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int num = 0;
	while (ifs >> d_Id && ifs >> d_Name && ifs >> d_Press && ifs >> d_Price && ifs >> d_Page_Words && ifs >> d_OtherProperties)
	{
		num++;
	}

	return num;
}

//��ʼ���ļ��������鱾���顢����
void CLIbraryManager::init_Book()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int d_Id;//�鱾���
	string d_Name;  //�鱾����
	string d_Press; //������
	string d_Price; //ͼ��۸�
	string d_Page_Words;  //ͼ��ҳ��������
	string d_OtherProperties;//�����������(Isbn,Issn,Format)

	int index = 0;//��¼����λ��
	while (ifs >> d_Id && ifs >> d_Name && ifs >> d_Press && ifs >> d_Price && ifs >> d_Page_Words && ifs >> d_OtherProperties)
	{
		CColective* book = NULL;

		//��ȡ��ȡ���������Ե�ǰ4���ַ��������Ϊ"ISBN"����˵����һ��������һ��ͼ��
		if (d_OtherProperties.substr(0, 4) == "ISBN")
		{
			book = new CBooks(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
			book->SetOtherProperties(d_OtherProperties.substr(5, d_OtherProperties.size() - 1));//д����
		}

		//��ȡ��ȡ���������Ե�ǰ4���ַ��������Ϊ"ISSN"����˵����һ����������־
		else if (d_OtherProperties.substr(0, 4) == "ISSN")
		{
			book = new CMagazine(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
			book->SetOtherProperties(d_OtherProperties.substr(5, d_OtherProperties.size() - 1));//д����
		}

		//������ǵ�������
		else
		{
			book = new CEBook(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
			book->SetOtherProperties(d_OtherProperties);
		}

		//����ȡ���鱾��Ϣ�����鱾������
		this->m_BookArray[index] = book;
		index++;
	}

	ifs.close();//�ر��ļ�
}

//��ʾ����
void CLIbraryManager::show_BookArray()
{
	if (this->m_BookNum == 0)
	{
		cout << "���鱾��Ϣ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->Get_BookNum(); i++)
		{
			this->m_BookArray[i]->showInfo();
			cout << endl;//���ú����Ķ�̬��������������ʾ����
		}
	}

	system("pause");
	system("cls");

}

//���Һ���
void CLIbraryManager::find_Book()
{
	if (this->m_BookNum == 0)
	{
		cout << "���鱾��Ϣ��" << endl;
	}
	else
	{
		cout << "��ͨ�����²��ң�" << endl;
		cout << "1.�鱾���" << endl
			<< "2.�鱾����" << endl;
		int select;//�û�����ѡ��
		cin >> select;
		int Id = 0;
		string book_name = "";
		switch (select)
		{
		case 1:
		{
			cout << "�������鱾��ţ�" << endl;
			cin >> Id;
			for (int i = 0; i < this->m_BookNum; i++)
			{
				if (i == this->m_BookNum - 1 && this->m_BookArray[i]->m_Id != Id) {
					cout << "δ��ѯ��������Ϣ��" << endl;
				}
				if (this->m_BookArray[i]->m_Id == Id) {
					cout << "���鱾��ϢΪ��" << endl;
					this->m_BookArray[i]->showInfo();
					cout << endl;
					break;
				}
			}
			break;
		}

		case 2:
		{
			cout << "�������鱾���ƣ�" << endl;
			cin >> book_name;
			for (int i = 0; i < this->m_BookNum; i++)
			{
				if (i == this->m_BookNum - 1 && this->m_BookArray[i]->m_Name != book_name) {
					cout << "δ��ѯ��������Ϣ��" << endl;
				}
				if (this->m_BookArray[i]->m_Name == book_name) {
					cout << "���鱾��ϢΪ��" << endl;
					this->m_BookArray[i]->showInfo();
					cout << endl;
					break;
				}
			}
			break;
		}

		default:
			break;
		}
	}
	system("pause");
	system("cls");
}

//����ĵ�����
void CLIbraryManager::clear_Txt()
{
	if (!this->m_isFile)
	{
		cout << "�ļ������ڣ�" << endl;
	}
	else
	{
		int select;
		cout << "�Ƿ�ȷ����������ĵ���" << endl
			<< "1.��" << endl
			<< "2.��" << endl;
		cin >> select;
		ofstream ofs;
		switch (select)
		{
		case 1:
		{
			ofs.open(FILENAME, ios::out | ios::trunc);
			ofs.close();
			delete[]this->m_BookArray;
			this->m_BookArray = NULL;
			this->m_BookNum = 0;
			this->m_isFile = false;
			cout << "�ĵ�����գ�" << endl;
			break;
		}

		case 2:
			break;
		default:
			break;
		}
	}

	system("pause");
	system("cls");
}

//ͨ��Id�жϸ����Ƿ���ڣ������򷵻������±�
int CLIbraryManager::isBook(int Id)
{
	int index = -1;
	for (int i = 0; i < this->m_BookNum; i++)
	{
		if (this->m_BookArray[i]->m_Id == Id) {
			index = i;
			break;
		}
	}
	return index;
}
//ͨ��name�жϸ����Ƿ���ڣ������򷵻������±꣨���أ�
int CLIbraryManager::isBook(string name)
{
	int index = -1;
	for (int i = 0; i < this->m_BookNum; i++)
	{
		if (this->m_BookArray[i]->m_Name == name) {
			index = i;
			break;
		}
	}
	return index;
}

//ɾ���鱾��Ϣ
void CLIbraryManager::delete_Book()
{
	//�ж��ļ����¼�Ƿ����
	if (!this->m_isFile)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		int Id;
		string name;
		int select;//�Ӆ��û�ѡ��
		int index = -1;//���շ��ص������±�

		cout << "������ͨ��ʲôɾ����" << endl
			<< "1.�鱾���" << endl
			<< "2.�鱾����" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			cout << "�������鱾��ţ�" << endl;
			cin >> Id;
			index = this->isBook(Id);
			break;
		}

		case 2:
		{
			cout << "�������鱾���ƣ�" << endl;
			cin >> name;
			index = this->isBook(name);
			break;
		}
		default:
			break;
		}
		//��index��ֵ��Ϊ-1����˵���������
		if (index != -1)
		{
			cout << "���鱾��ϢΪ��" << endl;
			this->m_BookArray[index]->showInfo();//��ʾ������Ϣ
			cout << endl << endl << "�Ƿ�ȷ��ɾ��������Ϣ��" << endl
				<< "1.��" << endl
				<< "2.��" << endl;
			cin >> select;

			switch (select)
			{
			case 1:
			{
				for (int i = index; i < this->m_BookNum - 1; i++)
				{
					this->m_BookArray[i] = this->m_BookArray[i + 1];
				}
				this->m_BookNum--;
				cout << "ɾ���ɹ���" << endl;
				this->Save();
				break;
			}
			case 2:
				cout << "��ȡ��ɾ����" << endl;
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "ɾ��ʧ�ܣ��޸�����Ϣ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ʵ��
void CLIbraryManager::sort_BookArray()
{
	if (!this->m_isFile)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < this->m_BookNum; i++)
		{
			for (int j = 0; j < this->m_BookNum; j++)
			{
				if (this->m_BookArray[i]->m_Id < this->m_BookArray[j]->m_Id)
				{
					CColective* Tbook = this->m_BookArray[i];//����Tbook�м����
					this->m_BookArray[i] = this->m_BookArray[j];
					this->m_BookArray[j] = Tbook;
				}
			}
		}
		this->Save();
		cout << "����ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//��������
CLIbraryManager::~CLIbraryManager()
{
	if (this->m_BookArray != NULL)
	{
		delete[] this->m_BookArray;
		this->m_BookArray = NULL;
	}
}