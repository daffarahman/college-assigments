#include <stdio.h>
#include "math_operations.h"

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("a + b = %d\n", add(a, b));
	printf("a - b = %d\n", subtract(a, b));
	printf("a * b = %d\n", multiply(a, b));
	printf("a / b = %.2f\n", divide(a, b));
}
