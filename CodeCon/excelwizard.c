/*
 * This program takes in an integer value as input and outputs its respective Microsoft Excel column label.
 * All integer values are assumed to be greater than 0.
 */

#include <stdio.h>

void convertBase(int b, int i){
	int multiple;
	char letter;

	multiple = (i-1)/26;
	letter = 65 + ((i-1) % b);

	if (multiple > 0){
		convertBase(b, multiple);
	}
	printf("%c", letter);
}

int main(){
	int base = 26;
	int value;

	scanf("%d", &value);
	convertBase(base, value);
	return 0;
}



