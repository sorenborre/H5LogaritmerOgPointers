#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y);
int main()
{

    int *pn, i, j, temp, size, numbers, length;
     //int numbers[] = {2, 3, 1, 7, 6, -4};
     //pn = numbers;

    printf("Enter size of array:");
	scanf("%d",&numbers); // user sets the "numbers" integer which is used as a parameter to the calloc method.

	pn = calloc(sizeof(int),numbers); //sets the pointer to the address of the array

    //minus 1 because the calloc method sets the last to '\0'
    length = numbers-1;

	printf("Enter %d Elements:",numbers);

    for(i=0;i<length;i++)
	{
		scanf("%d",pn+i); //user sets each of the array slots
	}

    // int length = sizeof(numbers) / sizeof(numbers[0]);

    for(i=0;i<length;i++)
	{

		for(j=0;j<length;j++)
		{

		    //compair numbers in pairs
			if(*(pn+j)>*(pn+j+1))
			{
                swap(pn+j,pn+j+1);
			}
		}

	}

    for(int i = 0; i < length; i++)
    {
        //numbers[i];
        //printf("Result: %d :: ", numbers[i]);
        printf("Result: %d :: ", *(pn+i));

    }
 return 0;
}

void swap(int *x, int *y) {
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}
