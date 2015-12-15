/*
 * https://www.hackerrank.com/contests/bingacm-sep-15/challenges/abo-factors
 *
 * This program takes as input the blood type and Rh factors from two parents and determines
 * all possible child combinations of blood type and Rh factors.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Global variables
int len = 0;
char possible[5][5];

/*
 * Updates the global variable to hold all combinations of two parent blood types.
 */
void get_possible(char *a, char *b){

	if (strcmp(a, "A") == 0 && strcmp(b, "A") == 0){
		strcpy(possible[0], "A");
		strcpy(possible[1], "O");
		len = 2;
	}
	else if (strcmp(a, "A") == 0 && strcmp(b, "B") == 0){
		strcpy(possible[0], "A");
		strcpy(possible[1], "AB");
		strcpy(possible[2], "B");
		strcpy(possible[3], "O");
		len = 4;

	}
	else if (strcmp(a, "A") == 0 && strcmp(b, "AB") == 0){
		strcpy(possible[0], "A");
		strcpy(possible[1], "AB");
		strcpy(possible[2], "B");
		len = 3;
	}
	else if (strcmp(a, "A") == 0 && strcmp(b, "O") == 0){
		strcpy(possible[0], "A");
		strcpy(possible[1], "O");
		len = 2;
	}
	else if (strcmp(a, "B") == 0 && strcmp(b, "B") == 0){
		strcpy(possible[0], "B");
		strcpy(possible[1], "O");
		len = 2;
	}
	else if (strcmp(a, "B") == 0 && strcmp(b, "AB") == 0){
		strcpy(possible[0], "A");
		strcpy(possible[1], "AB");
		strcpy(possible[2], "B");
		len = 3;
	}
	else if (strcmp(a, "B") == 0 && strcmp(b, "O") == 0){
		strcpy(possible[0], "B");
		strcpy(possible[1], "O");
		len = 2;
	}
	else if (strcmp(a, "AB") == 0 && strcmp(b, "AB") == 0){
		strcpy(possible[0], "A");
		strcpy(possible[1], "AB");
		strcpy(possible[2], "B");
		len = 3;
	}
	else if (strcmp(a, "AB") == 0 && strcmp(b, "O") == 0){
		strcpy(possible[0], "A");
		strcpy(possible[1], "B");
		len = 2;
	}
	else if (strcmp(a, "O") == 0 && strcmp(b, "O") == 0){
		strcpy(possible[0], "O");
		len = 1;
	}
	else {
		get_possible(b, a);
	}


}

int main() {

    int numLines, i, j;
    char firstLine[10];

    fgets(firstLine, 10, stdin);
    numLines = atoi(firstLine);

    char lines[numLines][15], lineArray[numLines][3][4], *item;
    char letter[2][4], sign[2][1];

    // Parse input into array of string
    for (i = 0; i < numLines; i++){
        fgets(lines[i], 15, stdin);
        item = strtok(lines[i], " \t\n");
        j = 0;
        while (item != NULL){
            strcpy(lineArray[i][j++], item);
            item = strtok(NULL, " \t\n");
        }
    }

    for (i = 0; i < numLines; i++){

    	// Get sign from string
    	char sign0 = lineArray[i][0][strlen(lineArray[i][0]) - 1];
    	char sign1 = lineArray[i][1][strlen(lineArray[i][1]) - 1];
    	sign[0][0] = sign0;
    	sign[1][0] = sign1;

    	// Replace sign with null character and get blood type as string
    	lineArray[i][0][strlen(lineArray[i][0]) - 1] = '\0';
    	lineArray[i][1][strlen(lineArray[i][1]) - 1] = '\0';
    	strcpy(letter[0], lineArray[i][0]);
    	strcpy(letter[1], lineArray[i][1]);

    	// Update global variable with possible child blood type combinations
    	get_possible(letter[0], letter[1]);

    	for (j = 0; j < len; j++){

    		// Handle sign combinations
    		if (strcmp(sign[0], "-") != 0 && strcmp(sign[1], "-") != 0){
    			printf("%s+ %s- ", possible[j], possible[j]);
    		}
    		else {
    			printf("%s- ", possible[j]);
    		}
    	}

    	printf("\n");

    }


    return 0;
}

