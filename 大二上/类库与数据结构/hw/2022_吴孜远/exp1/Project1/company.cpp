#include <iostream>
using namespace std;

#include "company.h"

void Company::inputEmployee()
{
	Employee newEmployee; 
	newEmployee.input(); //input�����Ѿ���װ����

	while (newEmployee.getName() != "*") //��name����"*"ʱֹͣѭ��
	{
		empContainer.addHead(newEmployee); //��newEmployee�е����ݴ�������
		newEmployee.input(); //����newEmployee�е�����
	}

	
	//please implement this
}
