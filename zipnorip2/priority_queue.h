#pragma once
#include <vector>


//Min-heap 
//как карсет на данные
//Структура хранит только указатели на данные, Пространственная сложность 64 * n 
template <typename X>
class PriorityQueue
{
private:
	std::vector<X*> binary_min_heap; //l - 2i +1; r - 2i +2
	void heapify_up(size_t);//(heapify = Делать кучей) восходящее упорядочивание 
	void heapify_down(size_t index);// нисходящее упорядочивание
	X* swap(size_t, size_t);//возвращает первый параметр проверить возможно висячий
	size_t min(size_t, size_t);
	bool (*comparator)(X*, X*);
	
public:
	void push(X*);//добавляет в min-кучу элемент
	X top() const;//просмотр корня(наименьшее значение)  
	X* pop();//забрать первый элемент (наименьшее значение)
	size_t size() const;

	PriorityQueue();
	PriorityQueue(bool(*comparator)(X*, X*));
};



