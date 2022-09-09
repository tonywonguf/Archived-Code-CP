//
// Created by Tony on 8/11/2021.
//


#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

typedef long long ll;

vector<ll> tree;
int two_pow = 1;

void update(int u, ll v) {
    u += two_pow;
    tree[u] = v;
    u/=2;
    while (u > 0) {
        tree[u] = tree[2*u]^tree[2*u+1];
        u /= 2;
    }
}

ll query(int a, int b) {
    a += two_pow;
    b += two_pow;

    ll xorsum = 0;
    while (a <= b) {
        if (a % 2 == 1) {
            xorsum = xorsum^tree[a];
            a++;
        }
        if (b % 2 == 0) {
            xorsum = xorsum^tree[b];
            b--;
        }
        a /= 2;
        b /= 2;
    }
    return xorsum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    while (two_pow < n)
        two_pow *= 2;

    vector<int> arr(n);
    tree.assign(2 * two_pow, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        update(i, arr[i]);

    for (int i = 0; i < q; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
          int b, c;
          cin >> b >> c;
//        if (a == 1) {
//            update(b - 1,c);
//        }
//        else
            cout << query(b - 1, c - 1) << "\n";
    }
    /*
    8 4
    3 2 4 5 1 1 5 3
    2 1 4
    2 5 6
    1 3 1
    2 1 4
     */

}