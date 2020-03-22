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