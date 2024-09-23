#pragma once
#include <vector>


//Min-heap 
//��� ������ �� ������
//��������� ������ ������ ��������� �� ������, ���������������� ��������� 64 * n 
template <typename T>
class PriorityQueue
{
private:
	std::vector<const T*> binary_min_heap; //l - 2i +1; r - 2i +2
	void heapify_up(size_t);//(heapify = ������ �����) ���������� �������������� 
	void heapify_down(size_t index);// ���������� ��������������
	const T* swap(size_t, size_t);//���������� ������ �������� ��������� �������� �������
	size_t min(size_t, size_t);
	bool (*comparator)(const T*, const T*);
	
public:
	void push(const T*);//��������� � min-���� �������
	T top() const;//�������� �����(���������� ��������)  
	const T* pop();//������� ������ ������� (���������� ��������)

	PriorityQueue();
	PriorityQueue(bool(*comparator)(const T*, const T*));
};



