#include <stdio.h>
#include <string.h>

char * longestPalindrome(char * s)
{
    static char palindromic[1001] = {0};
    memset(palindromic, 0, 1001);
    int length = strlen(s);
    if(length == 1)
    {
        palindromic[0] = s[0];
        return palindromic;
    }
    int i = 0;
    int LongestLen = 0;
    int LongestIndex = 0;
    /**获取最长奇数个数的回文序列*/
    int oddTempLen = 0;
    for(i = 1; i < length - 1; i++)
    {
        if(s[i-1] == s[i+1])
        {
            int cnt = 1;
            while(i >= cnt && (i + cnt) < length && s[i-cnt] == s[i+cnt])
            {
                cnt ++;
            }
            cnt -= 1;
            oddTempLen = 2 * cnt + 1;
            if(oddTempLen > LongestLen)
            {
                LongestIndex = i - cnt;
                LongestLen = oddTempLen;
            }
        }
    }

    int evenTempLen = 0;
    /**获取最长偶数个数的回文序列*/
    for(i = 0; i < length - 1; i++)
    {
        if(s[i] == s[i+1])
        {
            int cnt = 0;
            while(i >= cnt && (i + cnt + 1) < length && s[i-cnt] == s[i+cnt+1])
            {
                cnt ++;
            }
            evenTempLen = 2 * cnt;
            if(evenTempLen > LongestLen)
            {
                LongestLen = evenTempLen;
                LongestIndex = i + 1 - cnt;
            }
        }
    }
    /**补足没有发现个数大于1的回文序列处理*/
    if(LongestLen == 0)
    {
        LongestLen = 1;
        LongestIndex = 0;
    }
    memcpy(palindromic, s + LongestIndex, LongestLen);
    return palindromic;
}

int  main(int argc, char const *argv[])
{
    if(argc < 2)
    {
        printf("too few parameters! usage: string\n");
        return 0;
    }
    char string[1001] = {0};
    strcpy(string, argv[1]);
    char *pPalindromic = longestPalindrome(string);
    printf("longest palindromic is %s \n", pPalindromic);
    return 0;
}