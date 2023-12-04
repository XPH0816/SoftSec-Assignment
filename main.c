#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "utils/cli.h"
typedef struct USER
{
    string name;
    string DOB;
    string passport;
    string country;
    int code;
} User;

bool checkBirth(string str)
{
    int day, month, year;
    day = strtol(str, &str, 10);
    if (*str != '/')
    {
        return false;
    }
    month = strtol(++str, &str, 10);
    if (*str != '/')
    {
        return false;
    }
    year = strtol(++str, &str, 10);
    if (month <= 8 && month % 2 == 1 && day > 31)
    {
        return false;
    }
    if (month <= 8 && month % 2 == 0 && day > 30)
    {
        return false;
    }
    if (month > 8 && month % 2 == 1 && day > 30)
    {
        return false;
    }
    if (month > 8 && month % 2 == 0 && day > 31)
    {
        return false;
    }
    if (month == 2 && year % 4 == 0 && day > 29)
    {
        return false;
    }
    if (month == 2 && year % 4 != 0 && day > 28)
    {
        return false;
    }
    return true;
}

bool checkPassport(string str)
{
    if(strlen(str) == 9 && checkDigits(str + 2, 7)) {
        return true;
    }
    if (strlen(str) == 10 && checkDigits(str + 2, 8))
    {
        return true;
    }
    return false;
}

string getValidPassport()
{
    string passport;
    do
    {
        passport = getValidString(11);
        if (!checkUpperCaseAlphabet(passport[0]) || !checkUpperCaseAlphabet(passport[1]))
        {
            printf("First and 2nd character must be uppercase alphabet, please try again: ");
        }
        if (!checkPassport(passport))
        {
            printf("Last 7 or 8 characters must be digits, please try again: ");
        }
    } while (!checkUpperCaseAlphabet(passport[0]) || !checkUpperCaseAlphabet(passport[1]) || !checkPassport(passport));
    return passport;
}

string getValidName()
{
    string name;
    do
    {
        name = getValidString(50);
        if (!checkOnlyString(name))
        {
            printf("Only alphabet is allowed, please try again: ");
        }
    } while (!checkOnlyString(name));
    return name;
}

string getValidDOB()
{
    string DOB;
    do
    {
        DOB = getValidString(12);
        // why 12? dd/mm/yyyy is 10 characters,
        // but we need to add 2 more characters for the '\0' and the '\n' from fgets()
        if (!checkBirth(DOB))
        {
            printf("Invalid date, please try again: ");
        }
    } while (!checkBirth(DOB));
    return DOB;
}

string getValidCountry()
{
    string country;
    do
    {
        country = getValidString(50);
        if (!checkOnlyString(country))
        {
            printf("Only alphabet is allowed, please try again: ");
        }
    } while (!checkOnlyString(country));
    return country;
}

User *getUser()
{
    User *user = (User *)malloc(sizeof(User));
    printf("Enter name: ");
    user->name = getValidName();
    printf("Enter date of birth: ");
    user->DOB = getValidDOB();
    printf("Enter passport: ");
    user->passport = getValidPassport();
    printf("Enter country: ");
    user->country = getValidCountry();
    printf("Enter code (1: BIT, 2: BIS, 3: BIP): ");
    user->code = getValidInt(1, 3);
    return user;
}

void printProgramCode(int code)
{
    printf("Program Name: ");
    switch (code)
    {
    case 1:
        printf(" BIT\n");
        break;
    case 2:
        printf(" BIS\n");
        break;
    case 3:
        printf(" BIP\n");
        break;
    }
}

int main()
{
    User *user = getUser();
    clearScreen();
    printf("User information:\n");
    printf("====================================\n");
    printf("Name: %s\n", user->name);
    printf("Date of birth: %s\n", user->DOB);
    printf("Passport: %s\n", user->passport);
    printf("Country: %s\n", user->country);
    printf("Code: %d\n", user->code);
    printProgramCode(user->code);
    return 0;
}