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

void main2() {
    
    stack<string> buf;
    char c;
    string tmp;
    
    do {
        cin >> tmp;
        buf.push(tmp);
    } while(scanf("%c", &c) != EOF && c != '\r');
    
    cout << tmp;
    buf.pop();
    
    while(!buf.empty()) {
        cout << ' ';
        tmp = buf.top();
        cout << tmp;
        buf.pop();
    }
    
    cout << endl;
    
}

int main() {
    int T;
    scanf("%d\r\n", &T);
    for(int i = 0; i < T; i++) {
        printf("Case #%d: ", i + 1);
        main2();
    }
    return 0;
}