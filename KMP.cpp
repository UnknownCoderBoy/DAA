#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pattern, int m, vector < int > & lps) {
    int len = 0; 
    int i = 1;
    lps[0] = 0; 

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else { 
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector < int > lps(m);

    computeLPSArray(pattern, m, lps);

    int i = 0; 
    int j = 0; 
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
		if (j == m) { 
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; 
        } 
    }
}

int main() {
    string text = "AABAACAADAABAAABAA";
    string pattern = "AABA";
    KMPSearch(text, pattern);
    return 0;
}
