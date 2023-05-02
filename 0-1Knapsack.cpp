#include <bits/stdc++.h>
using namespace std;

int max(int a, int b){
    if(a<b)
        return b;
    else
        return a;
}

struct item {
    int value, weight;
};

bool compare(item a, item b) {
    return a.weight < b.weight;
}

int main() {
    int n, w;
    cout << "Enter the number of items: ";
    cin >> n;
    item items[n];

    cout << "Enter the value and weight of each item: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }
    sort(items, items+n, compare);
    
	cout << "Enter the capacity of the knapsack: ";
    cin >> w;
    
    int V[n+1][w+1];

    for (int i = 0; i <= n; i++)
    {
        V[i][0] = 0;
    }
    
    for (int i = 0; i <= w; i++)
    {
        V[0][i] = 0;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j-items[i-1].weight<0)
            {
                V[i][j] = V[i-1][j];
            }
            else{	
                V[i][j] = max(V[i-1][j], items[i-1].value + V[i-1][j-items[i-1].weight]);
            }
            
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            cout<<V[i][j]<<"\t";
        }

        cout<<"\n";
    }
    cout <<"The maximum value of items that can be put into the knapsack is: " << V[n][w] << endl;

	int res = V[n][w];
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == V[i - 1][w])
            continue;   
        else {
            cout<<items[i-1].weight<<" ";
            res = res - items[i-1].value;
            w = w - items[i-1].weight;
        }
    }
    return 0;
}

