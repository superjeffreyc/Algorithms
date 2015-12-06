/*
 * https://www.hackerrank.com/contests/bingacm-sep-15/challenges/the-return-of-loud-ajmal
 *
 * This program determines if a string (mix of upper and lower case) contains ingredients for menu items.
 * The menu item with the highest number of matching ingredients will be printed,
 * otherwise "repeat that" is printed.
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int numMenu, numOrders, i, j, k;
    char menuInt[10], ordersInt[10];
    char *item;

    // Get menu
    fgets(menuInt, 10, stdin);
    numMenu = atoi(menuInt);
    int menuLength[numMenu];
    char menu[numMenu][100];
    char menuArray[numMenu][100][20];
    for (i = 0; i < numMenu; i++){
        fgets(menu[i], 100, stdin);
    }


    // Get orders
    fgets(ordersInt, 10, stdin);
    numOrders = atoi(ordersInt);
    char orders[numOrders][100];
    int menuCount[numOrders][numMenu];

    for (i = 0; i < numOrders; i++){
        fgets(orders[i], 100, stdin);
    }

    // Split menu into array
    for (i = 0; i < numMenu; i++){
        item = strtok(menu[i], " \t\n");
        j = 0;
        while (item != NULL){
            strcpy(menuArray[i][j++], item);
            item = strtok(NULL, " \t\n");
        }
        menuLength[i] = j;
    }

    // Convert orders to lowercase

    for (i = 0; i < numOrders; i++){
        j = 0;
        while (orders[i][j]){
            orders[i][j] = tolower(orders[i][j]);
            j++;
        }
    }


    for (k = 0; k < numOrders; k++){
        for (i = 0; i < numMenu; i++){
            for (j = 0; j < menuLength[i]; j++){
                if (strstr(orders[k], menuArray[i][j])){
                    menuCount[k][i]++;
                }
            }
        }

        int max = 0;
        int index = 0;
        int tie = 0;
        for (i = 0; i < sizeof(menuCount[k])/sizeof(int); i++){
            if (menuCount[k][i] > max){
                max = menuCount[k][i];
                index = i;
                tie = 0;
            }
            else if (menuCount[k][i] == max){
                tie = 1;
            }
        }

        if (max == 0 || tie == 1){
            printf("repeat that\n");
        }
        else {
            printf("%s\n", menuArray[index][0]);
        }
    }


    return 0;
}

