#include <iostream>
#include <map> // 引入map头文件

int main() {
    // 创建一个以int为键，string为值的有序映射（map）
    std::map<int, std::string> numMap;

    // 插入元素
    numMap[1] = "one";
    numMap[2] = "two";
    numMap[3] = "three";

    // 访问元素
    std::cout << "键为2的值: " << numMap[2] << std::endl;

    // 判断某个键是否存在
    if (numMap.count(4)) {
        std::cout << "键4存在" << std::endl;
    } else {
        std::cout << "键4不存在" << std::endl;
    }

    // 遍历map（有序，按键从小到大）
    std::cout << "所有键值对:" << std::endl;
    for (const auto& pair : numMap) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    // 删除某个键
    numMap.erase(2);
    std::cout << "删除键2后，map内容:" << std::endl;
    for (const auto& pair : numMap) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    // 清空map
    numMap.clear();
    std::cout << "map是否为空: " << (numMap.empty() ? "是" : "否") << std::endl;

    return 0;
}