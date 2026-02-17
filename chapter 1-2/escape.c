#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 500

/* Функция преобразует символы \t, \n в фактические эквиваленты */
/* Копирует результат в s, размер считается достаточным         */
void escape(char* s, char* t);

/* Противоположная функции escape */
void descape(char* s, char* t);

int main(void)
{

    char line[MAXSIZE];
    char escapeLine[MAXSIZE];
    char descapeLine[MAXSIZE];

    while (1)
    {
    printf("Enter the line:\n> ");
    if (fgets(line, MAXSIZE, stdin) == NULL)
        break;

    escape(escapeLine, line);
    

    printf("Result of escape function:\n");
    printf("%s", escapeLine);

    descape(descapeLine, escapeLine);

    printf("Result of descape function:\n");
    printf("%s", descapeLine);
    }

    return 0;
}

void escape(char* s, char* t)
{
    int i, j;
    i = j = 0;
    while (t[i] != '\0')
    {
        if (t[i] == '\\' && t[i + 1] != '\0')
        {
            switch (t[i + 1])
            {
                case 't': {
                              s[j++] = '\t';
                              i += 2;
                              break;
                          }
                case 'n': {
                              s[j++] = '\n';
                              i += 2;
                              break;
                          }
                default: {
                             s[j++] = '\\';
                             s[j++] = t[i + 1];
                             i += 2;
                             break;
                         }
            }
        }
        else 
            s[j++] = t[i++];
    }
    s[j] = '\0';
}

void descape(char* s, char* t)
{
    int i, j;
    i = j = 0;
    while (t[i] != '\0')
    {
        if (t[i] == '\t')
        {
            s[j++] = '\\';
            s[j++] = 't';
            ++i;
        }
        else if (t[i] == '\n' && t[i + 1] != '\0')
        {
            s[j++] = '\\';
            s[j++] = 'n';
            i++;
        }
        else 
            s[j++] = t[i++];
    }
    s[j] = '\0';
}
