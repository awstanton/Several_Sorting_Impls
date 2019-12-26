#ifndef __HEAPSORT__
#define __HEAPSORT__

#include <vector>

void maxHeapify(std::vector<int>&, int, int);

void buildMaxHeap(std::vector<int>&, int, int);

void heapSort(std::vector<int>&, int);

#endif // __HEAPSORT__
