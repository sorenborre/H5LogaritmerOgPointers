#include <stdio.h>
#include <stdlib.h>
int RecursiveWordCounter(char *sp, int wordCounter);

int main()
{

    char sentence[] = "hej med dig jeg hedder kaj";
    char *sp = sentence;
    int wordCount = 1;

    printf("wordcount: %d", RecursiveWordCounter(sp, wordCount));
    return 0;
}

int RecursiveWordCounter(char *sp, int wordCount)
{
    if(*sp != '\0')
    {
        if(*sp == ' ')
        {
            wordCount ++;
        }
        sp++;
        return RecursiveWordCounter(sp, wordCount);
    }
    else
        return wordCount;
}
