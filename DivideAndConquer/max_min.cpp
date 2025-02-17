#include <cstdio>
void max_min(int* arr, int low, int high, int& min, int& max);

// Solution using recurrsion
void max_min(int* arr, int low, int high, int& min, int& max) {
	if (low == high) {
		max = arr[low];
		min = arr[low];
	} else if (low == high - 1) {
		if (arr[low] > arr[high]) {
			min = arr[high];
			max = arr[low];
		} else {
			min = arr[low];
			max = arr[high];
		}
	} else {
		int mid = (low + high) / 2;
		int min1, max1;
		max_min(arr, low, mid, min, max);
		max_min(arr, mid + 1, high, min1, max1);
		if (min1 < min) {
			min = min1;
		}
		if (max1 > max) {
			max = max1;
		}
	}
}

void max_min_iter(int* arr, int end, int& min, int& max) {
	int low = 0;
	int high = end;
	if (high == 0) {
		min = arr[0];
		max = arr[0];
	} else if (high == 1) {
		if (arr[0] > arr[1]) {
			min = arr[0];
			max = arr[1];
		} else {
			max = arr[0];
			min = arr[1];
		}
	} else {
		int stack[high] = {low, high / 2, high / 2 + 1, high};
		int top = 3;
		while (top > -1) {
			int last = stack[top--];
			int first = stack[top--];
			if (last - first == 0) {
				if (arr[last] > max) {
					max = arr[last];
				} else if (arr[last] < min) {
					min = arr[last];
				}
			} else if (last - first == 1) {
				if (arr[last] > arr[first]) {
					if (arr[last] > max) {
						max = arr[last];
					}
					if (arr[first] < min) {
						min = arr[first];
					}
				} else {
					if (arr[first] > max) {
						max = arr[first];
					}
					if (arr[last] < min) {
						min = arr[last];
					}
				}
			} else {
				int mid = (last + first) / 2;
				stack[++top] = first;
				stack[++top] = mid;
				stack[++top] = mid + 1;
				stack[++top] = last;
			}
		}
	}
}

void max_min_better(int* arr, int size, int& min, int& max) {
	for (int i = 0; i < size; i += 2) {
		if (i == size - 1) {
			if (arr[i] < min) {
				min = arr[i];
			} else if (arr[i] > max) {
				max = arr[i];
			}
		} else {
			if (arr[i] > arr[i + 1]) {
				if (arr[i] > max) {
					max = arr[i];
				}
			        if (arr[i + 1] < min) {
					min = arr[i + 1];
				}
			} else {
				if (arr[i + 1] > max) {
					max = arr[i + 1];
				}
				if (arr[i] < min) {
					min = arr[i];
				}
			}
		}
	}
}

int main() {
        int arr[10] = {22, 13, -6, -10, 14, 62, 19, 34, 45};
        int min = 1000;
        int max = -1000;
	int min1 = 1000;
	int max1 = -1000;
	int min2 = 1000;
	int max2 = -1000;
        int size = sizeof(arr) / sizeof(arr[0]);
        max_min(arr, 0, size - 1, min, max);
	max_min_iter(arr, size - 1, min1, max1);
	max_min_better(arr, size, min2, max2);
        printf("min: %d, max: %d", min, max);
	printf("min: %d, max: %d", min1, max1);
	printf("min: %d, max: %d", min2, max2);
}

