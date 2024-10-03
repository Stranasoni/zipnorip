#include "HaffmanTree.h"



template <typename T, typename C>
HaffmanTree<T, C>::HaffmanTree(std::map<T, C>& main_dict) 
	: PriorityQueue<Node<T,C>>([](Node<T, C>* a, Node<T, C>* b) { return a->value < b->value; })
{
	for (auto item : main_dict)
	{
		//���� ��� ���� ���������� �� ������
		Node<T, C>* temp = new Node<T, C>(item);
		this->push(temp);
		
	}
	//��� � ����� ����� ���������� ������ �� ������� � ��������� �����
	BuildTree();
}

template <typename T, typename C>
HaffmanTree<T,C>::HaffmanTree(std::map<T, C>& main_dict, bool(*comparator)(C*, C*))
	: PriorityQueue<Node<T, C>>([](Node<T, C>& a, Node<T, C>& b) { return comparator; })
{
	//��������� ���������
	//PriorityQueue<C>([](Node<T, C>& a, Node<T, C>& b) { return comparator; }); //!!!!!!!!!!!!!!!!!!!!!!1
	PriorityQueue<C> pr_queue([](Node<T, C>& a, Node<T, C>& b) { return a.value < b.value; });

	//this.main_dict = main_dict;
	//����� ����� � ���������������� ������� ���������� ��� Node
	for (std::pair<T, C>& item : main_dict)
	{
		//���� ��� ���� ���������� �� ������
		this->push(new Node<T, C>(item));
	}
	//��� � ����� ����� ���������� ������ �� ������� � ��������� �����
	BuildTree();

}

template <typename T, typename C>
void HaffmanTree<T, C>::BuildTree()
{
	while (this->size() != 1)
	{
		Node<T, C>* parent = new Node<T, C>(this->pop(), this->pop());
		this->push(parent);
	}
	root = this->pop();
	//generation code base
	std::vector<bool> code;
	Alphabet(this->root, code);

}


template <typename T, typename C>
void HaffmanTree<T, C>::Alphabet(Node<T, C>* node, std::vector<bool> code) // ������ ��� ���� �� 
{
	//��������� ���� ���� �� ������ � �������  �� ����� ������� �� bool
	// ���� ��� ����� 0 ������ 1 push 
	if (node->left == nullptr && node->right == nullptr)
	{
		result[node->key] = code;
		return;
	}
	if (node->left != nullptr) { code.push_back(0); Alphabet(node->left, code); }
	if (node->right != nullptr) { code.push_back(1); Alphabet(node->right, code); }
}


template <typename T, typename C>
std::map<T, std::vector<bool>> HaffmanTree<T, C>::GetHaffmanDict()
{
	return this->result;
}