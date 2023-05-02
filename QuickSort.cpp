#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j=low; j<high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[high]);
    return (i);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
	int num;
    cout << "Enter the Number of Elements: ";
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++) {
        cin>> arr[i];
    }
    quickSort(arr, 0, num-1);
    cout<<"Sorted array: \n";
    for (int i=0; i < num; i++)
        cout<<arr[i]<<" "; 
    return 0;
}

