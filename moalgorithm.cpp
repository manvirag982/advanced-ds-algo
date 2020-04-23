//intersting queries gfg
//https://www.geeksforgeeks.org/array-range-queries-elements-frequency-value/
//https://blog.anudeep2011.com/mos-algorithm/
// normal time complexity=O(n^2) ,,, but by mo algorithms O(N^1/2 *N) just by rearanging queries its cool na
// for complexity see above block...sqrt baap of this just O(n^1/2) but question should satisfied 
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define ld long double
#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)
#define w(x) int x; cin>>x; while(x--)
#define vi vector<int>
#define mod 1000000007
#define pi pair<int,int>
#define first fi
#define second se

struct  Query
{
  int l;
  int r; 
  int ix;
  
};
int bk;
bool com (Query x, Query y){
    
    if((x.l)/bk!=(y.l)/bk)
      return (int)x.l/bk < (int)y.l/bk;
    return x.r<y.r;

}
int32_t main(){

     
     w(x){

       int n,q,k; cin>>n>>q>>k;
         int a[n]; for(int i=0;i<n;i++) cin>>a[i];
         bk=sqrt(n);  
         Query qe[q];

         for(int i=0;i<q;i++) {cin>>qe[i].l>>qe[i].r; qe[i].ix=i;}
         int ans[q];
         sort(qe,qe+q,com);
         // unordered_map<int,int> mp;
         int mp[1010];
         memset(mp,0,sizeof(mp));
         int cl=0,cr=0;
          int cnt=0;
         
         for(int i=0;i<q;i++){
          
          int L=qe[i].l-1;
          int R=qe[i].r-1;
          
          while(cl<L)
          {
            mp[a[cl]]--;
            if(mp[a[cl]]==k-1)
              cnt--;
            cl++;}
          while(cl>L)
          {
            cl--;
            mp[a[cl]]++;
            if(mp[a[cl]]==k)
              cnt++;
            }

           while(cr<=R)
          {
            mp[a[cr]]++;
            if(mp[a[cr]]==k)
              cnt++;
            cr++;}
           
           while(cr>R+1)
          {
            cr--;
            mp[a[cr]]--;
            if(mp[a[cr]]==k-1)
              cnt--;
            }
           
           ans[qe[i].ix]=cnt; 
        } 
       
           for(int i=0;i<q;i++)
      cout<<ans[i]<<" ";
         
         cout<<endl;

     }
 
  return 0;
}
