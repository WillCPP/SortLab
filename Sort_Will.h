#pragma once
#include <array>
#include "LinkedList.h"
#include "Nodes.h"
#include "Student.h"
using namespace std;

enum class SortDir {ASC, DESC};

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

	return;
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

	return;
}

void countingSort(int arr[], int n) {
	//find minimum and maximum values in array
	int max = INT_MIN;
	int min = INT_MAX;
	for (int i = 0; i < n; i++) { 
		max = (arr[i] > max) ? arr[i] : max; 
		if (arr[i] < 0)
		{
			int j = 0;
			j = arr[i];
			int k = 0;
		}
		min = (arr[i] < min) ? arr[i] : min;
	}

	//calc shift
	int shift = max - min + 1;
	int *counts = new int[shift];
	for (int i = 0; i < shift; i++) { counts[i] = 0; }
	int *returnArr = new int[n];

	//count instances
	for (int i = 0; i < n; i++)
	{
		counts[arr[i] - min]++;
	}

	//sequential summation
	for (int i = 1; i < shift; i++)
	{
		counts[i] += counts[i - 1];
	}

	//sort
	for (int i = n - 1; i > -1 ; i--)
	{
		counts[arr[i] - min]--;
		returnArr[counts[arr[i] - min]] = arr[i];
	}

	//return restult
	for (int i = 0; i < n; i++)
	{
		arr[i] = returnArr[i];
	}

	delete[] counts;
	return;
}

void countingSortForRadix(int arr[], int n, int exp)
{
	int *returnArr = new int[n];
	int counts[] = { 0, 0, 0, 0 , 0, 0, 0, 0, 0, 0 };

	//count instances
	for (int i = 0; i < n; i++) {
		counts[(arr[i] / exp) % 10]++;
	}

	//sequential summaation
	for (int i = 1; i < 10; i++) {
		counts[i] += counts[i - 1];
	}

	//sort
	for (int i = n - 1; i >= 0; i--)
	{
		returnArr[counts[(arr[i] / exp) % 10] - 1] = arr[i];
		counts[(arr[i] / exp) % 10]--;
	}

	//return result
	for (int i = 0; i < n; i++) {
		arr[i] = returnArr[i];
	}

	return;
}

void radixSort(int arr[], int n) {
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	for (int i = 1; max/i > 0; i *= 10)
	{
		countingSortForRadix(arr, n, i);
	}

	return;
}

void bubbleSort_LL (Nodes<Student> *pHead, SortDir dir)
{
	bool swapped;
	Nodes<Student> *ptr = pHead;
	Nodes<Student> *prev = nullptr;

	if (ptr == nullptr) {
		return;
	}

	do
	{
		swapped = false;
		ptr = pHead;

		while (ptr->next != prev)
		{
			if (dir == SortDir::ASC)
			{
				if (ptr->data > ptr->next->data)
				{
					//swap(ptr, ptr->next);
					Student temp = ptr->data;
					ptr->data = ptr->next->data;
					ptr->next->data = temp;
					swapped = true;
				}
			}
			else if (dir == SortDir::DESC)
			{
				if (ptr->data < ptr->next->data)
				{
					//swap(ptr, ptr->next);
					Student temp = ptr->data;
					ptr->data = ptr->next->data;
					ptr->next->data = temp;
					swapped = true;
				}
			}
			ptr = ptr->next;
		}
		prev = ptr;
	} while (swapped);

	return;
}

void insertionSort_LL(LinkedList<Student> &ll, SortDir dir) {
	Nodes<Student> *newLL = nullptr;
	Nodes<Student> *ptr = ll.first;

	while (ptr != nullptr)
	{
		Nodes<Student> *next = ptr->next;

		if (dir == SortDir::ASC)
		{
			if (newLL == nullptr || (newLL->data > ptr->data || newLL->data == ptr->data))
			{
				ptr->next = newLL;
				newLL = ptr;
			}
			else
			{
				Nodes<Student> *ptrCur = newLL;
				while (ptrCur->next != nullptr && ptrCur->next->data < ptr->data)
				{
					ptrCur = ptrCur->next;
				}
				ptr->next = ptrCur->next;
				ptrCur->next = ptr;
			}
		}
		else if (dir == SortDir::DESC)
		{
			if (newLL == nullptr || (newLL->data < ptr->data))
			{
				ptr->next = newLL;
				newLL = ptr;
			}
			else
			{
				Nodes<Student> *ptrCur = newLL;
				while (ptrCur->next != nullptr && (ptrCur->next->data > ptr->data || ptrCur->next->data == ptr->data))
				{
					ptrCur = ptrCur->next;
				}
				ptr->next = ptrCur->next;
				ptrCur->next = ptr;
			}
		}
		
		ptr = next;
	}

	ll.first = newLL;

	return;
}

// Partitions the list taking the last element as the pivot
Nodes<Student>* split_LL(Nodes<Student> *head, Nodes<Student> *end,
	Nodes<Student> **newHead, Nodes<Student> **newEnd)
{
	Nodes<Student> *ptrPiv = end;
	Nodes<Student> *ptrPrev = nullptr, *ptrCur = head, *ptrTail = ptrPiv;

	while (ptrCur != ptrPiv)
	{
		if (ptrCur->data < ptrPiv->data)
		{
			if ((*newHead) == nullptr)
			{
				(*newHead) = ptrCur;
			}

			ptrPrev = ptrCur;
			ptrCur = ptrCur->next;
		}
		else
		{
			if (ptrPrev)
			{
				ptrPrev->next = ptrCur->next;
			}
			Nodes<Student> *tmp = ptrCur->next;
			ptrCur->next = nullptr;
			ptrTail->next = ptrCur;
			ptrTail = ptrCur;
			ptrCur = tmp;
		}
	}
	if ((*newHead) == nullptr)
	{
		(*newHead) = ptrPiv;
	}

	(*newEnd) = ptrTail;

	return ptrPiv;
}

Nodes<Student> *quickSort_LL_R(Nodes<Student> *head, Nodes<Student> *end)
{
	if (!head || head == end)
	{
		return head;
	}

	Nodes<Student> *newHead = nullptr, *newEnd = nullptr;
	Nodes<Student> *pivot = split_LL(head, end, &newHead, &newEnd);

	if (newHead != pivot)
	{
		Nodes<Student> *temp = newHead;
		while (temp->next != pivot)
			temp = temp->next;
		temp->next = nullptr;

		newHead = quickSort_LL_R(newHead, temp);

		while (temp != nullptr && temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = pivot;
	}

	pivot->next = quickSort_LL_R(pivot->next, newEnd);

	return newHead;
}

void quickSort_LL(Nodes<Student> **pHead)
{
	Nodes<Student> **tail = pHead;
	while ((*tail) != nullptr && (*tail)->next != nullptr)
	{
		(*tail) = (*tail)->next;
	}
	(*pHead) = quickSort_LL_R(*pHead, *tail);
	return;
}