#ifndef LISTTEMP_H
#define LISTTEMP_H

#define NULL 0

template<class T>
class ListTemp
{
private:
	struct Node
	{
		T data;
		Node *next;
	};

	Node *head;
	int size;

public:

	ListTemp(); //constructor

	~ListTemp(); //destructor

	int getLength() const; //get the number of elements

	bool isEmpty() const; //check whether the container is empty

	// Postcondition: A node with newData has been inserted at the
	//                head of the Linked container.
	void addHead(const T& newData);

};


//************************implementation of the linked list class template**************************
template<class T>
ListTemp<T>::ListTemp()
{
	head = NULL; //empty list
	size = 0;
}


template<class T>
ListTemp<T>::~ListTemp()
{
	Node *current = head;
	Node *temp = NULL;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		delete temp; //release
	}
}


template<class T>
int ListTemp<T>::getLength() const
{
	return size;
}


template<class T>
bool ListTemp<T>::isEmpty() const
{
	return size == 0;
}


template<class T>
void ListTemp<T>::addHead(const T& newData)
{
	//please implement this
	Node* newHead = new Node; //������Node����newHead����
	newHead->data = newData; //�ô����employee��ʼ��������
	newHead->next = head; //�þɵ�ͷָ���ʼ��ָ����
	head = newHead; //�޸�ͷָ��ʹ��ָ����Node
	size++; //size����
}


#endif