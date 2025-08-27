/*
Frog Jump Problem:
There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. Height[i] is the height of the (i+1)th stair .If frog jumps from ith to jth stair, the energy lost in the jump is given by Height[i-1] - Height[j-1]. If the frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair.Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair. 
*/

// Approach 1: Recursion        -- TLE Error
// Time Complexity: O(2^n) (Exponential)
// Space Complexity: O(n) for recursion stack

// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int frogJump(int n, vector<int>& heights) {
//     if(n==0) return 0; // Base Case: If on the first stair, no energy is used
//     int left = frogJump(n-1, heights) + abs(heights[n] - heights[n-1]); // Jump from (n-1)th stair to nth stair
//     int right = INT_MAX;
//     if(n>1) {
//         right = frogJump(n-2, heights) + abs(heights[n] - heights[n-2]); // Jump from (n-2)th stair to nth stair
//     }
//     return min(left, right); // Return the minimum energy used
// }
// int main() {
//     int n;
//     cout << "Enter number of stairs: ";
//     cin >> n;
//     vector<int> heights(n);
//     cout << "Enter heights of stairs: ";
//     for(int i=0; i<n; i++) {
//         cin >> heights[i];
//     }
//     int ans = frogJump(n-1, heights);
//     cout << "Minimum energy used by the frog to reach the top: " << ans << endl;
// }




// Approach 2: Memoization or Top-Down DP or Recursive DP
// Time Complexity: O(n)
// Space Complexity: O(n) for memoization (dp) array and O(n) for recursion stack = O(n) + O(n) = O(n)


// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int frogJump(int n, vector<int>& heights, vector<int>& dp) {
//     if(n==0) return 0; // Base Case: If on the first stair, no energy is used
//     if(dp[n] != -1) return dp[n]; // Check if already computed
//     int left = frogJump(n-1, heights, dp) + abs(heights[n] - heights[n-1]); // Jump from (n-1)th stair to nth stair
//     int right = INT_MAX;
//     if(n>1) {
//         right = frogJump(n-2, heights, dp) + abs(heights[n] - heights[n-2]); // Jump from (n-2)th stair to nth stair
//     }
//     return dp[n] = min(left, right); // Return the minimum energy used
// }
// int main() {
//     int n;
//     cout << "Enter number of stairs: ";
//     cin >> n;
//     vector<int> heights(n);
//     cout << "Enter heights of stairs: ";
//     for(int i=0; i<n; i++) {
//         cin >> heights[i];
//     }
//     vector<int> dp(n+1, -1); // Initialize dp array with -1
//     int ans = frogJump(n-1, heights, dp);
//     cout << "Minimum energy used by the frog to reach the top: " << ans << endl;
// }



// Approach 3: Tabulation or Bottom-Up DP or Iterative DP
// Time Complexity: O(n)
// Space Complexity: O(n) for dp array



// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter number of stairs: ";
//     cin >> n;
//     vector<int> heights(n);
//     cout << "Enter heights of stairs: ";
//     for(int i=0; i<n; i++) {
//         cin >> heights[i];
//     }
//     vector<int> dp(n+1); // Initialize dp array
//     dp[0] = 0; // Base Case: If on the first stair, no energy is used
//     for(int i=1; i<n; i++) {
//         int firstStep = dp[i-1] + abs(heights[i] - heights[i-1]); // Jump from (i-1)th stair to ith stair
//         int secondStep = INT_MAX;
//         if(i>1) {
//             secondStep = dp[i-2] + abs(heights[i] - heights[i-2]); // Jump from (i-2)th stair to ith stair
//         }
//         dp[i] = min(firstStep, secondStep); // Store the minimum energy used to reach ith stair
//     }
//     cout << "Minimum energy used by the frog to reach the top: " << dp[n-1] << endl;
// }



// Approach 4: Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1) since we are using only two variables to store the last two states instead of an entire dp array  -- prev2 and prev


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    vector<int> heights(n);
    cout << "Enter heights of stairs: ";
    for(int i=0; i<n; i++) {
        cin >> heights[i];
    }
    int prev2 = 0; // dp[0], Base Case: If on the first stair, no energy is used
    int prev = 0;  // dp[1]
    for(int i=1; i<n; i++) {
        int firstStep = prev + abs(heights[i] - heights[i-1]); // Jump from (i-1)th stair to ith stair
        int secondStep = INT_MAX;
        if(i>1) {
            secondStep = prev2 + abs(heights[i] - heights[i-2]); // Jump from (i-2)th stair to ith stair
        }
        int curr = min(firstStep, secondStep); // Store the minimum energy used to reach ith stair
        prev2 = prev; // Update prev2 to the previous prev
        prev = curr; // Update prev to the current minimum energy
    }
    cout << "Minimum energy used by the frog to reach the top: " << prev << endl;
}