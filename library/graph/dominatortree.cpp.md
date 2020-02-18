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


# :heavy_check_mark: graph/dominatortree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dominatortree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-21 20:40:33+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/0294.test.cpp.html">test/aoj/0294.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/dominatortree.test.cpp.html">test/yosupo/dominatortree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef call_from_test
#include<bits/stdc++.h>
using namespace std;
#endif
//BEGIN CUT HERE
struct DominatorTree{
  struct UnionFind{
    vector<int> &semi;
    vector<int> ps,ms;
    UnionFind(vector<int> &semi):
      semi(semi),ps(semi.size()),ms(semi.size()){
      iota(ps.begin(),ps.end(),0);
      iota(ms.begin(),ms.end(),0);
    }
    int find(int v){
      if(ps[v]==v) return v;
      int r=find(ps[v]);
      if(semi[ms[v]]>semi[ms[ps[v]]]) ms[v]=ms[ps[v]];
      return ps[v]=r;
    }
    int eval(int v){
      find(v);
      return ms[v];
    }
    void link(int p,int v){ps[v]=p;}
  };

  vector< vector<int> > G,R;
  vector<int> ord,par,idom,semi;
  DominatorTree(int n):
    G(n),R(n),par(n),idom(n,-1),semi(n,-1){
    ord.reserve(n);
  }

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  void dfs(int v){
    semi[v]=ord.size();
    ord.emplace_back(v);
    for(int u:G[v]){
      if(~semi[u]) continue;
      par[u]=v;
      dfs(u);
    }
  }

  void build(int rt){
    int n=G.size();
    dfs(rt);

    vector< vector<int> > bkt(n);
    UnionFind uf(semi);
    vector<int> us(n);

    for(int i=(int)ord.size()-1;i>=0;i--){
      int v=ord[i];
      for(int u:R[v]){
        if(semi[u]<0) continue;
        u=uf.eval(u);
        if(semi[v]>semi[u]) semi[v]=semi[u];
      }
      bkt[ord[semi[v]]].emplace_back(v);
      for(int u:bkt[par[v]]) us[u]=uf.eval(u);
      bkt[par[v]].clear();
      uf.link(par[v],v);
    }

    for(int i=1;i<(int)ord.size();i++){
      int v=ord[i],u=us[v];
      idom[v]=(semi[v]==semi[u]?semi[v]:idom[u]);
    }

    for(int i=1;i<(int)ord.size();i++){
      int v=ord[i];
      idom[v]=ord[idom[v]];
    }

    idom[rt]=rt;
  }

  int operator[](int k){return idom[k];}
};
//END CUT HERE
#ifndef call_from_test
int main(){
  return 0;
}
#endif

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 186, in main
    subcommand_run(paths=[], timeout=parsed.timeout, tle=parsed.tle, jobs=parsed.jobs)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/main.py", line 64, in subcommand_run
    onlinejudge_verify.verify.main(paths, marker=marker, timeout=timeout, tle=tle, jobs=jobs)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/verify.py", line 133, in main
    raise Exception('{} tests failed: {}'.format(len(failed_test_paths), [str(path.relative_to(pathlib.Path.cwd())) for path in failed_test_paths]))
Exception: 1 tests failed: ['test/aoj/0367.linkcuttree.test.cpp']

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: graph/dominatortree.cpp: line 5: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
