#include <iostream>
#include <math.h>
using namespace std;

bool check(int T[], int P[], int s, int m){
    for (int i = 0; i < m; i ++){
        if (P[i] != T[i + s]){
            return false;
        }
    }
    return true;
}

void rabinkarpmatcher(int T[], int P[], int n, int m, int d){
    int h = ((int) pow(d, m - 1));
    int p = 0, t0 = 0, ts = 0;
    for (int i = 0; i < m; i++){
        p = d*p + P[i];
        t0 = d*t0 + T[i];
        
    }
    ts = t0;
    for (int s = 0; s < n - m + 1; s++){
        if (p == ts){
            if (check(T, P, s, m)){
                cout << "Pattern found\n";
            }
        }
        if (s < n - m + 1)
            ts = ((ts - T[s]*h)*d + T[s + m]);
    }
}

int main(){
    int P[3] = {1,2,3};
    int T[7] = {1,1,2,3,1,2,3};
    int n = sizeof(T)/sizeof(T[0]);
    int m = sizeof(P)/sizeof(P[0]);
    rabinkarpmatcher(T, P, n, m, 10);
    return 0;
}