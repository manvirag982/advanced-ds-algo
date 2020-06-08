//  codechef MAXBTY
 #include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5;
int n, q, b[mxN];

struct segtree {
  ll a[1<<18]={}, b[1<<18]={};
  void app(int i, ll x) {
    a[i]+=x;
    b[i]+=x;
  }
  void psh(int i) {
    app(2*i, b[i]);
    app(2*i+1, b[i]);
    b[i]=0;
  }
  void upd(int l1, int r1, ll x, int i=1, int l2=0, int r2=n) {
    if(l1<=l2&&r2<=r1) {
      app(i, x);
      return;
    }
    int m2=(l2+r2)/2;
    psh(i);
    if(l1<=m2)
      upd(l1, r1, x, 2*i, l2, m2);
    if(m2<r1)
      upd(l1, r1, x, 2*i+1, m2+1, r2);
    a[i]=max(a[2*i], a[2*i+1]);
  }
  ll qry(int l1, int r1, int i=1, int l2=0, int r2=n) {
    if(l1<=l2&&r2<=r1)
      return a[i];
    int m2=(l2+r2)/2;
    psh(i);
    return max(l1<=m2?qry(l1, r1, 2*i, l2, m2):-1e18, m2<r1?qry(l1, r1, 2*i+1, m2+1, r2):-1e18);
  }
};

void solve() {
  //input
  cin >> n >> q;
  for(int i=0; i<n; ++i)
    cin >> b[i];

  segtree sr, sl;
  //init segtrees
  for(int i=0; i<n; ++i) {
    sr.upd(i+1, n, b[i]);
    sl.upd(i+1, n, -b[i]);
  }

  //queries
  for(int x, y; q--; ) {
    char qt;
    cin >> qt >> x >> y;
    if(qt=='Q') {
      //max suffix - min prefix
      cout << sr.qry(y, n)+sl.qry(0, x-1) << "\n";
    } else {
      sr.upd(x, n, y-b[x-1]);
      sl.upd(x, n, b[x-1]-y);
      b[x-1]=y;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--)
    solve();
}
