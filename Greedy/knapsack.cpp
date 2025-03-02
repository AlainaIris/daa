#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

struct item {
	float profit;
	float weight;
};

bool densitycmp(item i1, item i2) {
	return i1.profit / i1.weight > i2.profit / i2.weight;
}

float knapsack(vector<item> items, float bagWeight) {
	sort(items.begin(), items.end(), densitycmp);
	float profit = 0.0;
	int size = items.size();
	for (int i = 0; i < size && bagWeight > 0.0; i++) {
		if (bagWeight - items[i].weight < 0.0) {
			profit += items[i].profit * bagWeight / items[i].weight;
			bagWeight = 0.0;
		} else {
			profit += items[i].profit;
			bagWeight -= items[i].weight;
		}
	}
	return profit;
}

int main() {
	item i1 = {.profit = 25.0, .weight = 18.0};
	item i2 = {.profit = 24.0, .weight = 15.0};
	item i3 = {.profit = 15.0, .weight = 10.0};
	vector<item> items = {i1, i2, i3};
	printf("Profit: %.2f\n", knapsack(items, 20.0));
	return 0;
}
