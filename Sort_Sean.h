#pragma once
#include <iostream>

using namespace std;
void mergeSort(int data[], int start, int end, int n);
void mergeSort(int data[], int n) {//n = length of array
	mergeSort(data, 0, n / 2,n);//spliting array in two
	mergeSort(data, n / 2, n,n);
}
void mergeSort(int data[], int start, int end, int n) {//start is the number the split begins and end is the end but not included
	if (end-start > 2) {//if length of split is larger than 2 split again
		mergeSort(data, start, ((end - start) / 2) + start,n);
		mergeSort(data, ((end-start) / 2) + start, end,n);
	}
	int *temp = new int[end-start];//used to store sorted values 
	int i = start;//used to keep track of postion in start half
	int j = ((end - start) / 2)+start;//end-start gives length divding it in half gives how far it from start it begins 
	int t = 0;//used to keep track of position in temp
	while ( t < end) {
		if (i == ((end - start) / 2)+start) {//if there are no more spots in the start half
			temp[t] = data[j];
			j++;
		}
		else if (j == end) {//if there are no more spots in the end half
			temp[t] = data[i];
			i++;
		}
		else if (data[i] < data[j]) {//if i spot is smaller than j
			temp[t] = data[i];
			i++;
		}
		else {//if j is larger than i
			temp[t] = data[j];
			j++;
		}
		t++;
	}
	for (int x = 0; x < end-start; x++) {//seting data to equal sorted temp
		//cout << x + start << " set to " << temp[x] << endl;
		data[x+start] = temp[x];
	}
}

void quickSort(int data[], int n) {

}
