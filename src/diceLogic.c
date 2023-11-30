#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "../include/dice.h"

ProcessedNumber handleRolls(unsigned int* randomNumbers, unsigned int rollCount) {
	unsigned int number = 0;
	ProcessedNumber pn = {0,0,0};
		
	for (int i = 0; i < rollCount; i++){
		number = randomNumbers[i];		
		if (number % 2 == 0){
			pn.evenCount++;
		}		
		if (number <= 2){
			pn.lessThanTwoCount++;
		}
		if (number == 6){
			pn.sixCount++;
		}
	}
	return pn;
}
