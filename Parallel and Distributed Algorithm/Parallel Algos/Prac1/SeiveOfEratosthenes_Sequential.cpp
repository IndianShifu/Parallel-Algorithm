#include<iostream>
#include<new>
#include<ctime>
#include <sys/time.h>
using namespace std;

void seive(int,int []);
void print(int,int []);

int main()
{
    int n = 1000;

    // current date/time based on current system   
  //  const clock_t st = clock()/  CLOCKS_PER_SEC; 

    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    int* prime = new int[n-1];
    for(int i=0; i <= n-2; i++)
    {
        prime[i] = i+2;
      //  cout << "prime[" << i << "] = " << prime[i] << "\t";
    }

    seive(n,prime);
   // print(n,prime);

    // current date/time based on current system    
  //  cout << "TOTAL TIME TAKEN : " << float(clock()-st)/CLOCKS_PER_SEC << endl;  

    gettimeofday(&end, NULL);
    float delta = ((end.tv_sec  - start.tv_sec) * 1000000u + end.tv_usec - start.tv_usec) / 1.e6;
    cout << "N : " << n << endl;
    cout << "TOTAL TIME TAKEN : " << delta << endl;


    return 0;
}

void seive(int n, int prime[])
{
    int k = 2;
    while(k*k <= n)
    {
        //Marking the multiples of k
        for(int i=0;i <= n-2; i++)
        {
            if ( prime[i] >= k*k && prime[i]%k == 0)
            {
                prime[i] = -1;
            }
        }

        //Finding the next k
        for( int i=0; i<= n-2; i++)
        {
            if ( prime[i] > k && prime[i] != -1)
            {
                k = prime[i];
                break;
            }
        }
    }
}

void print(int n, int a[])
{
    cout << "\nList of prime numbers :\n" ;
    for( int i=0; i<= n-2; i++)
    {
        if(a[i] != -1)
        {
            cout << a[i] << "\t";
        }
    }
   cout << endl;
}
