#include <iostream>
using namespace std;

#include "company.h"

void Company::inputEmployee()
{
	Employee newEmployee;
	newEmployee.input();

	while (newEmployee.getName() != "*")
	{
		empContainer.addHead(newEmployee);
		newEmployee.input();
	}

	
}

void Company::findBestPaid()
{
	ListTemp<Employee>::Iterator itr; //������������ע�ⴴ����ʽ��
	
	bestPaid = *empContainer.Begin(); //�Ƚ���һ��employee��ֵ��bestpaid
    for (itr = empContainer.Begin(); !(itr == empContainer.End()); itr++) //��������
    {
		if (*itr > bestPaid){
			bestPaid = *itr;
		}
	}
}

void Company::printBestPaid() const
{
	cout << "The best-paid employee and gross pay: " << endl;
	bestPaid.output();
} // printBestPaid
