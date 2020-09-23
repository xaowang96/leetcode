#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * convert(char * s, int numRows)
{
    int length = strlen(s);
    if(numRows == 1)
    {
        return s;
    }
    
    /**计算有几列*/
    int oneCombosNum = numRows + (numRows - 2);         /**一个组合的数量*/
    int numCombos = (length + oneCombosNum - 1) / oneCombosNum; /**组合的数量，最后一个组合可能不满*/
    int numLines = numCombos * (numRows - 1);
    printf("length= %d oneCombosNum = %d numCombos = %d numLines = %d\n", length, oneCombosNum, numCombos, numLines);
    char newString[numRows][numLines];
    memset(newString, 0, sizeof(newString));
    int i = 0;
    int rows = 0;
    int lines = 0;
    /**得到zigzag的二维数组*/
    for ( i = 0; i < length; i++)
    {
        int iInOneCombo = (i + 1) % oneCombosNum;   /**i在一个组合的位置*/
        if(iInOneCombo < numRows && (iInOneCombo > 0))
        {
            newString[rows++][lines] = s[i];
            //printf("row %d line %d %c iInOneCombo %d \n", rows, lines, newString[rows][lines], iInOneCombo);
            //rows ++ ;z
        }
        else
        {
            newString[rows--][lines++] = s[i];
            //newString[rows][lines] = s[i];
            //printf("row %d line %d %c iInOneCombo %d \n", rows, lines, newString[rows][lines], iInOneCombo);
            //rows --;
            //lines ++;
        }     
    }
    i = 0;
    rows = 0;
    lines = 0;
    for(; rows < numRows ; rows ++)
    {
        lines = 0;
        for(; lines < numLines; lines ++)
        {
            if(newString[rows][lines] != 0)
            {
                s[i++] = newString[rows][lines];
                //printf("%c", newString[rows][lines]);
            }
            else
            {
                //printf(" ");
            }
            
        }
        printf("\n");
    }
    return s;
}

/*
int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        printf("too few params!\n");
        printf("Usage:[string][rows]\n");
        return 0;
    }
    int numRows = atoi(argv[2]);
    int length = strlen(argv[1]);
    char *s = (char *)malloc((length+1) * sizeof(char));
    strncpy(s, argv[1], length);
    printf("string %s \n", s);
    s = convert(s, numRows);
    printf("zigzag string %s \n", s);
    return 0;
}
*/
int main()
{
    char hexString[128] = {0};
    char *pchar = (strstr(hexString, "0x") == NULL)? strstr(hexString, "0X") : strstr(hexString, "0x");
    int result = 0;
    char *pHexValue = NULL;
    int dataLen = 0;
    int i = 0;
    while(gets(hexString))
    {
        //dec = convertToDec(hexString);
        pHexValue = hexString + 2;
        dataLen = strlen(hexString);
        result = 0;
        for(i = 0; i < dataLen - 2; i++)
        {
            if(pHexValue[i] <= '9' && pHexValue[i] >= '0')
            {
                result = (*(pHexValue+i) - '0') + result * 16;
            }
            else if(pHexValue[i] <= 'f' && pHexValue[i] >= 'a')
            {
                result = (*(pHexValue+i) - 'a' + 10) + result * 16;
            }
            else if(pHexValue[i] <= 'F' && pHexValue[i] >= 'A')
            {
                result = (*(pHexValue+i) - 'A' + 10) + result * 16;
            }
        }
        pHexValue =  NULL;
        printf("%d\n", result);
    }
    return 0;
}