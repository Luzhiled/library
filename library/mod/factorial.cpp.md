---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: mod/factorial.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ad148a3ca8bd0ef3b48c52454c493ec5">mod</a>
* <a href="{{ site.github.repository_url }}/blob/master/mod/factorial.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 18:40:14+09:00




## Depends on

* :heavy_check_mark: <a href="../convolution/garner.cpp.html">convolution/garner.cpp</a>
* :heavy_check_mark: <a href="../convolution/numbertheoretictransform.cpp.html">convolution/numbertheoretictransform.cpp</a>
* :heavy_check_mark: <a href="mint.cpp.html">mod/mint.cpp</a>
* :heavy_check_mark: <a href="rint.cpp.html">mod/rint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif

#define call_from_test
#include "mint.cpp"
#include "rint.cpp"
#include "../convolution/numbertheoretictransform.cpp"
#include "../convolution/garner.cpp"

#undef call_from_test
//BEGIN CUT HERE
int factorial(long long n,int MOD){
  if(n>=MOD) return 0;
  Garner arb;
  using R = Rint<int>;
  R::set_mod(MOD);

  int d=1<<15;
  vector<R> fact(d*2+1,1),finv(d*2+1,1);
  for(int i=1;i<=d*2;i++) fact[i]=fact[i-1]*R(i);
  finv[d*2]=fact[d*2].inv();
  for(int i=d*2-1;i>=0;i--) finv[i]=finv[i+1]*R(i+1);

  vector<R> seq({1,d+1});
  seq.reserve(d+1);

  int sz=1;
  while(sz<d){
    vector<R> aux(sz,1);
    vector<R> f(sz*4,0),g(sz*4,0);
    for(int i=0;i<=sz;i++){
      f[i]=finv[i]*finv[sz-i]*seq[i];
      if(((sz+i)&1)&&(f[i].v!=0)) f[i]=-f[i];
    }

    vector<R> pf(f);
    vector<R> as;
    as.emplace_back(R(sz+1));
    as.emplace_back(R(sz)/R(d));
    as.emplace_back(R(sz)/R(d)+R(sz+1));

    for(int idx=0;idx<3;idx++){
      for(int i=0;i<sz*4;i++) f[i]=pf[i];
      for(int i=1;i<sz*2+2;i++)
        g[i]=(as[idx]-R(sz-i+1)).inv();
      f=arb.multiply(f,g);
      f.resize(sz*4);

      R prod=1;
      for(int i=0;i<=sz;i++) prod*=as[idx]-R(i);

      for(int i=0;i<=sz;i++){
        f[sz+i+1]*=prod;
        prod*=as[idx]+R(i+1);
        prod/=as[idx]-R(sz-i);
      }
      if(idx==0){
        for(int i=0;i<sz;i++)
          aux[i]=f[sz+i+1];
      }
      if(idx==1){
        for(int i=0;i<=sz;i++)
          seq[i]*=f[sz+i+1];
      }
      if(idx==2){
        for(int i=0;i<sz;i++)
          aux[i]*=f[sz+i+1];
      }
    }
    for(R x:aux) seq.emplace_back(x);
    sz<<=1;
  }

  using ll = long long;
  R res=1;
  int l=min((ll)d,(n+1)/d);
  for(ll i=0;i<l;i++) res*=seq[i];
  for(ll i=l*d+1;i<=n;i++) res*=R(i);
  return res.v;
}
//END CUT HERE
#ifndef call_from_test
//INSERT ABOVE HERE
signed YUKI_502(){
  const int MOD = 1e9+7;
  long long n;
  cin>>n;
  cout<<factorial(n,MOD)<<endl;
  return 0;
}
/*
  verified on 2019/12/29
  https://yukicoder.me/problems/no/502
*/

signed main(){
  YUKI_502();
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: mod/factorial.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
