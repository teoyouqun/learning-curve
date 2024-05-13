class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jumpCount = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (jumpCount == 0) return false;
            jumpCount = (jumpCount - 1 > nums[i]) ? jumpCount - 1 : nums[i];
        }
        return true;
    }
};
