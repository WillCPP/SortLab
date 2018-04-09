#pragma once

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i)
	{
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);
	}
}

void countingSort(int arr[], int sz) {
	int index = 0;
	int min = -1;
	int max = -1;
	int k = -1;

	min = max = arr[0];
	for (int i = 1; i < sz; i++) {
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}

	k = max - min + 1;
	int *counts = new int[k];
	for (int i = 0; i < k; i++) {
		counts[i] = 0;
	}

	for (int i = 0; i < sz; i++) {
		counts[arr[i] - min]++;
	}
	for (int i = min; i <= max; i++) {
		for (int j = 0; j < counts[i - min]; j++) {
			arr[index++] = i;
		}
	}

	delete[] counts;
}

void countingSortForRadix(int arr[], int n, int exp)
{
	
}

void radixSort(int arr[], int n) {
	int max = -1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	for (int i = 0; max/i > 0; i *= 10)
	{
		countingSortForRadix(arr, n, i);
	}
}