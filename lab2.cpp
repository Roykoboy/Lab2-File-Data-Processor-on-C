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