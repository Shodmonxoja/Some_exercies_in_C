#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMatrix(int** , int);

int main(){
    FILE *fptr = fopen("info.txt", "r");
    int n = 2;
    int **sudoku = malloc(n*n*sizeof(int*));
    for(int i=0;i<n*n;i++){
        sudoku[i]=malloc(n*n*sizeof(int));
    }
    for(int i=0;i<n*n;i++){
        for(int j=0;j<n*n; j++){
            fscanf(fptr, "%d", &sudoku[i][j]);
        }
    }
    printMatrix(sudoku, n*n);
    fclose(fptr);
    return 0;
}

int solve_(int step,int **sudoku, int n){
    if(step >= n*n){
        return 1;
    }
    int i = step / n;
    int j = step % n;
    if(sudoku[i][j] != 0){
        return solve_(step+1, sudoku, n);
    }

}

int check_sud(int step, int **sudoku, int n){
    int i = step / n;
    int j = step % n;
    int valc = sudoku[i][j];
    int block_size = (int)sqrt(n); 
    for(int ii = 0; ii<n;ii++){
        if(sudoku[ii][j]==valc && ii != i){
            return 0;
        }
    }
    for(int ii = 0; ii<n;ii++){
        if(sudoku[i][ii]==valc && ii != j){
            return 0;
        }
    }

}

void printMatrix(int **mat, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}