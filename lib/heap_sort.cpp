/*
 * heap_sort.cpp
 *
 *  Created on: Apr 14, 2019
 *      Author: d-w-h
 */

#include <iostream>
#include "../inc/heap_sort.hpp"

void heap_sort_wrapper(int B[], int size) {
	Heap my_heap(size);
	my_heap.set_heap(B);
    my_heap.heap_sort();
    my_heap.get_heap(B);
}

Heap::Heap(int size) {
    this->length = size + 1;
    this->heap_size = size;
    this->A = new int[size+1];
}

Heap::~Heap() {
	delete [] this->A;
}

int Heap::parent(int i) {
	return i/2;
}

int Heap::left(int i) {
	return 2*i;
}

int Heap::right(int i) {
	return 2*i + 1;
}

void Heap::max_heapify(int A[], int i) {
	int l, r, largest;
	l = Heap::left(i);
	r = Heap::right(i);
	if(l < this->heap_size + 1 && A[l] > A[i]) {
		largest = l;
	}
	else {
		largest = i;
	}
	if(r < this->heap_size + 1 && A[r] > A[largest]) {
		largest = r;
	}
	if(largest != i) {
		int dummy;
		dummy = A[i];
		A[i] = A[largest];
		A[largest] = dummy;
		Heap::max_heapify(A, largest);
	}
}

void Heap::build_max_heap() {
	this->heap_size = this->length - 1;
	for(int i = this->heap_size/2; i > 0; --i) {
        Heap::max_heapify(this->A, i);
	}
}

void Heap::heap_sort() {
	Heap::build_max_heap();
	for(int i = this->length - 1; i > 1; --i) {
		int dummy;
		dummy = this->A[i];
		this->A[i] = this->A[1];
		this->A[1] = dummy;
		this->heap_size = this->heap_size - 1;
		Heap::max_heapify(this->A, 1);
	}
}

void Heap::set_heap(int B[]) {
	for(int i = 1; i < this->length; ++i) {
		this->A[i] = B[i-1];
	}
}

void Heap::get_heap(int B[]) {
	for(int i = 1; i < this->length; ++i) {
	    B[i-1] = this->A[i];
	}
}

bool Heap::max_heap_verify() {
    bool is_max_heap = true;
	for(int i = (this->length - 1)/2; i > 0; --i) {
        int l, r;
        l = Heap::left(i);
        r = Heap::right(i);
        if(this->A[i] < this->A[l] || this->A[i] < this->A[r]) {
        	is_max_heap = false;
        }
	}

	return is_max_heap;
}
