

  
   /// (  Graphs Representation )


#include <bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(false) , cin.tie(nullptr);

#define ll long long
#define el endl
#define ld long double
//#define MOD 1073741824

// أن تكون حيا فقط لاتكفى ! يجب أن تمتلك ضوءشمس ، حرية , أو زهرة صغيرة داخل قلبك  )) ;

//const int N = 1e5+ 5    ;
//const int mod = 1e9+7 ;
//const ll mod = 1000000007LL;





int main() {

  int n , m ;
  cin >> n >> m ;
/*
  /// Adjacency Matrix ///

    vector<vector<int>>adj1(n+1, vector<int>(n+1,-1)) ;

    for (int i = 0 , u , v ,w ; i < m; ++i) {

        cin>>u>>v>>w ;
        adj1[u][v] = w ;
        adj1[v][u] = w ; //// if is undirected graph ///

    }

    for (int i = 1; i <= n ; ++i) {

        for (int j = 1; j <= n ; ++j) {

            cout <<adj1[i][j]<<" ";
        }cout<<el ;
    }

 */

/*

 //// Adjacency List ////
    vector<pair<int , int >>adj2[n+1] ;

    for (int i = 0 , u , v , w ; i < m; ++i) {
        cin >> u >> v >> w ;
        adj2[u].push_back({v , w }) ;
        adj2[v].push_back({u ,w }) ; /// if undirected Graph ///

    }

    for(int i=1; i<=n; i++){
        cout << "Node " << i << ": ";
        for(auto it2 : adj2[i]){
            cout << "(" << it2.first << "," << it2.second << ") ";
        }
        cout << "\n";
    }

*/


    /// Edge List ///

    vector<array< int , 3 >> edges(m ) ;  /// Vector of Array ///

    for (auto & it:edges) {

        cin>>it[0] >> it[1] >> it[2];

    }
    /*
     * or

    for (auto [u ,v ,m ]: edges ) {

        cin >> u >> v >> m  ;
    }
*/

    for (auto it: edges ) {

        cout<<it[0] <<" "<<it[1]<<" "<< it[2] <<el  ;
    }






    return 0 ;
}





