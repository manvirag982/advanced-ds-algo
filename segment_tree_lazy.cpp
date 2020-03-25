// maximum range query
#include<bits/stdc++.h>
using namespace std;
int tree[25];
int lazy[25];
int n=5;
int arr[5]={1,2,3,4,5};
int getsum(int qs,int qe,int si=0,int ss=0,int se=n-1)
{ 
      

       if(lazy[si]!=0)
       {
            tree[si]+=lazy[si];

            if(se!=ss)
            {
                lazy[2*si+1]+=lazy[si];
                lazy[2*si+2]+=lazy[si];
            }
            lazy[si]=0;
       }
       
       // not in range
       if(ss>qe||se<qs||ss>se)
        return -1 ;

       // full overlapping
     if(ss>=qs&&se<=qe)
      return tree[si];

     int mid=(se+ss)/2;

     return max(getsum(qs,qe,si,ss,mid),getsum(qs,qe,si,mid+1,se));
}
void update(int qs,int qe,int diff,int si=0,int ss=0,int se=n-1)
{

      // previous work
       if(lazy[si]!=0)
       {
            tree[si]+=lazy[si];

            if(se!=ss)
            {
                lazy[2*si+1]+=lazy[si];
                lazy[2*si+2]+=lazy[si];
            }
            lazy[si]=0;
       }

       // if out of range

       if(ss>qe||se<qs||ss>se)
        return ;

       // overlapping range

      if(ss>=qs&&se<=qe)
      {
           tree[si]+=diff;
            if(se!=ss)
            {
                lazy[2*si+1]+=diff;
                lazy[2*si+2]+=diff;
            }
            return ;

      }

      // partial overlapping
      int mid=(se+ss)/2;

      update(qs,qe,diff,2*si+1,ss,mid);
      update(qs,qe,diff,2*si+2,mid+1,se);

      tree[si]=max(tree[2*si+1],tree[2*si+2]);
}

void cons(int as=0,int ae=n-1,int si=0)
{
    if(as>ae)
        return ;
    if(as==ae)
    {
         tree[si]=arr[as];
         return ;
    }

    int mid=(ae+as)/2;

    cons(as,mid,2*si+1);
    cons(mid+1,ae,2*si+2);
    tree[si]=max(tree[2*si+1],tree[2*si+2]);

}

int main()
{
    cons();  
    update(0,3,4); // update 0,3 == 4
    cout<<getsum(1,4)<<endl;
    return 0;
}

/*Maximize Letter Beauty Problem Code: MAXBTY codechef
  #include<bits/stdc++.h>
  using namespace std;
  #define int long long int
  #define ld long double
  #define w(x) int x; cin>>x; while(x--)
  #define fr(i,n)   for(int i=0;i<n;i++)
  #define frr(i,n)  for(int i=1;i<=n;i++)
  #define vi vector<int>
  #define mod 1000000007
  #define pi pair<int,int>
  #define f first
  #define s second
  #define pb push_back
  #define mk make_pair
  #define all(x) x.begin(),x.end() 
  #define i32 int32_t
  #define i16 int16_t
  #define endl "\n"
  #define fastio   ios_base::sync _with_stdio(false);cin.tie(NULL);
  const int MAX =100001;
  void pls()
  {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  }
int n,q;
int a[MAX];
struct segtree
     {
           int seg[3*MAX]={0},lazy[3*MAX]={0};

           void append(int i,int x){
            seg[i]+=x;
            lazy[i]+=x;
           }
           void print()
           {
                for(int i=0;i<2*n-1;i++)
                cout<<seg[i]<<" ";
                cout<<endl;
           }
           void push(int i){
            
            append(2*i+1,lazy[i]);
            append(2*i+2,lazy[i]);
            lazy[i]=0;
           }
           void update(int gl,int gr,int x,int i=0,int sl=0,int sr=n-1){
                   

                   if(sl!=sr)
                    push(i);
                   
                    if((sl>gr)|| sr<gl || sl>sr)
                      return ;

                   

                   if(sl>=gl && sr<=gr)
                   {   
                       append(i,x);
                       return ;
                   }

                   
                   int mid=(sl+sr)/2;
                  
                   
                    update(gl,gr,x,2*i+1,sl,mid);
                    update(gl,gr,x,2*i+2,mid+1,sr);
                  
                  seg[i]=max(seg[2*i+1],seg[2*i+2]);
           }
           int get(int gl,int gr,int i=0,int sl=0,int sr=n-2)
           {          
                     
                    if(sl!=sr) push(i); if((sl>gr)|| sr<gl || sl>sr) return
                    1LL*INT64_MAX;

                    if(sl>=gl && sr<=gr)
                      return seg[i];
                    int mid=(sl+sr)/2;
                    return max(get(gl,gr,2*i+1,sl,mid),get(gl,gr,2*i+2,mid+1,sr));
           }
     };     
void solve()
{       cin>>n>>q;
          segtree mx,mn;
        for(int i=0;i<n;i++) cin>>a[i];
          for(int i=0;i<n;i++){
             mn.update(i,n-1,-a[i]);
             mx.update(i,n-1,a[i]);
          }
          mn.print();
          mx.print();
          while(q--){
            char x; int y,z;
            cin>>x>>y>>z; y--;z--;
            if(x=='Q'){
              cout<<mx.get(z,n-1)+mn.get(0,y-1)<<endl;
            }
            else
            {    z++;
                mn.update(y,n-1,a[y]-z);
                mx.update(y,n-1,z-a[y]);
                a[y]=z;
            }
          }
}
i32 main(){pls();
        int t;
        cin>>t; 
        while(t--){
          solve();
        }
        
return 0;}
       
*/
