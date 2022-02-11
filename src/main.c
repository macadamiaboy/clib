#include "../hdrs/library.h"
#include "../src/library.c"
#include "../hdrs/tests.h"
#include "../src/tests.c"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("\nReceived arguments are wrong \n");
        return 1;
    }

    int size;
    sscanf(argv[1], "%d", &size);

    FILE *fileToRead;
    FILE *fileToWrite;

    fileToRead = fopen(argv[2],"r");
    if (fileToRead == NULL) {
        printf("Files are not available \n");
        fclose(fileToRead);
        return 1;
    }
    graph currentGraph = readFromFile(fileToRead, size);

    fileToWrite = fopen(argv[3],"w");
    if (fileToWrite == NULL) {
        printf("Files are not available \n");
        fclose(fileToWrite);
        return 1;
    }
    else {
        writeInFile(currentGraph, fileToWrite);
    }

    runTests();

    fclose(fileToWrite);
    fclose(fileToRead);
    clearMemory(currentGraph);
    return 0;
}