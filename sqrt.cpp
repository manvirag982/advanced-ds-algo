// find sum of given query 
// update is addition of fibonacci
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define w(x) int x; cin>>x; while(x--)
#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)
#define vi vector<int>
// #define mod 1000000007
#define pi pair<int,int>
#define f first
#define s second
#define i32 int32_t
#define i16 int16_t
#define mod 1000000009
int a[300001];
int bk;
int sqt[510];
int f[300010];
void preprocess(int n){

  fr(i,n){
    sqt[i/bk]+=a[i];
  }
}
void fibo(){

   f[0]=0;
   f[1]=1;
   f[2]=1;

   for(int i=3;i<=300005;i++)
   f[i]=(f[i-1]+f[i-2])%mod; 

}
void update(int l,int r){
                    

                   int i=l;
                   int sum=0;
                  while(l%bk&&l<r){
                    a[l]=(a[l]+f[l-i+1])%mod;
                    sum=(sum+f[l-i+1])%mod;
                    l++;}
                    sqt[l/bk-1]=(sqt[l/bk-1]+sum)%mod;
                  while(l+bk<=r){
                    sqt[l/bk]=(sqt[l/bk]+f[l+bk+2]-f[l+2])%mod;
                    l=l+bk;
                  } 
                  while(l<=r)
                  {a[l]=(a[l]+f[l-i+1])%mod;
                    sum=(sum+f[l-i+1])%mod;
                    l++;}
                    sqt[l/bk-1]=(sqt[l/bk-1]+sum)%mod;
                      
    

}
int32_t main()
{
  
   // w(t)
   // {    
           // clock_t start=clock();
           
            i32 n,q; cin>>n>>q;
            for(int i=0;i<n;i++) cin>>a[i];
            bk=sqrt(n);
            memset(sqt,0,sizeof(sqt));
            preprocess(n);
            fibo();
            
            for(int i=0;i<q;i++){
              i32 res=0;
              int j,l,r; cin>>j>>l>>r;
              l--; r--;

              if(j==1)
                update(l,r);
              else{

                  while(l%bk&&l<r){
                    res=(res+a[l++])%mod;}
                  while(l+bk<=r){
                    res=(res+sqt[l++])%mod;
                  } 
                  while(l<=r)
                  {
                    res=(res+a[l++])%mod;
                  } 
                  cout<<res<<endl;

              }
            }


             
              // start=clock()-start;
            // cout<<(float)start/CLOCKS_PER_SEC<<endl;

            
    // }
  return 0;
} 
