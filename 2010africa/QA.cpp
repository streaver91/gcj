#include <iostream>
// #include <sstream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <set>
// #include <map>
#include <algorithm>
// #include <functional>
// #include <utility>
// #include <bitset>
// #include <cmath>
// #include <cstdlib>
// #include <ctime>
// #include <cstdio>
#include <unordered_map>

using namespace std;

#define MAX_I 2000

void main2() {
    int C, I;
    int prices[MAX_I];
    
    scanf("%d %d", &C, &I);
    
    for(int i = 0; i < I; i++) {
        scanf("%d", &prices[i]);
    }
    
    unordered_map<int, int> price2Id;
    for(int i = 0; i < I; i++) {
        price2Id[prices[i]] = i;
    }
    
    for(int i = 0; i < I; i++) {
        int p1 = prices[i];
        int left = C - p1;
        if(price2Id.count(left) > 0 && i != price2Id[left]) {
            printf("%d %d\n", i + 1, price2Id[left] + 1);
            break;
        }
    }
    
}

int main() {
    int T, t;
    cin >> T;
    for(t = 0; t < T; t++) {
        printf("Case #%d: ", t + 1);
        main2();
    }
    return 0;
}