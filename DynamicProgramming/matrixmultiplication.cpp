int* mmorder(int* matricies) {
	return 0;
}

int* newmatrix(int n, int m) {
	int* matrix[n] = new int[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			matrix[i][j] = 1;
		}
	}
	return matrix;
}

int main() {
	int* matricies[1] = { newmatrix(10, 10) };
	return 0;
}
