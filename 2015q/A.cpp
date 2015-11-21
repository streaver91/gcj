#include <cstdio>
#include <cstdlib>

void main2() {
    int Smax;
    char c;
    int shyLevel;
    int curAud = 0;
    int addedAud = 0;
    int levelAud;
    
    scanf("%d", &Smax);
    
    scanf("%c", &c); // space
    
    for(int i = 0; i < Smax + 1; i++) {
        scanf("%c", &c);
        levelAud = c - '0';
        shyLevel = i;
        if(shyLevel > curAud) {
            addedAud += shyLevel - curAud;
            curAud = shyLevel;
        }
        curAud += levelAud;
    }
    
    printf("%d\n", addedAud);
    
}

int main() {
    int T;
    
    scanf("%d", &T);
    
    for(int i = 0; i < T; i++) {
        printf("Case #%d: ", i + 1);
        main2();
    }
}