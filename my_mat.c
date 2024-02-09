#include <stdio.h>
#include "my_mat.h"

#define true 1
#define false 0

//Largest int
#define infinity 2147483647

// The distant matrix
int distances[vertices][vertices];

// Finding out if a path exist
int hasAPath(int source, int destination){

    // If there is no path
    if(distances[source][destination] == infinity || source == destination){
        return false;
    }

    // Then there is a path
    else{
        return true;
    }
}


void shortestPath(int matrix[vertices][vertices]) {

    //Initialize the distance matrix
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){

            //If the same vertex
            if(i == j){
                distances[i][j] = 0;
            }

            //If the two vertexes have a connection
            else if(matrix[i][j] != 0){
                distances[i][j] = matrix[i][j];
            }

            //If the two vertexes does not have a connection
            else{
                distances[i][j] = infinity;
            }
        }
    }


    //Calculate the shortest paths using Floyd-Warshall algorithm
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (distances[i][k] != infinity && distances[k][j] != infinity && distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }
}

// Print the distance
void printShortestPath(int source, int destination){
    if(distances[source][destination] == infinity || source == destination){
        printf("-1");
    }

    else{
        printf("%d", distances[source][destination]);
    }

    printf("\n");
}


