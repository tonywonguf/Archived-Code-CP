//
// Created by Tony on 8/19/2021.
//


#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;

    int n;
    cin >> n;
    while(n--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        ans += (a+b+c)>=2;
    }
    cout << ans << endl;
}