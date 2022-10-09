class Solution {
public:
    string minRemoveToMakeValid(string s) {
        std::stack<int> sto;
        for (size_t i = 0; i < s.size(); ++i) {
            auto c = s[i];
            if (c == '(') {
                sto.push(i);
            } else if (c == ')') {
                if (!sto.empty()) {
                    sto.pop();
                } else {
                    s[i] = '?';
                }
            }
        }
        while (!sto.empty()) {
            s[sto.top()] = '?';
            sto.pop();
        }
        std::string ss;
        for (auto& c : s) {
            if (c != '?') {
                ss.push_back(c);
            }
        }
        return ss;
    }
};
