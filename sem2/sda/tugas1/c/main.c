/*
 * main.c
 *
 * Muhammad Daffa Rahman
 * L0124062
 *
 * ZuperZymple Calculator yang dapat melakukan operasi 2 angka sederhana (add, subtract, multiply, divide)
 */

#include <stdio.h>
#include <stdlib.h>

#include "math_operations.h"

// fungsi modular yang dapat digunakan untuk menampilkan perhitungan dan
// hasil dari fungsi add, subtract, multiply
void print_operation_int(int(func)(int, int), int a, int b, char operator)
{
    printf("%d %c %d = %d\n", a, operator, b, func(a, b));
}

// fungsi modular yang dapat digunakan untuk menampilkan perhitungan dan
// hasil khusus fungsi divide karena return type nya double
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

    // welcome!
    printf("Welcome to ZuperSymple Calculator\n\n");

    // prompt user untuk menginput nilai a dan b
    printf("enter a: ");
    scanf("%d", &a);
    printf("enter b: ");
    scanf("%d", &b);

    // prompt user untuk memilih ingin menampilkan operasi apa
    // bahkan user bisa memilih untuk menampilkan semua
    printf("\nWhat operation you want to do?\n"
           " 1. Add (+)\n"
           " 2. Subtract (-)\n"
           " 3. Multiply (*)\n"
           " 4. Divide (/)\n"
           " 5. All\n\n");

    printf("Selection: ");

    // terus prompt user ketika user tidak memilih opsi yang benar
    // opsi benar: (1,2,3,4,5)
    while (!(int_input > 0 && int_input <= 5))
    {
        fgets(str_input, 255, stdin);
        int_input = atoi(str_input);
    }

    // menampilkan hasil
    printf("\nResult:\n");

    // cek input
    switch (int_input)
    {
    // approach disini adalah jika user memilih 5 (pilih semua)
    // case 1-4 akan dieksekusi semua dikarenakan blok
    // if (int_input != 5)
    //     break;
    //
    // jika user tidak memilih 5 (memilih salah satu opsi),
    // tiap case dari 1 - 4 akan break
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
