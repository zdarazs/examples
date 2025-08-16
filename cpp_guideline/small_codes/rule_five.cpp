#include <iostream>

class MyClass
{
private:
    int* resource;

public:
    // Constructor: allocate resource, default constructor won't be automatically generate
    explicit MyClass( const int value ) : resource( new int(value) )
    {
        std::cout << "Resource allocated: " << *resource << std::endl;
    }

    // Destructor: free resource
    ~MyClass()
    {
        delete resource;
        std::cout << "Resource deallocated" << std::endl;
    }

    // Deleting the copy constructor to prevent copying
    MyClass( const MyClass& ) = delete;

    // Deleting the copy assignment operator to prevent copying
    MyClass& operator=( const MyClass& ) = delete;

    // Deleting the move constructor to prevent moving
    MyClass( MyClass&& ) = delete;

    // Deleting the move assignment operator to prevent moving
    MyClass& operator=( MyClass&& ) = delete;

    // Get the resource value
    inline int value() const noexcept { return *resource; }
};

int main()
{
    MyClass r(42); // Creates a resource with value 42

    // Uncommenting the following lines would cause compile-time errors
    // MyClass r2 = r;      // Copy constructor is deleted
    // MyClass r3 = std::move(r);  // Move constructor is deleted

    std::cout << "r value: " << r.value() << std::endl;

    return 0;
}
