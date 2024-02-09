CC = gcc
CFLAGS = -Wall

.PHONY: all clean

all: my_graph my_Knapsack

my_graph: my_graph.o my_mat.o
	$(CC) $(CFLAGS) -o my_graph my_graph.o my_mat.o

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c my_graph.c -o my_graph.o

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c -o my_mat.o

my_Knapsack: my_Knapsack.o
	$(CC) $(CFLAGS) -o my_Knapsack my_Knapsack.o

my_Knapsack.o: my_Knapsack.c
	$(CC) $(CFLAGS) -c my_Knapsack.c -o my_Knapsack.o

clean:
	rm -f *.o my_graph my_Knapsack