#include <iostream>
#include <unordered_map> // 引入哈希表（unordered_map）头文件

int main() {
    // 创建一个以int为键，string为值的哈希表
    std::unordered_map<int, std::string> numMap;

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

    // 遍历哈希表
    std::cout << "所有键值对:" << std::endl;
    // 遍历容器的每个元素
    // const表示不允许修复里面的值
    // &表示引用，避免拷贝开销
    // pair是循环变量的名字，pair是键值对，first是键，second是值
    for (const auto& pair : numMap) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    // 删除某个键
    numMap.erase(2);
    std::cout << "删除键2后，哈希表内容:" << std::endl;
    for (const auto& pair : numMap) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    // 清空哈希表
    numMap.clear();
    std::cout << "哈希表是否为空: " << (numMap.empty() ? "是" : "否") << std::endl;

    return 0;
}