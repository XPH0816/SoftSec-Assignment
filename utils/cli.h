#ifndef CLI_H
#define CLI_H

#include "type.h"
#include "check.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void clearScreen()
{
    system(CLEAR);
}

void clearStdin()
{
    while (getchar() != '\n')
        ;
}

string trim(string str)
{
    string end;

    if (*str == 0)
        return str;

    // Trim leading space
    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
        end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}

string getValidString(int max)
{
    string input = (string)malloc(max * sizeof(char));
    bool invalid;
    do
    {
        invalid = false;
        fgets(input, max, stdin);
        if (strchr(input, '\n') == NULL)
        {
            invalid = (getchar() != '\n');
            if (invalid)
                clearStdin();
        }
        strncpy(input, trim(input), max);
        invalid = !checkMaxLength(input, max) || invalid;
        if (invalid)
            printf("Exceed %d characters length, please try again: ", max - 1);
    } while (invalid);
    return input;
}

int getValidInt(int min, int max)
{
    int input;
    do
    {
        if (scanf("%d", &input) != 1)
        {
            clearStdin();
            printf("Invalid input. Please enter a number between %d and %d: ", min, max);
            continue;
        }
        if (input < min || input > max)
        {
            printf("Please enter a number between %d and %d: ", min, max);
        }
    } while (input < min || input > max);
    clearStdin();
    return input;
}

#endif