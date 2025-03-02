#include <iostream>
#include <cstdio>
using namespace std;

class Stack {
	public:
		int top;
		int *items;

		Stack(int size) {
			top = -1;
			items = new int[size];
		}

		void push(int low, int high) {
			items[++top] = low;
			items[++top] = high;
		}

		int* pop() {
			int high = items[top--];
			int low = items[top--];
			return new int[2] { low, high };
		}
};

int partition(int* arr, int low, int high) {
	int swap = arr[low];
	int i = low - 1;
	int j = high + 1;
	int hold;
	while (i < j) {
		do {
			i++;
		} while (arr[i] < swap);
		do {
			j--;
		} while (arr[j] > swap);
		if (i >= j) {
			return j;
		}
		hold = arr[i];
		arr[i] = arr[j];
		arr[j] = hold;
		i = j;
	}
	return -1;
}

void quick_sort(int* arr, int low, int high) {
	Stack s = Stack((high - low + 1) * 4);
	s.push(low, high);
	int part;
	int* bounds;
	do {
		bounds = s.pop();
		low = bounds[0];
		high = bounds[1];
		part = partition(arr, low, high);
		if (low >= 0 && high >= 0 && low < high) {
			s.push(low, part);
			s.push(part + 1, high);
		}
	} while (s.top != -1);
	delete s.items;
}

int main() {
	int arr[10] = {10, 30, 20, 34, 23, 92, 38, 54, 67, 65};
	quick_sort(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr[i];
		cout << " ";
	}
	return 0;
}
