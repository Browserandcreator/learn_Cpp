#include <iostream>
#include <queue>

// 使用两个队列实现栈
class MyStack {
public:
    MyStack() = default; // 默认构造函数；如果没有构造函数，编译器也会生成
    void push(int x) {
        // 将新元素入队到q1
        q1.push(x);
    }

    int pop() {
        // 将q1中的元素移动到q2中，直到只剩一个元素
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        // 取出最后一个元素
        int top = q1.front();
        q1.pop();
        // 交换q1和q2
        std::swap(q1, q2);
        return top;
    }

    int top() {
        // 将q1中的元素移动到q2中，直到只剩一个元素
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        // 取出最后一个元素
        int top = q1.front();
        q2.push(top);
        q1.pop();
        // 交换q1和q2
        std::swap(q1, q2);
        return top;
    }

    bool empty() const {
        return q1.empty();
    }

private:
    // MyStack类型的每一个对象都会有两个成员队列变量
    // 当创建MyStack类对象是，也会创建这两个队列对象，调用queue的默认构造函数
    std::queue<int> q1; // 主队列
    std::queue<int> q2; // 辅助队列
};

int main() {
    MyStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "栈顶元素: " << stack.top() << std::endl; // 输出 30

    std::cout << "弹出元素: " << stack.pop() << std::endl; // 输出 30
    std::cout << "新的栈顶元素: " << stack.top() << std::endl; // 输出 20

    std::cout << "栈是否为空: " << (stack.empty() ? "是" : "否") << std::endl; // 输出 否

    return 0;
}
