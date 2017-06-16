#include <iostream>
#include <math.h>
using namespace std;
int  k,st[60],n,i;
void initializare()
{
    st[k]=0;
}
int sucessor()
{ if(st[k]<n)
    {
        st[k]++;
        return 1;
    }
else
    return 0;
}
void tipar()
{char a[60][60];int j;

for(i=1;i<=n;i++)
   for(j=1;j<=n;j++) a[i][j]='0';
for(i=1;i<=n;i++)a[i][st[i]]='*';
for(i=1;i<=n;i++)
   {for(j=1;j<=n;j++)
   cout<<a[i][j];
   cout<<endl;}
cout<<endl;
}
int valid()
{
    for(i=1;i<k;i++)
    {
        int j=st[k]>st[i]?st[k]-st[i]:st[i]-st[k];
        int y=(k>i?k-i:i-k);
        if(  j==y )
           return 0;
    }
    for(i=1;i<k;i++) if(st[k]==st[i]) return 0;
    return 1;

}
 void back()
 {
     int as,ev;
     initializare();
     while(k>0)
     {
         do {
             as= sucessor();
             ev=valid();
            }
         while(as==1 && ev==0);
         if(as==1)
             if(k==n)
                tipar();
            else
                {
                k++;
                initializare();
                }
        else k--;
     }
 }

int main()
{
    cin>>n;
    k=1;
    back();
    return 0;
}
