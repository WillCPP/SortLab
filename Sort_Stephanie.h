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
<<<<<<< HEAD
=======
    //return array;
>>>>>>> 4ebc18e4a6a8a2a9aa120b6beef3e508c2a06906
}

void insertionSort(int array[], int len) {
    for (int i = 1; i < len; i++) {
        int item = array[i];
        int j = i-1;
        while (j >= 0 && array[j] > item) {
            array[j+1] = array[j];
            j = j-1;
        }
        array[j+1] = item;
    }
<<<<<<< HEAD
    insertionSort(array, len);
=======
    
>>>>>>> 4ebc18e4a6a8a2a9aa120b6beef3e508c2a06906
}