/*
给定一维数组，求数组中 从左往右 每个数字 第一次 出现的位置。如果是 第一次 出现则返回 -1, 否则返回出现的位置
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findFirstOccurrence(const vector<int>& nums) {
    unordered_map<int, int> numMap;
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        if (numMap.find(nums[i]) == numMap.end()) {
            result.push_back(-1);
            numMap[nums[i]] = i; // 记录第一次出现的位置
        } else {
            result.push_back(numMap[nums[i]]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 2, 1, 4};
    vector<int> result = findFirstOccurrence(nums);

    cout << "First occurrence indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}