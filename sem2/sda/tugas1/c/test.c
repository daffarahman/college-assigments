/*
 * test.c
 *
 * Muhammad Daffa Rahman
 * L0124062
 *
 * Test program for functions in math_operations.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

#include "math_operations.h"
#include "termcolors.h"

struct TestInt
{
	int a;
	int b;
	int result;
};

struct TestDouble
{
	int a;
	int b;
	double result;
};

void do_int_test(int(func)(int, int), char *func_name, struct TestInt tests[], int number_of_tests)
{
	printf("%sstart test for function %s%s\n", COLOR_WARNING, func_name, COLOR_DEFAULT);

	for (int i = 0; i < number_of_tests; i++)
	{
		int a = tests[i].a;
		int b = tests[i].b;
		int result = tests[i].result;

		bool test_result = func(a, b) == result;
		if (!test_result)
		{
			fprintf(stderr, "%s%s:%d, on iteration i=%d, DivisionByZeroError: Can't divide a number with zero! (b cannot be equal to 0)%s\nExited with exit code 1\n", COLOR_FAILED, __FILE__, __LINE__, i, COLOR_DEFAULT);
			exit(1);
		}
		else
		{
			printf("test: %s: i=%d: %s(%d, %d) == %d ... %spassed%s\n", func_name, i, func_name, a, b, result, COLOR_PASSED, COLOR_DEFAULT);
		}
	}

	printf("%sAll tests for %s passed%s\n\n", COLOR_PASSED, func_name, COLOR_DEFAULT);
}

void do_double_test(double(func)(int, int), char *func_name, struct TestDouble tests[], int number_of_tests)
{
	printf("%sstart test for function %s%s\n", COLOR_WARNING, func_name, COLOR_DEFAULT);

	for (int i = 0; i < number_of_tests; i++)
	{
		int a = tests[i].a;
		int b = tests[i].b;
		double result = tests[i].result;

		bool test_result = fabs(func(a, b) - result) < 1e-9;
		if (!test_result)
		{
			fprintf(stderr, "%s%s:%d: failed on iteration i=%d: fabs(%s(%d, %d) - %.2f) < 1e-9%s\nExited with exit code 1\n", COLOR_FAILED, __FILE__, __LINE__, i, func_name, a, b, result, COLOR_DEFAULT);
			exit(1);
		}
		else
		{
			printf("test: %s: i=%d: fabs(%s(%d, %d) - %.2f) < 1e-9 ... %spassed%s\n", func_name, i, func_name, a, b, result, COLOR_PASSED, COLOR_DEFAULT);
		}
	}

	printf("%sAll tests for %s passed%s\n", COLOR_PASSED, func_name, COLOR_DEFAULT);
}

int main()
{
	struct TestInt tests_add[5] = {{2, 5, 7}, {3, 5, 8}, {9, 5, 14}, {7, 8, 15}, {10, 10, 20}};
	struct TestInt tests_subtract[5] = {{7, 5, 2}, {4, 5, -1}, {10, 5, 5}, {8, 4, 4}, {9, 9, 0}};
	struct TestInt tests_multiply[5] = {{4, 2, 8}, {3, 5, 15}, {4, 5, 20}, {9, 5, 45}, {10, 10, 100}};
	struct TestDouble tests_divide[5] = {{5, 2, 2.5}, {4, 5, 0.8}, {8, 4, 2.0}, {10, 2, 5.0}, {10, 0, NAN}};

	do_int_test(add, "add", tests_add, 5);
	do_int_test(subtract, "subtract", tests_subtract, 5);
	do_int_test(multiply, "multiply", tests_multiply, 5);
	do_double_test(divide, "divide", tests_divide, 5);

	return 0;
}
