#include <unordered_map>
#include "priority_queue.h"
#include "priority_queue.cpp"
#include "iostream"

int main()
{
	//��� ����� ��� ������
	//������� �������() ��������� � unordered_map
	//���������� ������ ��������(����� ������� ����� ������ ������� �����
		//����� ����� ������ � �������(��������), ������� ����� ������� ����� ��� https://cloudstreamgate.com/response/show_text/23b97289-38ca-49d9-b91f-a707c2bb6e61
	//its work!!!!!
	PriorityQueue<int> pq([](int* a, int* b) {return (*a) < (*b); });
	std::vector<int>* v = new std::vector<int>{3,3,1,4,5,1,2,5};
	std::vector<int> v2 = { 3, 1, 4, 5, 1, 2, 5 }; 
	for (int i = 0; i < 6; ++i)
	{
		pq.push(&(*v)[i]);
		pq.push(&v2[i]);
	}
	v = &v2;
	v2.clear();
	v2 = { 0,0,0,0,0,0 };
	for (int i = 0; i < 12; ++i)
	{
		std::cout<< (*pq.pop())<<"\n";
	}
	
}
