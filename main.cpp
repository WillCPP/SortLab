#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <chrono>
#include "Sort_Will.h"
#include "Sort_Stephanie.h"
#include "Sort_Sean.h"
#include "LinkedList.h"
#include "Student.h"
#include "Date.h"
using namespace std;
using namespace std::chrono;

const int S_10 = 10;
const int S_100 = 100;
const int S_500 = 500;
const int S_5000 = 5000;
const int S_25000 = 25000;

int main() {
	//initialize random number generator and distributions
	random_device rd;

	default_random_engine rng{rd()};

	uniform_real_distribution<double> dist_10(0, 2 * S_10);
	uniform_real_distribution<double> dist_100(0, 2 * S_100);
	uniform_real_distribution<double> dist_500(0, 2 * S_500);
	uniform_real_distribution<double> dist_5000(0, 2 * S_5000);
	uniform_real_distribution<double> dist_25000(0, 2 * S_25000);

	//initialize arrays
	int arr_10[S_10];
	int arr_100[S_100];
	int arr_500[S_500];
	int arr_5000[S_5000];
	int arr_25000[S_25000];

	//fill arrays with random numbers
	for (int i = 0; i < S_25000; ++i) {
		int temp_10 = static_cast<int>(dist_10(rng));
		int temp_100 = static_cast<int>(dist_100(rng));
		int temp_500 = static_cast<int>(dist_500(rng));
		int temp_5000 = static_cast<int>(dist_5000(rng));
		int temp_25000 = static_cast<int>(dist_25000(rng));

		if (i < S_10){ arr_10[i] = temp_10; }
		if (i < S_100){ arr_100[i] = temp_100; }
		if (i < S_500){ arr_500[i] = temp_500; }
		if (i < S_5000){ arr_5000[i] = temp_5000; }
		if (i < S_25000){ arr_25000[i] = temp_25000; }
	}

	int arr_10_bubble[S_10];
	int arr_10_insertion[S_10];
	int arr_10_merge[S_10];
	int arr_10_quick[S_10];
	int arr_10_heap[S_10];
	int arr_10_counting[S_10];
	int arr_10_radix[S_10];
	copy(begin(arr_10), end(arr_10), begin(arr_10_bubble));
	copy(begin(arr_10), end(arr_10), begin(arr_10_insertion));
	copy(begin(arr_10), end(arr_10), begin(arr_10_merge));
	copy(begin(arr_10), end(arr_10), begin(arr_10_quick));
	copy(begin(arr_10), end(arr_10), begin(arr_10_heap));
	copy(begin(arr_10), end(arr_10), begin(arr_10_counting));
	copy(begin(arr_10), end(arr_10), begin(arr_10_radix));

	int arr_100_bubble[S_100];
	int arr_100_insertion[S_100];
	int arr_100_merge[S_100];
	int arr_100_quick[S_100];
	int arr_100_heap[S_100];
	int arr_100_counting[S_100];
	int arr_100_radix[S_100];
	copy(begin(arr_100), end(arr_100), begin(arr_100_bubble));
	copy(begin(arr_100), end(arr_100), begin(arr_100_insertion));
	copy(begin(arr_100), end(arr_100), begin(arr_100_merge));
	copy(begin(arr_100), end(arr_100), begin(arr_100_quick));
	copy(begin(arr_100), end(arr_100), begin(arr_100_heap));
	copy(begin(arr_100), end(arr_100), begin(arr_100_counting));
	copy(begin(arr_100), end(arr_100), begin(arr_100_radix));

	int arr_500_bubble[S_500];
	int arr_500_insertion[S_500];
	int arr_500_merge[S_500];
	int arr_500_quick[S_500];
	int arr_500_heap[S_500];
	int arr_500_counting[S_500];
	int arr_500_radix[S_500];
	copy(begin(arr_500), end(arr_500), begin(arr_500_bubble));
	copy(begin(arr_500), end(arr_500), begin(arr_500_insertion));
	copy(begin(arr_500), end(arr_500), begin(arr_500_merge));
	copy(begin(arr_500), end(arr_500), begin(arr_500_quick));
	copy(begin(arr_500), end(arr_500), begin(arr_500_heap));
	copy(begin(arr_500), end(arr_500), begin(arr_500_counting));
	copy(begin(arr_500), end(arr_500), begin(arr_500_radix));

	int arr_5000_bubble[S_5000];
	int arr_5000_insertion[S_5000];
	int arr_5000_merge[S_5000];
	int arr_5000_quick[S_5000];
	int arr_5000_heap[S_5000];
	int arr_5000_counting[S_5000];
	int arr_5000_radix[S_5000];
	copy(begin(arr_5000), end(arr_5000), begin(arr_5000_bubble));
	copy(begin(arr_5000), end(arr_5000), begin(arr_5000_insertion));
	copy(begin(arr_5000), end(arr_5000), begin(arr_5000_merge));
	copy(begin(arr_5000), end(arr_5000), begin(arr_5000_quick));
	copy(begin(arr_5000), end(arr_5000), begin(arr_5000_heap));
	copy(begin(arr_5000), end(arr_5000), begin(arr_5000_counting));
	copy(begin(arr_5000), end(arr_5000), begin(arr_5000_radix));

	int arr_25000_bubble[S_25000];
	int arr_25000_insertion[S_25000];
	int arr_25000_merge[S_25000];
	int arr_25000_quick[S_25000];
	int arr_25000_heap[S_25000];
	int arr_25000_counting[S_25000];
	int arr_25000_radix[S_25000];
	copy(begin(arr_25000), end(arr_25000), begin(arr_25000_bubble));
	copy(begin(arr_25000), end(arr_25000), begin(arr_25000_insertion));
	copy(begin(arr_25000), end(arr_25000), begin(arr_25000_merge));
	copy(begin(arr_25000), end(arr_25000), begin(arr_25000_quick));
	copy(begin(arr_25000), end(arr_25000), begin(arr_25000_heap));
	copy(begin(arr_25000), end(arr_25000), begin(arr_25000_counting));
	copy(begin(arr_25000), end(arr_25000), begin(arr_25000_radix));

	//============= test functions below
	//bubbleSort(arr_10, S_10);
	//insertionSort(arr_10,S_10);

	//mergeSort
	//quickSort
	
	//heapSort(arr_10, S_10);
	//countingSort(arr_10, S_10);
	//radixSort(arr_10, S_10);

	auto start_time_10_bubble = high_resolution_clock::now();
	bubbleSort(arr_10_bubble, S_10); //call function here
	auto stop_time_10_bubble = high_resolution_clock::now();
	auto duration_10_bubble = duration_cast<nanoseconds>(stop_time_10_bubble - start_time_10_bubble);
	auto start_time_100_bubble = high_resolution_clock::now();
	bubbleSort(arr_100_bubble, S_100); //call function here
	auto stop_time_100_bubble = high_resolution_clock::now();
	auto duration_100_bubble = duration_cast<nanoseconds>(stop_time_100_bubble - start_time_100_bubble);
	auto start_time_500_bubble = high_resolution_clock::now();
	bubbleSort(arr_500_bubble, S_500); //call function here
	auto stop_time_500_bubble = high_resolution_clock::now();
	auto duration_500_bubble = duration_cast<nanoseconds>(stop_time_500_bubble - start_time_500_bubble);
	auto start_time_5000_bubble = high_resolution_clock::now();
	bubbleSort(arr_5000_bubble, S_5000); //call function here
	auto stop_time_5000_bubble = high_resolution_clock::now();
	auto duration_5000_bubble = duration_cast<nanoseconds>(stop_time_5000_bubble - start_time_5000_bubble);
	auto start_time_25000_bubble = high_resolution_clock::now();
	bubbleSort(arr_25000_bubble, S_25000); //call function here
	auto stop_time_25000_bubble = high_resolution_clock::now();
	auto duration_25000_bubble = duration_cast<nanoseconds>(stop_time_25000_bubble - start_time_25000_bubble);

	auto start_time_10_insertion = high_resolution_clock::now();
	insertionSort(arr_10_insertion, S_10); //call function here
	auto stop_time_10_insertion = high_resolution_clock::now();
	auto duration_10_insertion = duration_cast<nanoseconds>(stop_time_10_insertion - start_time_10_insertion);
	auto start_time_100_insertion = high_resolution_clock::now();
	insertionSort(arr_100_insertion, S_100); //call function here
	auto stop_time_100_insertion = high_resolution_clock::now();
	auto duration_100_insertion = duration_cast<nanoseconds>(stop_time_100_insertion - start_time_100_insertion);
	auto start_time_500_insertion = high_resolution_clock::now();
	insertionSort(arr_500_insertion, S_500); //call function here
	auto stop_time_500_insertion = high_resolution_clock::now();
	auto duration_500_insertion = duration_cast<nanoseconds>(stop_time_500_insertion - start_time_500_insertion);
	auto start_time_5000_insertion = high_resolution_clock::now();
	insertionSort(arr_5000_insertion, S_5000); //call function here
	auto stop_time_5000_insertion = high_resolution_clock::now();
	auto duration_5000_insertion = duration_cast<nanoseconds>(stop_time_5000_insertion - start_time_5000_insertion);
	auto start_time_25000_insertion = high_resolution_clock::now();
	insertionSort(arr_25000_insertion, S_25000); //call function here
	auto stop_time_25000_insertion = high_resolution_clock::now();
	auto duration_25000_insertion = duration_cast<nanoseconds>(stop_time_25000_insertion - start_time_25000_insertion);

	auto start_time_10_merge = high_resolution_clock::now();
	//mergeSort(arr_10_merge, S_10); //call function here
	auto stop_time_10_merge = high_resolution_clock::now();
	auto duration_10_merge = duration_cast<nanoseconds>(stop_time_10_merge - start_time_10_merge);
	auto start_time_100_merge = high_resolution_clock::now();
	//mergeSort(arr_100_merge, S_100); //call function here
	auto stop_time_100_merge = high_resolution_clock::now();
	auto duration_100_merge = duration_cast<nanoseconds>(stop_time_100_merge - start_time_100_merge);
	auto start_time_500_merge = high_resolution_clock::now();
	//mergeSort(arr_500_merge, S_500); //call function here
	auto stop_time_500_merge = high_resolution_clock::now();
	auto duration_500_merge = duration_cast<nanoseconds>(stop_time_500_merge - start_time_500_merge);
	auto start_time_5000_merge = high_resolution_clock::now();
	//mergeSort(arr_5000_merge, S_5000); //call function here
	auto stop_time_5000_merge = high_resolution_clock::now();
	auto duration_5000_merge = duration_cast<nanoseconds>(stop_time_5000_merge - start_time_5000_merge);
	auto start_time_25000_merge = high_resolution_clock::now();
	//mergeSort(arr_25000_merge, S_25000); //call function here
	auto stop_time_25000_merge = high_resolution_clock::now();
	auto duration_25000_merge = duration_cast<nanoseconds>(stop_time_25000_merge - start_time_25000_merge);

	auto start_time_10_quick = high_resolution_clock::now();
	quickSort(arr_10_quick, 0, S_10 - 1); //call function here
	auto stop_time_10_quick = high_resolution_clock::now();
	auto duration_10_quick = duration_cast<nanoseconds>(stop_time_10_quick - start_time_10_quick);
	auto start_time_100_quick = high_resolution_clock::now();
	quickSort(arr_100_quick, 0, S_100 - 1); //call function here
	auto stop_time_100_quick = high_resolution_clock::now();
	auto duration_100_quick = duration_cast<nanoseconds>(stop_time_100_quick - start_time_100_quick);
	auto start_time_500_quick = high_resolution_clock::now();
	quickSort(arr_500_quick, 0, S_500 - 1); //call function here
	auto stop_time_500_quick = high_resolution_clock::now();
	auto duration_500_quick = duration_cast<nanoseconds>(stop_time_500_quick - start_time_500_quick);
	auto start_time_5000_quick = high_resolution_clock::now();
	quickSort(arr_5000_quick, 0, S_5000 - 1); //call function here
	auto stop_time_5000_quick = high_resolution_clock::now();
	auto duration_5000_quick = duration_cast<nanoseconds>(stop_time_5000_quick - start_time_5000_quick);
	auto start_time_25000_quick = high_resolution_clock::now();
	quickSort(arr_25000_quick, 0, S_25000 - 1); //call function here
	auto stop_time_25000_quick = high_resolution_clock::now();
	auto duration_25000_quick = duration_cast<nanoseconds>(stop_time_25000_quick - start_time_25000_quick);

	auto start_time_10_heap = high_resolution_clock::now();
	heapSort(arr_10_heap, S_10); //call function here
	auto stop_time_10_heap = high_resolution_clock::now();
	auto duration_10_heap = duration_cast<nanoseconds>(stop_time_10_heap - start_time_10_heap);
	auto start_time_100_heap = high_resolution_clock::now();
	heapSort(arr_100_heap, S_100); //call function here
	auto stop_time_100_heap = high_resolution_clock::now();
	auto duration_100_heap = duration_cast<nanoseconds>(stop_time_100_heap - start_time_100_heap);
	auto start_time_500_heap = high_resolution_clock::now();
	heapSort(arr_500_heap, S_500); //call function here
	auto stop_time_500_heap = high_resolution_clock::now();
	auto duration_500_heap = duration_cast<nanoseconds>(stop_time_500_heap - start_time_500_heap);
	auto start_time_5000_heap = high_resolution_clock::now();
	heapSort(arr_5000_heap, S_5000); //call function here
	auto stop_time_5000_heap = high_resolution_clock::now();
	auto duration_5000_heap = duration_cast<nanoseconds>(stop_time_5000_heap - start_time_5000_heap);
	auto start_time_25000_heap = high_resolution_clock::now();
	heapSort(arr_25000_heap, S_25000); //call function here
	auto stop_time_25000_heap = high_resolution_clock::now();
	auto duration_25000_heap = duration_cast<nanoseconds>(stop_time_25000_heap - start_time_25000_heap);

	auto start_time_10_counting = high_resolution_clock::now();
	countingSort(arr_10_counting, S_10); //call function here
	auto stop_time_10_counting = high_resolution_clock::now();
	auto duration_10_counting = duration_cast<nanoseconds>(stop_time_10_counting - start_time_10_counting);
	auto start_time_100_counting = high_resolution_clock::now();
	countingSort(arr_100_counting, S_100); //call function here
	auto stop_time_100_counting = high_resolution_clock::now();
	auto duration_100_counting = duration_cast<nanoseconds>(stop_time_100_counting - start_time_100_counting);
	auto start_time_500_counting = high_resolution_clock::now();
	countingSort(arr_500_counting, S_500); //call function here
	auto stop_time_500_counting = high_resolution_clock::now();
	auto duration_500_counting = duration_cast<nanoseconds>(stop_time_500_counting - start_time_500_counting);
	auto start_time_5000_counting = high_resolution_clock::now();
	countingSort(arr_5000_counting, S_5000); //call function here
	auto stop_time_5000_counting = high_resolution_clock::now();
	auto duration_5000_counting = duration_cast<nanoseconds>(stop_time_5000_counting - start_time_5000_counting);
	auto start_time_25000_counting = high_resolution_clock::now();
	countingSort(arr_25000_counting, S_25000); //call function here
	auto stop_time_25000_counting = high_resolution_clock::now();
	auto duration_25000_counting = duration_cast<nanoseconds>(stop_time_25000_counting - start_time_25000_counting);

	auto start_time_10_radix = high_resolution_clock::now();
	radixSort(arr_10_radix, S_10); //call function here
	auto stop_time_10_radix = high_resolution_clock::now();
	auto duration_10_radix = duration_cast<nanoseconds>(stop_time_10_radix - start_time_10_radix);
	auto start_time_100_radix = high_resolution_clock::now();
	radixSort(arr_100_radix, S_100); //call function here
	auto stop_time_100_radix = high_resolution_clock::now();
	auto duration_100_radix = duration_cast<nanoseconds>(stop_time_100_radix - start_time_100_radix);
	auto start_time_500_radix = high_resolution_clock::now();
	radixSort(arr_500_radix, S_500); //call function here
	auto stop_time_500_radix = high_resolution_clock::now();
	auto duration_500_radix = duration_cast<nanoseconds>(stop_time_500_radix - start_time_500_radix);
	auto start_time_5000_radix = high_resolution_clock::now();
	radixSort(arr_5000_radix, S_5000); //call function here
	auto stop_time_5000_radix = high_resolution_clock::now();
	auto duration_5000_radix = duration_cast<nanoseconds>(stop_time_5000_radix - start_time_5000_radix);
	auto start_time_25000_radix = high_resolution_clock::now();
	radixSort(arr_25000_radix, S_25000); //call function here
	auto stop_time_25000_radix = high_resolution_clock::now();
	auto duration_25000_radix = duration_cast<nanoseconds>(stop_time_25000_radix - start_time_25000_radix);

	cout << "Bubble Sort" << endl;
	cout << "===========" << endl;
	cout << "Number of Items | Execution Time (ns)" << endl;
	cout << setw(16) << "10" << "|" << setw(15) << right << duration_10_bubble.count() << " ns" << endl;
	cout << setw(16) << "100" << "|" << setw(15) << right << duration_100_bubble.count() << " ns" << endl;
	cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_bubble.count() << " ns" << endl;
	cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_bubble.count() << " ns" << endl;
	cout << setw(16) << "25000" << "|" << setw(15) << right << duration_25000_bubble.count() << " ns" << endl;
	cout << endl;

	cout << "Insertion Sort" << endl;
	cout << "===========" << endl;
	cout << "Number of Items | Execution Time (ns)" << endl;
	cout << setw(16) << "10" << "|" << setw(15) << right << duration_10_insertion.count() << " ns" << endl;
	cout << setw(16) << "100" << "|" << setw(15) << right << duration_100_insertion.count() << " ns" << endl;
	cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_insertion.count() << " ns" << endl;
	cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_insertion.count() << " ns" << endl;
	cout << setw(16) << "25000" << "|" << setw(15) << right << duration_25000_insertion.count() << " ns" << endl;
	cout << endl;

	// merge sort
	cout << "Merge Sort" << endl;
	cout << "===========" << endl;
	cout << "Number of Items | Execution Time (ns)" << endl;
	cout << setw(16) << "10" << "|" << setw(15) << right << duration_10_merge.count() << " ns" << endl;
	cout << setw(16) << "100" << "|" << setw(15) << right << duration_100_merge.count() << " ns" << endl;
	cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_merge.count() << " ns" << endl;
	cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_merge.count() << " ns" << endl;
	cout << setw(16) << "25000" << "|" << setw(15) << right << duration_25000_merge.count() << " ns" << endl;
	cout << endl;

	// quicksort
	cout << "quick Sort" << endl;
	cout << "===========" << endl;
	cout << "Number of Items | Execution Time (ns)" << endl;
	cout << setw(16) << "10" << "|" << setw(15) << right << duration_10_quick.count() << " ns" << endl;
	cout << setw(16) << "100" << "|" << setw(15) << right << duration_100_quick.count() << " ns" << endl;
	cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_quick.count() << " ns" << endl;
	cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_quick.count() << " ns" << endl;
	cout << setw(16) << "25000" << "|" << setw(15) << right << duration_25000_quick.count() << " ns" << endl;
	cout << endl;

	cout << "Heap Sort" << endl;
	cout << "===========" << endl;
	cout << "Number of Items | Execution Time (ns)" << endl;
	cout << setw(16) << "10" << "|" << setw(15) << right << duration_10_heap.count() << " ns" << endl;
	cout << setw(16) << "100" << "|" << setw(15) << right << duration_100_heap.count() << " ns" << endl;
	cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_heap.count() << " ns" << endl;
	cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_heap.count() << " ns" << endl;
	cout << setw(16) << "25000" << "|" << setw(15) << right << duration_25000_heap.count() << " ns" << endl;
	cout << endl;

	cout << "Counting Sort" << endl;
	cout << "===========" << endl;
	cout << "Number of Items | Execution Time (ns)" << endl;
	cout << setw(16) << "10" << "|" << setw(15) << right << duration_10_counting.count() << " ns" << endl;
	cout << setw(16) << "100" << "|" << setw(15) << right << duration_100_counting.count() << " ns" << endl;
	cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_counting.count() << " ns" << endl;
	cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_counting.count() << " ns" << endl;
	cout << setw(16) << "25000" << "|" << setw(15) << right << duration_25000_counting.count() << " ns" << endl;
	cout << endl;

	cout << "Radix Sort" << endl;
	cout << "===========" << endl;
	cout << "Number of Items | Execution Time (ns)" << endl;
	cout << setw(16) << "10" << "|" << setw(15) << right << duration_10_radix.count() << " ns" << endl;
	cout << setw(16) << "100" << "|" << setw(15) << right << duration_100_radix.count() << " ns" << endl;
	cout << setw(16) << "500" << "|" << setw(15) << right << duration_500_radix.count() << " ns" << endl;
	cout << setw(16) << "5000" << "|" << setw(15) << right << duration_5000_radix.count() << " ns" << endl;
	cout << setw(16) << "25000" << "|" << setw(15) << right << duration_25000_radix.count() << " ns" << endl;
	cout << endl;

	////linked list stuff
	//data for generating random students
	string firstNames[100] = { "Emily", " Madison", " Emma", " Hannah", " Olivia", " Abigail", " Isabella", " Ashley", " Samantha", " Elizabeth", " Alexis", " Sarah", " Alyssa",
		"Grace", " Sophia", " Taylor", " Brianna", " Lauren", " Ava", " Kayla", " Jessica", " Natalie", " Chloe", " Anna", " Victoria", " Hailey",
		"Mia", " Sydney", " Jasmine", " Morgan", " Julia", " Destiny", " Rachel", " Megan", " Kaitlyn", " Katherine", " Jennifer", " Savannah",
		"Ella", " Alexandra", " Haley", " Allison", " Maria", " Nicole", " Mackenzie", " Brooke", " Makayla", " Kaylee", " Lily", " Stephanie",
		"Jacob", " Michael", " Joshua", " Matthew", " Christopher", " Andrew", " Daniel", " Ethan", " Joseph", " William", " Anthony", " Nicholas",
		"David", " Alexander", " Ryan", " Tyler", " James", " John", " Jonathan", " Brandon", " Christian", " Dylan", " Zachary", " Noah", " Samuel", " Benjamin",
		"Nathan", " Logan", " Justin", " Jose", " Gabriel", " Austin", " Kevin", " Caleb", " Robert", " Elijah", " Thomas", " Jordan", " Cameron", " Hunter",
		"Jack", " Angel", " Isaiah", " Jackson", " Evan", " Luke", " Jason", " Isaac", " Mason", " Aaron" };

	string lastNames[100] = { "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia",
		"Martinez", "Robinson", "Clark", "Rodriguez", "Lewis", "Lee", "Walker", "Hall", "Allen", "Young", "Hernandez", "King", "Wright", "Lopez", "Hill", "Scott", "Green", "Adams", "Baker", "Gonzalez", "Nelson", 
		"Carter", "Mitchell", "Perez", "Roberts", "Turner", "Phillips", "Campbell", "Parker", "Evans", "Edwards", "Collins", "Stewart", "Sanchez", "Morris", "Rogers", "Reed", "Cook", "Morgan", "Bell", "Murphy", 
		"Bailey", "Rivera", "Cooper", "Richardson", "Cox", "Howard", "Ward", "Torres", "Peterson", "Gray", "Ramirez", "James", "Watson", "Brooks", "Kelly", "Sanders", "Price", "Bennett", "Wood", "Barnes", "Ross", 
		"Henderson", "Coleman", "Jenkins", "Perry", "Powell", "Long", "Patterson", "Hughes", "Flores", "Washington", "Butler", "Simmons", "Foster", "Gonzales", "Bryant", "Alexander", "Russell", "Griffin", "Diaz",
		"Hayes" };
	
	uniform_real_distribution<double> dist_names(0, 100);
	uniform_real_distribution<double> dist_m_num(10000000, 99999999);
	uniform_real_distribution<double> dist_gpa(2, 4);

	LinkedList<Student> ll;
	//add items to linked list
	for (int i = 0; i < 20; i++)
	{
		string t = "M" + to_string(i + 10000000); 
		//string t = "M" + to_string((int)dist_m_num(rng));//to_string(i + 10000000); 
		int f = dist_names(rng);
		int l = dist_names(rng);
		double gpa = dist_gpa(rng);
		Student s(firstNames[f], lastNames[l], t, Date(1,1,1), gpa);
		ll.addItem(s);
	}
	//bubble sort
	//bubbleSort_LL(ll.first, SortDir::DESC);
	//ll.displayList();
	//insertionsort
	//insertionSort_LL(ll.first, SortDir::DESC);
	//ll.displayList();
	//quicksort

	//menu

	return 0;
}