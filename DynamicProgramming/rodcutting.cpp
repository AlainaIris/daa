#include <cstdio>

int rodcutting(int* prices, int size, int rod) {
	int subrods[rod + 1] = {};
	for (int i = 0; i < size; i++) {
		subrods[i] = prices[i];
	}
	for (int i = size; i < rod; i++) {
		int p = -1;
		for (int j = 1; j < i; j++) {
			if (subrods[i - j - 1] + subrods[j] > p) {
				p = subrods[i - j - 1] + subrods[j];
			}
		}
		subrods[i] = p;
	}
	return subrods[rod - 1];
}

int main() {
	int rodprices[10] = {1, 5, 8, 9, 11, 18, 19, 21, 24, 28};
	printf("Largest price: %d", rodcutting(rodprices, 10, 42));
}
