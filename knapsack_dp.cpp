#include <iostream>
#include <queue>

//#define Verble
using namespace std;

int P[101], W[101];
int dp_map[101][10001] = {{0}};

int main(void){
    int n, M;
    int pri, wei;
    cin >> n >> M;
    for (int i = 1 ; i <= n ; i++) {
        cin >> pri >> wei;
        P[i] = pri;
        W[i] = wei;
    }

    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j <= M ; j++) {
            if (j == 0) dp_map[i][j] = 0;
            else if (W[i] <= j && P[i] + dp_map[i-1][j-W[i]] > dp_map[i-1][j])
                dp_map[i][j] = P[i] + dp_map[i-1][j-W[i]];
            else dp_map[i][j] = dp_map[i-1][j];
        }
    }

    #ifdef Verble
    for (int i = 0 ; i <= n ; i++) {
        for (int j = 0 ; j <= M ; j++) {
            cout << dp_map[i][j] << ' ';
            if (j == M) cout << endl;
        }
    }
    #endif

    cout << dp_map[n][M] << endl;
    return 0;
}