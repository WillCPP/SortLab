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
    //return array;
=======
>>>>>>> b6c093405c6192106f0b049f32f0183c03cdab37
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
    insertionSort(array, len);
}