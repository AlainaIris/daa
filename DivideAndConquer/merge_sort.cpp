#include <cstdio>
void merge(int* arr, int low, int mid, int high) {
	int size = high - low + 1;
	int b[size];
	int i = low;
	int j = mid + 1;
	int index = 0;
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j]) {
			b[index] = arr[i];
			i++;
		} else {
			b[index] = arr[j];
			j++;
		}
		index++;
	}
	if (i > mid) {
		while (j <= high) {
			b[index] = arr[j];
			j++;
			index++;
		}
	} else {
		while (i <= mid) {
			b[index] = arr[i];
			i++;
			index++;
		}
	}
	for (i = low; i <= high; i++) {
		arr[i] = b[i - low];
	}
}

void merge_sort(int* arr, int low, int high) {
        if (low < high) {
                int mid = (low + high) / 2;
                merge_sort(arr, low, mid);
                merge_sort(arr, mid + 1, high);
                merge(arr, low, mid, high);
        }
}

int main() {
	int arr[10] = {310, 244, 223, 102, 836, 289, 931, 324, 298, 241};
	merge_sort(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
