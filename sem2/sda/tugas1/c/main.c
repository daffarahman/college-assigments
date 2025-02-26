/*
 * main.c
 *
 * Muhammad Daffa Rahman
 * L0124062
 *
 * ZuperZymple Calculator that does simple operation of 2 number (add, subtract, multiply, divide)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "math_operations.h"

void print_operation_int(int(func)(int, int), int a, int b, char operator)
{
    printf("%d %c %d = %d\n", a, operator, b, func(a, b));
}

void print_operation_double(double(func)(int, int), int a, int b, char operator)
{
    printf("%d %c %d = %.2f\n", a, operator, b, func(a, b));
}

int main()
{
    // variabel a, b yang akan digunakan untuk melakukan operasi
    int a, b;

    // input akan menerima char* kemudian dirubah ke int menggunakan fungsi atoi()
    char *str_input = (char *)malloc(sizeof(char) * 255);
    int int_input = 0;

    printf("Welcome to ZuperSymple Calculator\n\n");

    printf("enter a: ");
    scanf("%d", &a);

    printf("enter b: ");
    scanf("%d", &b);

    printf("\nWhat operation you want to do?\n"
           " 1. Add (+)\n"
           " 2. Subtract (-)\n"
           " 3. Multiply (*)\n"
           " 4. Divide (/)\n"
           " 5. All\n\n");

    printf("Selection: ");
    while (!(int_input > 0 && int_input <= 5))
    {
        fgets(str_input, 255, stdin);
        int_input = atoi(str_input);
    }

    printf("\nResult:\n");

    switch (int_input)
    {
    case 5:
    case 1:
        print_operation_int(add, a, b, '+');
        if (int_input != 5)
            break;
    case 2:
        print_operation_int(subtract, a, b, '-');
        if (int_input != 5)
            break;
    case 3:
        print_operation_int(multiply, a, b, '*');
        if (int_input != 5)
            break;
    case 4:
        print_operation_double(divide, a, b, '/');
        if (int_input != 5)
            break;
    }
}
