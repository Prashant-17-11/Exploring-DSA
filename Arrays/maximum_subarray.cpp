#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 , max_sum = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            max_sum = max(sum,max_sum);
            if(sum < 0) {
                sum = 0;
            }
        }
        return max_sum;
    }
};

// https://leetcode.com/problems/maximum-subarray/
// Problem for day 1 of LeetCode DS study plan
// Simple application of Kadane's algorithm

// Striver's SDE sheet https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/  Day 1 Problem 5
