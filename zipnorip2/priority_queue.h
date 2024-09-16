#pragma once
#include <vector>


//Min-heap 
//��� ������ �� ������
template <typename T>
class PriorityQueue
{
private:
	std::vector<T*> binary_min_heap; //l - 2i +1; r - 2i +2
	void heapify_up(size_t);//(heapify = ������ �����) ���������� �������������� 
	void heapify_down(size_t index);// ���������� ��������������
	T* swap(size_t, size_t);//���������� ������ �������� ��������� �������� �������
	size_t min(size_t, size_t);
	bool (*comp)(T*, T*);
	
public:
	void push(T*);//��������� � min-���� �������
	T top() const;//�������� �����(���������� ��������)
	T* pop();//������� ������ ������� (���������� ��������)

	PriorityQueue();
	PriorityQueue(bool(*comparator)(T*, T*));
};



