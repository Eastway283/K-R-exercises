#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[]);
void swap(char* a, char* b);

int main(void)
{

    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = my_getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
        if (len > 1)
        {
        reverse(line);
        printf("%s", line);
        }
    }

    if (max > 1)
        printf("Longest string in input stream has %d symbols, this string:\n%s", max, longest);
    else 
        printf("You don't input string\n");

    return 0;
}

int my_getline(char line[], int lim)
{
    int c, i;

    i = 0;
    while (i < lim - 1 && (c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            if (i > 0 && (line[i - 1] == ' ' || line[i] == '\t'))
                --i;
            line[i] = c;
            ++i;
            break;
        }
        else if (c == ' ' || c == '\t')
        {
            if (i > 0 && (line[i - 1] == ' ' || line[i - 1] == '\t'))
                --i;
            else {
                line[i] = c;
                ++i;
            }
        }
        else 
        {
            line[i] = c;
            ++i;
        }
    }

    line[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(char line[])
{
    int i, j, len;
    len = 0;
    while (line[len] != '\0' && line[len] != '\n')
        len++;
    for (i = 0, j = len - 1; i < j; i++, j--)
        swap(&line[i], &line[j]);
}
