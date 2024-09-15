#pragma once
#include <vector>


//Min-heap 
//заменить int на шаблонный параметр

template <typename T>
class PriorityQueue
{
private:
	std::vector<T*> binary_min_heap; //l - 2i +1; r - 2i +2
	void heapify(size_t);//Делать кучей?)
	T* swap(size_t, size_t);//возвращает первый элемент
	bool (*comparator)(T, T);
	
public:
	void push(T*);//добавляет в max-кучу элемент
	T top() const;//просмотр корня
	T* pop();//забрать первый элемент 

	PriorityQueue();
	PriorityQueue(bool(*comparator)(T, T));
};

template <typename T>
PriorityQueue<T>::PriorityQueue(bool(*comparator)(T, T)) :comparator(comparator);

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	comparator = [](T* a, T* b) {return (*a) < (*b); };
}

template <typename T>
T* PriorityQueue<T>::swap(size_t a, size_t b)
{
	T* temp = binary_min_heap[a];
	binary_min_heap[a] = binary_min_heap[b];
	binary_min_heap[b] = temp;
	return (temp);

}

template <typename T>
void PriorityQueue<T>::heapify(size_t index)
{
	int parent;
	index % 2 == 0 ? parent = (index -2)/2 : parent = (index-1)/2;
	
	if (!comporator(binary_min_heap[index], binary_min_heap[parent])) return;
	swap(index, parent);
	heapify(parent);

}


template <typename T>
void PriorityQueue<T>::push(T* item)
{
	binary_min_heap.push_back(item);
	heapify(binary_min_heap.size() - 1);

}

//управление указателем передается области вызова (нельзя не присвоить обернуть в умные указатели)
template <typename T>
T* PriorityQueue<T>::pop()
{
	T* root = swap(0, binary_min_heap.size() - 1);
	binary_min_heap.resize(binary_min_heap.size() - 1);
	//здесь по другому мы двигаемся сверху вниз выбираем наименьший из детей и свап местами пока узел не станет наименьшим
	//ох нужно внимательно тестриовать следить за указателями боже спокойной ночи

}

