#pragma once
#include <vector>


//Min-heap 
//��� ������ �� ������
//��������� ������ ������ ��������� �� ������, ���������������� ��������� 64 * n 
template <typename X>
class PriorityQueue
{
private:
	std::vector<X*> binary_min_heap; //l - 2i +1; r - 2i +2
	void heapify_up(size_t);//(heapify = ������ �����) ���������� �������������� 
	void heapify_down(size_t index);// ���������� ��������������
	X* swap(size_t, size_t);//���������� ������ �������� ��������� �������� �������
	size_t min(size_t, size_t);
	bool (*comparator)(X*, X*);
	
public:
	void push(X*);//��������� � min-���� �������
	X top() const;//�������� �����(���������� ��������)  
	X* pop();//������� ������ ������� (���������� ��������)
	size_t size() const;

	PriorityQueue();
	PriorityQueue(bool(*comparator)(X*, X*));
};



