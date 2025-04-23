#include "CLIbraryManager.h"
#include<cstdlib>
using namespace std;
CLIbraryManager::CLIbraryManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打开文件

	//文件不存在
	if (!ifs.is_open())//ifs.is_open()返回值为bool类型，如果能打开返回true
	{
		this->m_isFile = false;//文件不存在，将m_isFile赋值为false
		this->m_BookNum = 0;//初始化书的本数
		this->m_BookArray = NULL;//初始化书数组指针
		ifs.close();
		return;
	}

	//文件存在，但数据为空
	char ch;
	ifs >> ch;//传入空字符
	if (ifs.eof())//如果文件是空，则返回true
	{
		this->m_isFile = false;//文件存在，但无数据，将m_isFile赋值为false
		this->m_BookNum = 0;//初始化书的本数
		this->m_BookArray = NULL;//初始化书数组指针
		ifs.close();
		return;
	}

	//文件存在且不为空
	else if (!ifs.eof())
	{
		this->m_isFile = true;//文件存在且有数据，将m_isFile赋值为true
		int num = this->Get_BookNum();
		this->m_BookNum = num;
		this->m_BookArray = new CColective * [this->m_BookNum];
		//将读取的数据存入数组中
		this->init_Book();
	}
}

//显示菜单函数
void CLIbraryManager::Show_Menu()
{
	cout << "————————————————————————" << endl;
	cout << "——————  欢迎使用图书管理系统！——————" << endl;
	cout << "———————— 0.退出管理程序 ————————" << endl;
	cout << "———————— 1.增加书本信息 ————————" << endl;
	cout << "———————— 2.显示书本信息 ————————" << endl;
	cout << "———————— 3.删除书本信息 ————————" << endl;
	cout << "———————— 4.查找书本信息 ————————" << endl;
	cout << "———————— 5.按照编号排序 ————————" << endl;
	cout << "———————— 6.清空所有文档 ————————" << endl;
	cout << "————————————————————————" << endl;
	cout << endl;

}

//退出程序函数
void CLIbraryManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

