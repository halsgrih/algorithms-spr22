#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 5100
using namespace std;

int sa[MAX], tmp[MAX], lcp[MAX], gap, N;
char S[MAX], pos[MAX];
void printArr (int a[], int size){
    cout << endl;
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

bool sufCmp(int i, int j){
    if (pos[i] != pos[j]){
        return pos[i] < pos[j];
    }
    i += gap;
    j+= gap;

    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA(){
    N = strlen(S);
    for (int i = 0; i < N; ++i){
        sa[i] = i;
        pos[i] = S[i];
    }

    for (gap = 1;; gap *= 2){
        sort(sa, sa + N, sufCmp);

        for (int i = 0; i < N - 1; ++i){
            tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        }

        for (int i = 0; i < N; ++i){
            pos[sa[i]] = tmp[i];
        }

        if (tmp[N - 1] == N - 1) break;
    }
}

void buildLCP()
    {
        for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
        {
            for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
            ++k;
            lcp[pos[i]] = k;
            if (k)--k;
        }
    }

int main(){
    return 0;
}