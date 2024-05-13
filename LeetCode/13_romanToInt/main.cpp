#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict;
        dict.insert({'I', 1});
        dict.insert({'V', 5});
        dict.insert({'X', 10});
        dict.insert({'L', 50});
        dict.insert({'C', 100});
        dict.insert({'D', 500});
        dict.insert({'M', 1000});
        int total = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (i == s.length() - 1) {
                total += dict.at(s.at(i));
            } else {
                if (dict.at(s[i]) < dict.at(s[i+1])) {
                    total -= dict.at(s.at(i));
                } else {
                    total += dict.at(s.at(i));
                }
            }
        }
        return total;
    }
};

int main() {
    Solution solution;
    string a = "IV";
    cout << solution.romanToInt(a) << endl;
    return 0;
}