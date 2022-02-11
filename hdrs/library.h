#include <stdio.h>
#include <stdbool.h>
#ifndef CLIB_LIBRARY_H
#define CLIB_LIBRARY_H

typedef struct item {
    bool seen;
    int number;
    int connections;
    int *neighbours;
} *vertex;

typedef struct graphList {
    int size;
    vertex *list;
} *graph;

graph createGraph(int size); //создание графа
void addVertex(graph currentGraph); //добавление вершины
void deleteVertex(graph currentGraph, int item); //удаление вершины
void connect(graph currentGraph, int first, int second); //соединение двух верщин
void checkGraph(graph currentGraph);
void clearMemory(graph currentGraph); //очистка памяти
void sortNilsInArray(int* array, int size);
int* search(graph currentGraph, int knownVertex, int unknownVertex); //поиск в глубину
void sortVertices(graph currentGraph, int size);
int* recursiveSearch(vertex current, int steps, int* way, graph currentGraph, int unknownVertex);
graph readFromFile(FILE* fileToRead, int size); //чтение из файла
void writeInFile(graph currentGraph, FILE* fileToWrite); //запись в файл


#endif //CLIB_LIBRARY_H
