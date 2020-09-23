#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <time.h>

#include "common.h"


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_TREE_NODE_NUM           5000


 struct TreeNode 
 {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
void InOrderTraverse(struct TreeNode* root, int *pNum, int *index)
{
    if(!root)
        return;
    InOrderTraverse(root->left, pNum, index);
    if(pNum)
    {
        pNum[(*index) ++] = root->val;
    }
    InOrderTraverse(root->right, pNum, index);
}

int *pMergeSortedNum(int *pNum1, int num1Cnt, int *pNum2, int num2Cnt)
{
    if((!pNum1 || num1Cnt <= 0) && (!pNum2 || num2Cnt <= 0))
        return NULL;
    int numCnt = num1Cnt + num2Cnt;
    int *pNum = (int *)malloc(numCnt * sizeof(int));
    if(!pNum)
    {
        return NULL;
    }
    int num1Index = 0;
    int num2Index = 0;
    int numIndex = 0;
    while((num1Index < num1Cnt) && (num2Index < num2Cnt))
    {
        if(pNum1[num1Index] < pNum2[num2Index])
        {
            pNum[numIndex ++] = pNum1[num1Index++];
        }
        else
        {
            pNum[numIndex ++] = pNum2[num2Index++];
        }
    }
    
    while(num1Index < num1Cnt)
    {
        pNum[numIndex ++] = pNum1[num1Index++];
    }
    while(num2Index < num2Cnt)
    {
        pNum[numIndex ++] = pNum2[num2Index++];
    }
    return pNum;
}    

    
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize)
{
    *returnSize = 0;
    if(!root1 && !root2)
        return NULL;
    int *pTree1Num = NULL;
    int Tree1NumIndex = 0;
    int *pTree2Num = NULL;
    int Tree2NumIndex = 0;
    int *pNum = NULL;
    pTree1Num = (int *)malloc(MAX_TREE_NODE_NUM * sizeof(int));  
    if(!pTree1Num)
        return pNum;
    /**中序遍历二叉搜索树，得到排序好的数组1和2*/
    InOrderTraverse(root1, pTree1Num, &Tree1NumIndex);
    pTree2Num = (int *)malloc(MAX_TREE_NODE_NUM * sizeof(int));
    if(!pTree2Num)
    {
        free(pTree1Num);
        pTree1Num = NULL;
        return pNum;
    }
    InOrderTraverse(root2, pTree2Num, &Tree2NumIndex);
    *returnSize = Tree1NumIndex + Tree2NumIndex;
    /**合并排序好的两个数组*/
    pNum = pMergeSortedNum(pTree1Num, Tree1NumIndex, pTree2Num, Tree2NumIndex);
    if(pTree1Num)
    {
        free(pTree1Num);
        pTree1Num = NULL;
    }
    if(pTree2Num)
    {
        free(pTree2Num);
        pTree2Num = NULL;
    }    
    return pNum;
}
                 
int main(int argc, char const *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage : %s  [nums] \n", argv[0]);
        exit(1);
    }
    int i = 0;
    /*
    int *nums = (int *)malloc((argc - 1) * sizeof(int));
    for(i = 0; i < (argc - 1); i++)
    {
        nums[i] = atoi(argv[i + 1]);
        printf("%d ", nums[i]);
    }
    printf("\n");
    */
    int *nums = (int *)malloc(10000 * sizeof(int));
    int index = 0;
    const char *pNumsParam = argv[1] + 1;
    while(*pNumsParam != 0)
    {
        char *pTemp = NULL;
        nums[index ++] = strtol(pNumsParam, &pTemp, 10); 
        pNumsParam = pTemp + 1;
    }
    LOG_INFO("nums of num %d ", index);
    int returnSize = 0;
    int **returnColumnSizes = (int **)malloc(5000000 * sizeof(int));
    U64 beginTimeUs = 0;     
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    beginTimeUs = (U64)1000000*(ts.tv_sec) + (U64)ts.tv_nsec/1000;
    //TODO
    clock_gettime(CLOCK_MONOTONIC, &ts);
    U64 endTimeUs = (U64)1000000*(ts.tv_sec) + (U64)ts.tv_nsec/1000;
    U64 costTimeUs = endTimeUs - beginTimeUs;
    LOG_INFO("cost time %lluus %llums %llus", costTimeUs, costTimeUs / 1000, costTimeUs / 1000 / 1000);
    LOG_INFO("sum is zero %d ", returnSize);
    #if 0
    if(zeroNums)
    {
        for(i = 0; i < returnSize; i ++)
        {
            int j = 0;
            //LOG_INFO("colume size %d", *returnColumnSizes[i]);
            for(; j < *returnColumnSizes[i]; j++)
            {
                printf("%d ", zeroNums[i][j]);
            }
            printf("\n");
        }
    }
    #endif
    return 0;
}