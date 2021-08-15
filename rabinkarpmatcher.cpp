#include <iostream>
#include <math.h>
using namespace std;

bool check(int T[], int P[], int s, int m){
    for (int i = 1; i < m; i ++){
        if (P[i] != T[i + s]){
            return false;
        }
    }
    return true;
}

void rabinkarpmatcher(int T[], int P[], int d, int q){
    int n = sizeof(T)/sizeof(*T);
    int m = sizeof(P)/sizeof(*P);
    int h = ((int) pow(d, m - 1)) % q;
    int p = 0, t0 = 0, ts = 0;

    for (int i = 0; i < m; i++){
        p = (d*p + P[i]) % q;
        t0 = (d*t0 + T[i]) % q;
    }
    ts = t0;
    for (int s = 0; s < n - m + 1; s++){
        if (p == ts){
            if (check(T, P, s, m)){
                cout << "Pattern found\n";
            }
        }
        if (s < n - m + 1)
            ts = ((ts - T[s + 1]*h)*d + T[s + m + 1]) % q;
    }

}

int main(){
    int P[3] = {1,2,3};
    int T[6] = {1,2,3,1,2,3};
    rabinkarpmatcher(T, P, 10, 1);
    return 0;
}