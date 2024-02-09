#include <stdio.h>

#define MaxWeight 20 // Maximum weight
#define Items 5 // Number of items
#define true 1
#define false 0
#define MaxStringLength 20 // Max length for a name of an item

int knapSack (int weights[MaxWeight], int values[Items] , int selected_bool[Items]);

int main(){
    char items[Items][MaxStringLength + 1]; // The + 1 is for /0 at the end of the string
    int values[Items] = {0};
    int weights[MaxWeight] = {0};

    // Get the values for the items
    for(size_t i = 0; i < Items; i++){
        scanf("%s %d %d", items[i], &values[i], &weights[i]);

        if(i < Items - 1){
            scanf(" ");
        }
    }

    int result[Items] = {0}; // The result array. It will indicate if we took the item

    // Finding the maximum profit possible
    int MaxProfit = knapSack(weights, values, result);

    // Printing the information
    printf("Maximum profit: %d\n", MaxProfit);
    printf("Selected items:");

    // Printing the selected items
    for(size_t i = 0; i < Items; i++){
        if(result[i] == true){
            printf(" %s", items[i]);
        }
    }

    return 0;
}

int knapSack (int weights[MaxWeight], int values[Items] , int selected_bool[Items]){
    int matrix[Items + 1][MaxWeight + 1];

    // Initialize the matrix with zeros
    for (size_t i = 0; i <= Items; i++) {
        for (size_t j = 0; j <= MaxWeight; j++) {
            matrix[i][j] = 0;
        }
    }

    // Fill the matrix using dynamic programming
    for (size_t i = 1; i <= Items; i++) {
        for (size_t j = 1; j <= MaxWeight; j++) {
            if (weights[i - 1] <= j) {
                matrix[i][j] = (values[i - 1] + matrix[i - 1][j - weights[i - 1]] > matrix[i - 1][j])
                        ? (values[i - 1] + matrix[i - 1][j - weights[i - 1]]) : matrix[i - 1][j];
            }

            else {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    // Find the items that will get us the maximum profit
    int totalWeight = MaxWeight;
    for (size_t i = Items; i > 0 ; i--) {
        if (matrix[i][totalWeight] != matrix[i - 1][totalWeight]) {
            selected_bool[i - 1] = true;
            totalWeight = totalWeight - weights[i - 1];
        }
    }

    return matrix[Items][MaxWeight];
}