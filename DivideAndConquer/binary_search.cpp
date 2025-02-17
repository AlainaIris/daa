#include <iostream>
using namespace std;

int binary_search(int* arr, int n, int value);

int main() {
	int arr[10] = {-20, -15, -14, -7, -1, 3, 6, 12, 13, 20};
	cout << binary_search(arr, 10, -7);
	cout << binary_search(arr, 10, 21);
	cout << binary_search(arr, 10, 13);
	cout << '\n';
	return 0;
}

int binary_search(int* arr, int n, int value) {
	int low = 0;
	int high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (value > arr[mid]) {
			low = mid + 1;
		} else if (value < arr[mid]) {
			high = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}
