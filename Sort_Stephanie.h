#pragma once

void bubbleSort(int array[], int len)
{
	bool swapped = false;
    for (int i = 0; i < len-1; i++) {
		swapped = false;
        for (int j = 0; j < len-i-1; j++){
            if (array[j] > array[j + 1]){ //swap
				swapped = true;
                int swap = array[j + 1];
                array[j + 1] = array[j];
                array[j] = swap;
            }
        }  
		if (!swapped) { return; }
    }
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
}