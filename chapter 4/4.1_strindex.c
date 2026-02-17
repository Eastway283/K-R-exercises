#include <stdio.h>

#define MAXSIZE 1000

int strindex(char* source, char* searchfor);

int Getline(char* s, int maxsize);

char pattern[] = "ould";

int main(void)
{
    char line[MAXSIZE];
    int found = 0;
    int index;

    while ((Getline(line, MAXSIZE)) > 0)
        if ((index = strindex(line, pattern)) >= 0)
        {
            printf("index: %d, %s", index, line);
            found++;
        }

    return found;
}

int Getline(char* s, int lim)
{
    int c, i;
    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

int strindex(char* s, char* t)
{
    int i, j, k;
    int index = -1;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            index = i;
    }
    return index;
}
