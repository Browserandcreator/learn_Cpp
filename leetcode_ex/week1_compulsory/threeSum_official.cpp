#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:

    void print(vector<int>& v) {
        for (auto& e: v) 
            cout << e << ", ";
        cout << "\n";
    }

    vector<vector<int>> ret;

    void twoSum(vector<int>& nums, int i) {
        // i < left < right
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] == 0) {
                ret.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left+1])
                    left++;
                while(left < right && nums[right] == nums[right-1])
                    right--;
                left++;
                right--;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // print(nums);
        for (int i = 0;i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                twoSum(nums, i);
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    vector<int> v = {-1,0,1,2,-1,-4};
    auto ret = s.threeSum(v);
    for (auto& vec: ret) {
        for (auto& e: vec) 
            cout << e << ", ";
        cout << "\n";
    }
}