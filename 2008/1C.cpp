#include <cstdio>
#include <cmath>

#define MAX_SQ 10

double sq[MAX_SQ];

void pre() {
    sq[0] = 1;
    sq[1] = 3 + sqrt(5);
    for(int i = 2; i < MAX_SQ; i++) {
        long long a, b, tmp;
        double c;
        sq[i] = sq[i - 1] * sq[i - 1];
        tmp = int(sq[i]);
        a = tmp / 1000 * 1000;
    }
}

void main2() {
    long long n;
    scanf("%ld", &n);
    
    
}

int main() {
    int T;
    
    pre();
    
    for(int i = 0; i < MAX_SQ; i++) {
        printf("%d\t%lf\n", i, sq[i]);
    }
    
    return 0;
    
    scanf("%d\n", T);
    
    for(int i = 0; i < T; i++) {
        printf("Case #%d: ", i + 1);
        main2();
    }
    
    return 0;
}