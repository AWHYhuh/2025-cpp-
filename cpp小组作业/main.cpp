// Library Management System2.0.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//"C/C++程序设计教程——面向对象分册（第三版）", "中国工信出版集团，电子工业出版社", "978-7-121-33047-6", "47.00", "356"
//"概率论与数理统计","中国工信出版集团，人民邮电出版社","978-7-115-53563-4","45","226"
#include <iostream>
#include "CLIbraryManager.h"
#include "CBook.h"//一般图书类
#include "CColective.h"//管理者类

int main()
{
    //实例化管理这对象
    CLIbraryManager LM;

    int choice = 0;//接收用户的选择
    while (true)
    {
        //调用展示菜单函数
        LM.Show_Menu();

        cout << "情输入您的选择：" << endl;
        cin >> choice;//接收用户的选择

        switch (choice)
        {
        case 0:  //退出系统
            LM.ExitSystem();//退出接口
            break;
        case 1:  //增加书本
            LM.Add_Book();
            break;
        case 2:  //显示书本
            LM.show_BookArray();
            break;
        case 3:  //删除书本
            LM.delete_Book();
            break;
        case 4:  //查找书本
            LM.find_Book();
            break;
        case 5:  //书本排序
            LM.sort_BookArray();
            break;
        case 6:  //清空书本
            LM.clear_Txt();
            break;
        default:
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}
