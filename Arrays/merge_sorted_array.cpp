// Leetcode DS1 Day 2 
// https://leetcode.com/problems/merge-sorted-array/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1 , j = n-1 , k = n+m-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i] <= nums2[j])
            {
                nums1[k] = nums2[j];
                j--;
            }
            else
            {
                nums1[k] = nums1[i];
                i--;
            }
            k--;
        }
        if(i < 0)
        {
            for(int z  = k ; z>=0 ; z--)
            {
                nums1[z] = nums2[j];
                j--;
            }
        }
        else if(j < 0)
        {    
            for(int z  = k ; z>=0 ; z--)
            {
                nums1[z] = nums1[i];
                i--;
            }
        }
    }
};