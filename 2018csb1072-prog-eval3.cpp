#include<iostream>
#include<math.h>
//you have to delete this
#include<bits/stdc++.h>


using namespace std;

long long int power_i(long long int p,long long int f)
{
    long long int w=1;                            //calculating the power using for loop
    long long int i;
    for(i=1;i<=f;i++)
    {
        w=w*p;
    }
    return w;
}

long long int random_prime(long long int g)
{
    long long int time=clock();                                    //generating the random odd prime no so that gcd of p and m is always 1,
    srand(time);                                                   //as it becomes easier to calculate the inverse modulo at the time of retriving the 
    long long int iy=2*(rand()%((power_i(g,3)/2)-2))+1;            //a[] array 
    return iy;
}

void gcd(long long int a,long long int b,long long int *c,long long int *d)
{
    if(a==1)                                                //calculating the x needed for some no whose modulo with a no. gives remainder 1,
    {                                                          //that is (some no)*(x)=1(modn) 
        *c=1;
        *d=0;
        return;
    }
    long long int e,f;
    gcd(b%a,a,&e,&f);
    *c=f-(b/a)*e;    
    *d=e;
    return;
}

long long int modin(long long int p,long long int m)
{
    long long int r,s;                                //converting the no to a postive no as it can be negative by adding the no w.r.t which in inverse is
    gcd(p,m,&r,&s);                                   //being calculated
    long long int u;
    u=(r%m+m)%m;
    return u;
}

int main()
{
    long long int n;
    cin>>n;
    string s;
    cin>>s;
    long long int i;
    long long int m;
    cin>>m;
    long long int a[n];
    int p=2;
    long long int k=4*(log(n)*log(n)*log(n));                 //k is the no for which the probability of getting a prime no increases.
    long long int we;
    long long int at[m];
    long long int pl;
    for(pl=0;pl<m;pl++)
    {                                                   //array for storing how many times the output is 1 for the provided random odd no. 
        at[pl]=0;
    }
    long long int j,as;
    long long int wq[m][4];
    for(j=0;j<m;j++)
    {
        for(as=0;as<4;as++)
        {                                                   //storing the queries given as input
            long long int i_m;                                //by subtracting one from it
            cin>>i_m;
            wq[j][as]=i_m-1;
        }
    }
    for(we=1;we<=k;we++)
    {
        long long int x=random_prime(n);                        //generating prime no. k times wrt the loop
        a[0]=s[0]%x;                                    
        long long int p_k=2;
        for(i=1;i<n;i++)
        {
            a[i]=(a[i-1]+(((s[i]-48)%x)*(p_k%x))%x)%x;                  
            p_k=p_k*p;
        }
        for(j=0;j<m;j++)
        {
            long long int carry,carry1;
            long long int rs,op;
            if(wq[j][0]!=0&&wq[j][2]!=0)
            {
                carry=power_i(p,wq[j][0]);
                carry1=power_i(p,wq[j][2]);
                rs=(((a[wq[j][1]]-a[wq[j][0]-1])%x)*(modin(carry,x)))%x;            //retriving the atored no again
                op=(((a[wq[j][3]]-a[wq[j][2]-1])%x)*(modin(carry1,x)))%x;
                op=op%x;
            }
            else if(wq[j][0]==0&&wq[j][2]!=0)
            {
                rs=a[wq[j][1]];
                carry1=power_i(p,wq[j][2]);
                op=(((a[wq[j][3]]-a[wq[j][2]-1])%x)*(modin(carry1,x)))%x;
            }
            else if(wq[j][0]!=0&&wq[j][2]==0)
            {
                carry=power_i(p,wq[j][0]);
                rs=(((a[wq[j][1]]-a[wq[j][0]-1])%x)*(modin(carry,x)))%x;
                op=a[wq[j][3]];
            }
            else
            {
                rs=a[wq[j][1]];
                op=a[wq[j][3]];
            }

            if(rs==op)
            {
                at[j]=at[j]+1;                          //storing no of times the strings are same
            }
        }
    }
        long long int xy;
        for(xy=0;xy<m;xy++)
        {
            if(at[xy]>=k/2)                    //if the value in the array is >= the no of times the loop is running then the strings are same otherwise not 
            {
                cout<<"1"<<endl;
            }
            else
            {
                cout<<"0"<<endl;
            }
        }   
}
