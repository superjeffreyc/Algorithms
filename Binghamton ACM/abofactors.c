/*
 * https://www.hackerrank.com/contests/bingacm-sep-15/challenges/abo-factors
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int numLines, i, j;
    char firstLine[10];
    fgets(firstLine, 10, stdin);
    numLines = atoi(firstLine);
    char lines[numLines][15], lineArray[numLines][3][4], *item;

    for (i = 0; i < numLines; i++){
        fgets(lines[i], 15, stdin);
        item = strtok(lines[i], " \t\n");
        j = 0;
        while (item != NULL){
            strcpy(lineArray[i][j++], item);
            item = strtok(NULL, " \t\n");
        }
    }

    // debug
    for (i = 0; i < numLines; i++){
        for (j = 0; j < 2; j++){
            printf("%s ", lineArray[i][j]);
        }
        printf("\n");
    }

    //TODO: parse input


    return 0;
}

