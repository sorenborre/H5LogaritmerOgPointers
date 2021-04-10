#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *array, int size);
void CountingSort(int *pInput, int *pOutput, int *pAux, int auxSize, int inputSize);

int main()
{
    int *pInput, *pOutput, *pAux;

    int input[52] = {5,6,7,12,13,11,11,1,2,3,12,4,4,
                     1,2,11,12,8,9,11,11,4,13,3,5,2,
                     3,6,7,8,0,10,1,3,4,4,5,7,8,
                     1,11,13,0,5,5,9,13,7,8,9,13,13};


    printf("input array: ");
    PrintArray(input, 52);

    pInput = input;

    pOutput = (int *) calloc(52, sizeof(int));

    //an auxiliary array containing k elements where k represents the range between 0 and maximum value in input array
    pAux = (int *) calloc(14, sizeof(int));

    CountingSort(pInput, pOutput, pAux, 14, 52);
    free(pOutput);
    free(pAux);

    return 0;
}

void CountingSort(int *pInput, int *pOutput, int *pAux, int auxSize, int inputSize)
{
    int i;

    //counts the occurrence of a number. fx the array[3] holds x number of times elements with the value of 3 occured. The index value correspond to the element value.
    for (i = 1; i <= inputSize; i++)
    {
        *(pAux+*(pInput+i))+=1;
    }

    printf("The occurrence of a number. fx the array[3] holds x number of elements with the value of 3.\n");

    PrintArray(pAux, auxSize);

    //sets the culminative numbers of elements less than k
    for (i = 1; i < auxSize; i++)
    {
        *(pAux + i) = *(pAux + i)+*(pAux + i - 1);
    }
    printf("\nThe culminative numbers of elements less than k\n");

    PrintArray(pAux, auxSize);

    printf("\nSets the elements in output array k\n");


    for (i = inputSize; i > 0; i--)
    {
        //Takes the inputValue and use it as index value in pAux, to get pAux elements value, which is auxValue.
        // We can then use auxValue as index value for pOutput and set that element to the input[i]s elements value.
        int *inputValue = pInput + i;
        int *auxValue = pAux + *inputValue;
        int *outputValue = (pOutput + *auxValue)-1;

        *outputValue = *inputValue;
        //*(pOutput+(*(pAux+*(pInput+i)))) = *(pInput+i);

        //decrement after moving a number to output
        *auxValue -= 1;
        //*(pAux+*(pInput+i)) = (*(pAux+*(pInput+i)) - 1);
    }

    PrintArray(pOutput, inputSize-1);

}

void PrintArray(int *array, int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("[%d]Result: %d \n",i ,*(array+i));
    }
}
