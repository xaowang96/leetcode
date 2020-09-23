#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int     bool;

#define true    1
#define false   0

/**Recursion*/
bool isMatch(const char * s, const char * p)
{
    if(*p == '\0')
    {
        return (*s == '\0') ? true : false;
    }
    bool firstMatch = *s != '\0' && (*p == '.' || *p == *s);
    if(*(p+1) == '*')
    {
        printf("s %s p %s \n", s, p);
        return (isMatch(s, p + 2) || (firstMatch && isMatch(s + 1, p)));
    }
    else 
    {
        return (firstMatch && isMatch(s + 1, p + 1));
    }  
}


/**Dynamic Programming*/
int *result = NULL;
int sLen = 0;
int pLen = 0;
bool dp(int i, int j, const char *s, const char *p)
{
    if(result[i * sLen + j] != -1)
    {
        return result[i * sLen + j];
    }
    bool ret = false;
    if(j == strlen(p))
    {
        ret = (i == strlen(s));
    }
    else
    {
        bool firstMatch = (i < strlen(s)) && (*p == '.' || *p == *s);
        if(*(p + 1) == '*')
        {
            ret = dp(i, j + 2, s, p + 2) || (firstMatch && dp(i + 1, j, s + 1, p));
        }
        else
        {
            ret = firstMatch && dp(i + 1, j + 1, s + 1, p + 1);
        }
        
    }
    result[i * sLen + j] = ret;
    return ret;
}
bool isMatch2(const char *s, const char *p)
{
    sLen = strlen(s);
    pLen = strlen(p);
    result = (int *)malloc(sLen * pLen);
    memset(result, -1, sLen * pLen);
    bool ret = dp(0, 0, s, p);
    free(result);
    return ret;
}

int main(int argc, char const *argv[])
{
    if(argc < 3)
    {
        printf("parameter count error!!!");
        printf("\t[Usage] : ./main s p\n");
        return -1;
    }
    const char *s = argv[1];
    const char *p = argv[2];
    bool ret = isMatch2(s, p);
    printf("%s %s match %s\n", p, ((ret == true) ? "is" : "is not"), s);
}