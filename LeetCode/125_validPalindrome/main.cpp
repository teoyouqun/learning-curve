class Solution {
public:
    bool isPalindrome(string s) {
        int lp {0}; 
        int rp = s.length() - 1;
        while (lp < rp) {
            while (!isalnum(s[lp]) && (lp < s.length() - 1)) lp++;
            while (!isalnum(s[rp]) && (rp > 0)) rp--;
            if (lp >= rp) return true;
            if (tolower(s[lp]) == tolower(s[rp])) {
                lp++;
                rp--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
