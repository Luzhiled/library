#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../bbst/basic/base.cpp"
#include "../../bbst/basic/lazy.cpp"
#undef call_from_test

signed main(){
  int n,q;
  cin>>n>>q;

  using P = pair<int, int>;
  auto f=[](P a,P b){return P(a.first+b.first,a.second+b.second);};
  auto g=[](P a,int b){return P(a.second*b,a.second);};
  auto h=[](int a,int b){(void)a;return b;};

  using Node = NodeBase<P, int>;
  constexpr size_t LIM = 1e6;
  Lazy<Node, LIM> G(f,g,h,P(0,0),-1010);
  auto rt=G.build(vector<Node>(n,Node(P(0,1),-1010)));

  for(int i=0;i<q;i++){
    int c;
    cin>>c;
    if(c==0){
      int s,t,x;
      cin>>s>>t>>x;
      rt=G.update(rt,s,t+1,x);
    }
    if(c==1){
      int s,t;
      cin>>s>>t;
      cout<<G.query(rt,s,t+1).first<<"\n";
    }
  }
  cout<<flush;
  return 0;
}