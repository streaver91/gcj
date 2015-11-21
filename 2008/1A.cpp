#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_N 1000

using namespace std;

int cmpAsc(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int cmpDesc(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}


void main2() {
    int n;
    long long x[MAX_N], y[MAX_N];
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%ld", &x[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%ld", &y[i]);
    }
    
    qsort(x, n, sizeof(long long), cmpAsc);
    qsort(y, n, sizeof(long long), cmpDesc);
    
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += x[i] * y[i];
    }
    
    printf("%ld\n", sum);
    
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        printf("Case #%d: ", i + 1);
        main2();
    }
}