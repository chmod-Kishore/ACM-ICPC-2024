#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 100

typedef struct graph{
    int vertices;
    int matrix[MAX_VERTICES][MAX_VERTICES];
}graph;

graph* create_graph(int vertices){
    graph* new_graph = (graph*)malloc(sizeof(graph));
    new_graph->vertices = vertices;
    for(int i=0;i<vertices;++i){
        for(int j=0;j<vertices;++j){
            new_graph->matrix[i][j] = 0;
        }
    }
    return new_graph;
}

void printGraph(graph* graph) {
    printf("Adjacency Matrix Representation:\n");
    for (int i=0;i<graph->vertices;++i) {
        for (int j=0;j<graph->vertices;++j) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void add_edge(graph* graph, int src, int dest){
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
int main(){
    int v = 5;
    graph* my_graph = create_graph(v);
    add_edge(my_graph,0,1);
    add_edge(my_graph,0,4);
    add_edge(my_graph,1,2);
    add_edge(my_graph,1,3);
    add_edge(my_graph,1,4);
    add_edge(my_graph,2,3);
    add_edge(my_graph,3,4);
    printGraph(my_graph);
    return 0;
}
