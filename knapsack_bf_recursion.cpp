#include <bits/stdc++.h>
using namespace std;

int val[1005];
int wei[1005];

int n, M;
int ret;
double START,END;
double bf_time;

void dfs(int it, int v, int w){
    /*
    if (it + 4 <= n + 1){
        dfs(it + 4, v, w);
        dfs(it + 4, v + val[it], w - wei[it]);
        dfs(it + 4, v + val[it + 1], w - wei[it + 1]);
        dfs(it + 4, v + val[it + 2], w - wei[it + 2]);
        dfs(it + 4, v + val[it + 3], w - wei[it + 3]);
        dfs(it + 4, v + val[it] + val[it + 1], w - wei[it] - wei[it + 1]);
        dfs(it + 4, v + val[it] + val[it + 2], w - wei[it] - wei[it + 2]);
        dfs(it + 4, v + val[it] + val[it + 3], w - wei[it] - wei[it + 3]);
        dfs(it + 4, v + val[it] + val[it + 1] + val[it + 2], w - wei[it] - wei[it + 1] - wei[it + 2]);
        dfs(it + 4, v + val[it] + val[it + 1] + val[it + 3], w - wei[it] - wei[it + 1] - wei[it + 3]);
        dfs(it + 4, v + val[it] + val[it + 2] + val[it + 3], w - wei[it] - wei[it + 2] - wei[it + 3]);
        dfs(it + 4, v + val[it] + val[it + 1] + val[it + 2] + val[it + 3], w - wei[it] - wei[it + 1] - wei[it + 2] - wei[it + 3]);
        dfs(it + 4, v + val[it + 1] + val[it + 2], w - wei[it + 1] - wei[it + 2]);
        dfs(it + 4, v + val[it + 1] + val[it + 3], w - wei[it + 1] - wei[it + 3]);
        dfs(it + 4, v + val[it + 1] + val[it + 2] + val[it + 3], w - wei[it + 1] - wei[it + 2] - wei[it + 3]);
        dfs(it + 4, v + val[it + 2] + val[it + 3], w - wei[it + 2] - wei[it + 3]);
        return;
    }
    */
    if (it > n){
        if (w >= 0) ret = max(ret, v);
        return;
    }
    dfs(it + 1, v + val[it], w - wei[it]);
    dfs(it + 1, v, w);
}

int main() {
    cin >> n >> M;
    
    val[0] = 0;
    wei[0] = 0;
    for (int i = 1 ; i <= n ; i++)
        cin >> val[i] >> wei[i];

    ret = 0;
    START = clock();
    dfs(0, 0, M);
    END = clock();
    bf_time = ((END - START) / CLOCKS_PER_SEC);
    cout << n << " " << bf_time << endl;

    return 0;
}