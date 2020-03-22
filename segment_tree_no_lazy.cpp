//sum range query
#include<bits/stdc++.h>
using namespace std;
void update(int sgn[],int ss,int se,int i,int diff)
{
            if(i<ss||i>se)
                return ;

            sgn[i]+=diff;

            if(se!=ss)
            {
                 int mid=(se+ss)/2;

                 update(sgn,ss,mid,2*i+1,diff);
                 update(sgn,mid+1,se,2*i+2,diff);
            }

}
int getsum(int sgn[],int ss,int se, int qs, int qe ,int i)
{
      if(ss>=qs&&qe>=se)
        return sgn[i];
     if(se<qs||ss>qe)
        return 0;

     int mid=(ss+se)/2;

     return getsum(sgn,ss,mid,qs,qe,i*2+1)+getsum(sgn,mid+1,se,qs,qe,i*2+2);
}
int consuti(int arr[],int as, int ae, int sgn[],int sgs)
{
       if(as==ae)
       {
         sgn[sgs]=arr[as];
         return arr[as];
       }

       int mid=(as+ae)/2;

       sgn[sgs]=consuti(arr,as,mid,sgn,sgs*2+1)/*left*/ + consuti(arr,mid+1,ae,sgn,sgs*2+2);

       return sgn[sgs];
}
int * cons(int arr[], int n)
{
    int x=(int)(ceil(log2(n)));
    int sz=2*pow(2,x)-1;

    int* sgt =new int[sz];

    consuti(arr,0,n-1,sgt,0);

    return sgt;

}
 int main()
 {
     int n=6;
      int arr[n]={1,3,5,7,9,11};

      int *sgt=cons(arr,n);

      cout<<getsum(sgt,0,n-1,1,3,0)<<endl;   //l==1 r==3

      int diff=10-arr[0];
      update(sgt,0,n-1,1,diff);

      cout<<getsum(sgt,0,n-1,1,3,0)<<endl;

      return 0;  
 }