#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int corrK = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + corrK);
        reverse(nums.begin() + corrK, nums.end());
    }

    void printArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << "[" << nums[i] << "] ";
        }
        cout << endl;
    }
};

int main() {
    Solution solution;
    vector<int> vec1, vec2; 
    int k1, k2; 
    vec1 = {1,2,3,4,5,6,7};
    k1 = 3;
    vec2 = {-1,-100,3,99};
    k2 = 2;
    solution.rotate(vec1, k1);
    solution.rotate(vec2, k2);
    solution.printArray(vec2);
    return 0;
}
