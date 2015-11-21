#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_P 1001
#define MAX_D 1000

void main2() {
    int D;
    int P[MAX_D];
    int maxP = 0;
    
    scanf("%d", &D);
    for(int i = 0; i < D; i++) {
        scanf("%d", &P[i]);
        if(maxP < P[i]) maxP = P[i];
    }
    
    int ans = MAX_P;
    for(int i = 1; i <= maxP; i++) {
        int cur = i;
        for(int j = 0; j < D; j++) {
            cur += (P[j] - 1) / i;
        }
        if(ans > cur) ans = cur;
    }
    
    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        printf("Case #%d: ", i + 1);
        main2();
    }
    return 0;
}