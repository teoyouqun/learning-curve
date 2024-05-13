#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Most solutions online use sorting

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int index = 0;
        bool cont = true;
        bool stop = false;
        if (strs[0].length() == 0) return ans;
        char currChar;
        while (cont) {
            if (strs[0].length() > index) currChar = (strs[0])[index];
            cout << currChar << endl;
            for (auto x: strs) {
                cout << x.length() << endl;
                if (x.length() > index) {
                    if (x[index] != currChar) {
                        cont = false;
                    } 
                }
                if (x.length() <= index + 1) stop = true;
            }
            if (cont) ans += currChar;
            if (stop) cont = false;
            index++;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> strList = {"abab","aba",""};
    cout << solution.longestCommonPrefix(strList) << endl;
    return 0;
}