#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <utility>

#include "header.h"


using namespace std;
using std::chrono::system_clock;

using std::chrono::duration_cast;

using std::chrono::nanoseconds;

using std::chrono::seconds;


long long NanoTime() {
    // Get the current time in seconds.
    auto now = system_clock::now();

    // Calculate the current time in nanoseconds.
    auto difference = duration_cast<nanoseconds>(now.time_since_epoch());

    // Store the result in a large integer (long long).
    long long current_time_nano = difference.count();

    return current_time_nano;
}

vector<int> Populator(int size) {

    vector<int> randomNum;

    for (int i = 0; i < size; i++) {
        int min = 1;
        int max = 100;

        std::random_device dev;

        std::mt19937 rng(dev());

        std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);

        int random_number = dist6(rng);

        randomNum.push_back(random_number);
    }

    return randomNum;

}





/*
Buble Sort Implementation

The following code referenced from geeksforgeeks.com, which can be found at the following link:

https://www.geeksforgeeks.org/bubble-sort-in-cpp/

Date Accessed: 05/01/2024

Authored By: No visible Author

*/

void bubbleSort(vector<int>& arr)
{
    bool isUnsorted;
    do {
        isUnsorted = false;
        for (int i = 0; i < (arr.size() - 1); i++) {
            if (arr[i] > arr[i + 1]) {
                isUnsorted = true;
                for (; i < (arr.size() - 1); i++) {
                    if (arr[i] > arr[i + 1]) {
                        std::swap(arr[i], arr[i + 1]);
                    }
                }
            }
        }
    } while (isUnsorted);
}


/*
Quick Sort

The following code referenced from <Medium.com>, which can be found at the following link:

https://medium.com/algo-101/quick-sort-explained-c-stl-c8d105cbaade

Date Accessed: 05/01/2024

Authored By: Purushottam Banerjee

*/
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pivot = partition(nums, low, high);
        quickSort(nums, low, pivot - 1);
        quickSort(nums, pivot + 1, high);
    }
}

void Bubble(int size)
{
    vector<int> data = Populator(size);
    long long startTime = NanoTime();
    bubbleSort(data);
    long long endTime = NanoTime();
    long long nanoSec = endTime - startTime;
    double timeSec = nanoSec / (1000000000.00);
    cout << "\t Dataset Size : " << size << ", \tTime(nanoseconds) : " << nanoSec << ", " << "\t" << " \tTime(seconds) : " << timeSec <<  endl;
}

void Quick(int size)
{
    vector<int> data = Populator(size);
    long long startTime = NanoTime();
    quickSort(data, 0, data.size() - 1);
    long long endTime = NanoTime();
    long long nanoSec = endTime - startTime;
    double timeSec = nanoSec / (1000000000.00);

    cout << "\t Dataset Size: " << size << ", \t Time (nanoseconds): " << nanoSec << "\t" << ", \tTime (seconds): " << timeSec << endl;
}