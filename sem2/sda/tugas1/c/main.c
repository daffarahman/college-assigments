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

#include "math_operations.h"

// fungsi clear screen yang dapat work di windows dan non-windows (mac, linux)
void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void print_add(int a, int b)
{
    printf("%d + %d = %d\n", a, b, add(a, b));
}

void print_subtract(int a, int b)
{
    printf("%d + %d = %d\n", a, b, subtract(a, b));
}

void print_multiply(int a, int b)
{
    printf("%d + %d = %d\n", a, b, multiply(a, b));
}

void print_divide(int a, int b)
{
    printf("%d + %d = %.2f\n", a, b, divide(a, b));
}

int main()
{
    // variabel a, b yang akan digunakan untuk melakukan operasi
    int a, b;

    // input akan menerima char* kemudian dirubah ke int menggunakan fungsi atoi()
    char *str_input = (char *)malloc(sizeof(char) * 255);
    int int_input = 0;

    clear_screen();

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
        print_add(a, b);
        if (int_input != 5)
            break;
    case 2:
        print_subtract(a, b);
        if (int_input != 5)
            break;
    case 3:
        print_multiply(a, b);
        if (int_input != 5)
            break;
    case 4:
        print_divide(a, b);
        if (int_input != 5)
            break;
    }
}
