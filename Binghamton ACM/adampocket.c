/*
 * https://www.hackerrank.com/contests/bingacm-sep-15/challenges/adams-pockets
 *
 * This program determines the unique items in two people's pockets.
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char friend[100];
    char adam[4];
    scanf("%s", friend);

    char items[100][100];
    char unique[100][100];
    int i, j, k, m, isDone = 0;

    char current[100];

    // Get first pocket items
    while (!isDone){
        scanf("%s", current);
        if (strcmp(current, "Adam") != 0){
            strcpy(items[i++], current);
        }
        else {
            isDone = 1;
        }
    }


    // Get second pocket items
    isDone = 0;
    while (!isDone){
        scanf("%s", current);
        if (strcmp(current, "END") != 0){
            strcpy(items[i++], current);
        }
        else {
            isDone = 1;
        }
    }

    // TODO: implement better sorting algorithm
    for (m = 1; m < i; m++){
        for (j = 1; j < i; j++){
            if(strcmp(items[j-1], items[j]) > 0){
                char temp[100];
                strcpy(temp, items[j-1]);
                strcpy(items[j-1], items[j]);
                strcpy(items[j], temp);
            }
        }
    }

    strcpy(unique[k++], items[0]);
    for (j = 1; j < i; j++){
        if(strcmp(items[j], items[j-1]) != 0){
            strcpy(unique[k++], items[j]);
        }
    }

    printf("%d {", k);
    for (j = 0; j < k-1; j++){
        printf("%s, ", unique[j]);
    }
    printf("%s}", unique[k-1]);

    return 0;
}
