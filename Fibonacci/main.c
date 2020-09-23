#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <time.h>

#include "common.h"


#define MAX_BUF_SIZE               1000

int FibonacciSeq(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else 
    {
        return FibonacciSeq(n - 1) + FibonacciSeq(n - 2);
    }
}

U32 FibonacciSeqLoop(int n)
{
    U32 a = 1;
    U32 b = 1;
    U32 temp = 0;
    while(n > 2)
    {
        temp = a + b;
        a = b;
        b = temp;
        n -= 1;
    }
    return b;
}

U32 *pRotationsquare(U32 *pNumber, U32 edgeLegth)
{
    AMCK(pNumber == NULL, LOG_ERROR("parameter error!!!"), return NULL);
    U32 numLength = edgeLegth * edgeLegth;
    U32 *pSpiralRec = (U32 *)malloc(edgeLegth * edgeLegth * sizeof(U32));
    AMCK(pSpiralRec == NULL, LOG_ERROR("malloc error!!!"), return NULL);
    S32 row = 0;
    S32 column = 0;
    S32 rowTopBound = 0;
    S32 rowBottemBound = edgeLegth - 1;
    S32 columnRightBound = edgeLegth - 1;  
    S32 columnleftBound = 0;  
    U32 numIndex = numLength - 1;

      
    while(columnleftBound < columnRightBound && rowTopBound < rowBottemBound)
    {
        LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        column = columnleftBound; 
        LOG_INFO("row column (%d,%d)", row, column);
        LOG_INFO("number index %d", numIndex);
        /**由左向右 --------->*/
        while(column <= columnRightBound)
        {
            pSpiralRec[row * edgeLegth + column] = pNumber[numIndex];
            numIndex --;
            if(column == columnRightBound)
            {
                break;
            }
            else
            {
                column ++;
            }
        }
        rowTopBound += 1;
        row += 1;
        LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        LOG_INFO("row column (%d,%d)", row, column);
        LOG_INFO("number index %d", numIndex);
        /**由上向下 */
        if(rowBottemBound >= rowTopBound )
        {
            while(row <= rowBottemBound)
            {
                pSpiralRec[row * edgeLegth + column] = pNumber[numIndex];
                numIndex --;
                if(row == rowBottemBound)
                {
                    break;
                }
                else
                {
                    row ++;
                }
            }
        }
        columnRightBound -= 1;        
        LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        column --;
        LOG_INFO("row column (%d,%d)", row, column);
        LOG_INFO("number index %d", numIndex);
        /**由右向左 <---------*/
        while(column >= columnleftBound)
        {
            pSpiralRec[row * edgeLegth + column] = pNumber[numIndex];
            numIndex --;
            if(column == columnleftBound)
            {
                break;
            }
            else
            {
                column --;
            }
        }
        rowBottemBound -= 1;
        LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        row --;
        /**由下向上 */
        while(row >= rowTopBound)
        {
            pSpiralRec[row * edgeLegth + column] = pNumber[numIndex];
            numIndex --;
            if(row == rowTopBound)
            {
                break;
            }
            else
            {
                row --;
            }
        }
        columnleftBound += 1;      
        LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);  
    }
    /**奇数边长*/
    if(edgeLegth & 0x01)
    {
        row = (edgeLegth - 1) / 2;
        column = row;
        pSpiralRec[row * edgeLegth + column] = pNumber[numIndex];
    }

    return pSpiralRec;
}

