#include <stdio.h>
#include <stdbool.h>

typedef char * string;

typedef struct USER
{
    string name;
    string DOB;
    string passport;
    string country;
    int code;
} User;

int getValidInt(int min, int max)
{
    int input;
    do
    {
        scanf("%d", &input);
        if (input < min || input > max)
        {
            printf("Invalid input, please try again: ");
        }
    } while (input < min || input > max);
    return input;
}

bool checkLength(string str, int length)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    if (count == length)
    {
        return true;
    }
    return false;
}

int main()
{
    return 0;
}