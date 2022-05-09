#include <bits/stdc++.h>
#define MAX_M 10000
#define MIN_M 500
#define MAX_W 9000
#define MIN_W 200
#define MAX_V 600
#define MIN_V 5
using namespace std;

struct Item {
    int v, w;
    double cp() {
        return (double) v / w;
    }
};

Item items[1005];

int n, M;
int ret;
double START,END;
double time_slot;

void dfs(int it, int v, int w){
    if (it > n){
        if (w >= 0)
            ret =  max(v, ret);
        return;
    }
    dfs(it + 1, v + items[it].v, w - items[it].w);
    dfs(it + 1, v, w);
}

int main() {
    srand(5);
    for (int k = 0 ; k < 8 ; k++){
        M = rand() % (MAX_M - MIN_M + 1) + MIN_M;
        n = 5 + 5 * k;
        
        items[0].v = 0;
        items[0].w = 0;
        for (int i = 1 ; i <= n ; i++) {
            items[i].v = rand() % (MAX_V - MIN_V + 1) + MIN_V;
            items[i].w = rand() % (MAX_W - MIN_W + 1) + MIN_W;
        }
        ret = 0;
        START = clock();
        dfs(0, 0, M);
        END = clock();
        time_slot = ((END - START) / CLOCKS_PER_SEC);
        //cout << ret << endl;
        cout << n << ":" << time_slot << endl;
    }
    return 0;
}