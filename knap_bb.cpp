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
double time_slot[3];

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
    srand(5);
    for (int k = 0 ; k < 8 ; k++){
        for (int l = 0 ; l < 3 ; l++){
            M = rand() % (MAX_M - MIN_M + 1) + MIN_M;
            n = 5 + 5 * k;
    
            items[0].v = 0;
            items[0].w = 0;
            for (int i = 1 ; i <= n ; i++){
                items[i].v = rand() % (MAX_V - MIN_V + 1) + MIN_V;
                items[i].w = rand() % (MAX_W - MIN_W + 1) + MIN_W;
            }
                
            START = clock();
            stable_sort(items + 1, items + (n + 1), cmpCP);
            ret = 0;
            dfs(0, 0, M);
            END = clock();
            time_slot[l] = ((END - START) / CLOCKS_PER_SEC);
            //cout << ret << endl;
        }
        double avarage = (time_slot[0] + time_slot[1] + time_slot[2]) / 3;
        cout << n << ":" << avarage << endl;
    }
    return 0;
}