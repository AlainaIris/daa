#include <cstdio>
#include <iostream>
/**
 * A linear sort using O(3n+k) time and O(k) space where k is the
 * size of the range of values. For simplicity, values are assumed
 * to be 0 or greater, but modification for negatives is trivial
 */
int* linearsort(int* arr, int &size) {
	int max = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	max++;
	int range[max] = {};
	for (int i = 0; i < size; i++) {
		range[arr[i]]++;
	}
	for (int i = 1; i < max; i++) {
		range[i] += range[i - 1];
	}
	int* sortedarr = new int[size + 1];
	for (int i = size - 1; i > 0; i--) {
		sortedarr[--range[arr[i]]] = arr[i];
	}
	return sortedarr;
}

int main() {
	int* arr = new int[10] {0, 0, 2, 1, 4, 3, 5, 2, 2, 3};
	int size = 10;
	int* sorted = linearsort(arr, size);
	for (int i = 0; i < 10; i++) {
		printf("%d ", sorted[i]);
	}
	delete[] sorted;
	delete[] arr;
}
