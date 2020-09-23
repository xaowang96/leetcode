#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    if (s == NULL)
    {
        return 0; 
    }
    int i = 0;
    int j = 0;
    int maxSubStringLength = 0;
    int strLenth = strlen(s);
    int strIndex[128] = {0};
    for (i = 0; i < strLenth; i++)
    {
        if (strIndex[s[i]] == 0 || (j > strIndex[s[i]]))
        {

        }
        else
        {
            maxSubStringLength = ((i - j) > maxSubStringLength)? (i - j): maxSubStringLength;

            j = strIndex[s[i]];
        }
        strIndex[s[i]] = i + 1; 
        
    }

    maxSubStringLength = ((i - j) > maxSubStringLength)? (i - j): maxSubStringLength;

    return maxSubStringLength;
}

int main(void)
{
    char string[50] = "abcabc";
    int x = 0;
    do
    {
        scanf("%s", string);
        x = lengthOfLongestSubstring(string);
        printf("Longest Substring Without Repeating Characters %d\n ", x);
    } while (1);
    
}