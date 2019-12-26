#include <cmath>
#include <vector>
#include <stdio.h>
#include "select.h"

// ASSUMING THAT EACH NUMBER IS DISTINCT

void insertionSort(std::vector<int>& numbers, int first, int last) {
    for (int index = first + 1; index < last; ++index) {
        int key = numbers.at(index);
        int findIndex = index - 1;
        while (findIndex >= first && numbers.at(findIndex) > key) {
            numbers.at(findIndex + 1) = numbers.at(findIndex);
            --findIndex;
        }
        numbers.at(findIndex + 1) = key;
    }
}

int PARTITION(std::vector<int>& numbers, int lowIndex, int highIndex, int medianOfMedians) {
	int temp;
	int index = lowIndex - 1;
	for (int compareIndex = lowIndex; compareIndex < highIndex; ++compareIndex) {
		if (numbers.at(compareIndex) < medianOfMedians) {
			++index;
			temp = numbers.at(index);
			numbers.at(index) = numbers.at(compareIndex);
			numbers.at(compareIndex) = temp;
		}
		else if (numbers.at(compareIndex) == medianOfMedians) {
            temp = numbers.at(highIndex);
            numbers.at(highIndex) = medianOfMedians;
            numbers.at(compareIndex) = temp;
            if (numbers.at(compareIndex) < medianOfMedians) {
                ++index;
                temp = numbers.at(index);
                numbers.at(index) = numbers.at(compareIndex);
                numbers.at(compareIndex) = temp;
            }
		}
	}
	temp = numbers.at(index + 1);
	numbers.at(index + 1) = numbers.at(highIndex);
	numbers.at(highIndex) = temp;
	return index + 1;
}

// compare difference between the indices rather than the size of numbers

//SELECT(numbers, 0, numbers.size() - 1, i); // findIndex ith smallest element in vector of distinct numbers

int SELECT(std::vector<int>& numbers, int lowIndex, int highIndex, int i) {
	if (lowIndex == highIndex)
        return numbers.at(lowIndex);
	else {
        const int length = highIndex - lowIndex + 1;
        const int numGroups = ceil(length / 5.0);
        const int remainder = fmod(length, 5);
		std::vector<int> medians(0);

        if (length >= 5) {
            // sort groups of five
            for (int groupIndex = lowIndex; groupIndex < lowIndex + length - remainder; groupIndex += 5)
                insertionSort(numbers, groupIndex, groupIndex + 5);
            // get median for groups of five
            for (int groupIndex = lowIndex; groupIndex < lowIndex + length - remainder; groupIndex += 5)
                medians.push_back(numbers.at(groupIndex + 2));
        }
		if (remainder != 0) { // can I pass by reference, will the recursive call maybe have a different vector
            // sort last group
            insertionSort(numbers, lowIndex + length - remainder, lowIndex + length);
			// get median for last group
			medians.push_back(numbers.at(lowIndex + length - remainder + floor((remainder + 1) / 2.0) - 1));
		}

		int groupMedianIndex = floor((numGroups + 1) / 2.0) - 1;
		int medianOfMedians = SELECT(medians, 0, numGroups - 1, groupMedianIndex + 1);
		//printf("medianOfMedians = %d\n", medianOfMedians);

		int partitionIndex = PARTITION(numbers, lowIndex, highIndex, medianOfMedians);

		int k = partitionIndex + 1; // place of medianOfMedians in numbers
        //printf("k = %d\n", k);

		if (i == k) // if medianOfMedians is ith smallest element, return medianOfMedians
			return numbers.at(partitionIndex);
		else if (i < k)
			return SELECT(numbers, lowIndex, partitionIndex - 1, i);
		else
			return SELECT(numbers, partitionIndex + 1, highIndex, i);
	}

}
