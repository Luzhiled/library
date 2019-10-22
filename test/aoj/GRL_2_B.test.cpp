#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../graph/stronglyconnectedcomponent.cpp"
#include "../../graph/arborescence_edmond.cpp"
#undef call_from_test

signed main(){
  int n,m,r;
  cin>>n>>m>>r;

  Arborescence<int> G(n);
  for(int i=0;i<m;i++){
    int s,t,w;
    cin>>s>>t>>w;
    G.add_edge(s,t,w);
  }

  cout<<G.build(r)<<endl;
  return 0;
}
