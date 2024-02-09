#include <stdio.h>
#include "my_mat.h"

#define true 1

int main() {

    char letter; // The letter we get from the user
    int weights[vertices][vertices]; // The weights of the graph
    int path; // Denote if a path exits
    int source; // The source of the path
    int destination; // The destination of the path

    // Initialize the weights to 0
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            weights[i][j] = 0;
        }
    }

    // Get chars from the user until he is asking to stop
    while(true){

        // Scan the letter
        scanf("%c", &letter);

        // Checking witch char we got
        switch (letter) {

            // In case of 'A' we set the matrix of weights
            case 'A':

                for (size_t i = 0; i < vertices; i++) {
                    for (size_t j = 0; j < vertices; j++) {
                        scanf(" %d", &weights[i][j]);
                    }
                }

                scanf(" ");

                //Initialize the shortest path table
                shortestPath(weights);

                break;

            // In case of 'B' find out if a path exists
            case 'B':
                scanf(" %d %d ", &source, &destination);
                path = hasAPath(source, destination);

                if(path == true){
                    printf("True\n");
                }

                else{
                    printf("False\n");
                }

                break;

            // In case of 'C' find the shortest path
            case 'C':
                scanf(" %d %d ", &source, &destination);
                printShortestPath(source, destination);
                break;

            // In case of 'D' or EOF stop the program
            case ('D' || EOF):
                return 0;
        }
    }
}
