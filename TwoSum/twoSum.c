#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *twoSum(int* nums, int numsSize, int target)
{
    int *returnValue = NULL;
    returnValue = malloc(2*sizeof(int));
    memset(returnValue, 0, 2*sizeof(int));
    int i,j;
    i = j = 0;
    for(; i < (numsSize - 1); i++)
    {
        for(j = (i + 1); j < numsSize; j++)
        {
            if((nums[i] + nums[j]) == target)
            {
                returnValue[0] = i;
                returnValue[1] = j;
                return returnValue;
            }
        }
        
    }
    return returnValue;

}

int main(void)
{
    int nums[] = {2, 7, 11, 15};
    int target = 17;
    int *subNum = twoSum(nums, 4, target);
    if(subNum != NULL)
    {
        printf("indices : %d %d\n", subNum[0], subNum[1]);
        free(subNum);
    }
    else
    {
        printf("calculate error!");
    }
    
    return 0;
}

