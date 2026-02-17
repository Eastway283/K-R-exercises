#include <stdio.h>
#include <stdbool.h>

#define TAB 4
#define MAXLINE 500

int GetLine_detab(char line[], int lim);

int GetLine_entab(char line[], int lim);

bool is_spaces(char line[], int i);

int main(void)
{
    int len;
    char line[MAXLINE];

    /* printf("Getline_detab:\n");
    while ((len = GetLine_detab(line, MAXLINE)) > 0)
    {
        printf("Lenght: %d, string: %s", len, line);
    } */

    printf("GetLine_entab:\n");
    while ((len = GetLine_entab(line, MAXLINE)) > 0)
    {
        printf("Lenght: %d, string: %s", len, line);
    }

    return 0;
}

int GetLine_detab(char line[], int lim)
{
    int c, i, j;

    i = 0;
    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
    {
        if (c == '\t')
        {
            for (j = 0; j < TAB; ++j)
            {
                line[i] = ' ';
                ++i;
            }
        }
        else {
        line[i] = c;
        ++i;
        }
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

int GetLine_entab(char line[], int lim)
{
    int c, i = 0;
    int space_count = 0;   // счётчик подряд идущих пробелов

    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
    {
        if (c == ' ')
        {
            line[i++] = c;
            ++space_count;

            if (space_count == TAB)
            {
                i -= TAB;
                line[i++] = '\t';
                space_count = 0;
            }
        }
        else {
        line[i++] = c;
        space_count = 0;
        }
    }

    if (c == '\n') {
        line[i++] = '\n';
    }

    line[i] = '\0';
    return i;
}