U32 *pRotationmatrix(U32 *pNumber, U32 rowLegth, U32 columnLength)
{
    AMCK(pNumber == NULL, LOG_ERROR("parameter error!!!"), return NULL);
    U32 numLength = rowLegth * columnLength;
    U32 *pSpiralRec = (U32 *)malloc(rowLegth * columnLength * sizeof(U32));
    AMCK(pSpiralRec == NULL, LOG_ERROR("malloc error!!!"), return NULL);
    S32 row = 0;
    S32 column = 0;
    S32 rowTopBound = 0;
    S32 rowBottemBound = rowLegth - 1;
    S32 columnRightBound = columnLength - 1;  
    S32 columnleftBound = 0;  
    S32 numIndex = numLength - 1;
    bool topToBottom = false;
    while((numIndex >= 0) && (columnleftBound < columnRightBound || rowTopBound < rowBottemBound))
    {
        column = columnleftBound; 
        LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        LOG_INFO("row column (%d,%d)", row, column);
        LOG_INFO("number index %d", numIndex);        
        /**由左向右 --------->*/
        if(columnRightBound > columnleftBound)
        {
            // LOG_ERROR();
            while(column <= columnRightBound)
            {
                pSpiralRec[row * columnLength + column] = pNumber[numIndex];
                numIndex --;
                if(column == columnRightBound)
                {
                    rowTopBound += 1;
                    row += 1;
                    break;
                }
                else
                {
                    column ++;
                }
            }

        }
        
        // LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        // LOG_INFO("row column (%d,%d)", row, column);
        // LOG_INFO("number index %d", numIndex);
        /**由上向下 */
        if((numIndex >= 0) && rowBottemBound >= rowTopBound )
        {
            // LOG_ERROR();
            topToBottom = true;
            while(row <= rowBottemBound)
            {
                pSpiralRec[row * columnLength + column] = pNumber[numIndex];
                numIndex --;
                if(row == rowBottemBound)
                {
                    columnRightBound -= 1;        
                    column --;                    
                    break;
                }
                else
                {
                    row ++;
                }
            }

        }
        else
        {
            topToBottom = false;
        }
        // LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        // LOG_INFO("row column (%d,%d)", row, column);
        // LOG_INFO("number index %d", numIndex);
        /**由右向左 <---------*/
        while((numIndex >= 0) && topToBottom && column >= columnleftBound)
        {
            // LOG_ERROR();
            pSpiralRec[row * columnLength + column] = pNumber[numIndex];
            numIndex --;
            if(column == columnleftBound)
            {
                rowBottemBound -= 1;
                row --;
                break;
            }
            else
            {
                column --;
            }

        }

        // LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        // LOG_INFO("row column (%d,%d)", row, column);
        // LOG_INFO("number index %d", numIndex);
        /**由下向上 */
        while((numIndex >= 0) && topToBottom && row >= rowTopBound)
        {
            // LOG_ERROR();
            pSpiralRec[row * columnLength + column] = pNumber[numIndex];
            numIndex --;
            if(row == rowTopBound)
            {
                break;
            }
            else
            {
                row --;
            }
        }
        columnleftBound += 1;      
    }
    /**奇数边长*/
    if(columnLength == rowLegth && columnLength & 0x01)
    {
        row = (columnLength - 1) / 2;
        column = row;
        pSpiralRec[row * columnLength + column] = pNumber[numIndex];
    }
    // while(rowTopBound < rowBottemBound)
    // {
    //     pSpiralRec[rowTopBound * columnLength + column] = pNumber[numIndex];
    //     numIndex --;
    //     rowTopBound ++;
    // }
    // if(columnleftBound < columnRightBound)
    // {
    //     pSpiralRec[row * columnLength + columnleftBound] = pNumber[numIndex];
    //     numIndex --;
    //     columnleftBound ++;
    // }
    return pSpiralRec;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(!matrix)
        return NULL;
    int numLength = matrixSize;
    int *pSpiralRec = (int *)malloc(matrixSize * sizeof(int));
    if(!pSpiralRec)
         return NULL;
    int row = 0;
    int column = 0;
    int rowTopBound = 0;
    int rowLength = matrixSize / *matrixColSize;
    int columnLength = *matrixColSize;
    int rowBottemBound = matrixSize / *matrixColSize  - 1;
    int columnRightBound = *matrixColSize - 1;  
    int columnleftBound = 0;  
    int numIndex = 0;
    int topToBottom = false;
    while((numIndex < matrixSize) && (columnleftBound < columnRightBound || rowTopBound < rowBottemBound))
    {
        column = columnleftBound;  
        // LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        // LOG_INFO("row column (%d,%d)", row, column);
        // LOG_INFO("number index %d", numIndex);      
        /**由左向右 --------->*/
        if(columnRightBound > columnleftBound)
        {
            // LOG_ERROR();
            while(column <= columnRightBound)
            {
                pSpiralRec[numIndex] = (*matrix)[row * columnLength + column];
                numIndex ++;
                if(column == columnRightBound)
                {
                    rowTopBound += 1;
                    row += 1;
                    break;
                }
                else
                {
                    column ++;
                }
            }

        }
        
        // LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        // LOG_INFO("row column (%d,%d)", row, column);
        // LOG_INFO("number index %d", numIndex);
        /**由上向下 */
        if(rowBottemBound >= rowTopBound )
        {
            // LOG_ERROR();
            topToBottom = true;
            while(row <= rowBottemBound)
            {
                pSpiralRec[numIndex] = (*matrix)[row * columnLength + column];
                numIndex ++;
                if(row == rowBottemBound)
                {
                    columnRightBound -= 1;        
                    column --;                    
                    break;
                }
                else
                {
                    row ++;
                }
            }

        }
        else
        {
            topToBottom = false;
        }
        // LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        // LOG_INFO("row column (%d,%d)", row, column);
        // LOG_INFO("number index %d", numIndex);
        /**由右向左 <---------*/
        while(topToBottom && column >= columnleftBound)
        {
            // LOG_ERROR();
            pSpiralRec[numIndex] = (*matrix)[row * columnLength + column];
            numIndex ++;
            if(column == columnleftBound)
            {
                rowBottemBound -= 1;
                row --;
                break;
            }
            else
            {
                column --;
            }

        }

        // LOG_INFO("left %d right %d top %d bottom %d", columnleftBound, columnRightBound, rowTopBound, rowBottemBound);
        // LOG_INFO("row column (%d,%d)", row, column);
        // LOG_INFO("number index %d", numIndex);
        /**由下向上 */
        while(topToBottom && row >= rowTopBound)
        {
            // LOG_ERROR();
            pSpiralRec[numIndex] = (*matrix)[row * columnLength + column];
            numIndex ++;
            if(row == rowTopBound)
            {
                break;
            }
            else
            {
                row --;
            }
        }
        columnleftBound += 1;      
    }
    /**奇数边长*/
    if(columnLength == rowLength && columnLength & 0x01)
    {
        row = (columnLength - 1) / 2;
        column = row;
        pSpiralRec[numIndex] = (*matrix)[row * columnLength + column];
    }

    return pSpiralRec;
}

