class Solution {
public:
    int romanToInt(string s) {
        std::deque<int> sto;
        for (const auto& c : s) {
            switch (c) {
                case 'I':
                    sto.push_back(1);
                    break;
                case 'V':
                    sto.push_back(5);
                    break;
                case 'X':
                    sto.push_back(10);
                    break;
                case 'L':
                    sto.push_back(50);
                    break;
                case 'C':
                    sto.push_back(100);
                    break;
                case 'D':
                    sto.push_back(500);
                    break;
                case 'M':
                    sto.push_back(1000);
                    break;
            }
        }
        int result = sto.back();
        int buffer = sto.back();
        sto.pop_back();
        while (!sto.empty()) {
            if (sto.back() < buffer) {
                result -= sto.back();
            } else {
                result += sto.back();
            }
            buffer = sto.back();
            sto.pop_back();
        }
        return result;
    }
};
