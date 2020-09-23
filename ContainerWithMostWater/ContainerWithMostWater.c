#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int     bool;

#define true    1
#define false   0

/**暴力计算所有的面积*/
int maxArea(int* height, int heightSize)
{
    int i = 0;
    int j = 0;
    int maxarea = 0;
    for(i = 0; i < heightSize; i ++)
    {
        for(j = i + 1; j < heightSize; j++)
        {
            int Tempheight = height[i] > height[j] ? height[j] : height[i];
            int TempArea = Tempheight * (j - i);
            maxarea = maxarea < TempArea ? TempArea : maxarea;
        }
    }

    return maxarea;
}


/**逐步计算，以矩形的宽为单一变量，逐步减小，高是变化的，计算最大面积*/
int maxArea2(int* height, int heightSize)
{
    int indexS = 0;
    int indexE = heightSize - 1;
    int maxarea = 0;
    int nowIndex = 0;
    int area = 0;
    while(indexE != indexS)
    {
        nowIndex = height[indexE] < height[indexS] ? indexE : indexS;
        area = height[nowIndex] * (indexE - indexS);
        maxarea = area > maxarea ? area : maxarea;
        if(indexE == nowIndex)
        {
            indexE --;
        }
        else
        {
            indexS ++;
        }
        
    }
    return maxarea;
}

int main(int argc, char const *argv[])
{
    int height[] = {1,8,6,2,5,4,8,3,7};
    int maxArea = maxArea2(height, sizeof(height) / sizeof(int));
    printf("max area is %d\n", maxArea);
}