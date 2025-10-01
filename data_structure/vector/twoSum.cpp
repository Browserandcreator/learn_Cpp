/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/leetcamp-3-plus/d55inc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <numeric> // 引入numeric头文件以使用std::accumulate
#include <unordered_map> // 引入unordered_map头文件以使用std::unordered_map
using namespace std;

class Solution {
public:
    // 返回一组整数索引
    vector<int> twoSum(vector<int>& nums, int target) {
        // 关联容器，存储数值和对应的索引
        // 底层为哈希表，查找和插入的时间复杂度为O(1)
        unordered_map<int, int> numMap; // 此处以需要查找的数值为键，索引为值
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    
    cout << "Indices of the two numbers that add up to " << target << ": ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
    
    return 0;
}