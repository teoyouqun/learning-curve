#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size();
        int l = 0;
        int r = 0; 
        int total = 0;
        while (true) {
            // cout << total << " " << l << " " << r << endl;
            total += nums[r];
            if (total < target) {
                total += 0;
            } else if (total == target) {
                if (r - l + 1 < minLen) minLen = r - l + 1;
            } else {
                while (total >= target) {
                    if (total == target && r - l + 1 < minLen) minLen = r - l + 1;
                    total -= nums[l];
                    l++;
                }
            }
            r++;
            if (r == nums.size()) {
                if (l == 0) return 0;
                else break;
            }
        }
        return minLen;
    }
};

int main() {
    Solution solution;
    vector<int> b = {2,3,1,2,4,3};
    int a = 7;
    cout << solution.minSubArrayLen(a, b) << endl;
    return 0;
}