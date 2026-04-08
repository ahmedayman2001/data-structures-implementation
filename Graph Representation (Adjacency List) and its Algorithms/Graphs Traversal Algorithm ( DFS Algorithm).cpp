
/**

Difference between dfs and dfsTree :

1️⃣ dfs(u) → General Graph DFS ✅

Works for:

- cyclic graph ✅

- acyclic graph ✅

- tree ✅

- disconnected graph ✅



2️⃣ dfsTree(u, parent) → Tree DFS only ⚠

Works ONLY when graph is a TREE.

Tree properties:

- nodes = n
- edges = n-1
- connected
- no cycles


 **/

#include <bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define ld long double
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;

  vector<pair<int ,int >>adj[N] ;

  bool vis[N] ;

void dfs(int u)
{
    cout << u << ' ';
    vis[u] = true;

    for (auto [v, w] :  adj[u] )

    {
        if (! vis[v] )

            dfs( v) ;
    }

}




  void dfsTree (int u  , int parent ){


    cout<<u<<' ';
      for (auto [v , w] : adj[u]) {

          if (v == parent ) continue;

          dfsTree(v , u ) ;
      }

}





int main() {

  int n , m ;
  cin >> n >> m ;


 //// Adjacency List ////

    for ( int i = 0 , u , v , w ; i < m ; ++i )  {

        cin >> u >> v >> w ;
        adj[u].push_back ( {v , w } ) ;
        adj[v].push_back ( {u , w } ) ; /// undirected  ///

    }


    // dfs(0)
    // dfsTree(1, 0) ;




    return 0 ;
}





