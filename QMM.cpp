#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(vector<int> &arr, int l, int r, int x) {
    int i;
    for (i = l; i < r; i++) {
        if (arr[i] == x) {
            break;
        }
    }
    swap(arr[i], arr[r]);
    i = l - 1;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int findMedian(vector<int> &arr, int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int n = r - l + 1;
        vector<int> medians;
        for (int i = 0; i < n/5; i++) {
            int m = l + i * 5;
            sort(arr.begin() + m, arr.begin() + m + 5);
            medians.push_back(arr[m + 2]);
        }
        if (n % 5) {
            int m = l + n/5 * 5;
            int e = l + n - 1;
            sort(arr.begin() + m, arr.begin() + e + 1);
            medians.push_back(arr[m + (e - m) / 2]);
        }
        int mom = findMedian(medians, 0, medians.size() - 1, medians.size() / 2);
        int pivot = partition(arr, l, r, mom);
        if (pivot - l == k - 1) {
            return arr[pivot];
        } else if (pivot - l > k - 1) {
            return findMedian(arr, l, pivot - 1, k);
        } else {
            return findMedian(arr, pivot + 1, r, k - pivot + l - 1);
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {8,33,17,51,57,49,35,11,25,37,14,3,2,13,52,12,6,29,32,54,5,16,22,23,7};
    int n = arr.size();
    int m = findMedian(arr, 0, n - 1, n / 2 + 1);
    cout << "Median: " << m << endl;
    return 0;
}
