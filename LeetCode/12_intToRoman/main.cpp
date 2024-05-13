#include <iostream>
#include <string>
#include <map>
#include <iterator>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string output;
        map<int, string> dict {{1000, "M"}, 
            {900, "CM"},
            {500, "D"},
            {400, "CD"}, 
            {100, "C"}, 
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"}, 
            {9, "IX"},
            {5, "V"}, 
            {4, "IV"},
            {1, "I"}};
        map<int, string>::reverse_iterator ptr = dict.rbegin();
        // cout << ptr->first << endl;
        while (num > 0) {
            if (ptr != dict.rend()) {
                cout << ptr -> first << next(ptr) -> first << endl;
                if (num >= ptr->first) {
                    output += ptr->second;
                    num -= ptr->first;
                } else {
                    ptr++;
                }
            }
        }
        return output;
    }
};

int main() {
    Solution solution;
    cout << solution.intToRoman(90) << endl;
    return 0;
}