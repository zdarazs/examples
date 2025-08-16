#include <iostream>

using namespace std;

class Rational 
{
public:
    explicit Rational( int numerator = 0, int denominator = 1 ) : 
        m_numerator{numerator},
        m_denominator{denominator} {}

    int numerator() const noexcept { return m_numerator; }
    int denominator() const noexcept { return m_denominator; }

    const Rational operator* ( const Rational& rhs ) const 
    {
        return Rational( m_numerator * rhs.numerator(), m_denominator * rhs.denominator() );
    }

private:
    int m_numerator;
    int m_denominator;
};

ostream& operator<< ( ostream& os, const Rational& r )
{
    os << r.numerator() << '/' << r.denominator();
    return os;
}

// const Rational operator*( const Rational& lhs, const Rational& rhs )
// {
//     return Rational( lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator() );
// }

int main()
{
    Rational oneHalf( 1, 2 );
    Rational oneThird( 1, 3 );
    Rational res = oneHalf * oneThird;
    cout << "oneHalf * oneThird = " << res << endl;
    return 0;
}
