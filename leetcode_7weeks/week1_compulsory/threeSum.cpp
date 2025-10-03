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
#include <algorithm> // 引入algorithm头文件以使用std::sort
using namespace std;

// 参考两数之和
class twoSumSolution {
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

class ThreeSumSolution {
public:
    // 参数：vector<int>& nums, 整数动态数组，加&表示直接引用本数组，不复制
    // vector<vector<int>>表示一个类型为vector<int>的二维数组，类似**int**
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // 首先对数组进行排序
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 跳过重复元素
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) ++left; // 跳过重复元素
                    while (left < right && nums[right] == nums[right - 1]) --right; // 跳过重复元素
                    ++left;
                    --right;
                }
            }
        }
        return result;
    }
};

int main() {
    ThreeSumSolution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);
    
    cout << "Triplets that sum to zero:" << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}