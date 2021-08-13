#include <iostream>

using namespace std;

int a, b, ans;

void solve()
{
    cin >> a >> b;

    ans = a + b;

    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();

    return 0;
}