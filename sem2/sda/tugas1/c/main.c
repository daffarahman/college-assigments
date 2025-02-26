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

// definitions for bitwise operation
#define ADD 1
#define SUBTRACT 2
#define MULTIPLY 3
#define DIVIDE 4

// fungsi clear screen yang dapat work di windows dan non-windows (mac, linux)
void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    // variabel a, b yang akan digunakan untuk melakukan operasi
    int a, b;

    // input akan menerima char* kemudian dirubah ke int menggunakan fungsi atoi()
    char *str_input = (char *)malloc(sizeof(char) * 255);
    int int_input = 0;

    for (;;)
    {
        printf("Welcome to ZuperSymple Calculator\n\n");

        printf("enter a: ");
        scanf("%d", &a);

        printf("enter b: ");
        scanf("%d", &b);

        printf("What operation you want to do?\n"
               " 1. Add\n"
               " 2. Subtract\n"
               " 3. Multiply\n"
               " 4. Divide\n");
    }
}
