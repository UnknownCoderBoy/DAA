#include <bits/stdc++.h>
using namespace std;

void naiveStringMatching(string text, string pattern) {
    int n = text.length(); 
    int m = pattern.length(); 

    for (int i = 0; i <= n - m; i++) {
        int j;
        
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) 
                break;
        }
        if (j == m) { 
            cout << "Pattern found at index " << i << endl;
    	}
    }
}

int main() {
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";
    naiveStringMatching(text, pattern); 
	return 0;
}

