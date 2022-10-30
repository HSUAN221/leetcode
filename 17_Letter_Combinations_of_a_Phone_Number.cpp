class Solution {
 private:
    std::string mapping(int num) {
        switch (num) {
            case 1 : {
                return std::string();
                break;
            }
            case 2 : {
                return "abc";
                break;
            }
            case 3 : {
                return "def";
                break;
            }
            case 4 : {
                return "ghi";
                break;
            }
            case 5 : {
                return "jkl";
                break;
            }
            case 6 : {
                return "mno";
                break;
            }
            case 7 : {
                return "pqrs";
                break;
            }
            case 8 : {
                return "tuv";
                break;
            }
            case 9 : {
                return "wxyz";
                break;
            }
        }

        return std::string();
    }
    
    void expand(std::string& str, int index, int max) {
        if (index == max) {
            str_list_.push_back(str);
        }

        int digit = 0;
        std::string product;
        if (index < max) {
            digit = digits_num_[index];
            product = mapping(digit);
        }
        
        for (int i = 0; i < product.size(); ++i) {
            str.push_back(product[i]);
            expand(str, index+1, max);
            str.erase(index);
        }
    }

    std::vector<string> str_list_;
    std::vector<int> digits_num_;

 public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return str_list_;
        for (size_t i = 0; i < digits.size(); ++i) {
            std::stringstream stream;
            stream << digits[i];
            int temp = 0;
            stream >> temp;
            digits_num_.push_back(temp);
        }
        std::string str;
        expand(str, 0, digits_num_.size());
        return str_list_;
    }
};
