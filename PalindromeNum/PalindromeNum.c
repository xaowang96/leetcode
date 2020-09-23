#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
/* reverse number */
bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    int y = reverse(x);
    if(x == y)
        return true;
    return false;
}

/* reverse half number */
bool isPalindrome(int x)
{
    int y = 0;
    if(x < 0 || 
       ((x % 10) == 0 && x != 0))
        return false;
    /**反转一半的数字，当剩余的数字x小于等于反转的数字y，表示已经到一半 
     * 例如：12321，x=12,y=123
    */
    while(x > y)
    {
        y = 10 * y + x % 10;
        x /= 10;
    }

    return (x == y || x == y / 10);
}