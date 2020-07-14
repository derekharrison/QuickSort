/*
 * main.cpp
 *
 *  Created on: Jul 14, 2020
 *      Author: d-w-h
 */

#include <iostream>

int partition(int A[], int p, int r) {
    int x = A[r];
    int i = p - 1;
    for(int j = p; j < r; j++) {
        if(A[j] <= x) {
            i = i + 1;
            int dummy = A[i];
            A[i] = A[j];
            A[j] = dummy;
        }
    }
    int dummy = A[i+1];
    A[i+1] = A[r];
    A[r] = dummy;

    return i + 1;
}

void quick_sort(int A[], int p, int r) {
    if(p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}

void quicksort(int A[], int size) {
    quick_sort(A, 0, size - 1);
}

int main(int argc, char * argv[])
{
    int A[] = {120, 3, 16, 13, 17,
               5, 8, 1, 0, 10, 3,
               2, 1, 25};

    int size = sizeof(A) / sizeof(int);
    quicksort(A, size);

    for(int i = 0; i < size; ++i) {
        std::cout << A[i] << std::endl;
    }

    return 0;
}
