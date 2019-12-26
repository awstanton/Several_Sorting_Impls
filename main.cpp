#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include "UnitTest++.h"
#include "countingsort.h"
#include "heapsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "print.h"
#include "quicksort.h"
#include "select.h"

int main() {

    int option, limit, i;
    std::vector<int> numbers;
    int number;
    // ask for input
    printf("Please select one of the following options (0 - 4):\n\n0 heapSort\n1 mergeSort\n2 quickSort\n3 countingSort\n4 select \n\n");
    scanf("%d", &option);
    printf("\n");
    // get a limit if countingSort is chosen
    if (option == 3) {
        printf("Please specify the largest number in the sequence: ");
        scanf("%d", &limit);
        printf("\n");
    }
    else if (option == 4) {
        printf("Please specify a number i to find the ith smallest element in numbers: ");
        scanf("%d", &i);
        printf("\n");
    }
    // read in the numbers to sort
    while (scanf("%d", &number))
        numbers.push_back(number);
    // print the numbers before sorting
    print(numbers);
    // sort the numbers based on chosen sorting algorithm
    switch (option) {
        case 0:
            heapSort(numbers, numbers.size()); break;
        case 1:
            mergeSort(0, numbers.size() - 1, numbers); break;
        case 2:
            quickSort(0, numbers.size() - 1, numbers); break;
        case 3:
            countingSort(numbers, limit + 1); break;
        case 4:
            int value = SELECT(numbers, 0, numbers.size() - 1, i);
            printf("%d", value); break;
    }
    // print the numbers after sorting
    if (option != 4)
        print(numbers);

    return 0;

// if command line parameter is 0, run tests, else run program
    //return UnitTest::RunAllTests();
}
