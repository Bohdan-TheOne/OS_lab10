#include "proj.h"

void printArray(int* arr, long size) {
    for (long i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void static_show_out(int num) {
	nameOutput(num);
}

void static_show_sort(int num) {
	srand(time(NULL));
	int* arr = new int[num];
	for (int i = 0; i < num; ++i) {
		arr[i] = rand() % 199 - 99;
	}
	printArray(arr, num);
	mergeSort(arr, num);
	printArray(arr, num);
}
