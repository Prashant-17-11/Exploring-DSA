// Leetcode DS1 Day 2 
// https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

// brute force solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        for(int i = 0 ; i < nums.size(); i++) {
            for(int j = i+1 ; j < nums.size() ; j++) {
                if(nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        
        return ans;
    }
};


