#include <iostream>
#include <random>
#include <ctime>
using namespace std;

const int S_10 = 10;
const int S_100 = 100;
const int S_500 = 500;
const int S_5000 = 5000;
const int S_25000 = 25000;

int main() {
	//initialize random number generator and distributions
	random_device rng;
	default_random_engine eng{rng()};
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
	for (int i = 0; i < S_25000 - 1; ++i) {
		int temp_10 = static_cast<int>(dist_10(eng));
		int temp_100 = static_cast<int>(dist_100(eng));
		int temp_500 = static_cast<int>(dist_500(eng));
		int temp_5000 = static_cast<int>(dist_5000(eng));
		int temp_25000 = static_cast<int>(dist_25000(eng));

		if (i < S_10){ arr_10[i] = temp_10; }
		if (i < S_100){ arr_100[i] = temp_100; }
		if (i < S_500){ arr_500[i] = temp_500; }
		if (i < S_5000){ arr_5000[i] = temp_5000; }
		if (i < S_25000){ arr_25000[i] = temp_25000; }
	}

	//============= test functions below

	return 0;
}