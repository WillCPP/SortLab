#pragma once
#include <iostream>

using namespace std;
void Merge(int data[], int start,int  end) {
	int mid = (end + start) / 2;
	int len = end - start + 1;
	int *temp = new int[len]();//used to store sorted values 
	int i = start;			//used to keep track of postion in start half
	int j = mid + 1;			//used to keep track of postion in end half
	int t = 0;				//used to keep track of position in temp
	while (i <= mid || j <= end) {
		if (data[i] < data[j]) {//if i spot is smaller than j
			temp[t] = data[i];
			i++;
		}
		else {//if j is larger than i
			temp[t] = data[j];
			j++;
		}
		t++;
	}
	while (i <= mid) {
		temp[t] = data[j];
		j++;
		t++;
	}
	while (j <= end) {
		temp[t] = data[i];
		i++;
		t++;
	}
	for (int x = start; x <= end; x++) {
		data[i] = temp[i-start];
	}
}

void mergeSort(int data[], int start, int end);
void mergeSort(int data[], int n) {//n = length of array
	mergeSort(data, 0, n / 2);//spliting array in two
	mergeSort(data, n / 2, n);
}

void mergeSort(int data[], int start, int end) {//start is the number the split begins and end is the end but not included
	if (start < end) {
		int mid = (end + start) / 2;
		mergeSort(data, start, mid);
		mergeSort(data, mid, start);
		Merge(data, start, end);

	}
}

void quickSort(int data[], int lower, int higher) {
	int low = lower;
	int high = higher;
	int pivot = data[(low + high) / 2];
	int temp = -1;

	while (low <= high)
	{
		while (data[low] < pivot)
		{
			low++;
		}
		while (data[high] > pivot)
		{
			high--;
		}
		if (low <= high)
		{
			temp = data[low];
			data[low] = data[high];
			data[high] = temp;
			low++;
			high--;
		}
	}

	if (lower < high)
	{
		//sort lower side
		quickSort(data, lower, high);
	}
	if (higher > low)
	{
		//sort higher side
		quickSort(data, low, higher);
	}
}
