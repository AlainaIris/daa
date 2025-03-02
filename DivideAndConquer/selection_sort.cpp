#include <cstdio>
void selection_sort(int* arr, int size) {
	int selected = 1;
	while (selected < size) {
		int hold = arr[selected];
		int j = selected - 1;
		while (arr[j] > hold && j != -1) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = hold;
		selected++;
	}
}

int main() {
	int arr[10] = {20, 13, 41, 21, 43, 19, 2, 46, 67, 7};
	selection_sort(arr, 10);
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
