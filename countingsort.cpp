#include <vector>
#include "countingsort.h"

// CHANGE THIS TO PASS BY VALUE
void countingSort(std::vector<int> numbers, int limit) {
    std::vector<int> temp(numbers);
    std::vector<int> range(limit + 1);

    for (std::vector<int>::size_type i = 0; i < temp.size(); ++i)
        ++range.at(temp.at(i));
    for (std::vector<int>::size_type i = 1; i < range.size(); ++i)
        range.at(i) += range.at(i - 1);
    for (std::vector<int>::size_type i = 0; i < temp.size(); ++i) {
        numbers.at(range.at(temp.at(i)) - 1) = temp.at(i);
        --range.at(temp.at(i));
    }
}


