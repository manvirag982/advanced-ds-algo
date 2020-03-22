// trie maximum xor of element
#include<bits/stdc++.h>
using namespace std;
// #define int long long int
#define ld long double
#define w(x) int x; cin>>x; while(x--)
#define fr(i,n)   for(int i=0;i<n;i++)
#define frr(i,n)  for(int i=1;i<=n;i++)
#define vi vector<int>
#define mod 1000000007
#define pi pair< int,int >
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define all(x) x.begin(),x.end() 
#define i32 int32_t
#define i16 int16_t
#define fastio   ios_base::sync_with_stdio(false);cin.tie(NULL);
     
const i32 MAX= 1e5;
struct TrieNode
{
     bool d;
     TrieNode *p[2];
};
TrieNode * newTrieNode(){
  
     TrieNode *temp= new TrieNode;
     temp->d=0;
     temp->p[0]=NULL;

     temp->p[1]=NULL;

     return temp;
   
}
void tinsert(TrieNode* root ,int xr)
{        TrieNode *temp=root;
         for(int i=31;i>=0;i--)
         {
              int bit=xr&(1<<i);  
              if(bit) bit=1; // whether rightmost digit is set or not set
              // cout<<i<<" "<<bit<<endl;
              if(!temp->p[bit])
                {temp->p[bit]=newTrieNode(); temp->d=bit;}

              temp=temp->p[bit];
         }
}
int tquery(TrieNode* root, int xr)
{
     
        TrieNode* temp=root;
         int res=0;
         for(int i=31;i>=0;i--)
         {
              int bit=xr&(1<<i);
              if(bit) bit=1;   // whether rightmost digit is set or not set
              

              //for maximun xor digit should be different

              if(temp->p[1-bit])
                {temp=temp->p[1-bit]; xr=xr|1<<i;}
                else
                {temp=temp->p[bit]; xr=xr&((1<<i)-1);}


            }
            return xr;

            // cout<<"xr"<<" "<<xr<<endl;
}
i32 main(){

      fastio  
      // time_t start,end;
      // time(&start);
      TrieNode *root =newTrieNode();
      int n=5;
      int a[5]={1,2,3,4,5};
      int pxor=0;
      tinsert(root,0);
      int res=INT_MIN;
      for(int i=0;i<5;i++)
      {
            pxor^=a[i];

            // cout<<"pxor"<<" "<<pxor<<endl;

            tinsert(root , pxor);
            res=max(res,pxor);
            res=max(res,tquery(root,pxor));

      }
      cout<<res;

      // time(&end);
      // double time_taken = double(end - start); 
      // cout << "Time taken by program is : " << fixed<< time_taken << setprecision(5)<< " sec " << endl; 

  return 0;
}