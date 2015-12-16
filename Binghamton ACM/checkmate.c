/*
 * https://www.hackerrank.com/contests/bingacm-sep-15/challenges/checkmate-2
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char lines[5], i, *p;
    int num_lines;

    fgets(lines, 5, stdin);
    num_lines = atoi(lines);

    char input[num_lines][num_lines+5];
    for (i = 0; i < num_lines; i++){
        fgets(input[i], num_lines+5, stdin);

        if ((p = strchr(input[i], '\n')) != NULL){
            *p = '\0';
        }
    }

    // TODO:
    // Assuming King is already in check
    // For each of the empty tiles surrounding the King, check if the King would be in check if moved to that tile
    // For each tile surrounding the King with an enemy piece, check if that piece is protected

    // Use a matrix with binary values and bitwise OR to determine all attackable areas by black.


    return 0;
}

