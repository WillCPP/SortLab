#pragma once

void heapify(int arr[], int i, int n) {
	int j = 2 * i;
	int temp = a[i];

	while (j <= n)
	{
		if (j < n && arr[j+1] > arr[j])
		{
			j = j += 1;
		}
		if (temp > arr[j])
		{
			break;
		}
		else if (temp <= arr[j])
		{
			arr[j / 2] = arr[j];
			j = 2 * j;
		}
	}
	arr[j / 2] = temp;
	return;
}

void buildHeap(int arr[], int n) {
	for (int i = n/2; i >= 1; i--)
	{
		heapify(arr, i, n);
	}
}

void heapSort(int arr[], int n) {
	buildHeap(arr, n);
	int temp = -1;
	for (int i = n; i >= 2; i--)
	{
		temp = arr[i];
		arr[i] = arr[1];
		arr[1] = temp;
		heapify(arr, 1, i - 1);
	}
}

void countingSort() {

}

void radixSort() {

}