#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "../include/dice.h"
#include "../include/diceTest.h"

void main(){
	bool result = doTests();
	if (result){
		exit(0);
	} 
	else {
		exit(-1);
	}	
}

bool doTests(){
	ProcessedNumber pn_expected = {7,3,5};
		
	int testValues[] = {2, 4, 1, 1, 6, 6, 6, 6, 6};
	int testValuesSize = sizeof(testValues) / sizeof(testValues[0]);
	
	ProcessedNumber pn_actual = handleRolls(testValues, testValuesSize);
		
	bool r1 = assertIntEquals("TEST 1: Even Count", pn_expected.evenCount, pn_actual.evenCount);
	bool r2 = assertIntEquals("TEST 2: LessThanTwoCount", pn_expected.lessThanTwoCount, pn_actual.lessThanTwoCount);
	bool r3 = assertIntEquals("TEST 3: SixCount", pn_expected.sixCount, pn_actual.sixCount);
	return r1 && r2 && r3;
}

bool assertIntEquals(char* testName, int expected, int actual){
	if (expected != actual){
		printf(
			"%s: Expected int = %d, actual was: %d \n", 
			testName,
			expected, 
			actual
		);
		return false;
	}
	else {
		printf("%s passed\n", testName); 
		return true;
	}
}
