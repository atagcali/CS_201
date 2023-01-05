// cs201_hw2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool isSubsetsimple(int* arr1, int* arr2, int arr1size, int arr2size);
int binarySearch(int* arr, int low, int high, int x);
bool isSubsetbinary(int* arr1, int* arr2, int arr1size, int arr2size);
bool isSubsetfreq(int* arr1, int* arr2, int arr1size, int arr2size);
int findmax(int* arr);
int* createarray1(int& size) {
    cout << " formula is x*10^y" << endl;
    cout << " x = ?";
    int x = 0;
    cin >> x;
    cout << " y = ?";
    int y = 0;
    cin >> y;
    int a = 1;
    for (int i = 0; i < y; i++) {
        a = a * 10;
    }
    a = x * a;
    int* array = new int[a];
    for (int i = 0; i < a ; i++) {
        array[i] = i + 1;
    }
    size = a;
    return array;
}
int* createarray2(int& size) {
    int answer;
    cout << "3 or 4" << endl;
    cin >> answer;
    int a = 1;
    for (int i = 0; i < answer; i++) {
        a = a * 10;
    }
    int* array = new int[a];
    for (int i = 0; i < a; i++) {
        array[i] = (rand() % 1000) + 1;
    }
    size = a;
    return array;
}

int* maxvaluesizedarray(int* arr,int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= max) {
            max = arr[i];
        }
    }
    int* newarray = new int[max];
    for (int i = 0; i < max; i++) {
        newarray[i] = 0;
    }
    return newarray;
}


bool isSubsetsimple(int* arr1, int* arr2, int arr1size, int arr2size){
    //double duration;
    //clock_t startTime = clock();
    int i = 0;
    int j = 0;
    int same = 0;
    bool result = 0;
    for (i = 0; i < arr1size; i++) {
        for (j = 0; j < arr2size; j++) {
            if (arr2[j] == arr1[i])
                same++;
        }
    }
    if (same == arr2size) {
        cout << "ALGO1 arr2[] is subset of arr1[] " << endl;
        result = 1;
    }
    else {
        cout << "ALGO1 arr2[] is not a subset of arr1[]" << endl;
        result = 0;
    }
    //duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    //cout << "Execution took " << duration << " milliseconds." << endl;
    return result;
};


int binarySearch(int* arr, int N, int value) {
    int low = 0, high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < value)
            low = mid + 1;
        else if (arr[mid] > value)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}


bool isSubsetbinary(int* arr1, int* arr2, int arr1size, int arr2size) {
    //double duration;
    //clock_t startTime = clock();
    bool result = 1;
    for (int i = 0; i < arr2size; i++) {
        if (binarySearch(arr1, arr1size - 1, arr2[i]) == -1) {
            result = 0;
        }
    }
    if (result)
        cout << "ALGO2  arr4[] is subset of arr3[] " << endl;
    else
        cout << "ALGO2  arr4[] is not a subset of arr3[]" << endl;
    return result;
}



bool isSubsetfreq(int* arr1, int* arr2, int arr1size, int arr2size) {
    //double duration;
    //clock_t startTime = clock();
    int* frequency = new int[arr1[arr1size - 1]];
    for (int i = 0; i < arr1size; i++) {
        frequency[arr1[i]]++;
    }
    bool subset = 1;
    for (int i = 0; i < arr2size; i++) {
        if (frequency[arr2[i]] == 0) {
            subset = 0;
        }
    }
    if (subset) {
        cout << "ALGO3  arr6[] is subset of arr5[] " << endl;
    }
    else {
        cout << "ALGO3  arr6[] is not a subset of arr5[]" << endl;
    }
    //duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    //cout << "Execution took " << duration << " milliseconds." << endl;
    return subset;
    
}


int main()
{
    

    int a;
    int b;
    int* arr3;
    int* arr4;
    arr3 = createarray1(a);
    arr4 = createarray2(b);
    double duration;
    clock_t startTime = clock();
    isSubsetsimple(arr3, arr4, a, b);
    duration = 1000 * double(clock() - startTime) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    double duration1;
    clock_t startTime1 = clock();
    for (int i = 0; i < 10; i++) {
        isSubsetbinary(arr3, arr4, a, b);
    }
    duration1 = 1000 * double(clock() - startTime1) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration1 << " milliseconds." << endl;
    double duration2;
    clock_t startTime2 = clock();
    for (int i = 0; i < 10; i++) {
        isSubsetfreq(arr3, arr4, a, b);
    }
    duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration2 << " milliseconds." << endl;
    
    
    
    
    
    
    return 0;



};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
