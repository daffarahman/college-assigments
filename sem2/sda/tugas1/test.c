#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

#include "math_operations.h"

#define COLOR_FAILED	"\x1b[31m"
#define COLOR_SUCCESS	"\x1b[32m"

void test_add() {
	assert(add(2, 5) == 7);
	assert(add(4, 5) == 9);
	assert(add(0, 0) == 0);
	assert(add(100, 155) == 255);
	assert(add(999, 999) == 1998);

	printf("%sAll test for 'add' succeed\n", COLOR_SUCCESS);
}

void test_subtract() {
	assert(subtract(10, 5) == 5);
	assert(subtract(9, 7) == 2);
	assert(subtract(2, 5) == -3);
	assert(subtract(100, 5) == 95);
	assert(subtract(999, 999) == 0);
	
	printf("%sAll test for 'subtract' succeed\n", COLOR_SUCCESS);
}

int main() {
	test_add();
	test_subtract();
}
