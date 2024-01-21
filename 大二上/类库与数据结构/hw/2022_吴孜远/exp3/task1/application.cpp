#include "application.h"
#include <iostream>
using namespace std;

#define NULL 0

//board
int maze[8][8] = {  {0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0},
					{0, 0, 0, 0, 0, 0, 0, 0} };

void Application::initialize() {}

//�ӵ�һ�дӵ�һ����ʼ����������,����ֻ���ҳ�����һ���ʺ����(0,0)�����
Position Application::getStartPosition() 
{
	//return Position(0, 0);
	static int c = 0; //��̬������ֻ�е�һ�ε��û��ʼ��
	return Position(0, c++); //ÿһ�ε��ô˺���������c��1��Ҳ���ǲ���Ų��ʼλ��
}

bool Application::isValid(const Position& p) //ֻ��Ϊ0����Ч
{
	int row = p.getRow();
	int column = p.getColumn();
	//��������Χ����ֵΪ0���ſ��Է���
	return (row >= 0 && row <= 7) && (column >= 0 && column <= 7) && (maze[row][column] == 0);
}

void Application::progress(const Position& p) //ÿ��һ���ʺ󣬱���Լ�Ϊ9������бΪ��ǰ�ʺ���������
{
	//����Ƿ�Ϊ0������0�����Ϊ��ǰ������ֵ����ڶ��еĻʺ��ȫ��Ϊ2�������еĻʺ��ȫ��ΪΪ3
	//������0���ǾͲ��䣬��Ϊ�Ѿ��������ʺ������
	//���п��ƣ�
	for (int i = 0; i <= 7; i++) {
		if (maze[p.getRow()][i] == 0) {
			maze[p.getRow()][i] = p.getRow() + 1; //��ռ��
		}
	}

	for (int i = 0; i <= 7; i++) {
		if (maze[i][p.getColumn()] == 0) {
			maze[i][p.getColumn()] = p.getRow() + 1; //��ռ��
		}
	}
	//б�߿���
	//���Խ���
	int row, column;//�ҵ����
	//���Խ���ռ��
	if (p.getRow() > p.getColumn()) {
		row = p.getRow() - p.getColumn();
		column = p.getColumn() - p.getColumn();
	}
	else {
		row = p.getRow() - p.getRow();
		column = p.getColumn() - p.getRow();
	}
	while (row <= 7 && column <= 7) { //�κ�һ�ߵ��߽綼���ǽ���
		if (maze[row][column] == 0) {
			maze[row][column] = p.getRow()+1;
		}
		row++;
		column++;
	}

	//���Խ���
	if ((p.getRow() + p.getColumn()) <= 3) {
		row = p.getRow() - p.getRow();
		column = p.getColumn() + p.getRow();
	}
	else {
		row = p.getRow() - (7 - p.getColumn());
		column = 7;
	}
	
	while (row <= 7 && column >= 0) {
		if (maze[row][column] == 0) {
			maze[row][column] = p.getRow() + 1;
		}
		row++;
		column--;
	}
	maze[p.getRow()][p.getColumn()] = 9;//�ʺ�����λ�ñ��Ϊ9
}

bool Application::success(const Position& p)
{
	if (p.getRow() == 7) { //����ǰλ��Ϊ�����У���˵������ط��Ѿ������˻ʺ�Ҳ���ǳɹ���
		return true; 
	}
	else {
		return false;
	}
	/*int queennum = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (maze[i][j] == 9) {
				queennum++;
			}
		}
	}
	return queennum == 8;*/
}

//����ʱ����ʱ���Ե�pos���Ϊ0,��Ҫ����ǰ�ʺ�ռ�еĸ������أ�ȫ������һ�飬���ڵ�ǰ������ȫ���ĳ�0
void Application::goBack(const Position& p) 
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (maze[i][j] == p.getRow()+1) {
				maze[i][j] = 0;
			}
		}
	}
	maze[p.getRow()][p.getColumn()] = 0;
}

void Application::print() //��ӡ
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) {
			if (maze[i][j] != 9) { //�����޸�maze������Ϊ֮��ÿ�ҳ�һ�ν����Ҫprint����ֹ����ʱmaze���޸���
				cout << 0 << " ";
			}
			else {
				cout << maze[i][j] << " ";
			}
			
		}
		cout << endl;
	}
}



//======================================================================
struct itrPosition 
{
	int row;
	int column;
	int turn;
};

//application iterator
Application::Iterator::Iterator() 
{
	currItrPosPtr = NULL; //��������ָ��ָ���
}

Application::Iterator::Iterator(const Position& currPos) //����Ϊ��λ�������õ�����ָ����һ��
{
	itrPosition* p = new itrPosition;
	p->row = currPos.getRow(); 
	p->column = 0;
	p->turn = 0;
	currItrPosPtr = p; //��������ָ��ָ�����������ʱ������ΪitrPosition*
}

Position Application::Iterator::getNextPosition() //����Ҫ�ĳɰ����н��б���
{
	int row = ((itrPosition*)currItrPosPtr)->row;
	int column = ((itrPosition*)currItrPosPtr)->column;
	int turn = ((itrPosition*)currItrPosPtr)->turn;
	//int turn = ((itrPosition*)currItrPosPtr)->turn;
	row++; //ת����һ�У������浽�������У���������ÿ�ε���������һ��
	column = turn; //��������¼����
	turn++; //��������1
	((itrPosition*)currItrPosPtr)->turn = turn; //��������ֵÿ�ζ�Ҫ����
	((itrPosition*)currItrPosPtr)->column = column; //��������
	return Position(row, column); //return the new position

}

bool Application::Iterator::noNextPosition() //��ǰ�г������
{
	return ((itrPosition *)currItrPosPtr)->turn > 7;
}

Application::Iterator::~Iterator()
{
	delete (itrPosition*)currItrPosPtr;
}