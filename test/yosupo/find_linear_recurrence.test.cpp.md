---
data:
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"test/yosupo/find_linear_recurrence.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n#define call_from_test\n#line 2 \"mod/mint.cpp\"\n\n#ifndef\
    \ call_from_test\n#line 5 \"mod/mint.cpp\"\nusing namespace std;\n#endif\n\n//BEGIN\
    \ CUT HERE\ntemplate<typename T,T MOD = 1000000007>\nstruct Mint{\n  static constexpr\
    \ T mod = MOD;\n  T v;\n  Mint():v(0){}\n  Mint(signed v):v(v){}\n  Mint(long\
    \ long t){v=t%MOD;if(v<0) v+=MOD;}\n\n  Mint pow(long long k){\n    Mint res(1),tmp(v);\n\
    \    while(k){\n      if(k&1) res*=tmp;\n      tmp*=tmp;\n      k>>=1;\n    }\n\
    \    return res;\n  }\n\n  static Mint add_identity(){return Mint(0);}\n  static\
    \ Mint mul_identity(){return Mint(1);}\n\n  Mint inv(){return pow(MOD-2);}\n\n\
    \  Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint& operator-=(Mint\
    \ a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return\
    \ *this;}\n  Mint& operator/=(Mint a){return (*this)*=a.inv();}\n\n  Mint operator+(Mint\
    \ a) const{return Mint(v)+=a;}\n  Mint operator-(Mint a) const{return Mint(v)-=a;}\n\
    \  Mint operator*(Mint a) const{return Mint(v)*=a;}\n  Mint operator/(Mint a)\
    \ const{return Mint(v)/=a;}\n\n  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}\n\
    \n  bool operator==(const Mint a)const{return v==a.v;}\n  bool operator!=(const\
    \ Mint a)const{return v!=a.v;}\n  bool operator <(const Mint a)const{return v\
    \ <a.v;}\n\n  static Mint comb(long long n,int k){\n    Mint num(1),dom(1);\n\
    \    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n      dom*=Mint(i+1);\n   \
    \ }\n    return num/dom;\n  }\n};\ntemplate<typename T,T MOD> constexpr T Mint<T,\
    \ MOD>::mod;\ntemplate<typename T,T MOD>\nostream& operator<<(ostream &os,Mint<T,\
    \ MOD> m){os<<m.v;return os;}\n//END CUT HERE\n#ifndef call_from_test\n\n//INSERT\
    \ ABOVE HERE\nsigned ABC127_E(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\n\
    \  int h,w,k;\n  cin>>h>>w>>k;\n  using M = Mint<int>;\n\n  M ans{0};\n  for(int\
    \ d=1;d<h;d++)\n    ans+=M(d)*M(h-d)*M(w)*M(w);\n\n  for(int d=1;d<w;d++)\n  \
    \  ans+=M(d)*M(w-d)*M(h)*M(h);\n\n  ans*=M::comb(h*w-2,k-2);\n  cout<<ans<<endl;\n\
    \  return 0;\n}\n/*\n  verified on 2019/06/12\n  https://atcoder.jp/contests/abc127/tasks/abc127_e\n\
    */\n\nsigned main(){\n  //ABC127_E();\n  return 0;\n}\n#endif\n#line 2 \"polynomial/berlekampmassey.cpp\"\
    \n\n#ifndef call_from_test\n#line 5 \"polynomial/berlekampmassey.cpp\"\nusing\
    \ namespace std;\n\n#endif\n//BEGIN CUT HERE\n// construct a charasteristic equation\
    \ from sequence\n// return a monic polynomial in O(n^2)\ntemplate<typename T>\n\
    vector<T> berlekamp_massey(vector<T> &as){\n  using Poly = vector<T>;\n  int n=as.size();\n\
    \  Poly bs({-T(1)}),cs({-T(1)});\n  T y(1);\n  for(int ed=1;ed<=n;ed++){\n   \
    \ int l=cs.size(),m=bs.size();\n    T x(0);\n    for(int i=0;i<l;i++) x+=cs[i]*as[ed-l+i];\n\
    \    bs.emplace_back(0);\n    m++;\n    if(x==T(0)) continue;\n    T freq=x/y;\n\
    \    if(m<=l){\n      for(int i=0;i<m;i++)\n        cs[l-1-i]-=freq*bs[m-1-i];\n\
    \      continue;\n    }\n    auto ts=cs;\n    cs.insert(cs.begin(),m-l,T(0));\n\
    \    for(int i=0;i<m;i++) cs[m-1-i]-=freq*bs[m-1-i];\n    bs=ts;\n    y=x;\n \
    \ }\n  for(auto &c:cs) c/=cs.back();\n  return cs;\n}\n//END CUT HERE\n#ifndef\
    \ call_from_test\nsigned main(){\n  return 0;\n}\n#endif\n#line 9 \"test/yosupo/find_linear_recurrence.test.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n\n  using M = Mint<int, 998244353>;\n  vector<M> as(n);\n\
    \  for(int i=0;i<n;i++) cin>>as[i].v;\n\n  auto cs=berlekamp_massey(as);\n  cs.pop_back();\n\
    \  reverse(cs.begin(),cs.end());\n  cout<<cs.size()<<endl;\n  for(int i=0;i<(int)cs.size();i++){\n\
    \    if(i) cout<<\" \";\n    cout<<-cs[i];\n  }\n  cout<<endl;\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n\n#include<bits/stdc++.h>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../mod/mint.cpp\"\n#include \"../../polynomial/berlekampmassey.cpp\"\
    \n#undef call_from_test\n\nsigned main(){\n  cin.tie(0);\n  ios::sync_with_stdio(0);\n\
    \n  int n;\n  cin>>n;\n\n  using M = Mint<int, 998244353>;\n  vector<M> as(n);\n\
    \  for(int i=0;i<n;i++) cin>>as[i].v;\n\n  auto cs=berlekamp_massey(as);\n  cs.pop_back();\n\
    \  reverse(cs.begin(),cs.end());\n  cout<<cs.size()<<endl;\n  for(int i=0;i<(int)cs.size();i++){\n\
    \    if(i) cout<<\" \";\n    cout<<-cs[i];\n  }\n  cout<<endl;\n  return 0;\n\
    }\n"
  dependsOn:
  - mod/mint.cpp
  - polynomial/berlekampmassey.cpp
  extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/mint.cpp
    title: mod/mint.cpp
  - icon: ':heavy_check_mark:'
    path: polynomial/berlekampmassey.cpp
    title: polynomial/berlekampmassey.cpp
  extendedRequiredBy: []
  extendedVerifiedWith: []
  isVerificationFile: true
  path: test/yosupo/find_linear_recurrence.test.cpp
  requiredBy: []
  timestamp: '2020-03-12 17:15:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verificationStatusIcon: ':heavy_check_mark:'
  verifiedWith: []
documentation_of: test/yosupo/find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/find_linear_recurrence.test.cpp
- /verify/test/yosupo/find_linear_recurrence.test.cpp.html
title: test/yosupo/find_linear_recurrence.test.cpp
---