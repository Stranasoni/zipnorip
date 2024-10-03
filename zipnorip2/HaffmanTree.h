#pragma once
#include "priority_queue.h"
#include <map>


//если надо я потом сделаю еще класс который будет будет читать данные в массив 
//что из себя представляет: структура данных дерево из node
//методы: 1.посторить дерево(передать сам массив но вообще очередь , может 
// даже интереснее будет унаследоваться от очереди)
//далее 2. генерация новых кодов символов(не обязательно ключ может быть любым
//) куда бы их записать ну вероятно вернуть словарь будет лучшим решением(символ(T) - "код(хотелось бы использовать побитовые сдвиги)")

template <typename T,typename C>
struct Node {
	T key;
	C value;
	Node* left = nullptr;
	Node* right = nullptr;
	Node(std::pair<T, C> item) : key(item.first), value(item.second) {}
	Node(Node* left,Node* right) : value(left->value + right->value), left(left), right(right) {}
};

//нельзя перестроить дерево 
template <typename T, typename C>
class HaffmanTree : protected PriorityQueue<Node<T,C>>
	//как именно синтаксически обозначается передача параметров родителю а
	//а если у него много конструкторов
{
	Node<T,C>* root;
	bool comporator = false;
	std::map<T, std::vector<bool>> result;

	
public:
	//в очередь передавать указательна Node
	HaffmanTree(std::map<T, C>& main_dict, bool(*comparator)(C*, C*));
	HaffmanTree(std::map<T, C>& main_dict);
	void BuildTree();
	
	void Alphabet(Node<T, C>* node, std::vector<bool> code); 

	std::map<T, std::vector<bool>> GetHaffmanDict();
};





