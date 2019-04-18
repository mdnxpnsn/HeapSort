/*
 * main.cpp
 *
 *  Created on: Apr 14, 2019
 *      Author: d-w-h
 *
 *      Implementation of heap sort for arrays of ints
 */

#include <iostream>
#include <cstdlib>
#include "../inc/heap_sort.hpp"

int main(int argc, char* argv[])
{
    int B[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1, 3, 5, 6, 11, 12, 13, 15};
	int size = sizeof(B)/sizeof(int);
	heap_sort_wrapper(B, size);
    for(int i = 0; i < size; ++i) {
    	std::cout << B[i] << std::endl;
    }
    std::cout << "done bro" << std::endl;
	return 0;
}
