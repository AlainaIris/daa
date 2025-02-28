#include <cstdio>

struct Matrix {
	int** vals;
	int rows;
	int cols;
};

int mmbestcase(Matrix* matricies, int size) {
	int** table = new int*[size];
	for (int i = 0; i < size; i++) {
		table[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		table[i][i] = 0;
	}
	for (int len = 1; len < size; len++) {
		for (int i = 0; i < size - len; i++) {
			int j = i + len;
			table[i][j] = 0x7fffffff;
			for (int k = i; k < j; k++) {
				int calculations = table[i][k] + table[k + 1][j] + matricies[i].rows * matricies[k].cols * matricies[j].cols;
				if (calculations < table[i][j]) {
					table[i][j] = calculations;
				}
			}
		}
	}
	int result = table[0][size - 1];
	for (int i = 0; i < size; i++) {
		delete table[i];
	}
	delete table;
	return result;
}

Matrix newmatrix(int n, int m) {
	Matrix matrix;
	int** vals = new int*[n];
	for (int i = 0; i < n; i++) {
		vals[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			vals[i][j] = 1;
		}
	}
	matrix.vals = vals;
	matrix.rows = n;
	matrix.cols = m;
	return matrix;
}

int main() {
	Matrix matricies[6] = { newmatrix(10, 10), newmatrix(10, 20), newmatrix(20, 5), newmatrix(5, 100), newmatrix(100, 30), newmatrix(30, 40) };
	int optimal = mmbestcase(matricies, 6);
	for (int i = 0; i < 6; i++) {
		Matrix m = matricies[i];
		for (int i = 0; i < m.rows; i++) {
			delete m.vals[i];
		}
	}
	printf("%d", optimal);
	return 0;
}
