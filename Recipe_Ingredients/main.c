#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ingredient{
    char name[20];
    int amount;
}ingredient;

typedef struct recipe{
    char name[20];
    int price;
    int num_ing;
    ingredient *req_ing;
}recipe;

int main(){
    FILE *fptr = fopen("ingre.txt", "r");
    int n_ing;
    fscanf(fptr, "%d", &n_ing);
    ingredient *ingredients = malloc(n_ing*sizeof(ingredient));
    int i = 0;
    while(fscanf(fptr, "%s %d", ingredients[i].name, &ingredients[i].amount) != EOF){
        i++;
    }
    fclose(fptr);
    fptr = fopen("reciper.txt", "r");

    return 0;
}

recipe *create_recipe(char *name, int num_ing, int price){
    recipe *recipe_;
    recipe_->num_ing = num_ing;
    recipe_->price = price;
    strcpy(recipe_->name, name);
    recipe_->req_ing = malloc(num_ing*sizeof(ingredient));
    
    return recipe_;
}