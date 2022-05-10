#include <bits/stdc++.h>
using namespace std;

struct Item {
    int v, w;
    double cp() {
        return (double) v / w;
    }
};

struct cur{
    int v, w, it;
    cur(int v_, int w_, int it_): v(v_), w(w_), it(it_) {}
};

stack<cur> st;
Item items[1005];

int n, M;
int ret;

void dfs(int it, int v, int w){
    st.push(cur(v, w, it));
    while(!st.empty()){
        cur tmp = st.top();
        st.pop();
        if (tmp.it > n){
            if (tmp.w >= 0){
                ret = max(ret, tmp.v);
            }
        }
        else{
            st.push(cur(tmp.v + items[tmp.it].v, tmp.w - items[tmp.it].w, tmp.it + 1));
            st.push(cur(tmp.v, tmp.w, tmp.it + 1));
        }
    }
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