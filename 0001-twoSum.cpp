#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // time complexity: O(sigma(n))
    // memory complexity: O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        /* gets a vector of numbers and a target number. 
        returns the indices of the first two numbers that add up to the target sum. */
        int j;
        for (int i = 0; i < nums.size() - 1; i++){
            for(j = i + 1; j < nums.size(); j++)
                if (*(nums.begin()+i) + *(nums.begin()+j) == target) // equivalent to: nums[i] + nums[j] == target
                    return {i, j};
        }
        return {};
    }
};