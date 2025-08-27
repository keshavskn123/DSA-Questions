/*
Frog Jump with K Distance:
There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. Height[i] is the height of the (i+1)th stair .If frog jumps from ith to jth stair, the energy lost in the jump is given by Height[i-1] - Height[j-1]. If the frog is on ith staircase, he can jump to any of the next k stairs.Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.
*/

// Approach 1: Recursion        -- TLE Error
// Time Complexity: O(k^n) (Exponential)
// Space Complexity: O(n) for recursion stack


// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int frogJump(int n, vector<int>& heights, int k) {
//     if(n==0) return 0; // Base Case: If on the first stair, no energy is used
//     int minSteps = INT_MAX;
//     for(int j=1; j<=k; j++) {
//         if(n-j >= 0) {
//             int jump = frogJump(n-j, heights, k) + abs(heights[n] - heights[n-j]); // Jump from (n-j)th stair to nth stair
//             minSteps = min(minSteps, jump);
//         }
//     }
    
//     return minSteps; // Return the minimum energy used
// }
// int main() {
//     int n;
//     cout << "Enter number of stairs: ";
//     cin >> n;
//     int k;
//     cout << "Enter maximum jump distance k: ";
//     cin >> k;
//     vector<int> heights(n);
//     cout << "Enter heights of stairs: ";
//     for(int i=0; i<n; i++) {
//         cin >> heights[i];
//     }
//     int ans = frogJump(n-1, heights, k);
//     cout << "Minimum energy used by the frog to reach the top: " << ans << endl;
// }



// Approach 2: Memoization or Top-Down DP or Recursive DP
// Time Complexity: O(n*k)
// Space Complexity: O(n) for memoization (dp) array and O(n) for recursion stack = O(n) + O(n) = O(n)

// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int frogJump(int n, vector<int>& heights, int k, vector<int>& dp) {
//     if(n==0) return 0; // Base Case: If on the first stair, no energy is used
//     if(dp[n] != -1) return dp[n]; // Check if already computed
//     int minSteps = INT_MAX;
//     for(int j=1; j<=k; j++) {
//         if(n-j >= 0) {
//             int jump = frogJump(n-j, heights, k, dp) + abs(heights[n] - heights[n-j]); // Jump from (n-j)th stair to nth stair
//             minSteps = min(minSteps, jump);
//         }
//     }
    
//     return dp[n] = minSteps; // Return the minimum energy used
// }

// int main() {
//     int n;
//     cout << "Enter number of stairs: ";
//     cin >> n;
//     int k;
//     cout << "Enter maximum jump distance k: ";
//     cin >> k;
//     vector<int> heights(n);
//     cout << "Enter heights of stairs: ";
//     for(int i=0; i<n; i++) {
//         cin >> heights[i];
//     }
//     vector<int> dp(n+1, -1); // Initialize dp array with -1
//     int ans = frogJump(n-1, heights, k, dp);
//     cout << "Minimum energy used by the frog to reach the top: " << ans << endl;
// }



// Approach 3: Tabulation or Bottom-Up DP or Iterative DP
// Time Complexity: O(n*k)
// Space Complexity: O(n) for dp array


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    int k;
    cout << "Enter maximum jump distance k: ";
    cin >> k;
    vector<int> heights(n);
    cout << "Enter heights of stairs: ";
    for(int i=0; i<n; i++) {
        cin >> heights[i];
    }
    vector<int> dp(n+1, -1); // Initialize dp array with -1
    dp[0] = 0; // Base Case: If on the first stair, no energy is used
    for(int i=1; i<n; i++) {
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++) {
            if(i-j >= 0) {
                int jump = dp[i-j] + abs(heights[i] - heights[i-j]); // Jump from (i-j)th stair to ith stair
                minSteps = min(minSteps, jump);
            }
        }
        dp[i] = minSteps; // Store the minimum energy used to reach ith stair
    }
    cout << "Minimum energy used by the frog to reach the top: " << dp[n-1] << endl;
}
