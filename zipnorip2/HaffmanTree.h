#pragma once
#include "priority_queue.h"
#include <map>


//���� ���� � ����� ������ ��� ����� ������� ����� ����� ������ ������ � ������ 
//��� �� ���� ������������: ��������� ������ ������ �� node
//������: 1.��������� ������(�������� ��� ������ �� ������ ������� , ����� 
// ���� ���������� ����� �������������� �� �������)
//����� 2. ��������� ����� ����� ��������(�� ����������� ���� ����� ���� �����
//) ���� �� �� �������� �� �������� ������� ������� ����� ������ ��������(������(T) - "���(�������� �� ������������ ��������� ������)")

template <typename T,typename C>
struct Node {
	T key;
	C value;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(std::pair<T, C> item) : key(item.first), value(item.second) {}
	Node(Node* left,Node* right) : value(left->value + right->value), left(left), right(right) {}
};

//������ ����������� ������ 
template <typename T, typename C>
class HaffmanTree : protected PriorityQueue<Node<T,C>>
	//��� ������ ������������� ������������ �������� ���������� �������� �
	//� ���� � ���� ����� �������������
{
	Node<T,C>* root;
	bool comporator = false;
	std::map<T, std::vector<bool>> result;

	
public:
	//� ������� ���������� ����������� Node
	HaffmanTree(std::map<T, C>& main_dict, bool(*comparator)(C*, C*));
	HaffmanTree(std::map<T, C>& main_dict);
	void BuildTree();
	
	void Alphabet(Node<T, C>* node, std::vector<bool> code); 

	std::map<T, std::vector<bool>> GetHaffmanDict();
};





