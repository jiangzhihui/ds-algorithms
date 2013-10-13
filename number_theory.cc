/*                                                                              
 ============================================================================
 Implement some basic number theory algorithms 
 ============================================================================
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map> 
#include<cstdlib>
#include<cmath>
using namespace std; 

int gcd(int a , int b){
    if(0 == b)
        return a;
    return gcd(b,a%b);
}

//test whether a number is prime
bool is_prime(int n){
    if(n < 2)
        return false;

    for(int i = 2; i*i <= n; ++i){
        if(n % i == 0)
            return false; 
    }
    return true;
}

//calculate all the divisors of number n
vector<int> divisor(int n){
    vector<int> divs;
    for(int i = 1; i*i <= n; ++i){
        if( n % i == 0){
            divs.push_back(i);
            if( n/i != i)
                divs.push_back(n/i);
        }
    }
    return divs;
}

//calculate all the prime factors of a number
map<int,int> prime_factors(int n ){
    map<int,int> re; 
    for(int i = 2; i*i <= n ; ++i){
        while( n > 0 && n % i == 0){
            ++ re[i];
            n = n / i;
        }
    }

    if( n != 1)
        re[n] = 1;

    return re;
}

//figure out all the prime number from 1 to n
vector<int> sieve(int n,vector<bool> & is_prime){
    is_prime[0]=is_prime[1]=false;
    vector<int> re; 
    for(int i = 2; i <= n; ++i){
        if(is_prime[i]){
            re.push_back(i);
            int j = 2; 
            while( i * j <= n){
                is_prime[i*j] = false; 
                ++j;
            }
        }
    }

    return re;
}

void test_gcd(){
    int N = 100;
    for(int i = 2; i < 100; i ++){
        int a = rand() % N;
        int b = rand() % N; 
        cout << a << " " << b << " " << gcd(a,b) << endl;
    }
}

void test_sieve(){
    int n = 1000;
    vector<bool> isprime(n+1,true);
    vector<int> primes =  sieve(n,isprime);
    for(size_t i = 0; i < primes.size() ; ++i)
        cout << primes[i] << endl;
    for(int i = 1; i <= n; i ++){
        if(is_prime(i) != isprime[i])
            cout << "Not equal "  << i << endl; 
    }
}

void test_prime_factor(){
    int n = 100;
    for(int i = 1; i <= n; i ++){
        cout << i << "     " ;
        map<int,int> pf = prime_factors(i);
        map<int,int>::iterator iter=pf.begin();
        while(iter != pf.end()){
            pair<int,int> p = *iter;
            cout << p.first << ":" << p.second << "  " ;
            iter ++;
        }
        cout << endl;
    }
}

int main()
{
    //test_gcd(); 
    //test_sieve();
    test_prime_factor();
}

