class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int cur = 0;
        int farhest = 0;

        for (int i = 0; i < nums.size()-1; ++i) {
            farhest = std::max(farhest, nums[i] + i);

            if ( i == cur) {
                cur = farhest;
                ++jumps;
            }
        }
        return jumps;
    }
};
