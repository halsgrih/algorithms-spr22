#include <iostream>
#include <cstring>
#define MAX 10000
using namespace std;
void computeLPSarr(char P[], int m, int lps[]){
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < m){
        if (P[i] == P[len]){
            lps[i] = ++len;
            i++;
        } else {
            if (len != 0){
                len = lps[len - 1];
            }else{
                lps[i++] = 0;
            }
        }
    }
}

void KMPsearch(char P[], char T[]){
    int m = strlen(P);
    int n = strlen(T);
    int lps[MAX];
    memset(lps, 0, m);
    computeLPSarr(P, m, lps);
    int i = 0, j = 0;
    while (i < n){
        if (T[i] == P[j]){
            i++;
            j++;
        } else {
            if (j!= 0){
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        if (j == m){
            cout <<i - j;
            j = lps[j - 1];
        }
    }
}

int main(){
    char P[MAX] = {'H', 'a', 'n', 'h'};
    char T[MAX] = {'N', 'H', 'H', 'a', 'n', 'h'};
    KMPsearch(P,T);
    return 0;
}