#pragma once
#include "priority_queue.h"
#include <map>

//��� �� ���� ������������: ��������� ������ ������ �� node
//������: 1.��������� ������(�������� ��� ������ �� ������ ������� , ����� 
// ���� ���������� ����� �������������� �� �������)
//����� 2. ��������� ����� ����� ��������(�� ����������� ���� ����� ���� �����
//) ���� �� �� �������� �� �������� ������� ������� ����� ������ ��������(������(T) - "���(�������� �� ������������ ��������� ������)")

template <typename T>
struct Node {
	T key;
	int value;
	Node* left;
	Node* right;
	Node(std::pair<T,int> item) : key(item.first), value(item.second)
};

//������ ����������� ������ 
template <typename T>
class HaffmanTree : protected PriorityQueue<int>
	//��� ������ ������������� ������������ �������� ���������� �������� �
	//� ���� � ���� ����� �������������
{
	Node<T>* root;
	std::map<T, int>* main_dict;
	std::map<T, std::vector<bool>> result;

		

public:
	//� ������� ���������� ����������� pair 
	HaffmanTree(std::map<T, int>& main_dict, PriorityQueue<int>(bool(*comparator)(const int*, const int*) = nullptr))
	{
		comparator ? PriorityQueue<int>(comparator) : PriorityQueue<int>();
		this.main_dict = main_dict;
		//����� ����� � ���������������� ������� ���������� ��� pair
		for (const std::pair<T, int>& item : main_dict)
		{
			push(item);
		}
		//��� � ����� ����� ���������� ������ �� ������� � ��������� �����
		
	};
	void BuildTree(Node<T>* node)
	{
		node(top());




	}

};

