#include <iostream>
#include <memory>

class Base {
public:
    virtual void foo() { std::cout << "Base\n"; };
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    virtual void foo() override { std::cout << "Derived\n"; };
    virtual ~Derived() = default;
};

int main()
{
    std::unique_ptr<Base> base = std::make_unique<Base>();
    std::unique_ptr<Base> derived = std::make_unique<Derived>();
    base->foo();
    derived->foo();
    return 0;
}