class Solution {
public:
    string getSmallestString(int n, int k) {
        std::string result(n, 'a');
        k -= n;
        n--;
        while (k > 0) {
            if (k >= 25) {
                k -= 25;
                result[n] += 25;
            } else {
                result[n] += k;
                k = 0;
            }
            --n;
        }
        return result;
    }
};
