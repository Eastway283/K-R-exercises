#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXLINESIZE 250
#define MAXBUFFERSIZE 1000

int GetLine(char line[], int lim);
void remove_comms(char line[]);

int main(void)
{

    char buffer[MAXBUFFERSIZE] = {0};
    char string[MAXLINESIZE];
    int len, buffer_size;
    buffer_size = 0;

    while ((len = GetLine(string, MAXLINESIZE)) > 0 && ((buffer_size += len) < MAXBUFFERSIZE - 1))
    {
        strcat(buffer, string);
    }

    remove_comms(buffer);
    printf("Program after removing comments:\n");
    printf("%s", buffer);

    return 0;
}

int GetLine(char line[], int lim)
{
    int c, i;

    i = 0;
    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';
    return i; /* */
}

void remove_comms(char line[])
{
    int i = 0;
    int j;
    int index_of_comm = 0;
    bool in_comm = false;
    while (line[i++] != '\0')
    {
        if (i > 0 && (line[i] == '*' && line[i - 1] == '/'))
        {
            in_comm = true;
            index_of_comm = i - 1;
        }

        if (i > 0 && (line[i] == '/' && line[i - 1] == '*') && in_comm)
        {
            for (j = index_of_comm; j <= i; j++)
                line[j] = ' ';
            in_comm = false;
        }

    }
}
