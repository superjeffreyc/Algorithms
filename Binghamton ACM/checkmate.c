/*
 * https://www.hackerrank.com/contests/bingacm-sep-15/challenges/checkmate-2
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void attackHV(int i, int j, int **matrix){
    // TODO
}

void attackDiagonal() {
    // TODO
}

int main() {

    char lines[5], i, j, k, *p;
    int num_lines, iKing, jKing, iAdd, jAdd, itemp, jtemp;

    fgets(lines, 5, stdin);
    num_lines = atoi(lines);

    char input[num_lines][num_lines+5];
    int matrix[num_lines][num_lines];

    for (i = 0; i < num_lines; i++){
        fgets(input[i], num_lines+5, stdin);

        if ((p = strchr(input[i], '\n')) != NULL){
            *p = '\0';
        }
    }

    // Initialize array to 0
    for (i = 0; i < num_lines; i++){
    	for (j = 0; j < num_lines; j++){
            matrix[i][j] = 0;

            // Look for King
            if (input[i][j] == 'K'){
                iKing = i;
                jKing = j;
            }
        }
    }

    // Create a matrix of all attackable areas
    for (i = 0; i < num_lines; i++){
    	for (j = 0; j < num_lines; j++){
    		if (input[i][j] == 'R'){
                // Vertical attacks
                for (itemp = 0; itemp < num_lines; itemp++){
                    if (i != itemp){
                        matrix[itemp][j] = 1;
                    }
                }
                // Horizontal attacks
                for (jtemp = 0; jtemp < num_lines; jtemp++){
                    if (j != jtemp){
                        matrix[i][jtemp] = 1;
                    }
                }
            }
            else if (input[i][j] == 'Q'){
                // Vertical attacks
                for (itemp = 0; itemp < num_lines; itemp++){
                    if (i != itemp){
                        matrix[itemp][j] = 1;
                    }
                }
                // Horizontal attacks
                for (jtemp = 0; jtemp < num_lines; jtemp++){
                    if (j != jtemp){
                        matrix[i][jtemp] = 1;
                    }
                }

                // Diagonal attacks
                for (k = 0; k < 4; k++){
                    itemp = i;
                    jtemp = j;

                    switch(k){

                        case 0:
                            // Diagonal attack top left
                            iAdd = -1;
                            jAdd = -1;
                            break;
                        case 1:
                            // Diagonal attack top right
                            iAdd = -1;
                            jAdd = 1;
                            break;
                        case 2:
                            // Diagonal attack bottom left
                            iAdd = 1;
                            jAdd = -1;
                            break;
                        case 3:
                            // Diagonal attack bottom right
                            iAdd = 1;
                            jAdd = 1;
                            break;
                    }
                    while (itemp >= 0 && itemp < num_lines && jtemp >= 0 && jtemp < num_lines){
                        if (itemp != i && jtemp != j){
                            matrix[itemp][jtemp] = 1;
                        }
                        itemp += iAdd;
                        jtemp += jAdd;
                    }
                }

            }
            else if (input[i][j] == 'N'){

                // 8 possible knight attacks
                for (k = 0; k < 8; k++){
                    itemp = i;
                    jtemp = j;

                    switch(k){

                        case 0:
                            iAdd = -2;
                            jAdd = -1;
                            break;
                        case 1:
                            iAdd = -2;
                            jAdd = 1;
                            break;
                        case 2:
                            iAdd = -1;
                            jAdd = 2;
                            break;
                        case 3:
                            iAdd = 1;
                            jAdd = 2;
                            break;
                        case 4:
                            iAdd = 2;
                            jAdd = -1;
                            break;
                        case 5:
                            iAdd = 2;
                            jAdd = 1;
                            break;
                        case 6:
                            iAdd = -1;
                            jAdd = -2;
                            break;
                        case 7:
                            iAdd = 1;
                            jAdd = -2;
                            break;
                    }

                    itemp += iAdd;
                    jtemp += jAdd;

                    if (itemp >= 0 && itemp < num_lines && jtemp >= 0 && jtemp < num_lines){
                        matrix[itemp][jtemp] = 1;
                    }
                }
            }
            else if (input[i][j] == 'B'){

                // Diagonal attacks
                for (k = 0; k < 4; k++){
                    itemp = i;
                    jtemp = j;

                    switch(k){

                        case 0:
                            // Diagonal attack top left
                            iAdd = -1;
                            jAdd = -1;
                            break;
                        case 1:
                            // Diagonal attack top right
                            iAdd = -1;
                            jAdd = 1;
                            break;
                        case 2:
                            // Diagonal attack bottom left
                            iAdd = 1;
                            jAdd = -1;
                            break;
                        case 3:
                            // Diagonal attack bottom right
                            iAdd = 1;
                            jAdd = 1;
                            break;
                    }
                    while (itemp >= 0 && itemp < num_lines && jtemp >= 0 && jtemp < num_lines){
                        if (itemp != i && jtemp != j){
                            matrix[itemp][jtemp] = 1;
                        }
                        itemp += iAdd;
                        jtemp += jAdd;
                    }
                }
            }
    	}
    }

    // Check surrounding tiles to see if King is in checkmate
    char *message = "checkmate";
    for (i = iKing - 1; i <= iKing + 1; i++){
        for (j = jKing - 1; j <= jKing + 1; j++){
            if (i >= 0 && i < num_lines && j >= 0 && j < num_lines){
                if (matrix[i][j] == 0){
                    message = "safe";
                }
            }
        }
    }

    printf("%s", message);

    return 0;
}

