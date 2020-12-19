#include <iostream>
#include <algorithm>
#include <ctime>
#include <fstream>
using namespace std;


time_t getTime();
void swap(double* element1, double* element2);
void bubbleSort(double arr[], int size);
void printArray(double arr[], int size);
void insertionSort(double arr[], int size);
void selectionSort(double arr[], int size);
void mergeSort(double arr[], int size);
void mergeSortHelper(double arr[], int leftIndex, int rightIndex);
void quickSort(double arr[], int size);
void quickSortHelper(double arr[], int low, int high);


int main(int argc, char const *argv[]) {
    ifstream inFile;

    int size = 0;
    double number;
    int counter = 0;
    string space;
    // Infile
    double *originalArr;
    double *bubbleSortArr;
    double *insertionSortArr;
    double *selectionSortArr;
    double *mergeSortArr;
    double *quickSortArr;

    inFile.open(argv[1]);
    if (!inFile) {
        cout << "Error opening the input file: \"" << argv[1] << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    inFile >> size;

    originalArr = new double[size];
    bubbleSortArr = new double[size];
    insertionSortArr = new double[size];
    selectionSortArr = new double[size];
    mergeSortArr = new double[size];
    quickSortArr = new double[size];

    for (int i = 0; i < size; ++i) {
        inFile >> number;
        getline(inFile, space);
        originalArr[i] = number;
        bubbleSortArr[i] = number;
        insertionSortArr[i] = number;
        selectionSortArr[i] = number;
        mergeSortArr[i] = number;
        quickSortArr[i] = number;
    }

    tm* startTime;
    tm* endTime;
    time_t startNow;
    time_t endNow;
    cout << endl;
    cout << "Bubble Sort Algorithm:  " << endl;
    cout << "Unsorted Array:  ";
    printArray(bubbleSortArr, size);
    startNow = getTime();
    startTime = localtime(&startNow);
    cout << "Start Time: " << 1 + startTime->tm_hour << ":" << 1 + startTime->tm_min << ":" << 1 + startTime->tm_sec << endl;
    bubbleSort(bubbleSortArr, size);
    endNow = getTime();
    endTime = localtime(&endNow);
    cout << "Start Time: " << 1 + startTime->tm_hour << ":" << 1 + startTime->tm_min << ":" << 1 + startTime->tm_sec << endl;
    cout << "Sorted Array:  ";
    printArray(bubbleSortArr, size);
    cout << "The amount of time taken is: " << difftime(startNow, endNow) << endl;
    cout << endl << endl;

    cout << "Insertion Sort Algorithm:  " << endl;
    cout << "Unsorted Array:  ";
    printArray(insertionSortArr, size);
    startNow = getTime();
    startTime = localtime(&startNow);
    cout << "Start Time: " << 1 + startTime->tm_hour << ":" << 1 + startTime->tm_min << ":" << 1 + startTime->tm_sec << endl;
    insertionSort(insertionSortArr, size);
    endNow = getTime();
    endTime = localtime(&endNow);
    cout << "End Time: " << 1 + startTime->tm_hour << ":" << 1 + startTime->tm_min << ":" << 1 + startTime->tm_sec << endl;
    cout << "Sorted Array:  ";
    printArray(insertionSortArr, size);
    cout << "The amount of time taken is: " << difftime(startNow, endNow) << endl;
    cout << endl << endl;

    cout << "Selection Sort Algorithm:  " << endl;
    cout << "Unsorted Array:  ";
    printArray(selectionSortArr, size);
    startNow = getTime();
    startTime = localtime(&startNow);
    cout << "Start Time: " << 1 + startTime->tm_hour << ":" << 1 + startTime->tm_min << ":" << 1 + startTime->tm_sec << endl;
    selectionSort(selectionSortArr, size);
    endNow = getTime();
    endTime = localtime(&endNow);
    cout << "End Time: " << 1 + startTime->tm_hour << ":" << 1 + startTime->tm_min << ":" << 1 + startTime->tm_sec << endl;
    cout << "Sorted Array:  ";
    printArray(selectionSortArr, size);
    cout << "The amount of time taken is: " << difftime(startNow, endNow) << endl;
    cout << endl << endl;

    cout << "Merge Sort Algorithm:  " << endl;
    cout << "Unsorted Array:  ";
    printArray(mergeSortArr, size);
    startNow = getTime();
    startTime = localtime(&startNow);
    cout << "Start Time: " << 1 + startTime->tm_hour << ":" << 1 + startTime->tm_min << ":" << 1 + startTime->tm_sec << endl;
    mergeSort(mergeSortArr, size);
    endNow = getTime();
    endTime = localtime(&endNow);
    cout << "End Time: " << 1 + startTime->tm_hour << ":" << 1 + startTime->tm_min << ":" << 1 + startTime->tm_sec << endl;
    cout << "Sorted Array:  ";
    printArray(mergeSortArr, size);
    cout << "The amount of time taken is: " << difftime(startNow, endNow) << endl;
    cout << endl << endl;

    cout << "Quick Sort Algorithm:  " << endl;
    cout << "Unsorted Array:  ";
    printArray(quickSortArr, size);
    startNow = getTime();
    startTime = localtime(&startNow);
    cout << "Start Time: " << 1 + startTime->tm_hour << ":" << 1 + startTime->tm_min << ":" << 1 + startTime->tm_sec << endl;
    quickSort(quickSortArr, size);
    endNow = getTime();
    endTime = localtime(&endNow);
    cout << "End Time: " << 1 + startTime->tm_hour << ":" << 1 + startTime->tm_min << ":" << 1 + startTime->tm_sec << endl;
    cout << "Sorted Array:  ";
    printArray(quickSortArr, size);
    cout << "The amount of time taken is: " << difftime(startNow, endNow) << endl;
    cout << endl << endl;
    return 0;
}

time_t getTime() {
    return time(0);
}

void swap(double* element1, double* element2) {
    double temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}

void bubbleSort(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertionSort(double arr[], int size) {
    double current;
    int j;
    for (int i = 1; i < size; i++) {
        current = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = current;
    }
}

void selectionSort(double arr[], int size) {
    int i, j, index;
    for (i = 0; i < size - 1; i++) {
        index = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[index])
                index = j;

        swap(&arr[index], &arr[i]);
    }
}

void mergeSort(double arr[], int size) {
    mergeSortHelper(arr, 0, size);
}

void mergeSortHelper(double arr[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        mergeSortHelper(arr, leftIndex, middleIndex);
        mergeSortHelper(arr, middleIndex + 1, rightIndex);

        int array1Size = middleIndex - leftIndex + 1;
        int array2Size = rightIndex - middleIndex;
        int leftArray[array1Size], rightArray[array2Size];

        for (int i = 0; i < array1Size; i++)
            leftArray[i] = arr[leftIndex + i];
        for (int j = 0; j < array2Size; j++)
            rightArray[j] = arr[middleIndex + 1 + j];

        int array1Index = 0;
        int array2Index = 0;
        int startingIndex = leftIndex;

        while (array1Index < array1Size && array2Index < array2Size) {
            if (leftArray[array1Index] <= rightArray[array2Index]) {
                arr[startingIndex] = leftArray[array1Index];
                array1Index++;
            } else {
                arr[startingIndex] = rightArray[array2Index];
                array2Index++;
            }
            startingIndex++;
        }
        while (array1Index < array1Size) {
            arr[startingIndex] = leftArray[array1Index];
            array1Index++;
            startingIndex++;
        }
        while (array2Index < array2Size) {
            arr[startingIndex] = rightArray[array2Index];
            array2Index++;
            startingIndex++;
        }

    }
}

void quickSort(double arr[], int size) {
    quickSortHelper(arr, 0, size);
}

void quickSortHelper(double arr[], int low, int high) {
    if (low < high) {
        int pivot = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= arr[high]) {
                pivot++;
                swap(&arr[pivot], &arr[j]);
            }
        }
        swap(&arr[pivot + 1], &arr[high]);
        quickSortHelper(arr, low, pivot - 1);
        quickSortHelper(arr, pivot + 1, high);
    }
}

void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}