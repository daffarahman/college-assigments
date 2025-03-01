/*
 * test.c
 *
 * Muhammad Daffa Rahman
 * L0124062
 *
 * Test program untuk fungsi di math_operations.h
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "math_operations.h"
#include "termcolors.h"

// Struct untuk add, subtract, multiply
struct TestInt
{
	int a;
	int b;
	int result;
};

// Struct untuk divide (karena divide return-nya double)
struct TestDouble
{
	int a;
	int b;
	double result;
};

// Fungsi yang dapat digunakan oleh fungsi add, subtract, multiply
// Fungsi ini akan meng-iterasi array tests bertipe TestInt dan otomatis memasukkan nilai a, b ke fungsi
// dan membandingkannya dengan result
void do_int_test(int(func)(int, int), char *func_name, struct TestInt tests[], int number_of_tests)
{
	printf("%sStart test for function %s%s\n", COLOR_WARNING, func_name, COLOR_DEFAULT);

	for (int i = 0; i < number_of_tests; i++)
	{
		// menaruh tests[i].a, tests[i].b, tests[i].result, ke variable a, b, result
		// hanya untuk memudahkan keterbacaan kode
		int a = tests[i].a;
		int b = tests[i].b;
		int result = tests[i].result;

		// kita simpan test_result dalam bentuk boolean
		bool test_result = func(a, b) == result;

		// jika test_result adalah false tampilkan error kemudian exit dengan nilai return 1
		// __FILE__ == menampilkan nama file ini
		// __LINE__ == menampilkan baris ke berapa error ini
		// disini juga menampilkan iterasi ke berapa errornya sehingga, developer
		// dapat mengetahui indeks ke berapa dari tests yang salah
		if (!test_result)
		{
			fprintf(stderr, "%s%s:%d: failed on iteration i=%d: %s(%d, %d) == %d%s\nExited with exit code 1\n", COLOR_FAILED, __FILE__, __LINE__, i, func_name, a, b, result, COLOR_DEFAULT);
			exit(1);
		}
		// jika test_result adalah true atau sukses
		// tampilkan passed
		else
		{
			printf("test: %s: i=%d: %s(%d, %d) == %d ... %spassed%s\n", func_name, i, func_name, a, b, result, COLOR_PASSED, COLOR_DEFAULT);
		}
	}

	// setelah semua aman tidak ada error, akan ditampilkan bahwa semua test passed!
	printf("%sAll tests for %s passed%s\n\n", COLOR_PASSED, func_name, COLOR_DEFAULT);
}

// Fungsi yang dapat digunakan oleh fungsi divide dikarenakan return double
// Fungsi ini akan meng-iterasi array tests bertipe TestDouble dan otomatis memasukkan nilai a, b ke fungsi
// dan membandingkannya dengan result
void do_double_test(double(func)(int, int), char *func_name, struct TestDouble tests[], int number_of_tests)
{
	printf("%sStart test for function %s%s\n", COLOR_WARNING, func_name, COLOR_DEFAULT);

	for (int i = 0; i < number_of_tests; i++)
	{
		int a = tests[i].a;
		int b = tests[i].b;
		double result = tests[i].result;

		// approach perbandingan disini tidak menggunakan "==" dikarenakan
		// dapat beresiko akibat dari hasil floating point yang tidak presisi
		bool test_result = fabs(func(a, b) - result) < 1e-9;

		// jika test_result adalah false tampilkan error kemudian exit dengan nilai return 1
		// __FILE__ == menampilkan nama file ini
		// __LINE__ == menampilkan baris ke berapa error ini
		// disini juga menampilkan iterasi ke berapa errornya sehingga, developer
		// dapat mengetahui indeks ke berapa dari tests yang salah
		if (!test_result)
		{
			fprintf(stderr, "%s%s:%d: failed on iteration i=%d: fabs(%s(%d, %d) - %.2f) < 1e-9%s\nExited with exit code 1\n", COLOR_FAILED, __FILE__, __LINE__, i, func_name, a, b, result, COLOR_DEFAULT);
			exit(1);
		}
		// jika test_result adalah true atau sukses
		// tampilkan passed
		else
		{
			printf("test: %s: i=%d: fabs(%s(%d, %d) - %.2f) < 1e-9 ... %spassed%s\n", func_name, i, func_name, a, b, result, COLOR_PASSED, COLOR_DEFAULT);
		}
	}

	// setelah semua aman tidak ada error, akan ditampilkan bahwa semua test passed!
	printf("%sAll tests for %s passed%s\n", COLOR_PASSED, func_name, COLOR_DEFAULT);
}

int main()
{
	// Tests yang akan dimasukan ke fungsi test
	// {a, b, result}
	struct TestInt tests_add[5] = {{2, 5, 7}, {3, 5, 8}, {9, 5, 14}, {7, 8, 15}, {10, 10, 20}};
	struct TestInt tests_subtract[5] = {{7, 5, 2}, {4, 5, -1}, {10, 5, 5}, {8, 4, 4}, {9, 9, 0}};
	struct TestInt tests_multiply[5] = {{4, 2, 8}, {3, 5, 15}, {4, 5, 20}, {9, 5, 45}, {10, 10, 100}};
	struct TestDouble tests_divide[5] = {{5, 2, 2.5}, {4, 5, 0.8}, {8, 4, 2.0}, {10, 2, 5.0}, /*test untuk pembagian dengan 0 -> */ {10, 0, NAN}};

	// Lakukan test
	// Urutan parameter: fungsi, nama fungsi, tests array, banyak test yang dilakukan atau panjang tests array
	do_int_test(add, "add", tests_add, 5);
	do_int_test(subtract, "subtract", tests_subtract, 5);
	do_int_test(multiply, "multiply", tests_multiply, 5);
	do_double_test(divide, "divide", tests_divide, 5);

	return 0;
}
