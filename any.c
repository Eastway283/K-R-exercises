#include <stdio.h>
#include <string.h>

/* Возвращает индекс первого символа s1, который есть в s2
   -1, если не найдено ни одного символа */
int any(char s1[], char s2[]);

int main(void)
{

    char line[100];
    char subline[100];
    
    while (1)
    {
        printf("Enter line:\n> ");
        if (fgets(line, sizeof(line), stdin) == NULL)
                break;
        line[strcspn(line, "\n")] = '\0';

        printf("Enter subline:\n> ");
        if (fgets(subline, sizeof(subline), stdin) == NULL)
                break;
        subline[strcspn(line, "\n")] = '\0';

        int result = any(line, subline);
        printf("Result of any: %d\n", result);
    }

    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }
    return -1;
}
