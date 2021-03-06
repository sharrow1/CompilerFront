#include "vm.h"

#include "OpCode.h"

#include <stack>
#include <memory>

namespace ink {

class Frame
{

};
typedef std::shared_ptr<Frame> FramePtr;

class Stack
{
    public:
        Stack();
        ~Stack();

        void Pop() { stack_.pop(); }
        void Push(FramePtr f) { stack_.push(f); }
        FramePtr GetTop() const { return stack_.top(); }

    private:
        std::stack<FramePtr> stack_;
};

class Runtime
{
    public:

        template<class T>
        T* GetValue(size_t) { return nullptr; }
};

void vm::Run()
{
    while (1)
    {
        // TODO, use direct-threaded dispatch to improve performance
        short in = code_[ip_];
        switch (in)
        {
            case OP_MOV:
            {
                break;
            }
            case OP_LDL:
            case OP_LDG:
            case OP_LDK:
            case OP_LDF:
            case OP_LDS:
                {
                    break;
                };
            default:
                return;
        }
    }
}

}

