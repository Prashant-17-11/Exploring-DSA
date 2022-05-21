// Striver's SDE sheet https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/  Day 1 Problem 6
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min = INT_MAX, max = 0;
        
        for(int i = 0; i < n; i++) {
            if(min > prices[i]){
                min = prices[i];
            }
            if(max < prices[i]-min) {
                max = prices[i]-min;
            }
        }
        return max;
    }
};