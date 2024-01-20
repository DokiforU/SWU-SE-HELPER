#include "company.h"
#include <iostream>
using namespace std;

void Company::inputEmployeeHead(int total_num)
{
	//please implement this
	//ѭ��input������Ϊ����Ĳ���total_num
	for (int i = 0; i < total_num; i++) {
		srand((unsigned int)time(NULL));//��ʼ���������������
		//�õ�ǰʱ�䣨ת��Ϊ�޷�����������Ϊseed
		int id = i + 1; //id�Ͱ�˳�������ˣ�����ν��
		Employee newEmployee;
		newEmployee.input(id);
		container.addHead(newEmployee);//��addHead������ͷ����
	}
}

void Company::inputEmployeeTail(int total_num)
{
	//please implement this
	for (int i = 0; i < total_num; i++) {
		srand((unsigned int)time(NULL));//��ʼ���������������
		//�õ�ǰʱ�䣨ת��Ϊ�޷�����������Ϊseed
		int id = i + 1;
		Employee newEmployee;
		newEmployee.input(id);
		container.addTail(newEmployee);
	}

}

void Company::findBestPaid()
{
	bestPaid = Employee();
	ListTemp<Employee>::Iterator curr = container.Begin();
	while (!(curr == container.End()))
	{
		if (*curr > bestPaid)
			bestPaid = *curr;
		curr++;
	}
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee and gross pay: " << endl;
	bestPaid.output();
} // printBestPaid
