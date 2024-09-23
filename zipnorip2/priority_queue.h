#pragma once
#include <vector>


//Min-heap 
//как карсет на данные
//Структура хранит только указатели на данные, Пространственная сложность 64 * n 
template <typename T>
class PriorityQueue
{
private:
	std::vector<const T*> binary_min_heap; //l - 2i +1; r - 2i +2
	void heapify_up(size_t);//(heapify = Делать кучей) восходящее упорядочивание 
	void heapify_down(size_t index);// нисходящее упорядочивание
	const T* swap(size_t, size_t);//возвращает первый параметр проверить возможно висячий
	size_t min(size_t, size_t);
	bool (*comparator)(const T*, const T*);
	
public:
	void push(const T*);//добавляет в min-кучу элемент
	T top() const;//просмотр корня(наименьшее значение)  
	const T* pop();//забрать первый элемент (наименьшее значение)

	PriorityQueue();
	PriorityQueue(bool(*comparator)(const T*, const T*));
};



