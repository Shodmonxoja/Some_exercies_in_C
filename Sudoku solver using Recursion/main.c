#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMatrix(int**, int);

int main() {
    FILE* fptr = fopen("info.txt", "r");
    int n = 2;
    int** sudoku = malloc(n * n * sizeof(int*));
    for (int i = 0;i < n * n;i++) {
        sudoku[i] = malloc(n * n * sizeof(int));
    }
    for (int i = 0;i < n * n;i++) {
        for (int j = 0;j < n * n; j++) {
            fscanf(fptr, "%d", &sudoku[i][j]);
        }
    }
    printMatrix(sudoku, n * n);
    fclose(fptr);
    if (solve_(0, sudoku, n * n)) {
        printf("\nSolved: \n");
        printMatrix(sudoku, n * n);
    }
    return 0;
}

int solve_(int step, int** sudoku, int n) {
    if (step >= n * n) {
        return 1;
    }
    int i = step / n;
    int j = step % n;
    if (sudoku[i][j] != 0) {
        return solve_(step + 1, sudoku, n);
    }
    for (int k = 1; k <= n; k++) {
        sudoku[i][j] = k;
        if (check_sud(step, sudoku, n)) {
            if (solve_(step + 1, sudoku, n)) {
                return 1;
            }
        }
        sudoku[i][j] = 0;
    }
    return 0;
}

int check_sud(int step, int** sudoku, int n) {
    int i = step / n;
    int j = step % n;
    int valc = sudoku[i][j];
    int sqN = (int)floor(sqrt(n));
    int ib = floor(i / sqN);
    int jb = floor(j / sqN);
    for (int ii = 0; ii < n;ii++) {
        if (sudoku[ii][j] == valc && ii != i) {
            return 0;
        }
    }
    for (int ii = 0; ii < n;ii++) {
        if (sudoku[i][ii] == valc && ii != j) {
            return 0;
        }
    }
    int sI = ib * sqN;
    int sJ = jb * sqN;
    int eI = (ib * sqN) + sqN;
    int eJ = (jb * sqN) + sqN;
    for (int ii = sI; ii < eI; ii++) {
        for (int jj = sJ;jj < eJ; jj ++) {
            if (sudoku[ii][jj] == valc && (ii != i || jj != j)) {
                return 0;
            }
        }
    }

    return 1;
}

void printMatrix(int** mat, int n) {
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}