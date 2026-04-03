#include <algorithm> 

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0; 
        int right = heights.size() - 1;
        int res = 0;

        while (left < right) {
            int water = min(heights[left], heights[right]) * (right - left);
            res = max(res, water);

            if (heights[left] < heights[right]) {
                left += 1;
            }
            else {
                right -= 1;
            }
        }

        return res;
    }
};
