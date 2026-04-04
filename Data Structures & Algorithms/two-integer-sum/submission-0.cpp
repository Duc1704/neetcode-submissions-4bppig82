#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> unmap;

        for (int i = 0; i < nums.size(); i++) {
            unmap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int otherNum = target - nums[i];

            if (unmap.find(otherNum) != unmap.end() && unmap[otherNum] != i) {
                return {i, unmap[otherNum]};
            }
        }
    }
};
