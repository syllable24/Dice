#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "../include/dice.h"

void exitWithUsage();

int main(int argc, char* argv[]){	
	InputFlags inputFlags = {false,10};
	
	if (argc > 1){
		handleInputFlags(argc, argv, &inputFlags);
	}
	
	printf("Bestimme %d ZufallsZahlen\n", inputFlags.rollCount);		
	
	srand(time(NULL));	
	unsigned int* randomNumbers = (unsigned int*)malloc(inputFlags.rollCount * sizeof(unsigned int));
	printf("Zufallszahlen: ");
	for (int i = 0; i < inputFlags.rollCount; i++){		
		randomNumbers[i] = rand() % 6 + 1;
		char* outputFormat = (i != (inputFlags.rollCount-1)) ? "%d, " : "%d\n";
		printf(outputFormat, randomNumbers[i]);
	}
	
	ProcessedNumber pn = handleRolls(randomNumbers, inputFlags.rollCount);
	
	free(randomNumbers);
	
	printf("Volle Auswertung: \n");	
	printf("Es sind %d Sechser gekommen \n", pn.sixCount);
	printf("Es waren %d gerade Zahlen dabei\n", pn.evenCount);
	printf("Es waren %d Einser und Zweier dabei\n", pn.lessThanTwoCount);	
}

void handleInputFlags(int argc, char* argv[], InputFlags* flags) {
	for (int i = 1; i < argc; i++){		
		if ((strcmp(argv[i], "-c") == 0) && ((i + 1) <= argc)){
			char* rollCountInput = argv[i + 1];
			int parseResult = atoi(rollCountInput);
			if (parseResult <= 0){
				printf("Parse Result <= 0, defaulting to 10!\n");
				parseResult = 10;
			}
			flags->rollCount = parseResult;
			i++;
		}
		else {
			exitWithUsage();
		}
	}
}

void exitWithUsage(){
	printf("Usage: a.exe [-t] [-c RollCount]\n");
	exit(-1);
}
