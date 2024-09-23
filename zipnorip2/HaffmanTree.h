#pragma once
#include "priority_queue.h"
#include <map>

//что из себя представляет: структура данных дерево из node
//методы: 1.посторить дерево(передать сам массив но вообще очередь , может 
// даже интереснее будет унаследоваться от очереди)
//далее 2. генерация новых кодов символов(не обязательно ключ может быть любым
//) куда бы их записать ну вероятно вернуть словарь будет лучшим решением(символ(T) - "код(хотелось бы использовать побитовые сдвиги)")

template <typename T>
struct Node {
	T key;
	int value;
	Node* left;
	Node* right;
	Node(std::pair<T,int> item) : key(item.first), value(item.second)
};

//нельзя перестроить дерево 
template <typename T>
class HaffmanTree : protected PriorityQueue<int>
	//как именно синтаксически обозначается передача параметров родителю а
	//а если у него много конструкторов
{
	Node<T>* root;
	std::map<T, int>* main_dict;
	std::map<T, std::vector<bool>> result;

		

public:
	//в очередь передавать указательна pair 
	HaffmanTree(std::map<T, int>& main_dict, PriorityQueue<int>(bool(*comparator)(const int*, const int*) = nullptr))
	{
		comparator ? PriorityQueue<int>(comparator) : PriorityQueue<int>();
		this.main_dict = main_dict;
		//здесь можно и инициализировать очередь элементами явл pair
		for (const std::pair<T, int>& item : main_dict)
		{
			push(item);
		}
		//тут в целом можно постороить дерево но вынесем в отдельный метод
		
	};
	void BuildTree(Node<T>* node)
	{
		node(top());




	}

};

