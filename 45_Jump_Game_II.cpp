class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int cur = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size()-1; ++i) {
            farthest = std::max(farthest, nums[i] + i);

            if ( i == cur) {
                cur = farthest;
                ++jumps;
            }
        }
        return jumps;
    }
};
