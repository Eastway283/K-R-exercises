#include <stdio.h>

#define MAXLEN 20
#define MAXSIZE 500

int sep_getline(char line[], int max);

int main(void)
{

    int len = 0;
    char line[MAXSIZE];

    while ((len = sep_getline(line, MAXSIZE)) > 0)
    {
        printf("lenght: %d, string: %s", len, line);
    }

    return 0;
}

int sep_getline(char line[], int max)
{
    int i, c;
    int symb_count = 0;

    i = 0;
    while (i < max - 1 && ((c = getchar()) != EOF) && c != '\n')
    {
        if (symb_count >= MAXLEN && (c == ' ' || c == '\t'))
        {
            line[i++] = '\n';
            symb_count = 0;
        }
        else 
        {
        line[i++] = c;
        ++symb_count;
        }

    }

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';
    return i;
}
