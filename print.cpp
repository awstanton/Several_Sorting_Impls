#include <vector>
#include <stdio.h>
#include "print.h"

void print(std::vector<int>& numbers) {
    for (std::vector<int>::size_type index = 0; index < numbers.size(); ++index) {
        printf("%d ", numbers.at(index));
    }
    printf("\n");
}


