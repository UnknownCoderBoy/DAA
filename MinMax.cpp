#include <bits/stdc++.h>
using namespace std;

void MinMax(int arr[], int low, int high, int & min, int & max) {
    int mid;
    if (low == high) {
        min = arr[low];
        max = arr[high];
        return;
    }
    
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            max = arr[low];
            min = arr[high];
        } else {
            max = arr[high];
            min = arr[low];
        }
        return;
    }
    
    mid = (low + high) / 2;
    MinMax(arr, low, mid, min, max);
    int min1, max1;
    MinMax(arr, mid + 1, high, min1, max1);
    if (min > min1)
        min = min1;
    if (max < max1)
        max = max1;
}

int main() {
    int arr[] = { 73, 6, 52, 15, 22 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    MinMax(arr, 0, n - 1, min, max);
    cout << "Minimum Element is " << min << endl;
    cout << "Maximum Element is " << max << endl;
    return 0;
}
