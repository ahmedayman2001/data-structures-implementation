
              ///  ( DFS-based Cycle Detection in an Directed Graph  )




   
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



  /// DFS-based Cycle Detection in an Directed Graph ////

  vector<pair<int,int>> adj[N];

  bool vis[N];
  bool inStack[N];

  bool dfsCycle(int u)
{
    vis[u] = true;
    inStack[u] = true;

    cout << u << ' ';

    for (auto [v, w] : adj[u])
    {
        if (!vis[v])
        {
            if (dfsCycle(v))
                return true;
        }
        else if (inStack[v])
        {
            return true; // cycle found
        }
    }

    inStack[u] = false;

    return false;
}

int main() {

  int n , m ;
  cin >> n >> m ;


 //// Adjacency List ////

    for ( int i = 0 , u , v , w ; i < m ; ++i )  {

        cin >> u >> v >> w ;
        adj[u].push_back ( {v , w } ) ;
       // adj[v].push_back ( {u , w } ) ; /// undirected  ///

    }
    bool hasCycle = false;

    for (int u = 1; u <= n; ++u)
    {
        if (!vis[u])
        {
            if (dfsCycle(u))
            {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle)

        cout << "\nGraph contains cycle\n";
    else
        cout << "\nGraph does NOT contain cycle\n";


    return 0 ;
}





