#include <vector>
#include <cmath>
#include "mergesort.h"

void merger(int first1, int last1, int first2, int last2, std::vector<int>& numbers) {
    int index0 = first1;
    int length0 = last2 - first1 + 1;
    int length1 = last1 - first1 + 1;
    //int length2 = last2 - first2 + 1;
    int index1 = 0;
    int index2 = length1;

    std::vector<int> temp(length0);

    for (int index = 0; index < length0; ++index) {
        temp[index] = numbers[index0];
        ++index0;
    }

    index0 = first1; // reset index0

    while (index1 < length1 && index2 < length0) {
        if (temp[index1] <= temp[index2]) {
            numbers[index0] = temp[index1++];
        }
        else {
            numbers[index0] = temp[index2++];
        }
        ++index0;
    }

    while (index1 < length1) {
        numbers[index0] = temp[index1++];
        ++index0;
    }

    while (index2 < length0) {
        numbers[index0] = temp[index2++];
        ++index0;
    }

}


void mergeSort(int first, int last, std::vector<int>& numbers) {
    if (first < last) {
        int middle = floor((last + first + 1) / 2);

        mergeSort(first, middle - 1, numbers);
        mergeSort(middle, last, numbers);
        merger(first, middle - 1, middle, last, numbers);
    }
}
