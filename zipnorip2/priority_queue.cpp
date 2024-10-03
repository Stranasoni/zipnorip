#include "Priority_queue.h"

template <typename X>
PriorityQueue<X>::PriorityQueue(bool(*comparator)(X*, X*)) :comparator(comparator) {};

template <typename X>
PriorityQueue<X>::PriorityQueue() 
{
	comparator = [](X* a, X* b) { return (*a) < (*b); };
}

template <typename X>
X* PriorityQueue<X>::swap(size_t a, size_t b)
{
	X* temp = binary_min_heap[a];
	binary_min_heap[a] = binary_min_heap[b];
	binary_min_heap[b] = temp;
	return (temp);

}

template <typename X>
void PriorityQueue<X>::heapify_up(size_t index)
{
	if (index == 0) return;
	size_t parent;
	index % 2 == 0 ? parent = (index - 2) / 2 : parent = (index - 1) / 2;
	//сын больше равен родителю тогда ничего, так как minheap
	if (!comparator(binary_min_heap[index], binary_min_heap[parent])) return;
	swap(index, parent);
	heapify_up(parent);

}

template <typename X>
size_t PriorityQueue<X>::min(size_t l, size_t r)
{
	if (comparator(binary_min_heap[r], binary_min_heap[l])) return r;
	return l;
}

template<typename X>
size_t PriorityQueue<X>::size() const {
	return binary_min_heap.size();
}

template <typename X>
void PriorityQueue<X>::heapify_down(size_t index)
{
	size_t l = 2 * index + 1;
	size_t r = 2 * index + 2;
	//если узел - лист
	if (!(l < binary_min_heap.size()) && !(r < binary_min_heap.size())) return;
	//если родитель имеет только одного сына(правого брата не будет без левого)
	if (!(r < binary_min_heap.size())) {
		if (!(comparator(binary_min_heap[l], binary_min_heap[index]))) return;
		swap(index, l);
		return;
	}
	//если родитель меньше обоих сыновей
	if (!(comparator(binary_min_heap[l], binary_min_heap[index]) 
		|| comparator(binary_min_heap[r], binary_min_heap[index])))
		return;

	size_t next = min(l, r);
	swap(index, next);//mmm
	heapify_down(next);
}

template <typename X>
X PriorityQueue<X>::top() const
{
	return *binary_min_heap[0];
}

template <typename X>
void PriorityQueue<X>::push(X* item)
{
	binary_min_heap.push_back(item);
	heapify_up(binary_min_heap.size() - 1);

}

//
template <typename X>
X* PriorityQueue<X>::pop()
{
	X* root = swap(0, binary_min_heap.size() - 1);
	binary_min_heap.resize(binary_min_heap.size() - 1);
	heapify_down(0);
	return root;// 

}
