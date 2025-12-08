#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int magic_check(int** mat, int n);
void printMatrix(int** mat, int n);

void recurr(int pos, int n, int* nums, int** mat)
{
	if (pos == n * n) {
		if (magic_check(mat, n)) {
			printMatrix(mat, n);
			printf("\n");
		}
		return;
	}
	int i = pos / n;
	int j = pos % n;
	for (int k = 0; k < n * n; k++) {
		if (nums[k] != 0) {
			int temp = nums[k];
			nums[k] = 0;
			mat[i][j] = temp;
			recurr(pos + 1, n, nums, mat);
			nums[k] = temp;
		}
	}
}

int main(void)
{
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	int* nums = malloc(n * n * sizeof(int));
	for (int i = 0;i < n * n;i++) {
		nums[i] = i+1;
	}
	int** mat = malloc(n * sizeof(int*));
	for (int i = 0;i < n;i++) {
		mat[i] = malloc(n * sizeof(int));
	}
	recurr(0, n, nums, mat);
	free(nums);
	for (int i = 0;i < n;i++) {
		free(mat[i]);
	}
	free(mat);
	return 0;
}

void printMatrix(int** mat, int n) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}

int magic_check(int** mat, int n) {
	int magic_sum = (n * ((n * n) + 1)) / 2;
	for (int k = 0;k < n; k++) {
		int sum = 0;
		for (int l = 0;l < n; l++) {
			sum = sum + mat[k][l];
		}
		if (sum != magic_sum) return 0;
	}
	for (int k = 0;k < n; k++) {
		int sum = 0;
		for (int l = 0;l < n; l++) {
			sum = sum + mat[l][k];
		}
		if (sum != magic_sum) return 0;
	}
	int suma = 0;
	for (int k = 0;k < n; k++) {
		suma = suma + mat[k][k];
	}
	if (suma != magic_sum) return 0;
	int dc = n - 1;
	suma = 0;
	for (int k = 0;k < n; k++) {
		suma = suma + mat[k][dc];
		dc--;
	}
	if (suma != magic_sum) return 0;
	return 1;
}