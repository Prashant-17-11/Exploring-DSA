// Striver's SDE sheet https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/  Day 1 Problem 3
// https://leetcode.com/problems/pascals-triangle/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        
        for(int i = 0; i <= numRows-1; i++) {
            vector<int> row;
            for(int j = 0; j <= i; j++) {
                if(j == 0 || j == i) {
                    row.push_back(1);
                } else {
                    row.push_back(pascalTriangle[i-1][j-1]+pascalTriangle[i-1][j]);
                }
            }
            pascalTriangle.push_back(row);
        }
        
        return pascalTriangle;
    }
};