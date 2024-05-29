class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> dict;
        for (auto c:magazine) {
            if (!dict.contains(c)) dict[c] = 1;
            else dict[c]++;
        }
        for (auto d:ransomNote) {
            if (dict.contains(d) && dict[d] >= 1) {
                dict[d]--;
                continue;
            }
            else return false;
        }
        return true;
    }
};

