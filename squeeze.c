#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Удаляет из строки s1 все символы, которые есть в s2 */
void squeeze(char s1[], char s2[]);

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

        printf("Result of squeeze:\n");
        squeeze(line, subline);
        printf("%s\n", line);
    }

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, index;
    index = 0;

    for (i = 0; s1[i] != '\0'; i++)
    {
        int found = 0;
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
            s1[index++] = s1[i];
    }
    s1[index] = '\0';
}
