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

int cmpCP(Item a, Item b) {
    double cpA = a.cp();
    double cpB = b.cp();
    if (cpA == cpB)
        return a.w > b.w;
    return cpA > cpB;
}

int greedy(int w, int it){
    int val = 0;
    for (int i = it ; i <= n ; i++){
        if (w <= items[i].w) {
            val += items[i].cp() * w;
            break;
        }
        val += items[i].v;
        w -= items[i].w;
    }
    return val;
}

void dfs(int it, int v, int w){
    if (it > n){
        ret =  max(v, ret);
        return;
    }
    int ub = greedy(w, it) + v;
    if (ub <= ret) return;
    if (ub == v){
        //cout << it << ',' << v << ',' << ret << endl;
        ret =  max(v, ret);
        return;
    }
    if (w >= items[it].w)
        dfs(it + 1, v + items[it].v, w - items[it].w);
    dfs(it + 1, v, w);
    return;
}

int main() {
    cin >> n >> M;
    
    items[0].v = 0;
    items[0].w = 0;
    for (int i = 1 ; i <= n ; i++)
        cin >> items[i].v >> items[i].w;
    
    stable_sort(items + 1, items + (n + 1), cmpCP);
    ret = 0;
    dfs(0, 0, M);
    cout << ret << endl;
    return 0;
}