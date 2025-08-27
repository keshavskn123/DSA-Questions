/*
LeetCode Problem Link: https://leetcode.com/problems/maximum-sum-of-non-adjacent-elements/

3165. Maximum Sum of Subsequence With Non-adjacent Elements


*/

// Approach 1: Recursion        -- TLE Error
// Time Complexity: O(2^n) (Exponential)
// Space Complexity: O(n) for recursion stack

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int maxSum(int n, vector<int>& arr) {
//     if(n==0) return arr[0];                     // Base Case: If only one element, return that element
//     if(n<0) return 0;                           // Base Case: If index is negative, return 0
//     int pick = arr[n] + maxSum(n-2, arr);       // Include the current element and move to n-2
//     int notPick = 0 + maxSum(n-1, arr); // Exclude the current element and move to n-1
//     return max(pick, notPick); // Return the maximum of include and exclude
// }

// int main() {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;
//     vector<int> arr(n);
//     cout << "Enter elements of array: ";
//     for(int i=0; i<n; i++) {
//         cin >> arr[i];
//     }
//     cout << "Maximum sum of non-adjacent elements: " << maxSum(n-1, arr) << endl;
// }




// Approach 2: Memoization or Top-Down DP or Recursive DP
// Time Complexity: O(n)
// Space Complexity: O(n) for memoization (dp) array and O(n) for recursion stack = O(n) + O(n) = O(n)

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int maxSum(int n, vector<int>& arr, vector<int>& dp) {
//     if(n==0) return arr[0];                     // Base Case: If only one element, return that element
//     if(n<0) return 0;                           // Base Case: If index is negative, return 0
//     if(dp[n] != -1) return dp[n];               // Check if already computed
//     int pick = arr[n] + maxSum(n-2, arr, dp);       // Include the current element and move to n-2
//     int notPick = 0 + maxSum(n-1, arr, dp); // Exclude the current element and move to n-1
//     return dp[n] = max(pick, notPick); // Return the maximum of include and exclude   
// }

// int main() {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;
//     vector<int> arr(n);
//     cout << "Enter elements of array: ";
//     for(int i=0; i<n; i++) {
//         cin >> arr[i];
//     }
//     vector<int> dp(n, -1);          // Initialize dp array with -1
//     cout << "Maximum sum of non-adjacent elements: " << maxSum(n-1, arr, dp) << endl;
// }



// AApproach 3: Tabulation or Bottom-Up DP or Iterative DP
// Time Complexity: O(n)
// Space Complexity: O(n) for dp array

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter number of elements: ";
//     cin >> n;
//     vector<int> arr(n);
//     cout << "Enter elements of array: ";
//     for(int i=0; i<n; i++) {
//         cin >> arr[i];
//     }
//     vector<int> dp(n, -1);          // Initialize dp array with -1
//     dp[0] = arr[0];                 // Base Case: If only one element, return that element
//     for(int i=1; i<n; i++) {
//         int pick = arr[i];                  // Include the current element
//         if(i>1) pick += dp[i-2];            // If i>1, add the value from dp[i-2]
//         int notPick = 0 + dp[i-1];          // Exclude the current element
//         dp[i] = max(pick, notPick);         // Store the maximum of include and exclude in dp[i]
//     }
//     cout << "Maximum sum of non-adjacent elements: " << dp[n-1] << endl; // The answer will be in dp[n-1]
// }


// Approach 4: Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of array: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int prev2 = 0;                   // To store dp[i-2]
    int prev = arr[0];              // To store dp[i-1]    
    // int curr;                        // To store dp[i]
    for(int i=1; i<n; i++) {
        int pick = arr[i];                  // Include the current element
        if(i>1) pick += prev2;            // If i>1, add the value from dp[i-2]
        int notPick = 0 + prev;          // Exclude the current element
        int curr = max(pick, notPick);         // Store the maximum of include and exclude in dp[i]
        prev2 = prev;                   // Update prev2 to prev
        prev = curr;                    // Update prev to curr
    }
    cout << "Maximum sum of non-adjacent elements: " << prev << endl; // The answer will be in dp[n-1]
}