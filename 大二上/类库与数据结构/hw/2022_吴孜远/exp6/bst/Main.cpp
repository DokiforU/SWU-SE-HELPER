#include<iostream>
#include"bst.h"
using namespace std;

int main() {
	
	srand((unsigned)time(0));
	/*int sum = 0;
	double aveHeight = 0;
	for (int n = 10; n < 60; n = n + 5) {
		cout << n << ", ";
	}
	cout << endl;
	for (int n = 10; n < 60; n = n + 5) { //���Խڵ���Ϊ11-20
		sum = 0;
		for (int i = 0; i < 20; i++) { //ÿ���ڵ�������20������ȡ����ƽ��ֵ
			BinSearchTree<int>* bst = new BinSearchTree<int>;

			for (int i = 0; i < n; i++) { //����һ��n��������
				bst->insert(rand() % 100 + 1);
			
			}
			sum = sum + bst->height();
		
			//cout << bst->height() << " ";
		}
		aveHeight = sum / 20.0;
		cout << aveHeight << ",";
	}*/
	BinSearchTree<int>* bst = new BinSearchTree<int>;
	BinSearchTree<int>::Iterator itr;
	for (int i = 0; i < 50; i++) { //����һ��n��������
		bst->insert(rand() % 100 + 1);

	}
	bst->printTree();

	return 0;
}
