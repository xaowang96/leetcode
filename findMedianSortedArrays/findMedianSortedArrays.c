#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int tmp = 0;
	int *numsTmp = NULL;
	/**确保m<=n，不然j=(m+n+1)/2 - i会小于0*/
	if (nums1Size > nums2Size)
	{
		tmp = nums1Size;
		numsTmp = nums1;
		nums1Size = nums2Size;
		nums1 = nums2;
		nums2 = numsTmp;
		nums2Size = tmp;
	}
	int imin = 0; 
	int imax = nums1Size;
	int halfLen = (nums1Size + nums2Size + 1) / 2;
	while(imin <= imax)
	{
		int i = (imin + imax) / 2;
		int j = halfLen - i;
		if ((i < nums1Size) && (nums2[j-1] > nums1[i]))
		{
			/*i is small, need crease */
			imin = i + 1;
		}
		else if((i > 0) && (nums1[i - 1] > nums2[j]))
		{
			/*i is big, need decrease*/
			imax = i - 1;
		}
		else 
		{
			/*i is perfect*/
			int leftMaxValue = 0;
			if (i == 0)
			{
				leftMaxValue = nums2[j-1];
			}
			else if(j == 0)
			{
				leftMaxValue = nums1[i-1];
			}
			else
			{
				leftMaxValue = (nums1[i-1] > nums2[j-1])? 
					nums1[i-1]: nums2[j-1];
			}
			if(((nums1Size + nums2Size) % 2) == 1)
			{
				printf("num1size %d num2size %d value %d\n", nums1Size, nums2Size, leftMaxValue);
				return leftMaxValue;
			}

			int rightMinValue = 0;
			if(i == nums1Size)
			{
				rightMinValue = nums2[j];
			}
			else if(j == nums2Size)
			{
				rightMinValue = nums1[i];
			}
			else
			{
				rightMinValue = (nums1[i] < nums2[j])?
					nums1[i]: nums2[j];
			}
			printf("left %d right %d\n", leftMaxValue, rightMinValue);
			return ((double)leftMaxValue + (double)rightMinValue) / 2.0;
		}
	}
}

int  main(int argc, char const *argv[])
{
	int nums1[] = {1, 3, 7};
	int nums2[] = {2, 4, 56};
	double mediaNum = findMedianSortedArrays(nums1, 3, nums2, 3);
	printf("mediaNum is %f\n", mediaNum);
	return 0;
}