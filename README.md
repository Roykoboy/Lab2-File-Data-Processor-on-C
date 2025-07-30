# Lab2-File-Data-Processor-on-C
# Project Name: File Data Processor
## Description:
This project is a C program that processes numerical data from input.txt and outputs the results to output.txt in various formats. Each function demonstrates different data processing techniques, such as converting numbers to ASCII characters, formatted output with indentation, controlling floating-point precision, and more.

## Features
1. Convert Numbers to ASCII Characters (task1)
  * Reads integers from input.txt.

  * Interprets them as ASCII codes and prints the corresponding characters.

  * Example:

       | Input:  | Output: |
       | ------  | ----------- |
       | 65 66 97 98 | A B a b     |

2. Formatted Number Output with Indentation (task2)
  * Reads integers and prints them with different indentation:

    * Even numbers: 5-space indent.

    * Odd numbers: 10-space indent.
* Example:

  * Input: 10 7

  * Output:
      ```
       10
            7
      ```
          
3. Floating-Point Numbers with Dynamic Precision (task3)
  * Reads floating-point numbers and prints them with decimal places equal to their position in the file.

* Example:

    * Input: 3.1415 2.718 1.5

    * Output:
      ```
        3.1
        2.72
        1.500
      ```
4. Number Output with Parity-Based Indentation (task4)
  * Reads integers and prints them with indentation:

    * Even numbers: 2-space indent.

    * Odd numbers: No indent.

  * Example:

    * Input: 4 3 8 5

    * Output: 4 3  8 5 

## What This Project Covers
✅ File handling in C (fopen, fclose, fscanf, fprintf).

✅ Formatted I/O (%d, %f, %c, %*d for padding).

✅ Conditional operations (even/odd checks).

✅ Dynamic output control (decimal precision, indentation).

✅ Error handling (file opening errors).

## How to Use
Create an input.txt file in the same directory as the program.

Fill it with numbers (integers or floats, depending on the task).

Run the program (by default, task1() is executed).

The result will appear in output.txt and in the console.

## Example Input (input.txt)
```
65 66 67 97 98 99
10 7
3.1415 2.718 1.5
4 3 8
```
## Code:
```C
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

void task1() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файла!\n");
        return;
    }

    int number;
    while (fscanf(inputFile, "%d", &number) != EOF) {
        fprintf(outputFile, "%c ", number);
        printf("%c ", number);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void task2() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файла!\n");
        return;
    }

    int number;
    while (fscanf(inputFile, "%d", &number) != EOF) {
        int indent = number % 2 == 0 ? 5 : 10;
        fprintf(outputFile, "%*d\n", indent, number);
        printf("%*d\n", indent, number);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void task3() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файла!\n");
        return;
    }

    double number;
    int position = 1;
    while (fscanf(inputFile, "%lf", &number) != EOF) {
        int decimalPlaces = position;
        fprintf(outputFile, "%.*f\n", decimalPlaces, number);
        printf("%.*f\n", decimalPlaces, number);
        position++;
    }

    fclose(inputFile);
    fclose(outputFile);
}

void task4() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файла!\n");
        return;
    }

    int number;
    int position = 1;
    while (fscanf(inputFile, "%d", &number) != EOF) {
        int indent = number % 2 == 0 ? 2 : 0;
        fprintf(outputFile, "%*d ", indent, number);
        printf("%*d ", indent, number);
        position++;
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    setlocale(LC_ALL, "Rus");
    task1();

    return 0;
}
```
