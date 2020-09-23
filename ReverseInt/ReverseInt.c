#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**1 使用long long int类型避免溢出*/
int reverse(int x)
{
    long long int y = 0;
    long long int longIntX = x;
    int negSign = (x < 0) ? 1 : 0;
    if(negSign == 1)
    {
        longIntX = -longIntX;               /**避免 -2^31，转换为正值overflow*/
    }
    while(longIntX)
    {
        y = y * 10 + (longIntX % 10);       /**此处可能导致溢出*/
        longIntX = longIntX / 10;
    }
    if(y > 0x80000000)
        return 0;
    return (negSign == 1) ? -y : y;
}


/**2 计算y之前判断是否会溢出*/
int reverse(int x)
{
    int y = 0;
    int xUnit = 0;
    while(x)
    {
        xUnit = x % 10;
        x = x / 10;
        /**如果 10*y+x 溢出，考虑y为正数的情况，只能是 y>=__INT_MAX__/10
         * __INT_MAX__ 为0x7FFFFFFF，即2147483647
         * y>__INT_MAX__/10 溢出
         * y=__INT_MAX__/10 当x>7时溢出
         * x为负数时同理
         */
        if(y > __INT_MAX__ / 10 || (y == __INT_MAX__ / 10 && xUnit > 7))
            return 0;
        if(y < __WINT_MIN__ / 10 || (y == __WINT_MIN__ / 10 && xUnit < -8))
            return 0;
        y = y * 10 + xUnit;
    }
    return  y;
}