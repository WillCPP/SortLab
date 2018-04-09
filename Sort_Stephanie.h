#pragma once


void bubbleSort(int array[], int len)
{
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++){
            if (array[j + 1] < array[j]){ //swap
                int swap = array[j + 1];
                array[j+1] = array[i];
                array[i] = swap;
                
            }
        }   
    }
    return array;
}

void insertionSort()