//增加书函数
void CLIbraryManager::Add_Book()
{
	cout << "请输入添加书本的数量：" << endl;
	int add_number = 0;
	cin >> add_number;//接收用户输入的大小
	if (add_number > 0) //输入大于零才执行增加操作
	{
		//执行添加
		int newSize = this->m_BookNum + add_number;//计算需要开辟的空间大小，新的数量 = 原来记录的 + 新输入的
		CColective** newspace = new CColective * [newSize];//分配空间

		//如果原来的数组不为空，则添加到新开辟的数组中
		if (this->m_BookArray != NULL)
		{
			for (int i = 0; i < this->m_BookNum; i++)
			{
				newspace[i] = this->m_BookArray[i];
			}
		}

		//添加新数据
		for (int i = 0; i < add_number; i++)
		{
			int d_Id = 0;//书本编号
			string d_Name;  //书本名字
			string d_Press; //出版社
			string d_Price; //图书价格
			string d_Page_Words;  //图书页数或字数
			string d_OtherProperties;//书的其他属性(Isbn,Issn,Format)

			cout << "请选择要添加的类型：" << endl;
			cout << "1.一般图书" << endl;
			cout << "2.杂志" << endl;
			cout << "3.电子书" << endl;
			int select;//用户的选择
			cin >> select;

			CColective* book = NULL;//创建book形参
			cout << "请输入第" << i + 1 << "本书编号：" << endl;
			cin >> d_Id;
			cout << endl;
			cout << "请输入第" << i + 1 << "本书书名：" << endl;
			cin >> d_Name;
			cout << endl;
			cout << "请输入第" << i + 1 << "本书出版社：" << endl;
			cin >> d_Press;
			cout << endl;
			cout << "请输入第" << i + 1 << "本书价格：" << endl;
			cin >> d_Price;
			cout << endl;

			switch (select)
			{
			case 1:
			{
				// 注意: 一下代码是判断ISBN码是否合法，现已将判断部分注释
				cout << "请输入第" << i + 1 << "本书页数：" << endl;//一般图书的页数
				cin >> d_Page_Words;
				cout << endl;
				book = new CBooks(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
				cout << "请输入第" << i + 1 << "本书Ibsn号：" << endl;
				cin >> d_OtherProperties;

				//do
				//{
				//	cout << "请输入第" << i + 1 << "本书页数：" << endl;//一般图书的页数
				//	cin >> d_Page_Words;
				//	cout << endl;
				//	book = new CBooks(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
				//	cout << "请输入第" << i + 1 << "本书Ibsn号：" << endl;
				//	cin >> d_OtherProperties;
				//	if (!book->Judge(d_OtherProperties)) {
				//		cout << "ISBN码不合法！" << endl
				//			<< "请重新输入：" << endl << endl;
				//		cout << "请输入第" << i + 1 << "本书编号：" << endl;
				//		cin >> d_Id;
				//		cout << endl;
				//		cout << "请输入第" << i + 1 << "本书书名：" << endl;
				//		cin >> d_Name;
				//		cout << endl;
				//		cout << "请输入第" << i + 1 << "本书出版社：" << endl;
				//		cin >> d_Press;
				//		cout << endl;
				//		cout << "请输入第" << i + 1 << "本书价格：" << endl;
				//		cin >> d_Price;
				/*	}
				} while (!book->Judge(d_OtherProperties));*/
				cout << endl;
				book->SetOtherProperties(d_OtherProperties);
				break;
			}

			case 2:
			{
				cout << "请输入第" << i + 1 << "本书页数：" << endl;
				cin >> d_Page_Words;
				cout << endl;
				book = new CMagazine(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
				cout << "请输入第" << i + 1 << "本书Issn号：" << endl;
				cin >> d_OtherProperties;
				cout << endl;
				book->SetOtherProperties(d_OtherProperties);
				break;
			}

			case 3:
			{
				cout << "请输入第" << i + 1 << "本书字数：" << endl;//电子书的字数
				cin >> d_Page_Words;
				cout << endl;
				book = new CEBook(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
				cout << "请输入第" << i + 1 << "本书格式：" << endl;//电子书的格式
				cout << "电子书的格式有：txt、pdf、epub、azw3、kindle" << endl;
				cin >> d_OtherProperties;
				cout << endl;
				book->SetOtherProperties(d_OtherProperties);
				break;
			}

			default:
				break;
			}
			//将创建好的书本增加到数组中
			newspace[this->m_BookNum + i] = book;
		}
		delete[]this->m_BookArray;//释放原来的空间
		this->m_BookArray = newspace;//将新的空间指向m_BookArrary
		this->m_BookNum = newSize;//更新新的书本数量

		//保存数据到文件中
		//this->delete_txt();
		this->Save();
		this->m_isFile = true;//添加成功，则说明文件创建成功且数据不为空
		cout << "成功添加" << add_number << "本新书" << endl;

	}
	else
	{
		cout << "输入的数据有误！" << endl;
	}
	system("pause");
	system("cls");
}

//保存书本数据
void CLIbraryManager::Save()
{
	ofstream ofs;//定义
	ofs.open(FILENAME, ios::out);//用输出的方式文件——写文件
	//将每本书的数据写入到文件中

	for (int i = 0; i < this->m_BookNum; i++)
	{
		ofs << this->m_BookArray[i]->m_Id << " "
			<< this->m_BookArray[i]->m_Name << " "
			<< this->m_BookArray[i]->m_Press << " "
			<< this->m_BookArray[i]->m_Price << " "
			<< this->m_BookArray[i]->m_Page << " "
			<< this->m_BookArray[i]->GetOtherProperties() << endl;
	}
	//关闭文件
	ofs.close();
}

//获取文件中已有书本的数量
int CLIbraryManager::Get_BookNum()
{
	int d_Id = 0;//书本编号
	string d_Name;  //书本名字
	string d_Press; //出版社
	string d_Price; //图书价格
	string d_Page_Words;  //图书页数或字数
	string d_OtherProperties;//书的其他属性(Isbn,Issn,Format)

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int num = 0;
	while (ifs >> d_Id && ifs >> d_Name && ifs >> d_Press && ifs >> d_Price && ifs >> d_Page_Words && ifs >> d_OtherProperties)
	{
		num++;
	}

	return num;
}

//初始化文件中已有书本数组、数量
void CLIbraryManager::init_Book()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int d_Id;//书本编号
	string d_Name;  //书本名字
	string d_Press; //出版社
	string d_Price; //图书价格
	string d_Page_Words;  //图书页数或字数
	string d_OtherProperties;//书的其他属性(Isbn,Issn,Format)

	int index = 0;//记录数组位置
	while (ifs >> d_Id && ifs >> d_Name && ifs >> d_Press && ifs >> d_Price && ifs >> d_Page_Words && ifs >> d_OtherProperties)
	{
		CColective* book = NULL;

		//截取读取的其他属性的前4个字符串。如果为"ISBN"，则说明这一行数据是一般图书
		if (d_OtherProperties.substr(0, 4) == "ISBN")
		{
			book = new CBooks(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
			book->SetOtherProperties(d_OtherProperties.substr(5, d_OtherProperties.size() - 1));//写错了
		}

		//截取读取的其他属性的前4个字符串。如果为"ISSN"，则说明这一行数据是杂志
		else if (d_OtherProperties.substr(0, 4) == "ISSN")
		{
			book = new CMagazine(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
			book->SetOtherProperties(d_OtherProperties.substr(5, d_OtherProperties.size() - 1));//写错了
		}

		//否则就是电子书类
		else
		{
			book = new CEBook(d_Id, d_Name, d_Press, d_Price, d_Page_Words);
			book->SetOtherProperties(d_OtherProperties);
		}

		//将读取的书本信息存入书本数组中
		this->m_BookArray[index] = book;
		index++;
	}

	ifs.close();//关闭文件
}

//显示函数
void CLIbraryManager::show_BookArray()
{
	if (this->m_BookNum == 0)
	{
		cout << "无书本信息！" << endl;
	}
	else
	{
		for (int i = 0; i < this->Get_BookNum(); i++)
		{
			this->m_BookArray[i]->showInfo();
			cout << endl;//利用函数的多态，调用派生类显示函数
		}
	}

	system("pause");
	system("cls");

}

//查找函数
void CLIbraryManager::find_Book()
{
	if (this->m_BookNum == 0)
	{
		cout << "无书本信息！" << endl;
	}
	else
	{
		cout << "可通过以下查找：" << endl;
		cout << "1.书本编号" << endl
			<< "2.书本名称" << endl;
		int select;//用户查找选择
		cin >> select;
		int Id = 0;
		string book_name = "";
		switch (select)
		{
		case 1:
		{
			cout << "请输入书本编号：" << endl;
			cin >> Id;
			for (int i = 0; i < this->m_BookNum; i++)
			{
				if (i == this->m_BookNum - 1 && this->m_BookArray[i]->m_Id != Id) {
					cout << "未查询到该书信息！" << endl;
				}
				if (this->m_BookArray[i]->m_Id == Id) {
					cout << "该书本信息为：" << endl;
					this->m_BookArray[i]->showInfo();
					cout << endl;
					break;
				}
			}
			break;
		}

		case 2:
		{
			cout << "请输入书本名称：" << endl;
			cin >> book_name;
			for (int i = 0; i < this->m_BookNum; i++)
			{
				if (i == this->m_BookNum - 1 && this->m_BookArray[i]->m_Name != book_name) {
					cout << "未查询到该书信息！" << endl;
				}
				if (this->m_BookArray[i]->m_Name == book_name) {
					cout << "该书本信息为：" << endl;
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

//清空文档函数
void CLIbraryManager::clear_Txt()
{
	if (!this->m_isFile)
	{
		cout << "文件不存在！" << endl;
	}
	else
	{
		int select;
		cout << "是否确定清空所有文档？" << endl
			<< "1.是" << endl
			<< "2.否" << endl;
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
			cout << "文档已清空！" << endl;
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

//通过Id判断该书是否存在，存在则返回数组下标
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
//通过name判断该书是否存在，存在则返回数组下标（重载）
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

//删除书本信息
void CLIbraryManager::delete_Book()
{
	//判断文件或记录是否存在
	if (!this->m_isFile)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		int Id;
		string name;
		int select;//接収用户选择
		int index = -1;//接收返回的数组下标

		cout << "请输入通过什么删除：" << endl
			<< "1.书本编号" << endl
			<< "2.书本名称" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
		{
			cout << "请输入书本编号：" << endl;
			cin >> Id;
			index = this->isBook(Id);
			break;
		}

		case 2:
		{
			cout << "请输入书本名称：" << endl;
			cin >> name;
			index = this->isBook(name);
			break;
		}
		default:
			break;
		}
		//若index的值不为-1，则说明该书存在
		if (index != -1)
		{
			cout << "该书本信息为：" << endl;
			this->m_BookArray[index]->showInfo();//显示该书信息
			cout << endl << endl << "是否确认删除该书信息？" << endl
				<< "1.是" << endl
				<< "2.否" << endl;
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
				cout << "删除成功！" << endl;
				this->Save();
				break;
			}
			case 2:
				cout << "已取消删除！" << endl;
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "删除失败，无该书信息！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序实现
void CLIbraryManager::sort_BookArray()
{
	if (!this->m_isFile)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < this->m_BookNum; i++)
		{
			for (int j = 0; j < this->m_BookNum; j++)
			{
				if (this->m_BookArray[i]->m_Id < this->m_BookArray[j]->m_Id)
				{
					CColective* Tbook = this->m_BookArray[i];//创建Tbook中间变量
					this->m_BookArray[i] = this->m_BookArray[j];
					this->m_BookArray[j] = Tbook;
				}
			}
		}
		this->Save();
		cout << "排序成功！" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
CLIbraryManager::~CLIbraryManager()
{
	if (this->m_BookArray != NULL)
	{
		delete[] this->m_BookArray;
		this->m_BookArray = NULL;
	}
}