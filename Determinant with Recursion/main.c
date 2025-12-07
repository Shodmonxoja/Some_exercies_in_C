#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ipow(int base, int exp) {
	int result = 1;
	while (exp > 0) {
		result *= base;
		exp--;
	}
	return result;
}

float recurr(int i, int n, int** mat) {
	int j = 0;
	if (i >= n) {
		return 0;
	}
	int** sm_mat = malloc((n - 1) * sizeof(int*));
	for (int k = 0;k < n - 1;k++) {
		sm_mat[k] = malloc((n - 1) * sizeof(int));
	}
	int v = 0, m = 0;
	for (int k = 0; k < n; k++) {
		if (k == 0) continue;
		v = 0;
		for (int l = 0; l < n; l++) {
			if (l == i) continue;
			sm_mat[m][v] = mat[k][l];
			v++;
		}
		m++;
	}
	float res = ipow(-1, i + j) * mat[j][i] * (sm_mat[0][0] * sm_mat[1][1] - sm_mat[0][1] * sm_mat[1][0]);
	return res + recurr(i + 1, n, mat);
}

int main(void)
{
	FILE* fptr = fopen("info.txt", "r");
	int n = 3;
	int** matrix_ = malloc(n * sizeof(int*));
	for (int i = 0;i < n;i++) {
		matrix_[i] = malloc(n * sizeof(int));
	}
	for (int i = 0;i < n;i++) {
		fscanf(fptr, "%d %d %d", &matrix_[i][0], &matrix_[i][1], &matrix_[i][2]);
	}
	/*for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			printf("%d ", matrix_[i][j]);
		}
		printf("\n");
	}*/
	if (!fptr) {
		printf("FAIL");
		return 1;
	}
	float sas = recurr(0, n, matrix_);
	printf("%f", sas);
	fclose(fptr);
	return 0;
}