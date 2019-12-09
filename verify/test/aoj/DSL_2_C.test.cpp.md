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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/DSL_2_C.test.cpp


[Back to top page](../../../index.html)

* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C)


## Dependencies
* :heavy_check_mark: [datastructure/kdtree.cpp](../../../library/datastructure/kdtree.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include<bits/stdc++.h>
using namespace std;

#define call_from_test
#include "../../datastructure/kdtree.cpp"
#undef call_from_test

signed main(){
  int N;
  scanf("%d",&N);
  KDTree kd(N);
  for(int i=0;i<N;i++) {
    int x,y;
    scanf("%d %d",&x,&y);
    kd.P[i]=KDTree::Point(i,x,y);
    kd.T[i].l = kd.T[i].r = kd.T[i].p = kd.NIL;
  }
  kd.np=0;
  int root=kd.makeKDTree(0,N,0);

  int q;
  scanf("%d",&q);
  int sx,tx,sy,ty;
  vector<KDTree::Point> ans;
  for(int i=0;i<q;i++){
    scanf("%d %d %d %d",&sx,&tx,&sy,&ty);
    ans.clear();
    kd.find(root,sx,tx,sy,ty,0,ans);
    sort(ans.begin(),ans.end());
    for(int j=0;j<(int)ans.size();j++){
      ans[j].print();
    }
    printf("\n");
  }
  return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)
