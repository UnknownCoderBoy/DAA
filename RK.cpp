#include <bits/stdc++.h>
using namespace std;
#define d 10

void RabinKarp(char pattern[], char string[], int q) {
    int m = strlen(pattern);
    int n = strlen(string);
    int i, j;
    int p = 0; 
    int t = 0; 
    int h = 1; 

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + string[i]) % q;
    }

    for (i = 0; i <= n - m; i++) {
        if (p == t) { 
            for (j = 0; j < m; j++) {
                if (string[i + j] != pattern[j]) 
                    break;
            }
            if (j == m) 
                cout << "Pattern is found at position: " << i << endl;
        }

        if (i < n - m) { 
            t = (d * (t - string[i] * h) + string[i + m]) % q;

            if (t < 0) 
                t = (t + q);
        }
    }
}


int main() {
    char string[] = "AABAACAADAABAAABAA";
    char pattern[] = "AABA";
    int q = 13;
    RabinKarp(pattern, string, q);
}
