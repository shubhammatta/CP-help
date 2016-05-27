
//Modular exponent  ie  for big a^b mod n
long long modexpo(long long a,long long b,int n)
{
    long long d=1;
    while(b)
    {
        if(b%2)
        {
            d=(d*a)%n;
        }
        b>>=1;
        a=(a*a)%n;
    }
    return d;
}


//TO SPLIT THE STRING BASED ON DELIMITER SUCH AS COMMA`
//USAGE TO BE USED INSIDE FUNNCTION... IMPORT PROPER LIBRARY
String left;
istringstream ss(left);
            string token;
            std::vector<string> values;
            while(getline(ss, token, ',')) {
                values.push_back(token);
            }

//when a sliding window is given find max of each subarray O(n) time
void SlidingWindow(int arr[], int n, int k)
{
    // Create a Double Ended Queue, Qi that will store indexes of array elements
    // The queue will store indexes of useful elements in every window and it will
    // maintain decreasing order of values from front to rear in Qi, i.e., 
    // arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order
    std::deque<int>  Qi(k);
    /* Process first k (or first window) elements of array */
    int i;
    for (i = 0; i < k; ++i){
        // For very element, the previous smaller elements are useless so
        // remove them from Qi
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();  // Remove from rear
        // Add new element at rear of queue
        Qi.push_back(i);
    }
 
    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for ( ; i < n; ++i){
        // The element at the front of the queue is the largest element of
        // previous window, so print it
        cout << arr[Qi.front()] << " ";
        // Remove the elements which are out of this window
        while ( (!Qi.empty()) && Qi.front() <= i - k)
            Qi.pop_front();  // Remove from front of queue
        // Remove all elements smaller than the currently
        // being added element (remove useless elements)
        while ( (!Qi.empty()) && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
         // Add current element at the rear of Qi
        Qi.push_back(i);
    }
    // Print the maximum element of last window
    cout << arr[Qi.front()];
}


//when making queries to an array such as update and all and then print sums of ranges use lazy propagation
// Segment tree(binary tree version)   ---- ques done SPOJ/horrible or folder spoj/ horrible.cpp / horrible_1.cpp 


// to find large fibinacci numbers use partial memoization along with the formula
/*
F(2n-1) =   F(n-1)^2    + F(n)^2   ===   a' = a^2 + b^2 
F(2n)   = 2 F(n-1) F(n) + F(n)^2   ===   b' = 2ab + b^2 
*/


//For finding nCr for big numbers where pascal triangle is not possible you have to use:-
/*If we have to calcuate nCr mod p(where p is a prime), we can calculate factorial mod p 
and then use modular inverse to find nCr mod p. If we have to find nCr mod m(where m is not prime), 
we can factorize m into primes and then use Chinese Remainder Theorem(CRT) to find nCr mod m.*/
/* This function calculates (a^b)%MOD */
long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long C(int n, int r, int MOD)
{
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

//most efficient way to check power of 2
int is_power_of_two(unsigned long long x) {
    return x && (x & (x - 1)) == 0;
}

//XOR from 1 to n is
if n % 2 == 1 {
    result = (n % 4 == 1) ? 1 : 0;
} else {
    result = (n % 4 == 0) ? n : n + 1;
}

//Xor of even numbers from 1 to n .
long long int Even_Xor(long long int n){
    if(n%8==0){
        return n;
    }
    else if(n%8==2) return 2;
        else if(n%8==6) return 0;
        else if(n%8==4) return n+2;
    return 0;
        }
