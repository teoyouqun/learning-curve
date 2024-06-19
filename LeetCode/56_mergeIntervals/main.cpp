#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

class Solution {
public:
// Had to refer to solution but could tell the logic
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> prev = intervals[0];
        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= prev[1]) prev[1] = max(prev[1], intervals[i][1]);
            else {
                ans.push_back({prev[0], prev[1]});
                prev = intervals[i];
            }
        }
        ans.push_back({prev[0], prev[1]});
        return ans;
    }
    vector<vector<int>> merge2(vector<vector<int>>& intervals) {
        map<int,int> dict;
        map<int,int>::reverse_iterator it;
        for (auto pair:intervals) {
            bool flag = true;
            for (it = make_reverse_iterator(dict.lower_bound(pair[0])); it != dict.rend(); it++) {
                if (it->second >= pair[0]) {
                    if (pair[])
                        dict[it->first] = pair[1];
                        flag = false;
                }
                if (!flag) break;
            }
            if (flag) dict[pair[0]] = pair[1];
        }
        vector<vector<int>> ans;
        map<int,int>::iterator it2;
        for (it2 = dict.begin(); it2 != dict.end(); it2++) {
            ans.push_back({it2->first,it2->second});
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> v1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> v2 = solution.merge(v1);
    // map<int,int> newmap = {{3,4}};
    // map<int,int>::iterator it = newmap.lower_bound(2);
    for (size_t i = 0; i < v2.size(); i++) {
        cout << v2[i][0] << " " << v2[i][1] << endl;
    }
    vector<int> t1 = {1,3};
    vector<int> t2 = {2,4};
    cout << min(t1, t2) << endl;
    return 0;
}