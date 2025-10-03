/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
说明：

你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/leetcamp-3-plus/vhba2v/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <stack>
#include <stdexcept> // 引入stdexcept头文件以使用std::runtime_error
using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        // 将元素推入栈1
        stack1.push(x);
    }

    int pop() {
        // 如果栈2为空，则将栈1中的元素全部移到栈2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // 如果栈2仍然为空，则抛出异常
        if (stack2.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        // 弹出栈2的顶部元素
        int value = stack2.top();
        stack2.pop();
        return value;
    }

    int peek() {
        // 如果栈2为空，则将栈1中的元素全部移到栈2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // 如果栈2仍然为空，则抛出异常
        if (stack2.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        // 返回栈2的顶部元素
        return stack2.top();
    }

    bool empty() const {
        return stack1.empty() && stack2.empty();
    }

private:
    stack<int> stack1; // 主栈
    stack<int> stack2; // 辅助栈
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    int front = q.peek();  // 返回 1
    int popped = q.pop();   // 返回 1
    bool isEmpty = q.empty(); // 返回 false
    return 0;
}