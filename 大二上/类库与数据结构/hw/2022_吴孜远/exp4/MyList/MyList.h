#ifndef LISTTEMP_H
#define LISTTEMP_H

#define NULL 0

template<class T>
class list
{
private:
	struct Node
	{
		T item;
		Node* next;
		Node* pre;
	};

	Node* head;
	Node* tail;

public:

	//************************declaration of the inner iterator class****************************
	class iterator
	{
		friend class list<T>; //friend class of the iterator class
	private:
		Node* curr;

	public:
		iterator(Node* ptr); //constructor with Node parameter, defined as private

		iterator(); //default constructor

		iterator& operator++(); //pre-increment of ++

		iterator operator++(int); //post-increment of ++

		iterator& operator--(); //pre-increment of --

		iterator operator--(int); //post-increment of --

		T& operator*() const; //����item�����ã����ڷ��ص������ã���������Է���ֵ���и�ֵ����ֱ���޸�list��item������

		bool operator==(const iterator other) const;

	};//class Iterator

	list(); //constructor

	~list(); //destructor


	list(const list<T>& x); //copy constructor, worstTime(n) is O(n)

	void push_front(const T& x); //��ͷ������Ԫ��

	void push_back(const T& x); //��β������Ԫ��

	iterator insert(iterator position, const T& x); //��positionǰ����x������ָ��x�ĵ�������worstTime(n) is constant. 

	void pop_front(); //list�ǿգ�ɾ����һ��Ԫ��

	void pop_back();// list�ǿգ�ɾ�����һ��Ԫ��

	iterator erase(iterator position); //ɾ��positionָ���Ԫ�أ�����ָ��position��һ��λ�õĵ�������worstTime(n) is constant. 

	iterator erase(iterator first, iterator last);//ɾ������[first,last)��Ԫ��

	unsigned size() const; //����size

	bool empty() const; //�����Ƿ�Ϊ������

	iterator begin() const; //����ָ���һ��Ԫ�صĵ�����

	iterator end() const; //����ָ�����һ��Ԫ�ص���һ��Ԫ�صĵ�����

	list<T>& operator=(const list<T>& x); //���ظ�ֵ���������һ��x�е����ݸ��ƹ���

	void splice(iterator position, list<T>& x); //��x�������ת�Ƶ�position֮ǰ��x��Ϊempty

};

#endif