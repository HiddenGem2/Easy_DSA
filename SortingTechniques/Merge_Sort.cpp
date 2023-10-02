#include <bits/stdc++.h>

using namespace std;

void merge(int array[], int left, int mid, int right) {
    int n = mid - left + 1, m = right - mid;

    auto *arr1 = new int[n], *arr2 = new int[m];

    for (int i = 0; i < n; i++) arr1[i] = array[left + i];
    for (int j = 0; j < m; j++) arr2[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            array[k] = arr1[i];
            i++;
        } else {
            array[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n) {
        array[k] = arr1[i];
        i++;
        k++;
    }

    while (j < m) {
        array[k] = arr2[j];
        j++;
        k++;
    }
    delete[] arr1;
    delete[] arr2;
}

void mergeSort(int array[], int begin, int end) {
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    cout << "\nEnter array\n";
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    cout << "Array after Sorting\n";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout << "\n";
    return 0;
}
