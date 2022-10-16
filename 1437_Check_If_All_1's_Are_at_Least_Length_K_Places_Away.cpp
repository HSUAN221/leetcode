class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 0;
        int one_cnt = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                one_cnt++;
                if (one_cnt == 1) cnt = 0;
                if (one_cnt == 2) {
                    if (cnt < k) return false;
                    one_cnt = 1;
                    cnt = 0;
                }
            }
            if (nums[i] == 0) cnt++;
        }
        return true;
    }
};
