
#include "backtrack.h"
#include<iostream>
using namespace std;

BackTrack::BackTrack() {}
	
BackTrack::BackTrack(const Application& thisApp)
{
	this->app = thisApp;
}

bool BackTrack::backTrack(const Position& currPos)
{
	
	app.progress(currPos);
	if (app.success(currPos)) {
		/*eturn true;*/

		app.print(); //ÿ�γɹ�����ӡһ��
		cout << endl;
		globalcount++; //����������1
		app.goBack(currPos); //��������
		return false;//����û���ҵ�������false
	}
	else
	{
		Application::Iterator itr(currPos);

		Position nextPos;

		while (!itr.noNextPosition())
		{
			nextPos = itr.getNextPosition();
			//cout << "����λ�ã�" << nextPos.getRow() << "��" << nextPos.getColumn() << endl;
			
			//�ȿ���һλ���Ƿ���Ч������Ч������һ�㣬����Ч������һ�ε���
			if (app.isValid(nextPos) && backTrack(nextPos)) {//recursive call if valid
				return true;
			}
			
		}
		//cannot reach goal from currPos
		app.goBack(currPos); //backtrack
		return false; //from currPos, no solution
	}
}