#include <vector>
#include "heapsort.h"

void maxHeapify(std::vector<int>& numbers, int index, int heapSize) {
    int leftIndex = index * 2 + 1;
    int rightIndex = leftIndex + 1;
    int maximumIndex = index;
    if (leftIndex < heapSize && numbers[leftIndex] > numbers[index]) {
        maximumIndex = leftIndex;
    }
    if (rightIndex < heapSize && numbers[rightIndex] > numbers[maximumIndex]) {
        maximumIndex = rightIndex;
    }
    if (maximumIndex != index) {
        int temp = numbers[index];
        numbers[index] = numbers[maximumIndex];
        numbers[maximumIndex] = temp;
        maxHeapify(numbers, maximumIndex, heapSize);
    }
}

void buildMaxHeap(std::vector<int>& numbers, int arraySize, int heapSize) {
    for (int index = arraySize / 2 - 1; index >= 0; --index) {
        maxHeapify(numbers, index, heapSize);
    }
}

void heapSort(std::vector<int>& numbers, int arraySize) {
    buildMaxHeap(numbers, arraySize, arraySize);

    for (int index = arraySize - 1; index >= 1; --index) {

        int temp = numbers[0];
        numbers[0] = numbers[index];
        numbers[index] = temp;

        maxHeapify(numbers, 0, index);
    }

}
