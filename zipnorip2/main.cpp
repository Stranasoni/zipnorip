#include <unordered_map>
#include "priority_queue.h"
#include "priority_queue.cpp"
#include "iostream"
#include "HaffmanTree.h"
#include "HaffmanTree.cpp"
#include "DictFrequencies.h"


std::string join(std::vector<bool>& code)
{
	std::string res = "";
	for (bool bit : code)
	{
		if (bit) res += "1";
		else res += "0";
	
	}
	return res;
}
int main()
{
	//ооп класс для всегоЖ
	//подсчет частоты() сохранить в unordered_map
	//построение дерева хаффмана(нужно создать класс дерево которое будет
		//иметь метод обхода в глубину(рекурсия), сложный метод который будет как https://cloudstreamgate.com/response/show_text/23b97289-38ca-49d9-b91f-a707c2bb6e61
	//its work!!!!!
	//далее после хаффмана неоюходимо класс чтения данных и сощздания сжатой версии файла
	PriorityQueue<int> pq([](int* a, int* b) {return (*a) < (*b); });
	int* a = new int(6);
	int* b = new int(7);
	int* c = new int(7);
	int* d = new int(8);
	int* e = new int(9);
	std::vector<int> v = std::vector<int> {1,2,3,65,6};
	

	//допустим у мои интики храняться в динамической памяти что полсе pop
	//std::vector<int> v2 = { a, 1, 4, 5, 1, 2, 5 }; 
	for (int i = 0; i < 5; ++i)
	{
		pq.push(&v[i]);
	}
	
	for (int i = 0; i < 5; ++i)
	{
		std::cout<< (*pq.pop())<<"\n";
	}
	GetDictFrequencies test("test.txt");
	std::map<char, int> win = test.get_dict_frequencies();

	HaffmanTree<char, int> tree(win);
	
	
	for (auto el : tree.GetHaffmanDict())
	{
		std::cout << el.first << " " << join(el.second) << std::endl;
	}
	//теперь нужно записать файл открыть в бинарном режиме лучше вообще побитово и режить как передать в файле словарь хаффмана
	//потом написать методы декодирования но сначала мне необходимо переписать под си 
}
