#include "../hdrs/tests.h"
#include "../hdrs/library.h"
#include "assert.h"

void runTests() {
    testCreationOfGraph();
    testAdditionOfVertex();
    testRemovalOfVertex();
    testConnection();
}

void testCreationOfGraph() {
    graph testGraph = createGraph(5);
    assert(testGraph->size == 5);
    for (int i = 0; i < testGraph->size; i++) {
        assert(testGraph->list[i]->number == i + 1);
    }
    clearMemory(testGraph);
}

void testAdditionOfVertex() {
    graph testGraph = createGraph(5);
    int oldSize = testGraph->size;
    addVertex(testGraph);
    int newSize = testGraph->size;
    assert((oldSize + 1) == newSize);
    assert(testGraph->list[newSize - 1]->number == newSize);
    clearMemory(testGraph);
}

void testRemovalOfVertex() {
    graph testGraph = createGraph(5);
    int oldSize = testGraph->size;
    assert(testGraph->list[2]->number == 3);
    deleteVertex(testGraph, 3);
    int newSize = testGraph->size;
    assert((oldSize - 1) == newSize);
    assert(testGraph->list[2]->number == 4);
    clearMemory(testGraph);
}

void testConnection() {
    graph testGraph = createGraph(4);
    connect(testGraph, 1, 2);
    assert(testGraph->list[0]->connections == 1 && testGraph->list[0]->neighbours[0] == 2);
    assert(testGraph->list[1]->connections == 1 && testGraph->list[1]->neighbours[0] == 1);
    connect(testGraph, 1, 3);
    assert(testGraph->list[0]->connections == 2 && testGraph->list[0]->neighbours[1] == 3);
    connect(testGraph, 1, 4);
    assert(testGraph->list[0]->connections == 3 && testGraph->list[0]->neighbours[2] == 4);
    deleteVertex(testGraph, 3);
    assert(testGraph->list[0]->connections == 2 && testGraph->list[0]->neighbours[1] == 4);
    clearMemory(testGraph);
}