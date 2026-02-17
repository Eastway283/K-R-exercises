#include <stdio.h>
#include <ctype.h>

#define MAXSIZE 500
/* Разворачивает последовательность вида a-z || A-Z || 0-9 */
/* Записывает результат в s */
void expand(char* s, char* t);

int main(void)
{
    char line[MAXSIZE];
    char result[MAXSIZE];

    while (1)
    {
        printf("Enter sequence: ");
        if (fgets(line, MAXSIZE, stdin) == NULL)
            break;

        expand(result, line);
        printf("Result of expand function: ");
        printf("%s", result);
    }

    return 0;
}

void expand(char* s, char* t)
{
    int i = 0, j = 0;
    while (t[i] != '\0')
    {
        if (t[i] == '-' && i > 0 && t[i + 1] != '\0')
        {
            char prev = t[i - 1];
            char next = t[i + 1];

            if ((isdigit(prev) && isdigit(next) && prev <= next) || (isalpha(prev) && isalpha(next) && prev <= next))
            {
                for (char c = prev + 1; c <= next; c++)
                {
                    s[j++] = c;
                }
                i += 2;
                continue;
            }
        }
        s[j++] = t[i++];
    }
    s[j] = '\0';
}
