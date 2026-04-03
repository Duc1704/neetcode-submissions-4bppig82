#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> triplets;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            std::vector<std::vector<int>> pairs = pair_sum_sorted_all_pairs(nums, i + 1, -nums[i]);

            for (vector<int>& pair : pairs) {
                std::vector<int> triplet;
                triplet.push_back(nums[i]);
                triplet.insert(triplet.end(), pair.begin(), pair.end());
                triplets.push_back(triplet);
            }

        }
        return triplets;

    }

    vector<vector<int>> pair_sum_sorted_all_pairs(vector<int>& nums, int start, int target) {
        int left = start;
        int right = nums.size() - 1;

        std::vector<std::vector<int>> pairs;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                std:vector<int> pair;
                pair.push_back(nums[left]);
                pair.push_back(nums[right]);
                pairs.push_back(pair);
                left += 1;

                while (left < right && nums[left] == nums[left - 1]) {
                    left += 1;
                } 
            }
            else if (sum < target) {
                left += 1;
            }
            else {
                right -= 1;
            }

        }

        return pairs;
    }
};
