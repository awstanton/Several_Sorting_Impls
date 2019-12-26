#include <vector>
#include "quicksort.h"

int partitioner(int first, int last, std::vector<int>& numbers) {
    int comparator = numbers[last];
    int index1 = first - 1;
    int index2 = first;
    while (index2 < last) {
        if (numbers[index2] <= comparator) {
            int temp = numbers[++index1];
            numbers[index1] = numbers[index2];
            numbers[index2] = temp;
        }
        ++index2;
    }
    if (numbers[++index1] > comparator) {
        int temp = numbers[index1];
        numbers[index1] = numbers[last];
        numbers[last] = temp;
    }
    return index1;
}
// use iterators instead of indices? Make them consistent in this way?
void quickSort(int first, int last, std::vector<int>& numbers) {
    int middle;
    if (first < last) {
        middle = partitioner(first, last, numbers);
        quickSort(first, middle - 1, numbers);
        quickSort(middle + 1, last, numbers);
    }
}
