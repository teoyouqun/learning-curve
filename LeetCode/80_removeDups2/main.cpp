#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currValue = nums[0];
        int currCount = 0;
        int writeIndex = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == currValue) {
                currCount++;
                i++;
            } else {
                int j = currCount >= 2 ? 2 : 1;
                for (int k = 0; k < j; k++) {
                    nums[writeIndex] = currValue;
                    writeIndex++;
                }
                currValue = nums[i];
                currCount = 0;
            }
            if (i == nums.size()) {
                int j = currCount >= 2 ? 2 : 1;
                for (int k = 0; k < j; k++) {
                    nums[writeIndex] = currValue;
                    writeIndex++;
                }
            }
        }
        return writeIndex;
    }

    int removeDuplicates2(vector<int>& nums) {
        int i =0;
        // int ele= nums[0];
        for(auto ele : nums)
        {
            if(i==0 || i==1 || nums[i-2] != ele)
            {
                nums[i] = ele;
                i++;
            }
        }
        return i ;
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
    vector<int> num1 = {1,1,1,2,2,3};
    vector<int> num2 = {0,0,1,1,1,1,2,3,3};
    solution.removeDuplicates(num2);
    solution.printArray(num2);
    return 0;
}