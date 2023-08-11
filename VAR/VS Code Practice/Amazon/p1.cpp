#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, armor;
    cin >> n;
    cin >> armor;
    vector<int> power;
    
    int s = 0, mx = 0;
    for (int i = 0; i < power.size(); i++)
    {
        int p;
        cin >> p;
        mx = max(mx, p);
        s += p;
    }
    s += 1;
    s -= min(armor, mx);
    cout << s << endl;
}