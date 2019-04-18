/*
 * heap_sort.hpp
 *
 *  Created on: Apr 14, 2019
 *      Author: d-w-h
 */

#ifndef HEAP_SORT_HPP_
#define HEAP_SORT_HPP_

class Heap {
private:
	int length;
	int heap_size;
	int* A;

	int parent(int i);
	int left(int i);
	int right(int i);
	void max_heapify(int A[], int i);
	void build_max_heap();
	bool max_heap_verify();
public:
	Heap(int size);
	~Heap();
	void heap_sort();
	void set_heap(int B[]);
	void get_heap(int B[]);
};

void heap_sort_wrapper(int B[], int size);

#endif /* HEAP_SORT_HPP_ */
