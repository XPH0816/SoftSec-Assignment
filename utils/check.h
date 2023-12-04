#ifndef UTILS_H
#define UTILS_H

#include "type.h"

bool checkMaxLength(string str, int length)
{
    if (strlen(str) > length)
    {
        return false;
    }
    return true;
}

bool checkUpperCaseAlphabet(char c)
{
    if ((c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    return false;
}

bool checkDigit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

bool checkDigits(string str, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (!checkDigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

bool checkOnlyString(string str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (checkDigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

#endif