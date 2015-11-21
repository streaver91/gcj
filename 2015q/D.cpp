#include <cstdio>

#define P1 "RICHARD"
#define P2 "GABRIEL"

void main2() {
    int X, R, C;
    int tmp;
    scanf("%d %d %d", &X, &R, &C);
    
    if(R < C) {
        tmp = R;
        R = C;
        C = tmp;
    }
    
    if(X >= 7) {
        printf("%s\n", P1);
        return;
    }
    
    if(X > R) {
        printf("%s\n", P1);
        return;
    }
    
    if(R * C % X != 0) {
        printf("%s\n", P1);
        return;
    }
    
    int maxShortEdge = (X + 1) >> 1;
    
    if(maxShortEdge > C) {
        printf("%s\n", P1);
        return;
    }
    
    if(X == 5 && R == 5 && C == 3) {
        printf("%s\n", P1);
        return;
    }
    
    if((X == 4 || X == 6) && maxShortEdge == C) {
        printf("%s\n", P1);
        return;
    }
    
    
    
    printf("%s\n", P2);
    
}

int main() {
    int T;
    
    scanf("%d", &T);
    
    for(int t = 0; t < T; t++) {
        printf("Case #%d: ", t + 1);
        main2();
    }
    
    return 0;
}