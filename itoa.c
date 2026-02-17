#include <stdio.h>
#include <string.h>

#define MAXSIZE 500

void reserve(char s[]);

void itoa(int n, char s[]);

void format_itoa(int n, char s[], int field);

void itob(int n, char s[], int base);

int main(void)
{

    char line[MAXSIZE];
    int input;

    while (1)
    {
        printf("Enter number\n> ");
        if (scanf("%1d", &input) == 0)
            break;

        itoa(input, line);

        printf("Result of itoa: %s\n", line);
    }

    return 0;
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i = 0;
    int sign = n;
    unsigned int un;
    if (n < 0)
        un = -n;
    else
        un = n;

    do {
        s[i++] = '0' + (un % 10);
    } while ((un /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void format_itoa(int n, char s[], int field)
{
    int i = 0;
    int sign = n;
    int count = 0;
    unsigned un;
    if (n < 0)
        un = -n;
    else
        un = n;

    do {
        s[i++] = '0' + (un % 10);
        ++count;
    } while ((un /= 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
        ++count;
    }

    if (count < field)
    {
        for (; count < field; count++)
            s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);
}

void itob(int n, char s[], int base)
{
    int i = 0;
    int sign = n;
    unsigned int un;

    if (base > 36 || base < 2)
    {
        s[0] = '\0';
        return;
    }

    if (n < 0)
        un = -n;
    else
        un = n;

    do {
        int digit = un % base;
        if (digit < 10)
            s[i++] = '0' + digit;
        else
            s[i++] = 'A' + (digit - 10);
    } while ((un /= base) != 0);
    
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
