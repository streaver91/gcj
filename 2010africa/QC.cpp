#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
// #include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <unordered_map>

#define MAX_LINE 1001

using namespace std;

char ch2num[] = "222333444555666777788899990";
int rep[27];

void pre() {
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(i == 0 || ch2num[i] != ch2num[i - 1]) cnt = 0;
        cnt++;
        rep[i] = cnt;
    }
    rep[26] = 1;
    // for(int i = 0; i < 26; i++) {
        // printf("%d ", rep[i]);
    // }
    
    // printf("\n");
}

void main2() {
    char c;
    char buf[MAX_LINE];
    
    for(int i = 0; i < MAX_LINE; i++) {
        if(scanf("%c", &c) == EOF || c == '\r') {
            buf[i] = '\0';
            scanf("%c", &c);
            break;
        }
        // printf("%c-", c);
        buf[i] = c;
    }
    
    // printf("%s\n", buf);
    // return;
    
    char last = '*', cur;
    int idx;
    for(int i = 0; i < strlen(buf); i++) {
        c = buf[i];
        if(c == ' ') {
            idx = 26;
        } else {
            idx = c - 'a';
        }
        
        cur = ch2num[idx];
        if(cur == last) {
            printf(" ");
        }
        for(int j = 0; j < rep[idx]; j++) printf("%c", cur);
        last = cur;
    }
    
    printf("\n");
}

int main() {
    int T;
    scanf("%d", &T);
    char c;
    scanf("%c%c", &c, &c);
    
    pre();
    
    for(int i = 0; i < T; i++) {
        printf("Case #%d: ", i + 1);
        main2();
    }
    return 0;
}