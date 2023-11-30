#include <stdbool.h>

#ifndef _ProcessedNumber_
#define _ProcessedNumber_
struct ProcessedNumber_s {
	unsigned int evenCount;
	unsigned int lessThanTwoCount;
	unsigned int sixCount;
};

typedef struct ProcessedNumber_s ProcessedNumber;

#endif

#ifndef _InputFlags_
#define _InputFlags_
struct InputFlags_s {
	bool testMode;
	unsigned int rollCount;	
};

typedef struct InputFlags_s InputFlags;
#endif

ProcessedNumber handleRolls(unsigned int* randomNumbers, unsigned int rollCount);

void handleInputFlags(int argc, char* argv[], InputFlags* flags);
