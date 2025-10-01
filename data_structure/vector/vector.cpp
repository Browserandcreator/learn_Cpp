#include <iostream>
#include <vector> // 引入vector头文件

int main() {
    // vector是一个动态顺序容器，可以存储任意类型的元素
    // vector可以在任意位置插入和删除元素，同时会涉及元素的搬运
    // 当vector空间不足时，会自动扩展空间，通常是扩展为原来的两倍
    std::vector<int> v; // 创建一个存储int的vector

    // 添加元素（尾部插入）
    v.push_back(5);
    v.push_back(10);
    v.push_back(15);

    std::cout << "vector的大小: " << v.size() << std::endl;

    // 访问元素，特别之处是可以使用下标访问
    std::cout << "第一个元素: " << v[0] << std::endl;
    std::cout << "最后一个元素: " << v.back() << std::endl;

    // 遍历vector
    std::cout << "所有元素: ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // 删除最后一个元素
    v.pop_back();
    std::cout << "删除最后一个元素后，新的最后一个元素: " << v.back() << std::endl;

    // 插入元素到指定位置
    v.insert(v.begin() + 1, 20); // 在第二个位置插入20
    std::cout << "插入元素后: ";
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 删除指定位置的元素
    v.erase(v.begin()); // 删除第一个元素
    std::cout << "删除第一个元素后: ";
    for (int num : v) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 清空vector
    v.clear();
    std::cout << "vector是否为空: " << (v.empty() ? "是" : "否") << std::endl;

    return 0;
}