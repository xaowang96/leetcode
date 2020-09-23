#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <time.h>

#include "common.h"

/**n个字符中取出m个字符的组合*/
char selectCharComb[DATA_SIZE_128B] = {0};
char *pSelectCharComb = selectCharComb;
int selectIndex = 0;
void charCombWithM(const char *pString, int n, int m)
{
    if(m == 0)
    {
        selectCharComb[selectIndex++] = ' ';
        selectCharComb[selectIndex++] = 0;
        //*pSelectCharComb ++ = ' ';
        //*pSelectCharComb ++ = 0;
        printf("%s", selectCharComb);
        selectIndex -= 2;
        // printf("selectIndex %d\n", selectIndex);
        //printf(" ");
        return;
    }
    if(m == n)
    {
        while(m > 0)
        {
            selectCharComb[selectIndex++] = *(pString + n - m);
            // *pSelectCharComb ++ = *(pString + n - m);
            //pSelectCharComb ++;
            m --;
        }
        // *pSelectCharComb ++ = ' ';
        // *pSelectCharComb ++ = 0;
        selectCharComb[selectIndex++] = ' ';
        selectCharComb[selectIndex++] = 0;        
        printf("%s", selectCharComb);
        selectIndex -= (n + 2);
        // pSelectCharComb -= (n + 1);        
        //printf("%s ", pString);
        return;
    }
    //printf("string %s", pString);
    /**第一个字符包含在组合中，则是计算剩下的n-1个字符中m-1个的组合*/
    //printf("%c", *pString);
    selectCharComb[selectIndex++] = *pString;
    // LOG_INFO("selectIndex %d", selectIndex);
    // *pSelectCharComb ++ = *pString;
    //pSelectCharComb ++;
    charCombWithM(pString + 1, n - 1, m - 1);
    /**第一个字符不包含在组合中，则是计算剩下的n-1个字符中m个的组合*/
    selectIndex --;
    // LOG_INFO("selectIndex %d", selectIndex);
    if((n - 1) >= m)
    {
        //printf("string %s", pString);
        charCombWithM(pString + 1, n - 1, m);
    }
        
    return;
}

void charCombination(const char *pString)
{
    AMCK(pString == NULL, LOG_ERROR("param error!"), return);
    int length = strlen(pString);
    int m = 0;
    LOG_INFO("string %s length %d", pString, length);
    for (m = 1; m <= length; m++)
    {
        charCombWithM(pString, length, m);
        printf("\n");
        //printf("%s\n", selectCharComb);
        memset(selectCharComb, 0, sizeof(selectCharComb));
        pSelectCharComb = selectCharComb;
        selectIndex = 0;
    }
    
    return;
}

int main(int argc, char const *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage : %s string \n", argv[0]);
        exit(1);
    }

    charCombination(argv[1]);
    return 0;
}