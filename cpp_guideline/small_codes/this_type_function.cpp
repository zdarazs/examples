#include <iostream>
#include <vector>

template< typename T >
class MyVector 
{
    using DataType = std::vector<T>;
public:
    MyVector() = default;
    explicit MyVector( const size_t size ) : m_data(size) {}
    explicit MyVector( const size_t size, const T& value ) : m_data(size, value) {}
    ~MyVector() = default;
    MyVector( const MyVector& ) = default;
    MyVector& operator=( const MyVector& ) = default;
    MyVector( MyVector&& ) noexcept = default;
    MyVector& operator=( MyVector&& ) noexcept = default;

    DataType& getData() &
    {
        std::cout << "lvalue member function called" << std::endl;
        return m_data; 
    }
    DataType getData() &&
    {
        std::cout << "rvalue member function called" << std::endl;
        return std::move(m_data);
    }
private: 
    DataType m_data;
};

int main()
{
    using std::cout;
    MyVector<int> myVector( 2, 42 );
    std::vector<int> vecl = myVector.getData();
    std::vector<int> vecr = (MyVector(3,137)).getData();
    for ( const auto& v : vecl ) cout << v << " ";
    cout << "\n";
    for ( const auto& v : vecr ) cout << v << " ";
    cout << std::endl;
    return 0;
}