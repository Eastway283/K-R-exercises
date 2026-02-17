#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);
int lower(int c);
void line_to_lower(char line[]);

int main(void)
{
    char line[20];
    int result;

    while ((scanf("%s", line)) != EOF)
    {
        result = htoi(line);
        line_to_lower(line);
        printf("String what you input: %s\n", line);
        printf("Is dec digit: %d\n", result);
    }

    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

void line_to_lower(char line[])
{
    int i;
    for (i = 0; line[i] != '\0'; i++)
        line[i] = lower(line[i]);
}

int htoi(char s[])
{
    int i = 0;
    int result = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    for (; s[i] != '\0'; i++)
    {
        int digit;
        char c = toupper(s[i]);
        if (c >= '0' && c <= '9')
            digit = c - '0';
        else if (c >= 'A' && c <= 'F')
            digit = c - 'A' + 10;
        else
         return 0;

        result = result * 16 + digit;
    }
    return result;
}
