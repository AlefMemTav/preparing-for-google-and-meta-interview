#include <stdio.h>
#include <stdlib.h>

/*
Given a string, remove the vowels from the string and print the string without vowels.
Example 1:
    Input: str[] = "Hello world"
    Output: newstr[] = "Hll wrld"
*/
int toLower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + ('a' - 'A');
    else
        return c;
}

int isVowel(char c)
{
    c = toLower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

char* removeVowel(char* str)
{
    if (str == NULL)
    {
        return NULL;
    }
    char* newstr = str;
    char* aux = str;
    while (*str != '\0')
    {
        if (!isVowel(*str))
        {
            *aux = *str;
            aux++;
        }
        str++;
    }
    *aux = '\0';

    return newstr;
}

int main()
{
    /*test1 */
    char str[] = "Hello world";
    char* newstr = removeVowel(str);
    printf("%s", newstr);
    return 0;
}
