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
const int MAX =1e5;
struct TrieNode
{      
       int  x;
       TrieNode* ch[26];
};

TrieNode * newnode()
{
       TrieNode *curr =new TrieNode;
       for(int i=0;i<26;i++)
        curr->ch[i]=NULL;

       curr->x=-1;

      return curr;
}
void insertT(TrieNode* root ,string s,int i)
{          
             TrieNode *curr=root;
          for(int i=0;i<s.size();i++)
          {       
                int ix=s[i]-'a';
                if(!curr->ch[ix])
                  curr->ch[ix]=newnode();
                curr=curr->ch[ix];
          }

          curr->x=i;

}
void  printT(TrieNode *root,string s[])
{
        TrieNode * curr=root;
        for(int i=0;i<26;i++)
        {      
               if(curr->ch[i])
               {
                        if(curr->ch[i]->x!=-1)
                          cout<<s[curr->ch[i]->x]<<" ";

                        printT(curr->ch[i],s);
               }       
        }
}
i32 main(){

  // time_t start,end;     // time(&start);// time(&end);

      string s[16]={"geeks", "for", "geeks", "a", "portal","to", "learn", "can", "be", "computer", "science", "zoom", "yup", "fire", "in", "data"};

       TrieNode *root =newnode();

        for(int i=0;i<16;i++)
          insertT(root,s[i],i);

        printT(root,s);


  //   double time_taken = double(end - start);    // cout << "Time taken by program is : " << fixed  //      << time_taken << setprecision(5); // cout << " sec " << endl; 

  return 0;
}