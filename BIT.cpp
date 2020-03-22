
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)
#define w(x) int x; cin>>x; while(x--)
#define vi vector<int>
#define mod 1000000009
#define pi pair<int,int>
#define fi first 
#define se second 
// BINARY INTEX TREE PREFIX SUM
int getsum(int bitree[] ,int n)
{
   n=n+1;
   int sum=0;
   while(n){
    sum+=bitree[n];
    n=(n-1)&n;
   }

   return sum;

}
void update(int bitree[], int i ,int x,int n){

  i=i+1;

  while(i<=n)
  {
    bitree[i]+=x;
    i=i+ i&(-i);
  }
}
int * cons(int a[],int n){
  int *bitree=new int[n+1];
  fr(i,n+1) bitree[i]=0;

  for(int i=0;i<n;i++)
    if(a[i]%2!=0)
    update(bitree,i,1,n);

  return bitree;
}
int32_t main(){

     
     // w(x){
      int n;
     cin>>n;
    int a[n]; fr(i,n){ cin>>a[i];}
    int *bitree=cons(a,n);
    int q; cin>>q; while(q--){
      int aa,l,r; cin>>aa>>l>>r;
      if(aa==0){
              // int i,x; cin>>i>>x;
              if(a[l-1]%2==0&&r%2!=0)
                update(bitree,l-1,1,n);
              else if(a[l-1]%2!=0&&r%2==0)
                update(bitree,l-1,-1,n);


      }
      else
      {      
          // int l,r; cin>>l>>r;
          int oddr=getsum(bitree,r-1);
          cout<<"r "<<oddr<<endl;

          int oddl=getsum(bitree,l-2);
 
          cout<<"l "<<oddl<<endl;
          int resodd=oddr-oddl;
           if(aa==1)
           {   
                cout<<(r-l+1-resodd)<<endl;

           }
           else
           {
                     cout<<resodd<<endl;
           } 
      }
    }
          
     // }
 
  return 0;
}