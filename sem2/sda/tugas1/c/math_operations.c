#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "math_operations.h"
#include "termcolors.h"

int add(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

double divide(int a, int b)
{
	if (b == 0)
	{
		fprintf(stderr, "%s%s:%d - DivisionByZeroError: divide(%d, %d): Can't divide a number with zero! (b cannot be equal to 0)%s\nExited with exit code 1\n", COLOR_FAILED, __FILE__, __LINE__, a, b, COLOR_DEFAULT);
		exit(1);
	}
	return (double)a / (double)b;
}
