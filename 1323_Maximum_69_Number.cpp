class Solution {
 public:
    int maximum69Number (int num) {
        auto str = std::to_string(num);
        auto switchChar = [](char c) -> char {
            if (c == '9') {
                c = '6';
            } else if (c == '6') {
                c = '9';
            }
            return c;
        };
        for (size_t i = 0; i < str.size(); ++i) {
            str[i] = switchChar(str[i]);
            num = std::max(num, std::stoi(str));
            str[i] = switchChar(str[i]);
        }
        return num;
    }
};
