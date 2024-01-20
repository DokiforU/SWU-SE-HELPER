#include "application.h"
#include <iostream>

using namespace std;

#define NULL 0

//board
int maze[8][8] = {  {0, 0, 0, 0, 0, 0, 0, 0,} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} ,
					{0, 0, 0, 0, 0, 0, 0, 0} };

void Application::initialize() {}

Position Application::getStartPosition()
{
	return Position(0, 0);
}

bool Application::isValid(const Position& p)
{
	int row = p.getRow();
	int column = p.getColumn();
	int newrow = p.getRow();
	int newcolumn = p.getColumn();
	int min = 0;
	//�¼ӵģ�
	bool noqueenrow= true;
	bool noqueencolumn = true;
	bool noqueenoblique = true;
	for (int i = 0; i < 8; i++ ) {
		if (maze[i][p.getColumn()] == 1) {
			noqueenrow = false;
		}
		if (maze[p.getRow()][i] == 1) {
			noqueencolumn = false;
		}
	}
	//��б��
	while( newrow < 7 && newcolumn < 7 ) {
		newrow++;
		newcolumn++;
	}
	if (newrow < newcolumn) {
		min = newrow;
	}
	else {
		min = newcolumn;
	}
	for (int i = 0; i< min+1; i++) {
		if (maze[newrow - i][newcolumn - i] == 1) {
			noqueenoblique = false;
			break;
		}
	}
	//��б��
	//���µ���p��λ��
	newrow = p.getRow();
	newcolumn = p.getColumn();
	while (newrow < 7 && newcolumn < 7) {
		newrow--;
		newcolumn++;
	}
	min = newcolumn - newrow;
	for (int i = 0; i < min+1; i++) {
		if (maze[newrow + i][newcolumn - i] == 1) {
			noqueenoblique = false;
			break;
		}
	}
	/*return (row >= 0 && row <= 7) && (column >= 0 && column <= 12) && maze[row][column] == 1;*/
	return (row >= 0 && row <= 7) && (column >= 0 && column <= 7) && maze[row][column] == 0 && noqueenrow == true && noqueencolumn == true && noqueenoblique == true;
			
	
}

void Application::progress(const Position& p)//���߹��ĵط������ı�, �ʺ���������������Ϊ�ʺ�1��
{
	maze[p.getRow()][p.getColumn()] = 1;
}

bool Application::success(const Position& p)//�ж��Ƿ�ɹ�
{
	int queennum = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (maze[i][j] == 1) {
				queennum++;
			}
		}
	}
	/*return p.getRow() == 7 && p.getColumn() == 12;*/
	return queennum == 8;
}

void Application::goBack(const Position& p) //�޸ĸ�λ�õ�ֵ
{

	/*maze[p.getRow()][p.getColumn()] = 1;*/
	maze[p.getRow()][p.getColumn()] = 0;
}

void Application::print()
{
	for (int i = 0; i < 8; i++)
	{
		/*for (int j = 0; j < 13; j++)*/
		for (int j = 0; j < 8; j++)
			cout << maze[i][j] << " ";
		cout << endl;
	}
}



//======================================================================
struct itrPosition
{
	int row;
	int column;
	//int turn;//����
	int count;
};

//application iterator
Application::Iterator::Iterator()
{
	currItrPosPtr = NULL;
}

Application::Iterator::Iterator(const Position& currPos)//�Ѳ�����λ�úͳ�ʼ����0����ָ��
{
	itrPosition* p = new itrPosition;
	p->row = currPos.getRow();
	p->column = currPos.getColumn();
	/*p->turn = 0;*/
	p->count = 0;
	currItrPosPtr = p;
}

Position Application::Iterator::getNextPosition()//���ݺ�������ļ��㣬������һ����Ӧ�����λ�ã�û����һ�Σ�����ͻ�+1
{
	int row = ((itrPosition*)currItrPosPtr)->row;
	int column = ((itrPosition*)currItrPosPtr)->column;
	/*int turn = ((itrPosition*)currItrPosPtr)->turn;*/
	int count = ((itrPosition*)currItrPosPtr)->count;
	//if (turn == 0)//������
	//{
	//	column++;
	//	turn++;
	//}
	//else if (turn == 1)//������
	//{
	//	row++;
	//	turn++;
	//}
	//else if (turn == 2)//������
	//{
	//	column--;
	//	turn++;
	//}
	//else if (turn == 3)//������
	//{
	//	row--;
	//	turn++;
	//}
	//else
	//{
	//}
	if (count < 8) {
		column++;
		row = count;
		count++;
	}
	((itrPosition*)currItrPosPtr)->count = count;
	return Position(row, column); //return the new position��������λ��
}

bool Application::Iterator::noNextPosition()
{
	return ((itrPosition*)currItrPosPtr)->count > 7;
}

Application::Iterator::~Iterator()
{
	delete (itrPosition*)currItrPosPtr;
}