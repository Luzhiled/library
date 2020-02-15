#define PROBLEM "https://yukicoder.me/problems/2085"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../tools/fastio.cpp"
#include "../../tree/rerooting.cpp"
#undef call_from_test

signed main(){
  int n;
  cin>>n;
  auto f1=[](int a,int b){return max(a,0)+max(b,0);};
  auto f2=[](int a,int d){return d-a;};
  ReRooting<int, int> G(n,f1,f2,0);
  for(int i=1;i<n;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.add_edge(a,b,1);
  }
  auto res=G.build();
  vector<int> ans;
  for(int i=0;i<n;i++)
    if(1-res[i]>0) ans.emplace_back(i);
  cout<<ans.size()<<"\n";
  for(int x:ans) cout<<x+1<<"\n";
  cout<<flush;
  return 0;
}