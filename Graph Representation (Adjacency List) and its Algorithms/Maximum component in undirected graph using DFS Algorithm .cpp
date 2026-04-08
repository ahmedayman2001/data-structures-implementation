 
         ///  ( Maximum component in undirected graph using DFS Algorithm ) : 



          
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


  //// Maximum component in undirected graph using DFS Algorithm ///

 int dfs ( int u )  {

    int cnt = 1 ;

    cout << u << ' ';
    vis[u] = true;

    for (auto [v, w] :  adj[u] )

    {
        if (! vis[v] )

             cnt+=dfs( v) ;
    }

     return cnt ;

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

    int res = 0 ;
    for (int u = 1; u <= n  ; ++u) {

        if ( vis[u] ) continue ;

        res = max(res , dfs(u)) ;

    }
cout <<"\nMaximum component = " << res <<el;



    return 0 ;
}





