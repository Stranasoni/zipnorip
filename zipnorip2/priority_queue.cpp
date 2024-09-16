#include "Priority_queue.h"

template <typename T>
PriorityQueue<T>::PriorityQueue(bool(*comparator)(T*, T*)) :comp(comparator) {};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	comp = [](T* a, T* b) { return (*a) < (*b); };
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
void PriorityQueue<T>::heapify_up(size_t index)
{
	if (index == 0) return;
	size_t parent;
	index % 2 == 0 ? parent = (index - 2) / 2 : parent = (index - 1) / 2;
	//сын больше равен родителю тогда ничего, так как minheap
	if (!comp(binary_min_heap[index], binary_min_heap[parent])) return;
	swap(index, parent);
	heapify_up(parent);

}

template <typename T>
size_t PriorityQueue<T>::min(size_t l, size_t r)
{
	if (comp(binary_min_heap[r], binary_min_heap[l])) return r;
	return l;
}

template <typename T>
void PriorityQueue<T>::heapify_down(size_t index)
{
	size_t l = 2 * index + 1;
	size_t r = 2 * index + 2;
	//если узел - лист
	if (!(l < binary_min_heap.size()) && !(r < binary_min_heap.size())) return;
	//если родитель имеет только одного сына(правого брата не будет без левого)
	if (!(r < binary_min_heap.size())) {
		if (!(comp(binary_min_heap[l], binary_min_heap[index]))) return;
		swap(index, l);
		return;
	}
	//если родитель меньше обоих сыновей
	if (!(comp(binary_min_heap[l], binary_min_heap[index]) || comp(binary_min_heap[r], binary_min_heap[index])))
		return;

	size_t next = min(l, r);
	swap(index, next);//mmm
	heapify_down(next);
}

template <typename T>
T PriorityQueue<T>::top() const
{
	return *binary_min_heap[0];
}

template <typename T>
void PriorityQueue<T>::push(T* item)
{
	binary_min_heap.push_back(item);
	heapify_up(binary_min_heap.size() - 1);

}

//управление указателем передается области вызова (нельзя не присвоить =>обернуть в умные указатели)
template <typename T>
T* PriorityQueue<T>::pop()
{
	T* root = swap(0, binary_min_heap.size() - 1);
	binary_min_heap.resize(binary_min_heap.size() - 1);
	heapify_down(0);
	return root;// 

}
