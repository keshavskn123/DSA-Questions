/*
Code studio Question: Climbing Stairs

Problem Statement: You are climbing a staircase with n steps. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top (from 0th step to nth step)

*/

#include<iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;

    if (n <= 1) {
        cout << "Number of distinct ways to climb to the top: " << n << endl;
        return 0;
    }

    int prev2 = 1; // Base case: 1 way to climb 0 steps
    int prev1 = 1; // Base case: 1 way to climb 1 step

    for (int i = 2; i <= n; i++) {
        int current = prev1 + prev2; // Current ways = ways to climb (i-1) + ways to climb (i-2)
        prev2 = prev1; // Update prev2 to prev1
        prev1 = current; // Update prev1 to current
    }

    cout << "Number of distinct ways to climb to the top: " << prev1 << endl;
    return 0;
}