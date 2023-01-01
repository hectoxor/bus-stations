#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define er erase
#define sz size()
#define em empty()
const int N = 110;
using namespace std;
vector <int> d(N);
vector <pair<pair<int,int>,int>> g[N];
void solve(){
    int n;
    cin>>n;
    int st,en;
    cin>>st>>en;
    int m;
    cin>>m;
    while(m--){
        int a,b,c,i;
        cin>>a>>b>>c>>i;
        g[a].pb({{b,i},c});
    }
    set <pair<int,int>> s;
    s.ins({0,st});
    for(int i = 1;i<=n;i++){
        d[i] = 1e9;
    }
    d[st] = 0;
    while(!s.em){
        int v = (*s.begin()).second;
        s.er(s.begin());
        for(auto to:g[v]){
            int q = to.first.first;
            int w = to.first.second;
            if(d[v] > to.first.first){
                continue;
            }
            if(d[to.second] > max(d[v],to.first.second)){
                s.er({d[to.second],to.second});
                d[to.second] = max(d[v],to.first.second);
                s.ins({d[to.second],to.second});
            }
        }
        
    }
    if(d[en] == 1e9){
        cout<<-1;
        return;
    }
    cout<<d[en];
}
int main(){
    int tt = 1;
    while(tt--){
        solve();
    }
}
