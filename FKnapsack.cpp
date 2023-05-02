#include<bits/stdc++.h>
using namespace std;

struct item {
    int value, weight;
    double fraction;
};

bool compare(item a, item b) {
    return a.fraction > b.fraction;
}

int main() {
    int n, w;
    cout << "Enter the number of items: ";
    cin >> n;
    item items[n];

    cout << "Enter the weight and value of each item: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].fraction = (double) items[i].value / items[i].weight;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> w;
    sort(items, items + n, compare);
    int currentWeight = 0;
    double totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= w) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remaining = w - currentWeight;
            totalValue += items[i].fraction * remaining;
            break;
        }
    }
    cout << "The maximum value of items that can be put into the knapsack is: " << totalValue << endl;

    return 0;
}
