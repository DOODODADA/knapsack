#include <bits/stdc++.h>
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
    cin >> n >> M;
    
    items[0].v = 0;
    items[0].w = 0;
    for (int i = 1 ; i <= n ; i++)
        cin >> items[i].v >> items[i].w;

    ret = 0;
    dfs(0, 0, M);
    cout << ret << endl;
    return 0;
}