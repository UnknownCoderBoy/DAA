#include <bits/stdc++.h>
using namespace std;

const int n = 4;
const int MAX = 1000000;

int dist[n][n] = { {  0, 10, 15, 20 },
                   { 10, 0, 25, 25 }, 
                   { 15, 25, 0, 30 },
                   { 20, 25, 30, 0 },
};

int tsp(int mask, int pos) {
    if (mask == ((1 << n) - 1))
        return dist[pos][0];

    int res = MAX;

    for (int j = 1; j < n; j++) {
        if ((mask & (1 << j)) == 0) {
            int newMask = mask | (1 << j);
            res = min(res, dist[pos][j] + tsp(newMask, j));
        }
    }

    return res;
}

int main() {
    int ans = tsp(1, 0);
    printf("The cost of most efficient tour = %d\n", ans);

    return 0;
}

