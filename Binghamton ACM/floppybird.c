/*
 * This program calculates the highest scorers given a list of names and scores
 * The first line contains the number of lines to follow
 *
 * Example Input:
 *
 * 4
 * abc 10
 * def 20
 * ghi 20
 * jkl 30
 *
 * Example Output:
 *
 * def and ghi have the high score of 20
 *
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int * max(int *score, int size, int *winners){
    int i, j, k, max = -1;

    for (i = 0; i < size; i++){

       if (score[i] > max){
            j = 0;
            // Reset the array
            for (k = 0; k < size; k++){
                winners[k] = -1;
            }

            max = score[i];
            winners[j] = i;
            j++;
       }
       else if (score[i] == max){
            winners[j] = i;
            j++;
       }
    }

    return winners;
}


int main() {

    int numLines, i;
    scanf("%d", &numLines);

    char name[numLines][100];
    int score[numLines], highestScores[numLines];

    for (i = 0; i < numLines; i++){
        scanf("%s", name[i]);
        scanf("%d", &score[i]);
    }

    int *winner;
    winner = max(score, sizeof(score)/sizeof(int), highestScores);

    int numWinners = 0;
    for (i = 0; i < numLines; i++){
        if (*(winner + i) != -1){
            numWinners++;
        }
    }

    if (numWinners == 1){
        printf("%s has the high score of %d", name[winner[0]], score[winner[0]]);
    }
    else if (numWinners == 2){
        printf("%s and %s have the high score of %d", name[winner[0]], name[winner[1]], score[winner[0]]);
    }
    else if (numWinners > 2){
        for (i = 0; i < numWinners - 1; i++){
            printf("%s, ", name[winner[i]]);
        }
        printf("and %s have the high score of %d", name[winner[numWinners-1]], score[winner[0]]);
    }

    return 0;
}