int main(int argc, char const *argv[])
{
    U32 FiSeq[MAX_BUF_SIZE] = {0};
    if(argc < 2)
    {
        fprintf(stderr, "Usage : %s n \n", argv[0]);
        exit(1);
    }
    int i = 0;
    int number = atoi(argv[1]);      
    U64 beginTimeUs = 0;     
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    beginTimeUs = (U64)1000000*(ts.tv_sec) + (U64)ts.tv_nsec/1000;
    for(; i < number * number; i ++)
    {
        FiSeq[i] = FibonacciSeqLoop(i+1);
    }
    clock_gettime(CLOCK_MONOTONIC, &ts);
    U64 endTimeUs = (U64)1000000*(ts.tv_sec) + (U64)ts.tv_nsec/1000;
    LOG_INFO("cost time %lluus", endTimeUs - beginTimeUs);
    int row = atoi(argv[1]);
    int column = row;
    if(argc > 2)
    {
        column = atoi(argv[2]);
        for(; i < row * column; i ++)
        {
            FiSeq[i] = FibonacciSeqLoop(i+1);
        }
    }
    LOG_INFO("Fibnoacci sequence %d ", number);
    for(i = 0; i < row; i ++)
    {
        int j = 0;
        for (; j < column; j++)
        {
            printf("%4u ", FiSeq[i * column + j]);
        }
        printf("\n");
    }
    U32 *pNewNumber = pRotationmatrix(FiSeq, row, column);
    if(pNewNumber == NULL)
    {   
        LOG_ERROR("Fibonacci spiral fails");
        return 1;
    }
    LOG_INFO("Fibonacci spiral");
    for(i = 0; i < row; i ++)
    {
        int j = 0;
        for (; j < column; j++)
        {
            printf("%4u ", pNewNumber[i * column + j]);
        }
        printf("\n");
    }
    free(pNewNumber);
    pNewNumber = NULL;  

    //int numberArray[3][4] = {1, 2, 3, 4,5, 6, 7, 8,9,10,11,12};
    int *numberArray = (int *)malloc(12*sizeof(4));
    for ( i = 0; i < 12; i++)
    {
        numberArray[i] = i + 1;
    }
    
    column = 4;
    row = 3;
    for(i = 0; i < row; i ++)
    {
        int j = 0;
        for (; j < column; j++)
        {
            printf("%4u ", numberArray[i * column + j]);
        }
        printf("\n");
    }
    pNewNumber = spiralOrder(&numberArray, 12, &column, NULL);
    for(i = 0; i < row; i ++)
    {
        int j = 0;
        for (; j < column; j++)
        {
            printf("%4u ", pNewNumber[i * column + j]);
        }
        printf("\n");
    }
    free(pNewNumber);
    pNewNumber = NULL;      
    return 0;
}