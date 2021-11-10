#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 1 ; i < nums.size(); i++){
            if(nums[i-1] == nums[i]) {
                return true;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/contains-duplicate/
// Problem for day 1 of LeetCode DS Study Plan