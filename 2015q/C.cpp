#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cmath>

#define I 2
#define J 3
#define K 4
#define MAX_L 10001

int lut[][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, I, J, K},
    {0, I, -1, K, -J},
    {0, J, -K, -1, I},
    {0, K, J, -I, -1},
};

int getProd(int o1, int o2) {
    int sign = o1 * o2 >= 0 ? 1 : -1;
    return sign * lut[abs(o1)][abs(o2)];
};

void main2(int t) {
    long long L, X;
    char c;
    int seq[MAX_L];
    int loopLength;
    int loop[10];
    
    scanf("%ld %ld", &L, &X);
    scanf("%c%c", &c, &c); // \r\n
    for(int i = 0; i < L; i++) {
        scanf("%c", &c);
        seq[i] = c - 'i' + I;
        // printf("%d ", seq[i]);
    }
    // printf("\n");
    
    int cur = 1;
    loop[0] = 1;
    int i;
    for(i = 0; i < 10; i++) {
        for(int j = 0; j < L; j++) {
            cur = getProd(cur, seq[j]);
        }
        loop[i + 1] = cur;
        if(cur == 1) {
            loopLength = i + 1;
            break;
        }
        // fflush(stdout);
        // if(t == 35 || t == 59) printf("loop %d: %d\n", i + 1, cur);
        // if(t == 35 || t == 59) cur = i - i + cur;
    }
    // printf("\n");
    
    
    int stage = I;
    int curLoop = 0;
    cur = 1;
    int curStageSteps = 0;
    // int i;
    
    for(i = 0; i < L && curLoop < X; i++) {
        curStageSteps++;
        cur = getProd(cur, seq[i]);
        // if(t == 35 || t == 59) {
            // printf("%d\n", cur);
        // }
        
        if(cur == stage) {
            stage++;
            curStageSteps = 0;
            cur = 1;
            // if(t == 35) printf("Out\n");
            if(stage == K + 1) break;
        }
        
        if(curStageSteps > L * loopLength) {
            printf("NO\n");
            return;
        }
        
        if(i == L - 1) {
            i = -1;
            curLoop += 1;
        }
    }
    
    // if(t == 35) printf("Here\n");
    
    if(stage <= K && curLoop == X) {
        printf("NO\n");
        return;
    }
    
    for(i = i + 1; i < L; i++) {
        cur = getProd(cur, seq[i]);
        // printf("%d ", cur);
    }
    
    int loopsLeft = X - curLoop - 1;
    // printf("%d ", cur);
    cur = getProd(cur, loop[loopsLeft % loopLength]);
    // printf("%d ", cur);
    if(cur == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    scanf("%c%c", &c, &c);
    
}

int main() {
    int T;
    
    setbuf(stdout, NULL);
    
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++) {
        printf("Case #%d: ", i + 1);
        // fflush(stdout);
        main2(i + 1);
    }
    
    return 0;
}