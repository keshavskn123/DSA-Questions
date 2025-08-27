/*
House Robber [Leetcode 198]
Leetcode Problem Link: https://leetcode.com/problems/house-robber/

Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Approach 1: Recursion
// Time Complexity: O(2^n)
// Space Complexity: O(n) for recursion stack   

// int f(vector<int>& arr, int i) {
//     //Base Cases 
//     if(i==arr.size()-1) return arr[i];
//     if(i==arr.size()-2) return max(arr[i], arr[i+1]);
//     if(i>= arr.size()) return 0;
//     return max(arr[i] + f(arr, i+2), 0 + f(arr, i+1));       // max(pick, notPick)
// }

// int rob(vector<int>& nums) {
//     return f(nums, 0);       // Start from index i=0
// }

// int main() {
//     vector<int> nums = {2,7,9,3,1};
//     cout << "Maximum amount of money you can rob: " << rob(nums) << endl;
// }



// Approach 2: Memoization or Top-Down DP or Recursive DP
// Time Complexity: O(n)
// Space Complexity: O(n) for memoization (dp) array and O(n) for recursion stack = O(n) + O(n) = O(n)


// int f(vector<int>& arr, int i, vector<int>& dp) {
//     int n = arr.size();
//     //Base Cases 
//     if(i == n-1) return arr[i];
//     if(i == n-2) return max(arr[i], arr[i+1]);
//     if(i >= n) return 0;

//     if(dp[i] != -1) return dp[i];
//     return dp[i] = max(arr[i] + f(arr, i+2, dp), 0 + f(arr, i+1, dp));  // max(pick, notPick)
// }

// int rob(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> dp(n+1, -1);
//     return f(nums, 0, dp);       // Start from index i=0
// }

// int main() {
//     vector<int> nums = {2,7,9,3,1};
//     cout << "Maximum amount of money you can rob: " << rob(nums) << endl;
// }



// Approach 3: Tabulation or Bottom-Up DP or Iterative DP
// Time Complexity: O(n)
// Space Complexity: O(n) for dp array

// int rob(vector<int>& nums) {
//     int n = nums.size();
//     if(n==1) return nums[0];
//     vector<int> dp(n);
//     dp[n-1] = nums[n-1];
//     dp[n-2] = max(nums[n-2], nums[n-1]);
//     for(int i=n-3; i>=0; i--) {
//         dp[i] = max(dp[i+1], nums[i]+dp[i+2]);      
//     }
//     return dp[0];
// }

// int main() {
//     vector<int> nums = {2,7,9,3,1};
//     cout << "Maximum amount of money you can rob: " << rob(nums) << endl;
// }



// Approach 4: Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1)

// int rob(vector<int>& nums) {
//     int n = nums.size();
//     if(n==1) return nums[0];
//     int next2 = nums[n-1];               // dp[i+1]     -- similar to dp[n-1]
//     int next1 = max(nums[n-2], nums[n-1]); // dp[i+2]   -- similar to dp[n-2]
//     for(int i=n-3; i>=0; i--) {
//         int curr = max(next1, nums[i]+next2); // dp[i] = max(dp[i+1], nums[i]+dp[i+2])
//         next2 = next1;   // Move to next
//         next1 = curr;    // Move to next
//     }
//     return next1;       // dp[0]
// }

// int main() {
//     vector<int> nums = {2,7,9,3,1};
//     cout << "Maximum amount of money you can rob: " << rob(nums) << endl;
// }


// Alternate Method [Similar to Maximum Sum of Non-Adjacent Elements Problem]

// Approach: Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1)


int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    int prev2 = 0;                   // To store dp[i-2]
    int prev = nums[0];              // To store dp[i-1]    
    for(int i=1; i<n; i++) {
        int pick = nums[i];                  // Include the current element
        if(i>1) pick += prev2;            // If i>1, add the value from dp[i-2]
        int notPick = 0 + prev;          // Exclude the current element
        int curr = max(pick, notPick);         // Store the maximum of include and exclude in dp[i]
        prev2 = prev;                   // Update prev2 to prev
        prev = curr;                    // Update prev to curr
    }
    return prev;                       // The answer will be in prev (dp[n-1])

    // For circular version:
    // return max({helper(temp1), helper(temp2), helper(nums)});   
}

int main() {
    vector<int> nums = {2,7,9,3,1};
    cout << "Maximum amount of money you can rob: " << rob(nums) << endl;
}