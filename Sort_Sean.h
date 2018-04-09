#pragma once
#include <iostream>

using namespace std;
void mergeSort(int data[], int start, int end, int n);
void mergeSort(int data[], int n) {
	mergeSort(data, 0, n / 2,n);
	mergeSort(data, n / 2, n,n);
}
void mergeSort(int data[], int start, int end, int n) {
	if (end-start > 2) {
		mergeSort(data, start, ((end - start) / 2) + start,n);
		mergeSort(data, ((end-start) / 2) + start, end,n);
	}
	int *temp = new int[end-start];
	int i = start;
	int j = ((end - start) / 2);
	int t = 0;
	while ( t < end) {
		if (i == ((end - start) / 2)) {
			temp[t] = data[j];
			j++;
		}
		else if (j == end) {
			temp[t] = data[i];
			i++;
		}
		else if (data[i] < data[j]) {
			temp[t] = data[i];
			i++;
		}
		else {
			temp[t] = data[j];
			j++;
		}
		t++;
	}
	for (int x = 0; x < end-start; x++) {
		cout << x + start << " set to " << temp[x] << endl;
		data[x+start] = temp[x];
	}
}
