/*
Leetcode 509. Fibonacci Number

https://leetcode.com/problems/fibonacci-number/description/
*/

// Approach 1: Recursive Solution
// Time Complexity: O(2^n)
// Space Complexity: O(n) due to recursion stack

// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int fibo(int n) {
//     if(n<=1) return n;     // Base Case
//     return fibo(n-1) + fibo(n-2); // Recursive Call
// }

// int main() {
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     cout << "Fibonacci number at position " << n << " is: ";
//     cout << fibo(n) << endl;
//     return 0;
// }



// Approach 2: Memoization or Top-Down DP or Recursive DP
// Time Complexity: O(n)
// Space Complexity: O(n) for memoization (dp) array and O(n) for recursion stack = O(n) + O(n) = O(n)


// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int fibo(int n, vector<int>& dp) {
//     if(n<=1) return n;     // Base Case
//     if(dp[n] != -1) return dp[n]; // Check if already computed
//     return dp[n] = fibo(n-1, dp) + fibo(n-2, dp); // Recursive Call
// }

// int main() {
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     vector<int> dp(n+1, -1); // Initialize dp array with -1
//     cout << "Fibonacci number at position " << n << " is: ";
//     cout << fibo(n, dp) << endl;
//     return 0;
// }


// Approach 3: Tabulation or Bottom-Up DP or Iterative DP
// Time Complexity: O(n)
// Space Complexity: O(n) for dp array


// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int fibo(int n) {
//     if(n<=1) return n;     // Base Case
//     vector<int> dp(n+1); // Initialize dp array with -1

//     dp[0] = 0; // Base case: fibo(0) = 0
//     dp[1] = 1; // Base case: fibo(1) = 1
//     for(int i=2; i<=n ; i++) {
//         dp[i] = dp[i-1] + dp[i-2]; // Fill the dp array iteratively
//     }
//     return dp[n]; // Return the nth Fibonacci number
// }

// int main() {
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     cout << "Fibonacci number at position " << n << " is: ";
//     cout << fibo(n) << endl;
//     return 0;
// }



// Approach 4: Space Optimized DP
// Time Complexity: O(n)
// Space Complexity: O(1) since we are using only two variables to store the last two Fibonacci numbers


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int fibo(int n) {
    if(n<=1) return n;     // Base Case
    int prev2 = 0; // fibo(0)
    int prev1 = 1; // fibo(1)

    for(int i=2; i<=n; i++) {
        int curr = prev1 + prev2; // Calculate current Fibonacci number
        prev2 = prev1; // Update prev2 to the previous prev1
        prev1 = curr; // Update prev1 to the current Fibonacci number
    }

    return prev1; // Return the nth Fibonacci number
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is: ";
    cout << fibo(n) << endl;
    return 0;
}