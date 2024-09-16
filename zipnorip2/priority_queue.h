#pragma once
#include <vector>


//Min-heap 
//как карсет на данные
template <typename T>
class PriorityQueue
{
private:
	std::vector<T*> binary_min_heap; //l - 2i +1; r - 2i +2
	void heapify_up(size_t);//(heapify = Делать кучей) восходящее упорядочивание 
	void heapify_down(size_t index);// нисходящее упорядочивание
	T* swap(size_t, size_t);//возвращает первый параметр проверить возможно висячий
	size_t min(size_t, size_t);
	bool (*comp)(T*, T*);
	
public:
	void push(T*);//добавляет в min-кучу элемент
	T top() const;//просмотр корня(наименьшее значение)
	T* pop();//забрать первый элемент (наименьшее значение)

	PriorityQueue();
	PriorityQueue(bool(*comparator)(T*, T*));
};



