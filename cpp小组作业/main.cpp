// Library Management System2.0.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
//"C/C++������ƽ̡̳����������ֲᣨ�����棩", "�й����ų��漯�ţ����ӹ�ҵ������", "978-7-121-33047-6", "47.00", "356"
//"������������ͳ��","�й����ų��漯�ţ������ʵ������","978-7-115-53563-4","45","226"
#include <iostream>
#include "CLIbraryManager.h"
#include "CBook.h"//һ��ͼ����
#include "CColective.h"//��������

int main()
{
    //ʵ�������������
    CLIbraryManager LM;

    int choice = 0;//�����û���ѡ��
    while (true)
    {
        //����չʾ�˵�����
        LM.Show_Menu();

        cout << "����������ѡ��" << endl;
        cin >> choice;//�����û���ѡ��

        switch (choice)
        {
        case 0:  //�˳�ϵͳ
            LM.ExitSystem();//�˳��ӿ�
            break;
        case 1:  //�����鱾
            LM.Add_Book();
            break;
        case 2:  //��ʾ�鱾
            LM.show_BookArray();
            break;
        case 3:  //ɾ���鱾
            LM.delete_Book();
            break;
        case 4:  //�����鱾
            LM.find_Book();
            break;
        case 5:  //�鱾����
            LM.sort_BookArray();
            break;
        case 6:  //����鱾
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
